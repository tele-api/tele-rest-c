/*
 * giveaway_winners.h
 *
 * This object represents a message about the completion of a giveaway with public winners.
 */

#ifndef _giveaway_winners_H_
#define _giveaway_winners_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct giveaway_winners_t giveaway_winners_t;

#include "chat.h"
#include "user.h"



typedef struct giveaway_winners_t {
    struct chat_t *chat; //model
    int giveaway_message_id; //numeric
    int winners_selection_date; //numeric
    int winner_count; //numeric
    list_t *winners; //nonprimitive container
    int additional_chat_count; //numeric
    int prize_star_count; //numeric
    int premium_subscription_month_count; //numeric
    int unclaimed_prize_count; //numeric
    int only_new_members; //boolean
    int was_refunded; //boolean
    char *prize_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} giveaway_winners_t;

__attribute__((deprecated)) giveaway_winners_t *giveaway_winners_create(
    chat_t *chat,
    int giveaway_message_id,
    int winners_selection_date,
    int winner_count,
    list_t *winners,
    int additional_chat_count,
    int prize_star_count,
    int premium_subscription_month_count,
    int unclaimed_prize_count,
    int only_new_members,
    int was_refunded,
    char *prize_description
);

void giveaway_winners_free(giveaway_winners_t *giveaway_winners);

giveaway_winners_t *giveaway_winners_parseFromJSON(cJSON *giveaway_winnersJSON);

cJSON *giveaway_winners_convertToJSON(giveaway_winners_t *giveaway_winners);

#endif /* _giveaway_winners_H_ */

