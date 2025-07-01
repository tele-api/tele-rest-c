/*
 * owned_gift_unique.h
 *
 * Describes a unique gift received and owned by a user or a chat.
 */

#ifndef _owned_gift_unique_H_
#define _owned_gift_unique_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct owned_gift_unique_t owned_gift_unique_t;

#include "unique_gift.h"
#include "user.h"



typedef struct owned_gift_unique_t {
    char *type; // string
    struct unique_gift_t *gift; //model
    int send_date; //numeric
    char *owned_gift_id; // string
    struct user_t *sender_user; //model
    int is_saved; //boolean
    int can_be_transferred; //boolean
    int transfer_star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} owned_gift_unique_t;

__attribute__((deprecated)) owned_gift_unique_t *owned_gift_unique_create(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    int is_saved,
    int can_be_transferred,
    int transfer_star_count
);

void owned_gift_unique_free(owned_gift_unique_t *owned_gift_unique);

owned_gift_unique_t *owned_gift_unique_parseFromJSON(cJSON *owned_gift_uniqueJSON);

cJSON *owned_gift_unique_convertToJSON(owned_gift_unique_t *owned_gift_unique);

#endif /* _owned_gift_unique_H_ */

