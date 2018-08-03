#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_bozohttpd
SRCS=   fuzz_bozohttpd.c mock-ssl-bozo.c
.PATH:  ${NETBSDSRCDIR}/libexec/httpd
SRCS+=	bozohttpd.c daemon-bozo.c dir-index-bozo.c content-bozo.c tilde-luzah-bozo.c cgi-bozo.c lua-bozo.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror -I${NETBSDSRCDIR}/libexec/httpd #-Dbozowarn=mock_bozowarn
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror -lssl -llua

fuzz: fuzz_bozohttpd
	mkdir -p slashdir && export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_bozohttpd -only_ascii=1 ./input > /dev/null

.include <bsd.prog.mk>
