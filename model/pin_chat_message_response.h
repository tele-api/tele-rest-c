/*
 * pin_chat_message_response.h
 *
 * 
 */

#ifndef _pin_chat_message_response_H_
#define _pin_chat_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pin_chat_message_response_t pin_chat_message_response_t;




typedef struct pin_chat_message_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} pin_chat_message_response_t;

__attribute__((deprecated)) pin_chat_message_response_t *pin_chat_message_response_create(
    int ok,
    int result
);

void pin_chat_message_response_free(pin_chat_message_response_t *pin_chat_message_response);

pin_chat_message_response_t *pin_chat_message_response_parseFromJSON(cJSON *pin_chat_message_responseJSON);

cJSON *pin_chat_message_response_convertToJSON(pin_chat_message_response_t *pin_chat_message_response);

#endif /* _pin_chat_message_response_H_ */

