/*
 * promote_chat_member_response.h
 *
 * 
 */

#ifndef _promote_chat_member_response_H_
#define _promote_chat_member_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct promote_chat_member_response_t promote_chat_member_response_t;




typedef struct promote_chat_member_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} promote_chat_member_response_t;

__attribute__((deprecated)) promote_chat_member_response_t *promote_chat_member_response_create(
    int ok,
    int result
);

void promote_chat_member_response_free(promote_chat_member_response_t *promote_chat_member_response);

promote_chat_member_response_t *promote_chat_member_response_parseFromJSON(cJSON *promote_chat_member_responseJSON);

cJSON *promote_chat_member_response_convertToJSON(promote_chat_member_response_t *promote_chat_member_response);

#endif /* _promote_chat_member_response_H_ */

