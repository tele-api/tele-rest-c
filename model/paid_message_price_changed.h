/*
 * paid_message_price_changed.h
 *
 * Describes a service message about a change in the price of paid messages within a chat.
 */

#ifndef _paid_message_price_changed_H_
#define _paid_message_price_changed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_message_price_changed_t paid_message_price_changed_t;




typedef struct paid_message_price_changed_t {
    int paid_message_star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} paid_message_price_changed_t;

__attribute__((deprecated)) paid_message_price_changed_t *paid_message_price_changed_create(
    int paid_message_star_count
);

void paid_message_price_changed_free(paid_message_price_changed_t *paid_message_price_changed);

paid_message_price_changed_t *paid_message_price_changed_parseFromJSON(cJSON *paid_message_price_changedJSON);

cJSON *paid_message_price_changed_convertToJSON(paid_message_price_changed_t *paid_message_price_changed);

#endif /* _paid_message_price_changed_H_ */

