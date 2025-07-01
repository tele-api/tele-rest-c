/*
 * _send_chat_action_post_request.h
 *
 * 
 */

#ifndef __send_chat_action_post_request_H_
#define __send_chat_action_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_chat_action_post_request_t _send_chat_action_post_request_t;

#include "_send_message_post_request_chat_id.h"

// Enum ACTION for _send_chat_action_post_request

typedef enum  { telegram_bot_api__send_chat_action_post_request_ACTION_NULL = 0, telegram_bot_api__send_chat_action_post_request_ACTION_typing, telegram_bot_api__send_chat_action_post_request_ACTION_upload_photo, telegram_bot_api__send_chat_action_post_request_ACTION_record_video, telegram_bot_api__send_chat_action_post_request_ACTION_upload_video, telegram_bot_api__send_chat_action_post_request_ACTION_record_voice, telegram_bot_api__send_chat_action_post_request_ACTION_upload_voice, telegram_bot_api__send_chat_action_post_request_ACTION_upload_document, telegram_bot_api__send_chat_action_post_request_ACTION_choose_sticker, telegram_bot_api__send_chat_action_post_request_ACTION_find_location, telegram_bot_api__send_chat_action_post_request_ACTION_record_video_note, telegram_bot_api__send_chat_action_post_request_ACTION_upload_video_note } telegram_bot_api__send_chat_action_post_request_ACTION_e;

char* _send_chat_action_post_request_action_ToString(telegram_bot_api__send_chat_action_post_request_ACTION_e action);

telegram_bot_api__send_chat_action_post_request_ACTION_e _send_chat_action_post_request_action_FromString(char* action);



typedef struct _send_chat_action_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    telegram_bot_api__send_chat_action_post_request_ACTION_e action; //enum
    char *business_connection_id; // string
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _send_chat_action_post_request_t;

__attribute__((deprecated)) _send_chat_action_post_request_t *_send_chat_action_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    telegram_bot_api__send_chat_action_post_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
);

void _send_chat_action_post_request_free(_send_chat_action_post_request_t *_send_chat_action_post_request);

_send_chat_action_post_request_t *_send_chat_action_post_request_parseFromJSON(cJSON *_send_chat_action_post_requestJSON);

cJSON *_send_chat_action_post_request_convertToJSON(_send_chat_action_post_request_t *_send_chat_action_post_request);

#endif /* __send_chat_action_post_request_H_ */

