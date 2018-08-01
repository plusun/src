#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_strspct
SRCS=   fuzz_strspct.c
.PATH:  ${NETBSDSRCDIR}/lib/libutil
SRCS+=	strpct.c

CPPFLAGS+=-Wall -Werror

fuzz: fuzz_strspct
	export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_strspct -only_ascii ./input > /dev/null

.include <bsd.prog.mk>
