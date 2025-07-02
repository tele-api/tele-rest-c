/*
 * decline_chat_join_request_response.h
 *
 * 
 */

#ifndef _decline_chat_join_request_response_H_
#define _decline_chat_join_request_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct decline_chat_join_request_response_t decline_chat_join_request_response_t;




typedef struct decline_chat_join_request_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} decline_chat_join_request_response_t;

__attribute__((deprecated)) decline_chat_join_request_response_t *decline_chat_join_request_response_create(
    int ok,
    int result
);

void decline_chat_join_request_response_free(decline_chat_join_request_response_t *decline_chat_join_request_response);

decline_chat_join_request_response_t *decline_chat_join_request_response_parseFromJSON(cJSON *decline_chat_join_request_responseJSON);

cJSON *decline_chat_join_request_response_convertToJSON(decline_chat_join_request_response_t *decline_chat_join_request_response);

#endif /* _decline_chat_join_request_response_H_ */

