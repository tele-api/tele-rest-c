/*
 * inline_query.h
 *
 * This object represents an incoming inline query. When the user sends an empty query, your bot could return some default or trending results.
 */

#ifndef _inline_query_H_
#define _inline_query_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inline_query_t inline_query_t;

#include "location.h"
#include "user.h"

// Enum CHATTYPE for inline_query

typedef enum  { telegram_bot_api_inline_query_CHATTYPE_NULL = 0, telegram_bot_api_inline_query_CHATTYPE_sender, telegram_bot_api_inline_query_CHATTYPE__private, telegram_bot_api_inline_query_CHATTYPE_group, telegram_bot_api_inline_query_CHATTYPE_supergroup, telegram_bot_api_inline_query_CHATTYPE_channel } telegram_bot_api_inline_query_CHATTYPE_e;

char* inline_query_chat_type_ToString(telegram_bot_api_inline_query_CHATTYPE_e chat_type);

telegram_bot_api_inline_query_CHATTYPE_e inline_query_chat_type_FromString(char* chat_type);



typedef struct inline_query_t {
    char *id; // string
    struct user_t *from; //model
    char *query; // string
    char *offset; // string
    telegram_bot_api_inline_query_CHATTYPE_e chat_type; //enum
    struct location_t *location; //model

    int _library_owned; // Is the library responsible for freeing this object?
} inline_query_t;

__attribute__((deprecated)) inline_query_t *inline_query_create(
    char *id,
    user_t *from,
    char *query,
    char *offset,
    telegram_bot_api_inline_query_CHATTYPE_e chat_type,
    location_t *location
);

void inline_query_free(inline_query_t *inline_query);

inline_query_t *inline_query_parseFromJSON(cJSON *inline_queryJSON);

cJSON *inline_query_convertToJSON(inline_query_t *inline_query);

#endif /* _inline_query_H_ */

