#ifdef ENABLE_FUZZER

#include <string.h>
#include "fuzzer_ops.h"
#include "prog_ops.h"

struct {
	fuffer_t *fuffers;
	size_t n, used;
} fstate = {
	.fuffers = NULL,
	.n = 0,
	.used = 0,
};

static uint8_t **fuzzer_buffers = NULL;

/* The format of "packet" is "|uint16_t|content|" */
static inline size_t fuzzer_fuffer_size(fuffer_t *f) {
	return f->len > f->off ? f->len - f->off : 0;
}

static inline uint8_t *fuzzer_fuffer_start(fuffer_t *f) {
	return f->buf + f->off;
}

static inline int fuzzer_fuffer_readable(fuffer_t *f) {
	return f->open && f->read && fuzzer_fuffer_size(f) > sizeof(uint16_t);
}

static inline int fuzzer_fuffer_writable(fuffer_t *f) {
	return f->open && f->write;
}

void fuzzer_init_fuffer(fuffer_t *f, uint8_t *buf, size_t len) {
	f->len = len;
	f->off = 0;
	f->buf = buf;
	f->open = 0;
	f->read = 0;
	f->write = 0;
}

void fuzzer_install_fuffers(fuffer_t *fuffers, size_t n) {
	fstate.fuffers = fuffers;
	fstate.n = n;
	fstate.used = 0;
}

int fuzzer_socket(int domain, int type, int protocol) {
	if (fstate.used >= fstate.n)
		return -1;
	int s = fstate.used++;
	fstate.fuffers[s].open = 1;
	fstate.fuffers[s].read = 1;
	fstate.fuffers[s].write = 1;
	return s + 1;
}

static inline int fuzzer_sock_to_index(int s) {
	s--;
	if (s < 0 || s >= fstate.n)
		return -1;
	return s;
}

int fuzzer_setsockopt(int s, int level, int optname,
			const void *optval, socklen_t optlen) {
	if ((s = fuzzer_sock_to_index(s)) < 0)
		return -1;
	return 0;
}
int fuzzer_shutdown(int s, int how) {
	if ((s = fuzzer_sock_to_index(s)) < 0)
		return -1;
	if (how == SHUT_RD || how == SHUT_RDWR)
		fstate.fuffers[s].read = 0;
	if (how == SHUT_WR || how == SHUT_RDWR)
		fstate.fuffers[s].write = 0;
	return 0;
}
int fuzzer_poll(struct pollfd *fds, nfds_t nfds, int timeout) {
	if (!fds)
		return -1;

	nfds_t i;
	for (i = 0; i < nfds; i++) {
		if (fds[i].fd < 0) {
			fds[i].revents = 0;
			continue;
		}
		short e = fds[i].events;
		int index = fuzzer_sock_to_index(fds[i].fd);
		if (index < 0 ||
		    !(fstate.fuffers[index].read || fstate.fuffers[index].write)) {
			fds[i].revents = POLLNVAL;
			return fds[i].fd;
		}
		if ((e & POLLIN) || (e & POLLRDNORM) || (e & POLLRDNORM) || (e & POLLPRI)) {
			if (fuzzer_fuffer_readable(fstate.fuffers + index)) {
				fds[i].revents = e;
				return fds[i].fd;
			}
			if (!fstate.fuffers[index].read) {
				fds[i].revents = POLLHUP;
				return fds[i].fd;
			}
		}
		if ((e & POLLOUT) || (e & POLLWRNORM) || (e & POLLWRBAND)) {
			if (fuzzer_fuffer_writable(fstate.fuffers + index)) {
				fds[i].revents = e;
				return fds[i].fd;
			}
			if (!fstate.fuffers[index].write) {
				fds[i].revents = POLLHUP;
				return fds[i].fd;
			}
		}
	}
	if (timeout == INFTIM)
		do {} while (1);
	return 0;
}

static uint8_t *fuzzer_fuffer_get(fuffer_t *f, size_t len) {
	if (fuzzer_fuffer_size(f) < len)
		return NULL;
	uint8_t *ret = fuzzer_fuffer_start(f);
	f->off += len;
	return ret;
}

static inline void fuzzer_fuffer_put(fuffer_t *f, uint8_t *buf, size_t len) {
	if (f->off >= len)
		f->off -= len;
}

ssize_t fuzzer_recvfrom(int s, void *buf, size_t len, int flags,
			struct sockaddr *from, socklen_t *fromlen) {
	if ((fuzzer_sock_to_index(s)) < 0)
		return -1;
	fuffer_t *f = fstate.fuffers + s;
	uint16_t blen = 0;
	while (blen == 0) {
		uint8_t *pblen = fuzzer_fuffer_get(f, sizeof(uint16_t));
		if (pblen == NULL)
			return 0;
		blen = *(uint16_t *)pblen;
	}

	uint8_t *buffer = fuzzer_fuffer_get(f, blen);
	if (buffer == NULL)
		return 0;

	if ((flags & MSG_WAITALL) && len < blen) {
		fuzzer_fuffer_put(f, NULL, blen + sizeof(uint16_t));
		return -1;
	}
	if (len > blen)
		len = blen;
	memcpy(buf, buffer, len);
	if (flags & MSG_PEEK)
		fuzzer_fuffer_put(f, NULL, blen + sizeof(uint16_t));
	return len;
}

ssize_t fuzzer_sendto(int s, const void *msg, size_t len, int flags,
		      const struct sockaddr *to, socklen_t tolen) {
	if ((s = fuzzer_sock_to_index(s)) < 0)
		return -1;
	fuffer_t *f = fstate.fuffers + s;
	if (!fuzzer_fuffer_writable(f))
		return -1;
	return len;
}

int fuzzer_close(int s) {
	if ((s = fuzzer_sock_to_index(s)) < 0)
		return -1;
	fstate.fuffers[s].open = 0;
	return 0;
}

#endif
