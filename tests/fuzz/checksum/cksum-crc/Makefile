#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_crc
SRCS=   fuzz_crc.c

.PATH:	${NETBSDSRCDIR}/usr.bin/cksum
SRCS+=	crc.c

CPPFLAGS+=-I${NETBSDSRCDIR}/usr.bin/cksum/

fuzz: fuzz_crc
	./fuzz_crc ./input > /dev/null

.include <bsd.prog.mk>
