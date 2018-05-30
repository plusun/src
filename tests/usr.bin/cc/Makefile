# $NetBSD: Makefile,v 1.4 2018/05/02 18:46:05 kamil Exp $

.include <bsd.own.mk>

TESTSDIR=	${TESTSBASE}/usr.bin/cc

TESTS_SH=	#
TESTS_SH+=	t_asan_double_free
TESTS_SH+=	t_asan_global_buffer_overflow
TESTS_SH+=	t_asan_heap_overflow
TESTS_SH+=	t_asan_off_by_one
TESTS_SH+=	t_asan_poison
TESTS_SH+=	t_asan_uaf
TESTS_SH+=	t_fuzzer_oom
TESTS_SH+=	t_fuzzer_simple
TESTS_SH+=	t_fuzzer_timeout
TESTS_SH+=	t_hello
TESTS_SH+=	t_msan_allocated_memory
TESTS_SH+=	t_msan_check_mem
TESTS_SH+=	t_msan_free
TESTS_SH+=	t_msan_heap
TESTS_SH+=	t_msan_partial_poison
TESTS_SH+=	t_msan_poison
TESTS_SH+=	t_msan_realloc
TESTS_SH+=	t_msan_shadow
TESTS_SH+=	t_msan_stack
TESTS_SH+=	t_msan_unpoison
TESTS_SH+=	t_tsan_data_race
TESTS_SH+=	t_tsan_heap_use_after_free
TESTS_SH+=	t_tsan_lock_order_inversion
TESTS_SH+=	t_tsan_locked_mutex_destroy
TESTS_SH+=	t_tsan_signal_errno
TESTS_SH+=	t_tsan_thread_leak
TESTS_SH+=	t_ubsan_int_add_overflow
TESTS_SH+=	t_ubsan_int_sub_overflow
TESTS_SH+=	t_ubsan_int_neg_overflow
TESTS_SH+=	t_ubsan_int_divzero
TESTS_SH+=	t_ubsan_vla_out_of_bounds

.include <bsd.test.mk>
