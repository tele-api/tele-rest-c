/*
 * replace_sticker_in_set_response.h
 *
 * 
 */

#ifndef _replace_sticker_in_set_response_H_
#define _replace_sticker_in_set_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct replace_sticker_in_set_response_t replace_sticker_in_set_response_t;




typedef struct replace_sticker_in_set_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} replace_sticker_in_set_response_t;

__attribute__((deprecated)) replace_sticker_in_set_response_t *replace_sticker_in_set_response_create(
    int ok,
    int result
);

void replace_sticker_in_set_response_free(replace_sticker_in_set_response_t *replace_sticker_in_set_response);

replace_sticker_in_set_response_t *replace_sticker_in_set_response_parseFromJSON(cJSON *replace_sticker_in_set_responseJSON);

cJSON *replace_sticker_in_set_response_convertToJSON(replace_sticker_in_set_response_t *replace_sticker_in_set_response);

#endif /* _replace_sticker_in_set_response_H_ */

