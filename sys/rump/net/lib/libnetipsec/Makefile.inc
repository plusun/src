#	$NetBSD: Makefile.inc,v 1.1 2017/04/14 02:43:28 ozaki-r Exp $
#

.PATH:	${.CURDIR}/../../../../netipsec

CPPFLAGS+=	-DIPSEC -DINET -DINET6

SRCS+=		ipsec.c ipsec_netbsd.c key_debug.c xform_esp.c \
		ipsec_input.c ipsec_output.c keysock.c xform_ipcomp.c \
		ipsec_mbuf.c key.c xform_ah.c xform_ipip.c
# Add it once TCP_SIGNATURE is enabled
#SRCS+=		xform_tcp.c

# IPsec debugging
.ifdef RUMP_DEBUG
CPPFLAGS+=	-DIPSEC_DEBUG
.endif
