#	$NetBSD$

.if !defined(_BSD_MSAN_MK)
_BSD_UBSAN_MK=1

CFLAGS+=	-fsanitize=undefined -g -O0
CXXFLAGS+=	-fsanitize=undefined -g -O0
LDFLAGS+=	-fsanitize=undefined -g -O0

.endif

