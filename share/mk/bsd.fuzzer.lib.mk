#	$NetBSD$

.if !defined(_BSD_FUZZER_LIB_MK)
_BSD_FUZZER_LIB_MK=1

.include <bsd.fuzzer.mk>
LDFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer-no-link,$(FUZZER_SANITIZERS) -g -O0

.endif

