/*
 * owned_gift.h
 *
 * This object describes a gift received and owned by a user or a chat. Currently, it can be one of  * [OwnedGiftRegular](https://core.telegram.org/bots/api/#ownedgiftregular) * [OwnedGiftUnique](https://core.telegram.org/bots/api/#ownedgiftunique)
 */

#ifndef _owned_gift_H_
#define _owned_gift_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct owned_gift_t owned_gift_t;

#include "message_entity.h"
#include "owned_gift_regular.h"
#include "owned_gift_unique.h"
#include "unique_gift.h"
#include "user.h"



typedef struct owned_gift_t {
    char *type; // string
    struct unique_gift_t *gift; //model
    int send_date; //numeric
    char *owned_gift_id; // string
    struct user_t *sender_user; //model
    char *text; // string
    list_t *entities; //nonprimitive container
    int is_private; //boolean
    int is_saved; //boolean
    int can_be_upgraded; //boolean
    int was_refunded; //boolean
    int convert_star_count; //numeric
    int prepaid_upgrade_star_count; //numeric
    int can_be_transferred; //boolean
    int transfer_star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} owned_gift_t;

__attribute__((deprecated)) owned_gift_t *owned_gift_create(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    char *text,
    list_t *entities,
    int is_private,
    int is_saved,
    int can_be_upgraded,
    int was_refunded,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_transferred,
    int transfer_star_count
);

void owned_gift_free(owned_gift_t *owned_gift);

owned_gift_t *owned_gift_parseFromJSON(cJSON *owned_giftJSON);

cJSON *owned_gift_convertToJSON(owned_gift_t *owned_gift);

#endif /* _owned_gift_H_ */

