#ifndef _FUZZER_OPS_H_
#define _FUZZER_OPS_H_

#include <sys/socket.h>
#include <stddef.h>
#include <stdint.h>
#include <poll.h>

typedef struct s_fuzzer_buffer_t {
	size_t len, off;
	const uint8_t *buf;
	char open, read, write;
} fuffer_t;

/* The init function should be provided by the users,
   because the fed buffer is unknown to this file. */
extern int fuzzer_init(void);

void fuzzer_init_fuffer(fuffer_t *f, const uint8_t *buf, size_t len);
void fuzzer_install_fuffers(fuffer_t *fuffers, size_t n);
int fuzzer_socket(int domain, int type, int protocol);
int fuzzer_setsockopt(int s, int level, int optname,
			const void *optval, socklen_t optlen);
int fuzzer_shutdown(int s, int how);
int fuzzer_poll(struct pollfd *fds, nfds_t nfds, int timeout);
ssize_t fuzzer_recvfrom(int s, void *buf, size_t len, int flags,
			struct sockaddr *from, socklen_t *fromlen);
ssize_t fuzzer_sendto(int s, const void *msg, size_t len, int flags,
		      const struct sockaddr *to, socklen_t tolen);
int fuzzer_close(int s);

#endif
