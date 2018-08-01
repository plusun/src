#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_md2
SRCS=   fuzz_md2.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/hash/md2/
SRCS+=	md2.c md2hl.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror

CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include

fuzz: fuzz_md2
	./fuzz_md2 ./input > /dev/null

.include <bsd.prog.mk>
