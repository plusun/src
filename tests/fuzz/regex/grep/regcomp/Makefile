#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_regcomp
SRCS=   fuzz_regcomp.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/grep/dist/lib
# SRCS+=	regex.c 
SRCS+=  hard-locale.c isdir.c \
	regex.c stpcpy.c \
	xstrtoumax.c
# .PATH:  ${NETBSDSRCDIR}/external/gpl2/grep/dist/intl

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror
CPPFLAGS+=-g -I${NETBSDSRCDIR}/external/gpl2/grep/dist/lib/ -DLOCALEDIR=\"/usr/share/locale\" -DHAVE_CONFIG_H -I${NETBSDSRCDIR}/external/gpl2/grep/include -I${NETBSDSRCDIR}/external/gpl2/grep/dist/src/ -Dgettext=__MKFUZZER_gettext -Dregfree=__MKFUZZER_regfree -Dregcomp=__MKFUZZER_regcomp -Dregexec=__MKFUZZER_regexec -Dregerror=__MKFUZZER_regerror

fuzz: fuzz_regcomp
	export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_regcomp -only_ascii=1  -dict=./dict ./input > /dev/null

.include <bsd.prog.mk>
