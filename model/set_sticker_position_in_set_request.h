/*
 * set_sticker_position_in_set_request.h
 *
 * Request parameters for setStickerPositionInSet
 */

#ifndef _set_sticker_position_in_set_request_H_
#define _set_sticker_position_in_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_position_in_set_request_t set_sticker_position_in_set_request_t;




typedef struct set_sticker_position_in_set_request_t {
    char *sticker; // string
    int position; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_position_in_set_request_t;

__attribute__((deprecated)) set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_create(
    char *sticker,
    int position
);

void set_sticker_position_in_set_request_free(set_sticker_position_in_set_request_t *set_sticker_position_in_set_request);

set_sticker_position_in_set_request_t *set_sticker_position_in_set_request_parseFromJSON(cJSON *set_sticker_position_in_set_requestJSON);

cJSON *set_sticker_position_in_set_request_convertToJSON(set_sticker_position_in_set_request_t *set_sticker_position_in_set_request);

#endif /* _set_sticker_position_in_set_request_H_ */

