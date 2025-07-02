/*
 * get_sticker_set_request.h
 *
 * Request parameters for getStickerSet
 */

#ifndef _get_sticker_set_request_H_
#define _get_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_sticker_set_request_t get_sticker_set_request_t;




typedef struct get_sticker_set_request_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_sticker_set_request_t;

__attribute__((deprecated)) get_sticker_set_request_t *get_sticker_set_request_create(
    char *name
);

void get_sticker_set_request_free(get_sticker_set_request_t *get_sticker_set_request);

get_sticker_set_request_t *get_sticker_set_request_parseFromJSON(cJSON *get_sticker_set_requestJSON);

cJSON *get_sticker_set_request_convertToJSON(get_sticker_set_request_t *get_sticker_set_request);

#endif /* _get_sticker_set_request_H_ */

