/*
 * restrict_chat_member_response.h
 *
 * 
 */

#ifndef _restrict_chat_member_response_H_
#define _restrict_chat_member_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct restrict_chat_member_response_t restrict_chat_member_response_t;




typedef struct restrict_chat_member_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} restrict_chat_member_response_t;

__attribute__((deprecated)) restrict_chat_member_response_t *restrict_chat_member_response_create(
    int ok,
    int result
);

void restrict_chat_member_response_free(restrict_chat_member_response_t *restrict_chat_member_response);

restrict_chat_member_response_t *restrict_chat_member_response_parseFromJSON(cJSON *restrict_chat_member_responseJSON);

cJSON *restrict_chat_member_response_convertToJSON(restrict_chat_member_response_t *restrict_chat_member_response);

#endif /* _restrict_chat_member_response_H_ */

