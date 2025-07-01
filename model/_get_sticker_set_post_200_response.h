/*
 * _get_sticker_set_post_200_response.h
 *
 * 
 */

#ifndef __get_sticker_set_post_200_response_H_
#define __get_sticker_set_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_sticker_set_post_200_response_t _get_sticker_set_post_200_response_t;

#include "sticker_set.h"



typedef struct _get_sticker_set_post_200_response_t {
    int ok; //boolean
    struct sticker_set_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _get_sticker_set_post_200_response_t;

__attribute__((deprecated)) _get_sticker_set_post_200_response_t *_get_sticker_set_post_200_response_create(
    int ok,
    sticker_set_t *result
);

void _get_sticker_set_post_200_response_free(_get_sticker_set_post_200_response_t *_get_sticker_set_post_200_response);

_get_sticker_set_post_200_response_t *_get_sticker_set_post_200_response_parseFromJSON(cJSON *_get_sticker_set_post_200_responseJSON);

cJSON *_get_sticker_set_post_200_response_convertToJSON(_get_sticker_set_post_200_response_t *_get_sticker_set_post_200_response);

#endif /* __get_sticker_set_post_200_response_H_ */

