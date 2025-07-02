/*
 * get_chat_administrators_response.h
 *
 * 
 */

#ifndef _get_chat_administrators_response_H_
#define _get_chat_administrators_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_chat_administrators_response_t get_chat_administrators_response_t;

#include "chat_member.h"



typedef struct get_chat_administrators_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_chat_administrators_response_t;

__attribute__((deprecated)) get_chat_administrators_response_t *get_chat_administrators_response_create(
    int ok,
    list_t *result
);

void get_chat_administrators_response_free(get_chat_administrators_response_t *get_chat_administrators_response);

get_chat_administrators_response_t *get_chat_administrators_response_parseFromJSON(cJSON *get_chat_administrators_responseJSON);

cJSON *get_chat_administrators_response_convertToJSON(get_chat_administrators_response_t *get_chat_administrators_response);

#endif /* _get_chat_administrators_response_H_ */

