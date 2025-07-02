/*
 * add_sticker_to_set_response.h
 *
 * 
 */

#ifndef _add_sticker_to_set_response_H_
#define _add_sticker_to_set_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct add_sticker_to_set_response_t add_sticker_to_set_response_t;




typedef struct add_sticker_to_set_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} add_sticker_to_set_response_t;

__attribute__((deprecated)) add_sticker_to_set_response_t *add_sticker_to_set_response_create(
    int ok,
    int result
);

void add_sticker_to_set_response_free(add_sticker_to_set_response_t *add_sticker_to_set_response);

add_sticker_to_set_response_t *add_sticker_to_set_response_parseFromJSON(cJSON *add_sticker_to_set_responseJSON);

cJSON *add_sticker_to_set_response_convertToJSON(add_sticker_to_set_response_t *add_sticker_to_set_response);

#endif /* _add_sticker_to_set_response_H_ */

