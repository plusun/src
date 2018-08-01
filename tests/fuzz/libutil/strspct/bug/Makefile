#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH: 	..
SRCS=   fuzz_strspct.c
.PATH:  ${NETBSDSRCDIR}/lib/libutil
SRCS+=	strpct.c
.PATH: 	../../../
SRCS+=	main.c

CPPFLAGS+=-Wall -Werror

.include <bsd.prog.mk>
