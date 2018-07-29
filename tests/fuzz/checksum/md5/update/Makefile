#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_md5
SRCS=   fuzz_md5.c
.PATH:  ${NETBSDSRCDIR}/lib/libc/md/
SRCS+=	md5hl.c
.PATH:  ${NETBSDSRCDIR}/common/lib/libc/md/
SRCS+=	md5c.c

CPPFLAGS+=-I${NETBSDSRCDIR}/lib/libc/include

fuzz: fuzz_md5
	./fuzz_md5 ./input > /dev/null

.include <bsd.prog.mk>
