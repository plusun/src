#	$NetBSD$

.if !defined(_BSD_FUZZER_MK)
_BSD_FUZZER_MK=1

FUZZER_SANITIZERS=	undefined,address

CFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer-no-link,$(FUZZER_SANITIZERS) -g -O0
CXXFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer-no-link,$(FUZZER_SANITIZERS) -g -O0

.endif

