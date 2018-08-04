#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   main
.PATH:	../
SRCS=   fuzz_bozohttpd.c mock-ssl-bozo.c
.PATH: ../../../
SRCS+=	main.c
.PATH:  ${NETBSDSRCDIR}/libexec/httpd
SRCS+=	bozohttpd.c daemon-bozo.c dir-index-bozo.c content-bozo.c tilde-luzah-bozo.c cgi-bozo.c lua-bozo.c

CFLAGS= -fsanitize=address,undefined -Wall -Werror -I${NETBSDSRCDIR}/libexec/httpd -g #-Dbozowarn=mock_bozowarn
LDFLAGS= -fsanitize=address,undefined -Wall -Werror -lssl -llua -g

.include <bsd.prog.mk>
