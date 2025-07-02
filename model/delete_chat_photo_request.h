/*
 * delete_chat_photo_request.h
 *
 * Request parameters for deleteChatPhoto
 */

#ifndef _delete_chat_photo_request_H_
#define _delete_chat_photo_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_chat_photo_request_t delete_chat_photo_request_t;

#include "send_message_request_chat_id.h"



typedef struct delete_chat_photo_request_t {
    struct send_message_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} delete_chat_photo_request_t;

__attribute__((deprecated)) delete_chat_photo_request_t *delete_chat_photo_request_create(
    send_message_request_chat_id_t *chat_id
);

void delete_chat_photo_request_free(delete_chat_photo_request_t *delete_chat_photo_request);

delete_chat_photo_request_t *delete_chat_photo_request_parseFromJSON(cJSON *delete_chat_photo_requestJSON);

cJSON *delete_chat_photo_request_convertToJSON(delete_chat_photo_request_t *delete_chat_photo_request);

#endif /* _delete_chat_photo_request_H_ */

