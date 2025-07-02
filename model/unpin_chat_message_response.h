/*
 * unpin_chat_message_response.h
 *
 * 
 */

#ifndef _unpin_chat_message_response_H_
#define _unpin_chat_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unpin_chat_message_response_t unpin_chat_message_response_t;




typedef struct unpin_chat_message_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} unpin_chat_message_response_t;

__attribute__((deprecated)) unpin_chat_message_response_t *unpin_chat_message_response_create(
    int ok,
    int result
);

void unpin_chat_message_response_free(unpin_chat_message_response_t *unpin_chat_message_response);

unpin_chat_message_response_t *unpin_chat_message_response_parseFromJSON(cJSON *unpin_chat_message_responseJSON);

cJSON *unpin_chat_message_response_convertToJSON(unpin_chat_message_response_t *unpin_chat_message_response);

#endif /* _unpin_chat_message_response_H_ */

