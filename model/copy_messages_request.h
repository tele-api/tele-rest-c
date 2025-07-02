/*
 * copy_messages_request.h
 *
 * Request parameters for copyMessages
 */

#ifndef _copy_messages_request_H_
#define _copy_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct copy_messages_request_t copy_messages_request_t;

#include "forward_messages_request_from_chat_id.h"
#include "send_message_request_chat_id.h"



typedef struct copy_messages_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    struct forward_messages_request_from_chat_id_t *from_chat_id; //model
    list_t *message_ids; //primitive container
    int message_thread_id; //numeric
    int disable_notification; //boolean
    int protect_content; //boolean
    int remove_caption; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} copy_messages_request_t;

__attribute__((deprecated)) copy_messages_request_t *copy_messages_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_messages_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
);

void copy_messages_request_free(copy_messages_request_t *copy_messages_request);

copy_messages_request_t *copy_messages_request_parseFromJSON(cJSON *copy_messages_requestJSON);

cJSON *copy_messages_request_convertToJSON(copy_messages_request_t *copy_messages_request);

#endif /* _copy_messages_request_H_ */

