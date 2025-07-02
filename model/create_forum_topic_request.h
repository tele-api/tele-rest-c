/*
 * create_forum_topic_request.h
 *
 * Request parameters for createForumTopic
 */

#ifndef _create_forum_topic_request_H_
#define _create_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_forum_topic_request_t create_forum_topic_request_t;

#include "bot_command_scope_chat_chat_id.h"

// Enum ICONCOLOR for create_forum_topic_request

typedef enum  { telegram_bot_api_create_forum_topic_request_ICONCOLOR_NULL = 0, telegram_bot_api_create_forum_topic_request_ICONCOLOR__7322096, telegram_bot_api_create_forum_topic_request_ICONCOLOR__16766590, telegram_bot_api_create_forum_topic_request_ICONCOLOR__13338331, telegram_bot_api_create_forum_topic_request_ICONCOLOR__9367192, telegram_bot_api_create_forum_topic_request_ICONCOLOR__16749490, telegram_bot_api_create_forum_topic_request_ICONCOLOR__16478047 } telegram_bot_api_create_forum_topic_request_ICONCOLOR_e;

char* create_forum_topic_request_icon_color_ToString(telegram_bot_api_create_forum_topic_request_ICONCOLOR_e icon_color);

telegram_bot_api_create_forum_topic_request_ICONCOLOR_e create_forum_topic_request_icon_color_FromString(char* icon_color);



typedef struct create_forum_topic_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    char *name; // string
    int icon_color; //numeric
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_forum_topic_request_t;

__attribute__((deprecated)) create_forum_topic_request_t *create_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
);

void create_forum_topic_request_free(create_forum_topic_request_t *create_forum_topic_request);

create_forum_topic_request_t *create_forum_topic_request_parseFromJSON(cJSON *create_forum_topic_requestJSON);

cJSON *create_forum_topic_request_convertToJSON(create_forum_topic_request_t *create_forum_topic_request);

#endif /* _create_forum_topic_request_H_ */

