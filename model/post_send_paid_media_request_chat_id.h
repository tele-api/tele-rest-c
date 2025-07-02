/*
 * post_send_paid_media_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;). If the chat is a channel, all Telegram Star proceeds from this media will be credited to the chat&#39;s balance. Otherwise, they will be credited to the bot&#39;s balance.
 */

#ifndef _post_send_paid_media_request_chat_id_H_
#define _post_send_paid_media_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_paid_media_request_chat_id_t post_send_paid_media_request_chat_id_t;




typedef struct post_send_paid_media_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_paid_media_request_chat_id_t;

__attribute__((deprecated)) post_send_paid_media_request_chat_id_t *post_send_paid_media_request_chat_id_create(
);

void post_send_paid_media_request_chat_id_free(post_send_paid_media_request_chat_id_t *post_send_paid_media_request_chat_id);

post_send_paid_media_request_chat_id_t *post_send_paid_media_request_chat_id_parseFromJSON(cJSON *post_send_paid_media_request_chat_idJSON);

cJSON *post_send_paid_media_request_chat_id_convertToJSON(post_send_paid_media_request_chat_id_t *post_send_paid_media_request_chat_id);

#endif /* _post_send_paid_media_request_chat_id_H_ */

