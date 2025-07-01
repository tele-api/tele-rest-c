/*
 * paid_media_purchased.h
 *
 * This object contains information about a paid media purchase.
 */

#ifndef _paid_media_purchased_H_
#define _paid_media_purchased_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paid_media_purchased_t paid_media_purchased_t;

#include "user.h"



typedef struct paid_media_purchased_t {
    struct user_t *from; //model
    char *paid_media_payload; // string

    int _library_owned; // Is the library responsible for freeing this object?
} paid_media_purchased_t;

__attribute__((deprecated)) paid_media_purchased_t *paid_media_purchased_create(
    user_t *from,
    char *paid_media_payload
);

void paid_media_purchased_free(paid_media_purchased_t *paid_media_purchased);

paid_media_purchased_t *paid_media_purchased_parseFromJSON(cJSON *paid_media_purchasedJSON);

cJSON *paid_media_purchased_convertToJSON(paid_media_purchased_t *paid_media_purchased);

#endif /* _paid_media_purchased_H_ */

