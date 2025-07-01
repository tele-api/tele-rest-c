/*
 * web_app_info.h
 *
 * Describes a [Web App](https://core.telegram.org/bots/webapps).
 */

#ifndef _web_app_info_H_
#define _web_app_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_app_info_t web_app_info_t;




typedef struct web_app_info_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} web_app_info_t;

__attribute__((deprecated)) web_app_info_t *web_app_info_create(
    char *url
);

void web_app_info_free(web_app_info_t *web_app_info);

web_app_info_t *web_app_info_parseFromJSON(cJSON *web_app_infoJSON);

cJSON *web_app_info_convertToJSON(web_app_info_t *web_app_info);

#endif /* _web_app_info_H_ */

