/*
 * send_chat_action_response.h
 *
 * 
 */

#ifndef _send_chat_action_response_H_
#define _send_chat_action_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_chat_action_response_t send_chat_action_response_t;




typedef struct send_chat_action_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} send_chat_action_response_t;

__attribute__((deprecated)) send_chat_action_response_t *send_chat_action_response_create(
    int ok,
    int result
);

void send_chat_action_response_free(send_chat_action_response_t *send_chat_action_response);

send_chat_action_response_t *send_chat_action_response_parseFromJSON(cJSON *send_chat_action_responseJSON);

cJSON *send_chat_action_response_convertToJSON(send_chat_action_response_t *send_chat_action_response);

#endif /* _send_chat_action_response_H_ */

