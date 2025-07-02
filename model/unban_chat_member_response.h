/*
 * unban_chat_member_response.h
 *
 * 
 */

#ifndef _unban_chat_member_response_H_
#define _unban_chat_member_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unban_chat_member_response_t unban_chat_member_response_t;




typedef struct unban_chat_member_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} unban_chat_member_response_t;

__attribute__((deprecated)) unban_chat_member_response_t *unban_chat_member_response_create(
    int ok,
    int result
);

void unban_chat_member_response_free(unban_chat_member_response_t *unban_chat_member_response);

unban_chat_member_response_t *unban_chat_member_response_parseFromJSON(cJSON *unban_chat_member_responseJSON);

cJSON *unban_chat_member_response_convertToJSON(unban_chat_member_response_t *unban_chat_member_response);

#endif /* _unban_chat_member_response_H_ */

