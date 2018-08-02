#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_logout
SRCS=   fuzz_logout.c
.PATH:  ${NETBSDSRCDIR}/lib/libutil
SRCS+=	logout.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror

fuzz: fuzz_logout
	export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_logout -only_ascii ./input > /dev/null

.include <bsd.prog.mk>
