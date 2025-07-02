/*
 * create_new_sticker_set_response.h
 *
 * 
 */

#ifndef _create_new_sticker_set_response_H_
#define _create_new_sticker_set_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_new_sticker_set_response_t create_new_sticker_set_response_t;




typedef struct create_new_sticker_set_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_new_sticker_set_response_t;

__attribute__((deprecated)) create_new_sticker_set_response_t *create_new_sticker_set_response_create(
    int ok,
    int result
);

void create_new_sticker_set_response_free(create_new_sticker_set_response_t *create_new_sticker_set_response);

create_new_sticker_set_response_t *create_new_sticker_set_response_parseFromJSON(cJSON *create_new_sticker_set_responseJSON);

cJSON *create_new_sticker_set_response_convertToJSON(create_new_sticker_set_response_t *create_new_sticker_set_response);

#endif /* _create_new_sticker_set_response_H_ */

