#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_regcomp
SRCS=   fuzz_regcomp.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/grep/dist/lib
SRCS+=	regex.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/grep/dist/intl

CPPFLAGS+=-I${NETBSDSRCDIR}/external/gpl2/grep/dist/lib/posix -g -Wall -Werror -DLOCALEDIR=\"/usr/share/locale\" -DHAVE_CONFIG_H -I${NETBSDSRCDIR}/external/gpl2/grep/include

fuzz: fuzz_regcomp
	./fuzz_regcomp -only_ascii=1  -dict=./dict ./input > /dev/null

.include <bsd.prog.mk>
