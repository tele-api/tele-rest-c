/*
 * add_sticker_to_set_request.h
 *
 * Request parameters for addStickerToSet
 */

#ifndef _add_sticker_to_set_request_H_
#define _add_sticker_to_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct add_sticker_to_set_request_t add_sticker_to_set_request_t;

#include "input_sticker.h"



typedef struct add_sticker_to_set_request_t {
    int user_id; //numeric
    char *name; // string
    struct input_sticker_t *sticker; //model

    int _library_owned; // Is the library responsible for freeing this object?
} add_sticker_to_set_request_t;

__attribute__((deprecated)) add_sticker_to_set_request_t *add_sticker_to_set_request_create(
    int user_id,
    char *name,
    input_sticker_t *sticker
);

void add_sticker_to_set_request_free(add_sticker_to_set_request_t *add_sticker_to_set_request);

add_sticker_to_set_request_t *add_sticker_to_set_request_parseFromJSON(cJSON *add_sticker_to_set_requestJSON);

cJSON *add_sticker_to_set_request_convertToJSON(add_sticker_to_set_request_t *add_sticker_to_set_request);

#endif /* _add_sticker_to_set_request_H_ */

