/*
 * set_chat_photo_response.h
 *
 * 
 */

#ifndef _set_chat_photo_response_H_
#define _set_chat_photo_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_photo_response_t set_chat_photo_response_t;




typedef struct set_chat_photo_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_photo_response_t;

__attribute__((deprecated)) set_chat_photo_response_t *set_chat_photo_response_create(
    int ok,
    int result
);

void set_chat_photo_response_free(set_chat_photo_response_t *set_chat_photo_response);

set_chat_photo_response_t *set_chat_photo_response_parseFromJSON(cJSON *set_chat_photo_responseJSON);

cJSON *set_chat_photo_response_convertToJSON(set_chat_photo_response_t *set_chat_photo_response);

#endif /* _set_chat_photo_response_H_ */

