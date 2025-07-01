/*
 * giveaway.h
 *
 * This object represents a message about a scheduled giveaway.
 */

#ifndef _giveaway_H_
#define _giveaway_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct giveaway_t giveaway_t;

#include "chat.h"



typedef struct giveaway_t {
    list_t *chats; //nonprimitive container
    int winners_selection_date; //numeric
    int winner_count; //numeric
    int only_new_members; //boolean
    int has_public_winners; //boolean
    char *prize_description; // string
    list_t *country_codes; //primitive container
    int prize_star_count; //numeric
    int premium_subscription_month_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} giveaway_t;

__attribute__((deprecated)) giveaway_t *giveaway_create(
    list_t *chats,
    int winners_selection_date,
    int winner_count,
    int only_new_members,
    int has_public_winners,
    char *prize_description,
    list_t *country_codes,
    int prize_star_count,
    int premium_subscription_month_count
);

void giveaway_free(giveaway_t *giveaway);

giveaway_t *giveaway_parseFromJSON(cJSON *giveawayJSON);

cJSON *giveaway_convertToJSON(giveaway_t *giveaway);

#endif /* _giveaway_H_ */

