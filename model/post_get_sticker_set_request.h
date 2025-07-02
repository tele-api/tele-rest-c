/*
 * post_get_sticker_set_request.h
 *
 * 
 */

#ifndef _post_get_sticker_set_request_H_
#define _post_get_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_sticker_set_request_t post_get_sticker_set_request_t;




typedef struct post_get_sticker_set_request_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_sticker_set_request_t;

__attribute__((deprecated)) post_get_sticker_set_request_t *post_get_sticker_set_request_create(
    char *name
);

void post_get_sticker_set_request_free(post_get_sticker_set_request_t *post_get_sticker_set_request);

post_get_sticker_set_request_t *post_get_sticker_set_request_parseFromJSON(cJSON *post_get_sticker_set_requestJSON);

cJSON *post_get_sticker_set_request_convertToJSON(post_get_sticker_set_request_t *post_get_sticker_set_request);

#endif /* _post_get_sticker_set_request_H_ */

