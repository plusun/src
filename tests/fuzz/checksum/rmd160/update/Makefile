#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_rmd160
SRCS=   fuzz_rmd160.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/hash/rmd160
SRCS+=	rmd160hl.c
.PATH:  ${NETBSDSRCDIR}/common/lib/libc/hash/rmd160
SRCS+=	rmd160.c

CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include

fuzz: fuzz_rmd160
	./fuzz_rmd160 ./input > /dev/null

.include <bsd.prog.mk>
