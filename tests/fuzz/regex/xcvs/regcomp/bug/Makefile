#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH:	${.CURDIR}/../../../../
SRCS=	main.c
.PATH:	${.CURDIR}/../
SRCS+=   fuzz_regcomp.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/xcvs/dist/lib
SRCS+=  regex.c

USE_FORT?= yes  # network client/server

WARNS?= 0

CWARNFLAGS.clang+=      -Wno-tautological-compare -Wno-parentheses \
                        -Wno-format-security -Wno-format \
                        -Wno-tautological-constant-out-of-range-compare


CPPFLAGS+=-g -I${NETBSDSRCDIR}/external/gpl2/xcvs/dist/lib/ -DSETXID_SUPPORT -DHAVE_CONFIG_H -I${NETBSDSRCDIR}/external/gpl2/xcvs/include

.include <bsd.prog.mk>
