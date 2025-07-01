/*
 * message_entity.h
 *
 * This object represents one special entity in a text message. For example, hashtags, usernames, URLs, etc.
 */

#ifndef _message_entity_H_
#define _message_entity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_entity_t message_entity_t;

#include "user.h"

// Enum TYPE for message_entity

typedef enum  { telegram_bot_api_message_entity_TYPE_NULL = 0, telegram_bot_api_message_entity_TYPE_mention, telegram_bot_api_message_entity_TYPE_hashtag, telegram_bot_api_message_entity_TYPE_cashtag, telegram_bot_api_message_entity_TYPE_bot_command, telegram_bot_api_message_entity_TYPE_url, telegram_bot_api_message_entity_TYPE_email, telegram_bot_api_message_entity_TYPE_phone_number, telegram_bot_api_message_entity_TYPE_bold, telegram_bot_api_message_entity_TYPE_italic, telegram_bot_api_message_entity_TYPE_underline, telegram_bot_api_message_entity_TYPE_strikethrough, telegram_bot_api_message_entity_TYPE_spoiler, telegram_bot_api_message_entity_TYPE_blockquote, telegram_bot_api_message_entity_TYPE_expandable_blockquote, telegram_bot_api_message_entity_TYPE_code, telegram_bot_api_message_entity_TYPE_pre, telegram_bot_api_message_entity_TYPE_text_link, telegram_bot_api_message_entity_TYPE_text_mention, telegram_bot_api_message_entity_TYPE_custom_emoji } telegram_bot_api_message_entity_TYPE_e;

char* message_entity_type_ToString(telegram_bot_api_message_entity_TYPE_e type);

telegram_bot_api_message_entity_TYPE_e message_entity_type_FromString(char* type);



typedef struct message_entity_t {
    telegram_bot_api_message_entity_TYPE_e type; //enum
    int offset; //numeric
    int length; //numeric
    char *url; // string
    struct user_t *user; //model
    char *language; // string
    char *custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_entity_t;

__attribute__((deprecated)) message_entity_t *message_entity_create(
    telegram_bot_api_message_entity_TYPE_e type,
    int offset,
    int length,
    char *url,
    user_t *user,
    char *language,
    char *custom_emoji_id
);

void message_entity_free(message_entity_t *message_entity);

message_entity_t *message_entity_parseFromJSON(cJSON *message_entityJSON);

cJSON *message_entity_convertToJSON(message_entity_t *message_entity);

#endif /* _message_entity_H_ */

