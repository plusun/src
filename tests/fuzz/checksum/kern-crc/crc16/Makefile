#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_crc16
SRCS=   fuzz_crc16.c

CPPFLAGS+=-I${NETBSDSRCDIR}/sys/lib/libkern

fuzz: fuzz_crc16
	./fuzz_crc16 ./input > /dev/null

.include <bsd.prog.mk>
