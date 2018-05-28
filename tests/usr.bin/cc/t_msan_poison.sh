# Copyright (c) 2018 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Harry Pantazis.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

test_target()
{
	SUPPORT='n'
	if uname -m | grep -q "amd64"; then
		SUPPORT='y'
	fi
}

atf_test_case poison
poison_head() {
	atf_set "descr" "Test memory sanitizer for __msan_poison interface"
	atf_set "require.progs" "cc"
}

atf_test_case poison_profile
poison_profile_head() {
	atf_set "descr" "Test memory sanitizer for __msan_poison with profiling option"
	atf_set "require.progs" "cc"
}
atf_test_case poison_pic
poison_pic_head() {
	atf_set "descr" "Test memory sanitizer for __msan_poison with position independent code (PIC) flag"
	atf_set "require.progs" "cc"
}
atf_test_case poison_pie
poison_pie_head() {
	atf_set "descr" "Test memory sanitizer for __msan_poison with position independent execution (PIE) flag"
	atf_set "require.progs" "cc"
}
atf_test_case poison32
poison32_head() {
	atf_set "descr" "Test memory sanitizer for __msan_poison in NetBSD_32 emulation"
	atf_set "require.progs" "cc file diff cat"
}


poison_body(){
	cat > test.c << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -o test test.c
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./test
}

poison_profile_body(){
	cat > test.c << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -o test -pg test.c 
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./test
}

poison_pic_body(){
	cat > test.c << EOF
#include <stdio.h>
#include <stdlib.h>
int help(int);
int main(int argc, char **argv) {return help(argc);}
EOF

	cat > pic.c << EOF
#include <sanitizer/msan_interface.h>

int help(int argc) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -fPIC -shared -o libtest.so pic.c
	cc -o test test.c -fsanitize=memory -L. -ltest

	export LD_LIBRARY_PATH=.
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./test
}
poison_pie_body(){
	
	#check whether -pie flag is supported on this architecture
	if ! cc -pie -dM -E - < /dev/null 2>/dev/null >/dev/null; then 
		atf_set_skip "cc -pie not supported on this architecture"
	fi
	cat > test.c << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -o test -fpie -pie test.c 
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./test
}


poison32_body(){
	
	# check what this architecture is, after all
	if ! cc -dM -E - < /dev/null | grep -F -q _LP64; then
		atf_skip "This is not a 64 bit architecture"
	fi
	if ! cc -m32 -dM -E - < /dev/null 2>/dev/null > ./def32; then
		atf_skip "cc -m32 Not supported on this architecture"
	else
		if grep -F -q _LP64 ./def32; then
		atf_fail "cc -m32 Does not generate NetBSD32 binaries"
		fi
	fi

	cat > test.c << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -o md32 -m32 test.c
	cc -fsanitize=memory -o md64 test.c
	file -b ./md32 > ./ftype32
	file -b ./md64 > ./ftype64
	if diff ./ftype32 ./ftype64 >/dev/null; then
		atf_fail "Generated 32bit binaries do not differ from 64bit ones"
	fi
	echo "32bit binaries on this platform are:"
	cat ./ftype32
	echo "64bit binaries are on the other hand:"
	cat ./ftype64
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./md32

	# Another test with profile 32bit binaries, just to make sure everything has been thoroughly done
	cat > test.c << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  __msan_poison(p + 10, 2);

  __msan_check_mem_is_initialized(p + 5, 20);
  return 0;
}
EOF

	cc -fsanitize=memory -pg -m32 -o test test.c
	atf_check -s ignore -o ignore -e match:"Uninitialized bytes in __msan_check_mem_is_initialized at offset 5 inside" ./test
}

atf_test_case target_not_supported
target_not_supported_head()
{
	atf_set "descr" "Test forced skip"
}

atf_init_test_cases()
{
	test_target
	test $SUPPORT = 'n' && {
		atf_add_test_case target_not_supported
		return 0
	}
	atf_add_test_case poison
	atf_add_test_case poison_profile
	atf_add_test_case poison_pie
	atf_add_test_case poison_pic
	# atf_add_test_case poison32
}
