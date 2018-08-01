#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_regexec
SRCS=   fuzz_regexec.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/regex
SRCS+=	regcomp.c regerror.c regexec.c regfree.c regsub.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror
CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include -Dregnsub=__mkfuzzer_regnsub -Dregasub=__mkfuzzer_regasub -g
NOMAN=	# defined

fuzz: fuzz_regexec
	./fuzz_regexec -only_ascii=1  -dict=./dict ./input > /dev/null

.include <bsd.prog.mk>
