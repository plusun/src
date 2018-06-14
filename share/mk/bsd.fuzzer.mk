#	$NetBSD$

.if !defined(_BSD_FUZZER_MK)
_BSD_FUZZER_MK=1

CFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer-no-link -g -O0
CXXFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer-no-link -g -O0
LDFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer -g -O0

.endif

