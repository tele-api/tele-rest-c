/*
 * _create_forum_topic_post_request.h
 *
 * 
 */

#ifndef __create_forum_topic_post_request_H_
#define __create_forum_topic_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_forum_topic_post_request_t _create_forum_topic_post_request_t;

#include "_restrict_chat_member_post_request_chat_id.h"

// Enum ICONCOLOR for _create_forum_topic_post_request

typedef enum  { telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_NULL = 0, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__7322096, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__16766590, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__13338331, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__9367192, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__16749490, telegram_bot_api__create_forum_topic_post_request_ICONCOLOR__16478047 } telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_e;

char* _create_forum_topic_post_request_icon_color_ToString(telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_e icon_color);

telegram_bot_api__create_forum_topic_post_request_ICONCOLOR_e _create_forum_topic_post_request_icon_color_FromString(char* icon_color);



typedef struct _create_forum_topic_post_request_t {
    struct _restrict_chat_member_post_request_chat_id_t *chat_id; //model
    char *name; // string
    int icon_color; //numeric
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _create_forum_topic_post_request_t;

__attribute__((deprecated)) _create_forum_topic_post_request_t *_create_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
);

void _create_forum_topic_post_request_free(_create_forum_topic_post_request_t *_create_forum_topic_post_request);

_create_forum_topic_post_request_t *_create_forum_topic_post_request_parseFromJSON(cJSON *_create_forum_topic_post_requestJSON);

cJSON *_create_forum_topic_post_request_convertToJSON(_create_forum_topic_post_request_t *_create_forum_topic_post_request);

#endif /* __create_forum_topic_post_request_H_ */

