/*
 * delete_message_request.h
 *
 * Request parameters for deleteMessage
 */

#ifndef _delete_message_request_H_
#define _delete_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_message_request_t delete_message_request_t;

#include "send_message_request_chat_id.h"



typedef struct delete_message_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} delete_message_request_t;

__attribute__((deprecated)) delete_message_request_t *delete_message_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id
);

void delete_message_request_free(delete_message_request_t *delete_message_request);

delete_message_request_t *delete_message_request_parseFromJSON(cJSON *delete_message_requestJSON);

cJSON *delete_message_request_convertToJSON(delete_message_request_t *delete_message_request);

#endif /* _delete_message_request_H_ */

