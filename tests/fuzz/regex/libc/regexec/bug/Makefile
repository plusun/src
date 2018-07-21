#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH: 	..
SRCS=   fuzz_regexec.c
.PATH:	../../../../
SRCS+=	main.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/regex
SRCS+=	regcomp.c regerror.c regexec.c regfree.c regsub.c

CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include -D_REPRODUCE_

.include <bsd.prog.mk>
