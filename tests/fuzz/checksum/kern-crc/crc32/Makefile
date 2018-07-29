#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_crc32
SRCS=   fuzz_crc32.c

.PATH:	${NETBSDSRCDIR}/sys/lib/libkern
SRCS+=	crc32.c

CPPFLAGS+=-I${NETBSDSRCDIR}/sys/

fuzz: fuzz_crc32
	./fuzz_crc32 ./input > /dev/null

.include <bsd.prog.mk>
