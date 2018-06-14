#	$NetBSD$

.if !defined(_BSD_FUZZER_PROG_MK)
_BSD_FUZZER_PROG_MK=1

.include <bsd.fuzzer.mk>
LDFLAGS+=	-DENABLE_FUZZER -fsanitize=fuzzer,$(FUZZER_SANITIZERS) -g -O0

.endif

