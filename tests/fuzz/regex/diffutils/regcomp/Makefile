#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_regcomp
SRCS=   fuzz_regcomp.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/diffutils/dist/lib
SRCS+=	regex.c 
IDIST=  ${NETBSDSRCDIR}/external/gpl2/diffutils/dist
CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror
CPPFLAGS+=-g -DLOCALEDIR=\"/usr/share/locale\" -DHAVE_CONFIG_H \
          -I${IDIST}/../include -I${IDIST}/lib -Dregfree=__MKFUZZER_regfree \
	  -Dregexec=__MKFUZZER_regexec -Dregcomp=__MKFUZZER_regcomp -Dregerror=__MKFUZZER_regerror

fuzz: fuzz_regcomp
	export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_regcomp -only_ascii=1  -dict=./dict ./input > /dev/null

.include <bsd.prog.mk>
