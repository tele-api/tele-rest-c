/*
 * post_send_chat_action_request.h
 *
 * 
 */

#ifndef _post_send_chat_action_request_H_
#define _post_send_chat_action_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_chat_action_request_t post_send_chat_action_request_t;

#include "post_send_message_request_chat_id.h"

// Enum ACTION for post_send_chat_action_request

typedef enum  { telegram_bot_api_post_send_chat_action_request_ACTION_NULL = 0, telegram_bot_api_post_send_chat_action_request_ACTION_typing, telegram_bot_api_post_send_chat_action_request_ACTION_upload_photo, telegram_bot_api_post_send_chat_action_request_ACTION_record_video, telegram_bot_api_post_send_chat_action_request_ACTION_upload_video, telegram_bot_api_post_send_chat_action_request_ACTION_record_voice, telegram_bot_api_post_send_chat_action_request_ACTION_upload_voice, telegram_bot_api_post_send_chat_action_request_ACTION_upload_document, telegram_bot_api_post_send_chat_action_request_ACTION_choose_sticker, telegram_bot_api_post_send_chat_action_request_ACTION_find_location, telegram_bot_api_post_send_chat_action_request_ACTION_record_video_note, telegram_bot_api_post_send_chat_action_request_ACTION_upload_video_note } telegram_bot_api_post_send_chat_action_request_ACTION_e;

char* post_send_chat_action_request_action_ToString(telegram_bot_api_post_send_chat_action_request_ACTION_e action);

telegram_bot_api_post_send_chat_action_request_ACTION_e post_send_chat_action_request_action_FromString(char* action);



typedef struct post_send_chat_action_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    telegram_bot_api_post_send_chat_action_request_ACTION_e action; //enum
    char *business_connection_id; // string
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_chat_action_request_t;

__attribute__((deprecated)) post_send_chat_action_request_t *post_send_chat_action_request_create(
    post_send_message_request_chat_id_t *chat_id,
    telegram_bot_api_post_send_chat_action_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
);

void post_send_chat_action_request_free(post_send_chat_action_request_t *post_send_chat_action_request);

post_send_chat_action_request_t *post_send_chat_action_request_parseFromJSON(cJSON *post_send_chat_action_requestJSON);

cJSON *post_send_chat_action_request_convertToJSON(post_send_chat_action_request_t *post_send_chat_action_request);

#endif /* _post_send_chat_action_request_H_ */

