#include "bozohttpd.h"
#include <string.h>

struct {
    const uint8_t *data;
    size_t size;
} buffer;

void init_bozo_read_buffer(const uint8_t *data, size_t size) {
    buffer.data = data;
    buffer.size = size;
}

void bozo_ssl_init(bozohttpd_t *httpd) {}
int bozo_ssl_accept(bozohttpd_t *httpd) { return 0; }
void bozo_ssl_destroy(bozohttpd_t *httpd) {}
int bozo_printf(bozohttpd_t *httpd, const char *fmt, ...) { return 0; }
int bozo_flush(bozohttpd_t *httpd, FILE *fp) { return 0; }
ssize_t bozo_write(bozohttpd_t *httpd, int fd, const void *buf, size_t len) { return len; }
ssize_t bozo_read(bozohttpd_t *httpd, int fd, void *buf, size_t len) {
    if (len > buffer.size) {
        len = buffer.size;
    }
    if (len == 0) {
        return len;
    }

    memcpy(buf, buffer.data, len);
    buffer.data += len;
    buffer.size -= len;
    return len;
}

void mock_bozowarn(bozohttpd_t *httpd, const char *fmt, ...) {}
