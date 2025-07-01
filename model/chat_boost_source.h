/*
 * chat_boost_source.h
 *
 * This object describes the source of a chat boost. It can be one of  * [ChatBoostSourcePremium](https://core.telegram.org/bots/api/#chatboostsourcepremium) * [ChatBoostSourceGiftCode](https://core.telegram.org/bots/api/#chatboostsourcegiftcode) * [ChatBoostSourceGiveaway](https://core.telegram.org/bots/api/#chatboostsourcegiveaway)
 */

#ifndef _chat_boost_source_H_
#define _chat_boost_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_source_t chat_boost_source_t;

#include "chat_boost_source_gift_code.h"
#include "chat_boost_source_giveaway.h"
#include "chat_boost_source_premium.h"
#include "user.h"



typedef struct chat_boost_source_t {
    char *source; // string
    struct user_t *user; //model
    int giveaway_message_id; //numeric
    int prize_star_count; //numeric
    int is_unclaimed; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_source_t;

__attribute__((deprecated)) chat_boost_source_t *chat_boost_source_create(
    char *source,
    user_t *user,
    int giveaway_message_id,
    int prize_star_count,
    int is_unclaimed
);

void chat_boost_source_free(chat_boost_source_t *chat_boost_source);

chat_boost_source_t *chat_boost_source_parseFromJSON(cJSON *chat_boost_sourceJSON);

cJSON *chat_boost_source_convertToJSON(chat_boost_source_t *chat_boost_source);

#endif /* _chat_boost_source_H_ */

