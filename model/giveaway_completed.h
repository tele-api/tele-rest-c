/*
 * giveaway_completed.h
 *
 * This object represents a service message about the completion of a giveaway without public winners.
 */

#ifndef _giveaway_completed_H_
#define _giveaway_completed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct giveaway_completed_t giveaway_completed_t;

#include "message.h"



typedef struct giveaway_completed_t {
    int winner_count; //numeric
    int unclaimed_prize_count; //numeric
    struct message_t *giveaway_message; //model
    int is_star_giveaway; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} giveaway_completed_t;

__attribute__((deprecated)) giveaway_completed_t *giveaway_completed_create(
    int winner_count,
    int unclaimed_prize_count,
    message_t *giveaway_message,
    int is_star_giveaway
);

void giveaway_completed_free(giveaway_completed_t *giveaway_completed);

giveaway_completed_t *giveaway_completed_parseFromJSON(cJSON *giveaway_completedJSON);

cJSON *giveaway_completed_convertToJSON(giveaway_completed_t *giveaway_completed);

#endif /* _giveaway_completed_H_ */

