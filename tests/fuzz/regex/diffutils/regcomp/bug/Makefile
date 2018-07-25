#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH: 	..
SRCS=   fuzz_regcomp.c
.PATH:	../../../../
SRCS+=	main.c
.PATH:  ${NETBSDSRCDIR}/external/gpl2/diffutils/dist/lib
SRCS+=	regex.c 
IDIST=  ${NETBSDSRCDIR}/external/gpl2/diffutils/dist
CPPFLAGS+=-g -DLOCALEDIR=\"/usr/share/locale\" -DHAVE_CONFIG_H \
          -I${IDIST}/../include -I${IDIST}/lib -Dregfree=__MKFUZZER_regfree \
	  -Dregexec=__MKFUZZER_regexec -Dregcomp=__MKFUZZER_regcomp -Dregerror=__MKFUZZER_regerror

.include <bsd.prog.mk>
