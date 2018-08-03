#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "bozohttpd.h"

extern void init_bozo_read_buffer(const uint8_t *data, size_t size);

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    init_bozo_read_buffer(data, size);
    bozohttpd_t httpd;
    bozoprefs_t prefs;
    memset(&httpd, 0x0, sizeof(httpd));
    memset(&prefs, 0x0, sizeof(prefs));
    bozo_set_defaults(&httpd, &prefs);
    bozo_setup(&httpd, &prefs, "localhost", "./slashdir");
    do {
        bozo_httpreq_t *request;
        if ((request = bozo_read_request(&httpd)) != NULL) {
            bozo_process_request(request);
            bozo_clean_request(request);
        }
    } while (httpd.background);

    return 0;
}
