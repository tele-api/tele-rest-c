/*
 * delete_messages_request.h
 *
 * Request parameters for deleteMessages
 */

#ifndef _delete_messages_request_H_
#define _delete_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_messages_request_t delete_messages_request_t;

#include "send_message_request_chat_id.h"



typedef struct delete_messages_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    list_t *message_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} delete_messages_request_t;

__attribute__((deprecated)) delete_messages_request_t *delete_messages_request_create(
    send_message_request_chat_id_t *chat_id,
    list_t *message_ids
);

void delete_messages_request_free(delete_messages_request_t *delete_messages_request);

delete_messages_request_t *delete_messages_request_parseFromJSON(cJSON *delete_messages_requestJSON);

cJSON *delete_messages_request_convertToJSON(delete_messages_request_t *delete_messages_request);

#endif /* _delete_messages_request_H_ */

