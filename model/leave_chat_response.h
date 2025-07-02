/*
 * leave_chat_response.h
 *
 * 
 */

#ifndef _leave_chat_response_H_
#define _leave_chat_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct leave_chat_response_t leave_chat_response_t;




typedef struct leave_chat_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} leave_chat_response_t;

__attribute__((deprecated)) leave_chat_response_t *leave_chat_response_create(
    int ok,
    int result
);

void leave_chat_response_free(leave_chat_response_t *leave_chat_response);

leave_chat_response_t *leave_chat_response_parseFromJSON(cJSON *leave_chat_responseJSON);

cJSON *leave_chat_response_convertToJSON(leave_chat_response_t *leave_chat_response);

#endif /* _leave_chat_response_H_ */

