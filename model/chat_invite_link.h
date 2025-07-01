/*
 * chat_invite_link.h
 *
 * Represents an invite link for a chat.
 */

#ifndef _chat_invite_link_H_
#define _chat_invite_link_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_invite_link_t chat_invite_link_t;

#include "user.h"



typedef struct chat_invite_link_t {
    char *invite_link; // string
    struct user_t *creator; //model
    int creates_join_request; //boolean
    int is_primary; //boolean
    int is_revoked; //boolean
    char *name; // string
    int expire_date; //numeric
    int member_limit; //numeric
    int pending_join_request_count; //numeric
    int subscription_period; //numeric
    int subscription_price; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} chat_invite_link_t;

__attribute__((deprecated)) chat_invite_link_t *chat_invite_link_create(
    char *invite_link,
    user_t *creator,
    int creates_join_request,
    int is_primary,
    int is_revoked,
    char *name,
    int expire_date,
    int member_limit,
    int pending_join_request_count,
    int subscription_period,
    int subscription_price
);

void chat_invite_link_free(chat_invite_link_t *chat_invite_link);

chat_invite_link_t *chat_invite_link_parseFromJSON(cJSON *chat_invite_linkJSON);

cJSON *chat_invite_link_convertToJSON(chat_invite_link_t *chat_invite_link);

#endif /* _chat_invite_link_H_ */

