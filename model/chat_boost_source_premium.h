/*
 * chat_boost_source_premium.h
 *
 * The boost was obtained by subscribing to Telegram Premium or by gifting a Telegram Premium subscription to another user.
 */

#ifndef _chat_boost_source_premium_H_
#define _chat_boost_source_premium_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_source_premium_t chat_boost_source_premium_t;

#include "user.h"



typedef struct chat_boost_source_premium_t {
    char *source; // string
    struct user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_source_premium_t;

__attribute__((deprecated)) chat_boost_source_premium_t *chat_boost_source_premium_create(
    char *source,
    user_t *user
);

void chat_boost_source_premium_free(chat_boost_source_premium_t *chat_boost_source_premium);

chat_boost_source_premium_t *chat_boost_source_premium_parseFromJSON(cJSON *chat_boost_source_premiumJSON);

cJSON *chat_boost_source_premium_convertToJSON(chat_boost_source_premium_t *chat_boost_source_premium);

#endif /* _chat_boost_source_premium_H_ */

