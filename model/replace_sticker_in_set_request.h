/*
 * replace_sticker_in_set_request.h
 *
 * Request parameters for replaceStickerInSet
 */

#ifndef _replace_sticker_in_set_request_H_
#define _replace_sticker_in_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct replace_sticker_in_set_request_t replace_sticker_in_set_request_t;

#include "input_sticker.h"



typedef struct replace_sticker_in_set_request_t {
    int user_id; //numeric
    char *name; // string
    char *old_sticker; // string
    struct input_sticker_t *sticker; //model

    int _library_owned; // Is the library responsible for freeing this object?
} replace_sticker_in_set_request_t;

__attribute__((deprecated)) replace_sticker_in_set_request_t *replace_sticker_in_set_request_create(
    int user_id,
    char *name,
    char *old_sticker,
    input_sticker_t *sticker
);

void replace_sticker_in_set_request_free(replace_sticker_in_set_request_t *replace_sticker_in_set_request);

replace_sticker_in_set_request_t *replace_sticker_in_set_request_parseFromJSON(cJSON *replace_sticker_in_set_requestJSON);

cJSON *replace_sticker_in_set_request_convertToJSON(replace_sticker_in_set_request_t *replace_sticker_in_set_request);

#endif /* _replace_sticker_in_set_request_H_ */

