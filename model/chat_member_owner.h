/*
 * chat_member_owner.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that owns the chat and has all administrator privileges.
 */

#ifndef _chat_member_owner_H_
#define _chat_member_owner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_owner_t chat_member_owner_t;

#include "user.h"



typedef struct chat_member_owner_t {
    char *status; // string
    struct user_t *user; //model
    int is_anonymous; //boolean
    char *custom_title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_owner_t;

__attribute__((deprecated)) chat_member_owner_t *chat_member_owner_create(
    char *status,
    user_t *user,
    int is_anonymous,
    char *custom_title
);

void chat_member_owner_free(chat_member_owner_t *chat_member_owner);

chat_member_owner_t *chat_member_owner_parseFromJSON(cJSON *chat_member_ownerJSON);

cJSON *chat_member_owner_convertToJSON(chat_member_owner_t *chat_member_owner);

#endif /* _chat_member_owner_H_ */

