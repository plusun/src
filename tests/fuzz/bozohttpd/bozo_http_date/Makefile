#       $NetBSD: Makefile,v 1.15 2007/05/28 12:06:25 tls Exp $
#       @(#)Makefile    8.2 (Berkeley) 4/2/94

.include <bsd.own.mk>

PROG=   fuzz_bozo_http_date
SRCS=   fuzz_bozo_http_date.c
.PATH:  ${NETBSDSRCDIR}/libexec/httpd
SRCS+=	bozohttpd.c ssl-bozo.c daemon-bozo.c dir-index-bozo.c content-bozo.c tilde-luzah-bozo.c cgi-bozo.c lua-bozo.c

CFLAGS= -fsanitize=fuzzer-no-link,address,undefined -Wall -Werror
LDFLAGS= -fsanitize=fuzzer,address,undefined -Wall -Werror -lssl -llua

fuzz: fuzz_bozo_http_date
	export UBSAN_OPTIONS=halt_on_error=1 && ./fuzz_bozo_http_date -only_ascii ./input > /dev/null

.include <bsd.prog.mk>
