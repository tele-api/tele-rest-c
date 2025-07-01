/*
 * chat.h
 *
 * This object represents a chat.
 */

#ifndef _chat_H_
#define _chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_t chat_t;


// Enum TYPE for chat

typedef enum  { telegram_bot_api_chat_TYPE_NULL = 0, telegram_bot_api_chat_TYPE__private, telegram_bot_api_chat_TYPE_group, telegram_bot_api_chat_TYPE_supergroup, telegram_bot_api_chat_TYPE_channel } telegram_bot_api_chat_TYPE_e;

char* chat_type_ToString(telegram_bot_api_chat_TYPE_e type);

telegram_bot_api_chat_TYPE_e chat_type_FromString(char* type);



typedef struct chat_t {
    int id; //numeric
    telegram_bot_api_chat_TYPE_e type; //enum
    char *title; // string
    char *username; // string
    char *first_name; // string
    char *last_name; // string
    int is_forum; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_t;

__attribute__((deprecated)) chat_t *chat_create(
    int id,
    telegram_bot_api_chat_TYPE_e type,
    char *title,
    char *username,
    char *first_name,
    char *last_name,
    int is_forum
);

void chat_free(chat_t *chat);

chat_t *chat_parseFromJSON(cJSON *chatJSON);

cJSON *chat_convertToJSON(chat_t *chat);

#endif /* _chat_H_ */

