#ifndef _FUZZER_OPS_H_
#define _FUZZER_OPS_H_

#include <stddef.h>
#include <stdint.h>
#include <poll.h>

typedef struct s_fuzzer_buffer_t {
	size_t len, off;
	uint8_t *buf;
	char open, read, write;
} fuffer_t;

/* The init function should be provided by the users,
   because the fed buffer is unknown to this file. */
extern int fuzzer_init(void);

void fuzzer_init_fuffer(fuffer_t *f, uint8_t *buf, size_t len);
void fuzzer_install_fuffers(fuffer_t *fuffers, size_t n);
int fuzzer_socket(int domain, int type, int protocol);
int fuzzer_setsocketopt(int s, int level, int optname,
			const void *optval, socketlen_t optlen);
int fuzzer_shutdown(int s, int how);
int fuzzer_poll(struct pollfd *fds, nfds_t nfds, int timeout);

#endif
