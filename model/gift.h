/*
 * gift.h
 *
 * This object represents a gift that can be sent by the bot.
 */

#ifndef _gift_H_
#define _gift_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gift_t gift_t;

#include "sticker.h"



typedef struct gift_t {
    char *id; // string
    struct sticker_t *sticker; //model
    int star_count; //numeric
    int upgrade_star_count; //numeric
    int total_count; //numeric
    int remaining_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} gift_t;

__attribute__((deprecated)) gift_t *gift_create(
    char *id,
    sticker_t *sticker,
    int star_count,
    int upgrade_star_count,
    int total_count,
    int remaining_count
);

void gift_free(gift_t *gift);

gift_t *gift_parseFromJSON(cJSON *giftJSON);

cJSON *gift_convertToJSON(gift_t *gift);

#endif /* _gift_H_ */

