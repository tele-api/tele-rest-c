/*
 * owned_gift_regular.h
 *
 * Describes a regular gift owned by a user or a chat.
 */

#ifndef _owned_gift_regular_H_
#define _owned_gift_regular_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct owned_gift_regular_t owned_gift_regular_t;

#include "gift.h"
#include "message_entity.h"
#include "user.h"



typedef struct owned_gift_regular_t {
    char *type; // string
    struct gift_t *gift; //model
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

    int _library_owned; // Is the library responsible for freeing this object?
} owned_gift_regular_t;

__attribute__((deprecated)) owned_gift_regular_t *owned_gift_regular_create(
    char *type,
    gift_t *gift,
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
    int prepaid_upgrade_star_count
);

void owned_gift_regular_free(owned_gift_regular_t *owned_gift_regular);

owned_gift_regular_t *owned_gift_regular_parseFromJSON(cJSON *owned_gift_regularJSON);

cJSON *owned_gift_regular_convertToJSON(owned_gift_regular_t *owned_gift_regular);

#endif /* _owned_gift_regular_H_ */

