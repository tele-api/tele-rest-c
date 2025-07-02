/*
 * get_sticker_set_response.h
 *
 * 
 */

#ifndef _get_sticker_set_response_H_
#define _get_sticker_set_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_sticker_set_response_t get_sticker_set_response_t;

#include "sticker_set.h"



typedef struct get_sticker_set_response_t {
    int ok; //boolean
    struct sticker_set_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_sticker_set_response_t;

__attribute__((deprecated)) get_sticker_set_response_t *get_sticker_set_response_create(
    int ok,
    sticker_set_t *result
);

void get_sticker_set_response_free(get_sticker_set_response_t *get_sticker_set_response);

get_sticker_set_response_t *get_sticker_set_response_parseFromJSON(cJSON *get_sticker_set_responseJSON);

cJSON *get_sticker_set_response_convertToJSON(get_sticker_set_response_t *get_sticker_set_response);

#endif /* _get_sticker_set_response_H_ */

