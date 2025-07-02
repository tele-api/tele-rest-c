/*
 * send_paid_media_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;). If the chat is a channel, all Telegram Star proceeds from this media will be credited to the chat&#39;s balance. Otherwise, they will be credited to the bot&#39;s balance.
 */

#ifndef _send_paid_media_request_chat_id_H_
#define _send_paid_media_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_paid_media_request_chat_id_t send_paid_media_request_chat_id_t;




typedef struct send_paid_media_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} send_paid_media_request_chat_id_t;

__attribute__((deprecated)) send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_create(
);

void send_paid_media_request_chat_id_free(send_paid_media_request_chat_id_t *send_paid_media_request_chat_id);

send_paid_media_request_chat_id_t *send_paid_media_request_chat_id_parseFromJSON(cJSON *send_paid_media_request_chat_idJSON);

cJSON *send_paid_media_request_chat_id_convertToJSON(send_paid_media_request_chat_id_t *send_paid_media_request_chat_id);

#endif /* _send_paid_media_request_chat_id_H_ */

