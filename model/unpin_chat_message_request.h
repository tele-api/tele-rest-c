/*
 * unpin_chat_message_request.h
 *
 * Request parameters for unpinChatMessage
 */

#ifndef _unpin_chat_message_request_H_
#define _unpin_chat_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unpin_chat_message_request_t unpin_chat_message_request_t;

#include "send_message_request_chat_id.h"



typedef struct unpin_chat_message_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *business_connection_id; // string
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unpin_chat_message_request_t;

__attribute__((deprecated)) unpin_chat_message_request_t *unpin_chat_message_request_create(
    send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
);

void unpin_chat_message_request_free(unpin_chat_message_request_t *unpin_chat_message_request);

unpin_chat_message_request_t *unpin_chat_message_request_parseFromJSON(cJSON *unpin_chat_message_requestJSON);

cJSON *unpin_chat_message_request_convertToJSON(unpin_chat_message_request_t *unpin_chat_message_request);

#endif /* _unpin_chat_message_request_H_ */

