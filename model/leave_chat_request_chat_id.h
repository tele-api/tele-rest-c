/*
 * leave_chat_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup or channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _leave_chat_request_chat_id_H_
#define _leave_chat_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct leave_chat_request_chat_id_t leave_chat_request_chat_id_t;




typedef struct leave_chat_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} leave_chat_request_chat_id_t;

__attribute__((deprecated)) leave_chat_request_chat_id_t *leave_chat_request_chat_id_create(
);

void leave_chat_request_chat_id_free(leave_chat_request_chat_id_t *leave_chat_request_chat_id);

leave_chat_request_chat_id_t *leave_chat_request_chat_id_parseFromJSON(cJSON *leave_chat_request_chat_idJSON);

cJSON *leave_chat_request_chat_id_convertToJSON(leave_chat_request_chat_id_t *leave_chat_request_chat_id);

#endif /* _leave_chat_request_chat_id_H_ */

