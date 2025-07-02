/*
 * approve_chat_join_request_response.h
 *
 * 
 */

#ifndef _approve_chat_join_request_response_H_
#define _approve_chat_join_request_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct approve_chat_join_request_response_t approve_chat_join_request_response_t;




typedef struct approve_chat_join_request_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} approve_chat_join_request_response_t;

__attribute__((deprecated)) approve_chat_join_request_response_t *approve_chat_join_request_response_create(
    int ok,
    int result
);

void approve_chat_join_request_response_free(approve_chat_join_request_response_t *approve_chat_join_request_response);

approve_chat_join_request_response_t *approve_chat_join_request_response_parseFromJSON(cJSON *approve_chat_join_request_responseJSON);

cJSON *approve_chat_join_request_response_convertToJSON(approve_chat_join_request_response_t *approve_chat_join_request_response);

#endif /* _approve_chat_join_request_response_H_ */

