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

int fuzzer_init(void);

void fuzzer_init_fuffer(fuffer_t *f, const uint8_t *buf, size_t len);
void fuzzer_install_fuffers(fuffer_t *fuffers, size_t n);
int socket(int domain, int type, int protocol);
int setsockopt(int s, int level, int optname,
			const void *optval, socklen_t optlen);
int shutdown(int s, int how);
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
ssize_t recvfrom(int s, void *buf, size_t len, int flags,
			struct sockaddr *from, socklen_t *fromlen);
ssize_t sendto(int s, const void *msg, size_t len, int flags,
		      const struct sockaddr *to, socklen_t tolen);
int close(int s);

#endif
