/*
 * chat_boost_source_giveaway.h
 *
 * The boost was obtained by the creation of a Telegram Premium or a Telegram Star giveaway. This boosts the chat 4 times for the duration of the corresponding Telegram Premium subscription for Telegram Premium giveaways and *prize\\_star\\_count* / 500 times for one year for Telegram Star giveaways.
 */

#ifndef _chat_boost_source_giveaway_H_
#define _chat_boost_source_giveaway_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_source_giveaway_t chat_boost_source_giveaway_t;

#include "user.h"



typedef struct chat_boost_source_giveaway_t {
    char *source; // string
    int giveaway_message_id; //numeric
    struct user_t *user; //model
    int prize_star_count; //numeric
    int is_unclaimed; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_source_giveaway_t;

__attribute__((deprecated)) chat_boost_source_giveaway_t *chat_boost_source_giveaway_create(
    char *source,
    int giveaway_message_id,
    user_t *user,
    int prize_star_count,
    int is_unclaimed
);

void chat_boost_source_giveaway_free(chat_boost_source_giveaway_t *chat_boost_source_giveaway);

chat_boost_source_giveaway_t *chat_boost_source_giveaway_parseFromJSON(cJSON *chat_boost_source_giveawayJSON);

cJSON *chat_boost_source_giveaway_convertToJSON(chat_boost_source_giveaway_t *chat_boost_source_giveaway);

#endif /* _chat_boost_source_giveaway_H_ */

