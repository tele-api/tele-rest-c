/*
 * set_sticker_set_title_request.h
 *
 * Request parameters for setStickerSetTitle
 */

#ifndef _set_sticker_set_title_request_H_
#define _set_sticker_set_title_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_set_title_request_t set_sticker_set_title_request_t;




typedef struct set_sticker_set_title_request_t {
    char *name; // string
    char *title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_set_title_request_t;

__attribute__((deprecated)) set_sticker_set_title_request_t *set_sticker_set_title_request_create(
    char *name,
    char *title
);

void set_sticker_set_title_request_free(set_sticker_set_title_request_t *set_sticker_set_title_request);

set_sticker_set_title_request_t *set_sticker_set_title_request_parseFromJSON(cJSON *set_sticker_set_title_requestJSON);

cJSON *set_sticker_set_title_request_convertToJSON(set_sticker_set_title_request_t *set_sticker_set_title_request);

#endif /* _set_sticker_set_title_request_H_ */

