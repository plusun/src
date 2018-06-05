#	$NetBSD$

.if !defined(_BSD_MSAN_MK)
_BSD_MSAN_MK=1

CFLAGS+=	-fsanitize=memory -g -O0
CXXFLAGS+=	-fsanitize=memory -g -O0
LDFLAGS+=	-fsanitize=memory -g -O0

.endif

