/*
 * post_set_sticker_set_title_request.h
 *
 * 
 */

#ifndef _post_set_sticker_set_title_request_H_
#define _post_set_sticker_set_title_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_sticker_set_title_request_t post_set_sticker_set_title_request_t;




typedef struct post_set_sticker_set_title_request_t {
    char *name; // string
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_sticker_set_title_request_t;

__attribute__((deprecated)) post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_create(
    char *name,
    char *title
);

void post_set_sticker_set_title_request_free(post_set_sticker_set_title_request_t *post_set_sticker_set_title_request);

post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_parseFromJSON(cJSON *post_set_sticker_set_title_requestJSON);

cJSON *post_set_sticker_set_title_request_convertToJSON(post_set_sticker_set_title_request_t *post_set_sticker_set_title_request);

#endif /* _post_set_sticker_set_title_request_H_ */

