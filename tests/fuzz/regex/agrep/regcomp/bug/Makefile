#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH: ../
SRCS=	fuzz_regcomp.c
.PATH:	../../../../
SRCS+=   main.c
.PATH:  ${NETBSDSRCDIR}/external/bsd/tre/dist/lib
SRCS+=	regcomp.c regerror.c regexec.c
SRCS+=	tre-compile.c tre-stack.c tre-mem.c tre-ast.c tre-match-backtrack.c tre-match-approx.c tre-match-parallel.c tre-parse.c
# .PATH:  ${NETBSDSRCDIR}/external/gpl2/grep/dist/intl

CPPFLAGS+=-g -I${NETBSDSRCDIR}/external/bsd/tre/dist/lib/ -I${NETBSDSRCDIR}/external/bsd/tre/include -DHAVE_CONFIG_H=1 -DTRE_SYSTEM_REGEX_H_PATH=\"${NETBSDSRCDIR}/include/regex.h\" -DTRE_USE_SYSTEM_REGEX_H=1 -DTRE_REGEX_T_FIELD=re_g

.include <bsd.prog.mk>
