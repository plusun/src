#	$NetBSD$

.if !defined(_BSD_UBSAN_MK)
_BSD_UBSAN_MK=1

CFLAGS+=	-fsanitize=undefined,address -g -O0
CXXFLAGS+=	-fsanitize=undefined,address -g -O0
LDFLAGS+=	-fsanitize=undefined,address -g -O0

.endif

