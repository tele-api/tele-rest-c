/*
 * set_sticker_mask_position_request.h
 *
 * Request parameters for setStickerMaskPosition
 */

#ifndef _set_sticker_mask_position_request_H_
#define _set_sticker_mask_position_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_sticker_mask_position_request_t set_sticker_mask_position_request_t;

#include "mask_position.h"



typedef struct set_sticker_mask_position_request_t {
    char *sticker; // string
    struct mask_position_t *mask_position; //model

    int _library_owned; // Is the library responsible for freeing this object?
} set_sticker_mask_position_request_t;

__attribute__((deprecated)) set_sticker_mask_position_request_t *set_sticker_mask_position_request_create(
    char *sticker,
    mask_position_t *mask_position
);

void set_sticker_mask_position_request_free(set_sticker_mask_position_request_t *set_sticker_mask_position_request);

set_sticker_mask_position_request_t *set_sticker_mask_position_request_parseFromJSON(cJSON *set_sticker_mask_position_requestJSON);

cJSON *set_sticker_mask_position_request_convertToJSON(set_sticker_mask_position_request_t *set_sticker_mask_position_request);

#endif /* _set_sticker_mask_position_request_H_ */

