/*
 * _send_paid_media_post_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;). If the chat is a channel, all Telegram Star proceeds from this media will be credited to the chat&#39;s balance. Otherwise, they will be credited to the bot&#39;s balance.
 */

#ifndef __send_paid_media_post_request_chat_id_H_
#define __send_paid_media_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_paid_media_post_request_chat_id_t _send_paid_media_post_request_chat_id_t;




typedef struct _send_paid_media_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _send_paid_media_post_request_chat_id_t;

__attribute__((deprecated)) _send_paid_media_post_request_chat_id_t *_send_paid_media_post_request_chat_id_create(
);

void _send_paid_media_post_request_chat_id_free(_send_paid_media_post_request_chat_id_t *_send_paid_media_post_request_chat_id);

_send_paid_media_post_request_chat_id_t *_send_paid_media_post_request_chat_id_parseFromJSON(cJSON *_send_paid_media_post_request_chat_idJSON);

cJSON *_send_paid_media_post_request_chat_id_convertToJSON(_send_paid_media_post_request_chat_id_t *_send_paid_media_post_request_chat_id);

#endif /* __send_paid_media_post_request_chat_id_H_ */

