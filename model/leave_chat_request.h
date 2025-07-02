/*
 * leave_chat_request.h
 *
 * Request parameters for leaveChat
 */

#ifndef _leave_chat_request_H_
#define _leave_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct leave_chat_request_t leave_chat_request_t;

#include "leave_chat_request_chat_id.h"



typedef struct leave_chat_request_t {
    struct leave_chat_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} leave_chat_request_t;

__attribute__((deprecated)) leave_chat_request_t *leave_chat_request_create(
    leave_chat_request_chat_id_t *chat_id
);

void leave_chat_request_free(leave_chat_request_t *leave_chat_request);

leave_chat_request_t *leave_chat_request_parseFromJSON(cJSON *leave_chat_requestJSON);

cJSON *leave_chat_request_convertToJSON(leave_chat_request_t *leave_chat_request);

#endif /* _leave_chat_request_H_ */

