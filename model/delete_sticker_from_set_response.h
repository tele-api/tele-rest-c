/*
 * delete_sticker_from_set_response.h
 *
 * 
 */

#ifndef _delete_sticker_from_set_response_H_
#define _delete_sticker_from_set_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_sticker_from_set_response_t delete_sticker_from_set_response_t;




typedef struct delete_sticker_from_set_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_sticker_from_set_response_t;

__attribute__((deprecated)) delete_sticker_from_set_response_t *delete_sticker_from_set_response_create(
    int ok,
    int result
);

void delete_sticker_from_set_response_free(delete_sticker_from_set_response_t *delete_sticker_from_set_response);

delete_sticker_from_set_response_t *delete_sticker_from_set_response_parseFromJSON(cJSON *delete_sticker_from_set_responseJSON);

cJSON *delete_sticker_from_set_response_convertToJSON(delete_sticker_from_set_response_t *delete_sticker_from_set_response);

#endif /* _delete_sticker_from_set_response_H_ */

