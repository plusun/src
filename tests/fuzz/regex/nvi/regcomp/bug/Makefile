#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH: 	..
SRCS=   fuzz_regcomp.c
.PATH:	../../../../
SRCS+=	main.c
.PATH:  ${NETBSDSRCDIR}/external/bsd/nvi/dist/regex
SRCS+=	regcomp.c regerror.c regexec.c regfree.c

CFLAGS= -fsanitize=address,undefined -Wall -Werror
LDFLAGS= -fsanitize=address,undefined -Wall -Werror
CPPFLAGS+= -I${NETBSDSRCDIR}/external/bsd/nvi/usr.bin/nvi -I${NETBSDSRCDIR}/external/bsd/nvi/dist/regex -D__REGEX_PRIVATE -DUSE_WIDECHAR -D__REGEX_PRIVATE -DUSE_WIDECHAR -Dregcomp=__mkfuzzer_regcomp -Dregerror=__mkfuzzer_regerror -Dregexec=__mkfuzzer_regexec -Dregfree=__mkfuzzer_regfree -g
CFLAGS+= -g
LDFLAGS+= -g

.include <bsd.prog.mk>
