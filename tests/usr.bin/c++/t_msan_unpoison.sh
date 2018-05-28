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

atf_test_case unpoison
unpoison_head() {
	atf_set "descr" "Test memory sanitizer for __msan_unpoison interface"
	atf_set "require.progs" "c++"
}

atf_test_case unpoison_profile
unpoison_profile_head() {
	atf_set "descr" "Test memory sanitizer for __msan_unpoison with profiling option"
	atf_set "require.progs" "c++"
}
atf_test_case unpoison_pic
unpoison_pic_head() {
	atf_set "descr" "Test memory sanitizer for __msan_unpoison with position independent code (PIC) flag"
	atf_set "require.progs" "c++"
}
atf_test_case unpoison_pie
unpoison_pie_head() {
	atf_set "descr" "Test memory sanitizer for __msan_unpoison with position independent execution (PIE) flag"
	atf_set "require.progs" "c++"
}
atf_test_case unpoison32
unpoison32_head() {
	atf_set "descr" "Test memory sanitizer for __msan_unpoison in NetBSD_32 emulation"
	atf_set "require.progs" "c++ file diff cat"
}


unpoison_body(){
	cat > test.cc << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -o test test.cc
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./test
}

unpoison_profile_body(){
	cat > test.cc << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -o test -pg test.cc 
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./test
}

unpoison_pic_body(){
	cat > test.cc << EOF
#include <stdio.h>
#include <stdlib.h>
int help(int);
int main(int argc, char **argv) {return help(argc);}
EOF

	cat > pic.cc << EOF
#include <sanitizer/msan_interface.h>

int help(int argc) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -fPIC -shared -o libtest.so pic.cc
	c++ -o test test.cc -fsanitize=memory -L. -ltest

	export LD_LIBRARY_PATH=.
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./test
}
unpoison_pie_body(){
	
	#check whether -pie flag is supported on this architecture
	if ! c++ -pie -dM -E - < /dev/null 2>/dev/null >/dev/null; then 
		atf_set_skip "c++ -pie not supported on this architecture"
	fi
	cat > test.cc << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -o test -fpie -pie test.cc 
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./test
}


unpoison32_body(){
	
	# check what this architecture is, after all
	if ! c++ -dM -E - < /dev/null | grep -F -q _LP64; then
		atf_skip "This is not a 64 bit architecture"
	fi
	if ! c++ -m32 -dM -E - < /dev/null 2>/dev/null > ./def32; then
		atf_skip "c++ -m32 Not supported on this architecture"
	else
		if grep -F -q _LP64 ./def32; then
		atf_fail "c++ -m32 Does not generate NetBSD32 binaries"
		fi
	fi

	cat > test.cc << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -o md32 -m32 test.cc
	c++ -fsanitize=memory -o md64 test.cc
	file -b ./md32 > ./ftype32
	file -b ./md64 > ./ftype64
	if diff ./ftype32 ./ftype64 >/dev/null; then
		atf_fail "Generated 32bit binaries do not differ from 64bit ones"
	fi
	echo "32bit binaries on this platform are:"
	cat ./ftype32
	echo "64bit binaries are on the other hand:"
	cat ./ftype64
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./md32

	# Another test with profile 32bit binaries, just to make sure everything has been thoroughly done
	cat > test.cc << EOF
#include <sanitizer/msan_interface.h>

int main(void) {
  char p[32] = {};
  char q[32] = {};
  __msan_poison(p + 10, 2);
  __msan_poison(q, 32);
  __msan_unpoison(p + 10, 2);
  __msan_unpoison_string(q);
  __msan_check_mem_is_initialized(p, 32);
  __msan_check_mem_is_initialized(p, 32);
  return 0;
}
EOF

	c++ -fsanitize=memory -pg -m32 -o test test.cc
	atf_check -s ignore -o ignore -e not-match:"WARNING: MemorySanitizer: use-of-uninitialized-value" ./test
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
	atf_add_test_case unpoison
	atf_add_test_case unpoison_profile
	atf_add_test_case unpoison_pie
	atf_add_test_case unpoison_pic
	# atf_add_test_case unpoison32
}
