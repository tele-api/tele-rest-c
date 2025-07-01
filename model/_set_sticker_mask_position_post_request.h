/*
 * _set_sticker_mask_position_post_request.h
 *
 * 
 */

#ifndef __set_sticker_mask_position_post_request_H_
#define __set_sticker_mask_position_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_sticker_mask_position_post_request_t _set_sticker_mask_position_post_request_t;

#include "mask_position.h"



typedef struct _set_sticker_mask_position_post_request_t {
    char *sticker; // string
    struct mask_position_t *mask_position; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _set_sticker_mask_position_post_request_t;

__attribute__((deprecated)) _set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_create(
    char *sticker,
    mask_position_t *mask_position
);

void _set_sticker_mask_position_post_request_free(_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request);

_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_parseFromJSON(cJSON *_set_sticker_mask_position_post_requestJSON);

cJSON *_set_sticker_mask_position_post_request_convertToJSON(_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request);

#endif /* __set_sticker_mask_position_post_request_H_ */

