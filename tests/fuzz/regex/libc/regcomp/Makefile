#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_regcomp
SRCS=   fuzz_regcomp.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/regex
SRCS+=	regcomp.c regerror.c regexec.c regfree.c regsub.c

CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include -Dregnsub=__mkfuzzer_regnsub -Dregasub=__mkfuzzer_regasub

fuzz: fuzz_regcomp
	./fuzz_regcomp -only_ascii=1  -dict=./dict ./input > /dev/null

.include <bsd.prog.mk>
