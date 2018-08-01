#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_sha1
SRCS=   fuzz_sha1.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/hash/sha1
SRCS+=	sha1hl.c
.PATH:  ${NETBSDSRCDIR}/common/lib/libc/hash/sha1
SRCS+=	sha1.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror
CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include

fuzz: fuzz_sha1
	./fuzz_sha1 ./input > /dev/null

.include <bsd.prog.mk>
