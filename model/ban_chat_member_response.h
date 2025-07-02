/*
 * ban_chat_member_response.h
 *
 * 
 */

#ifndef _ban_chat_member_response_H_
#define _ban_chat_member_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ban_chat_member_response_t ban_chat_member_response_t;




typedef struct ban_chat_member_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ban_chat_member_response_t;

__attribute__((deprecated)) ban_chat_member_response_t *ban_chat_member_response_create(
    int ok,
    int result
);

void ban_chat_member_response_free(ban_chat_member_response_t *ban_chat_member_response);

ban_chat_member_response_t *ban_chat_member_response_parseFromJSON(cJSON *ban_chat_member_responseJSON);

cJSON *ban_chat_member_response_convertToJSON(ban_chat_member_response_t *ban_chat_member_response);

#endif /* _ban_chat_member_response_H_ */

