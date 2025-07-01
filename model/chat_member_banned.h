/*
 * chat_member_banned.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that was banned in the chat and can&#39;t return to the chat or view chat messages.
 */

#ifndef _chat_member_banned_H_
#define _chat_member_banned_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_banned_t chat_member_banned_t;

#include "user.h"



typedef struct chat_member_banned_t {
    char *status; // string
    struct user_t *user; //model
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_banned_t;

__attribute__((deprecated)) chat_member_banned_t *chat_member_banned_create(
    char *status,
    user_t *user,
    int until_date
);

void chat_member_banned_free(chat_member_banned_t *chat_member_banned);

chat_member_banned_t *chat_member_banned_parseFromJSON(cJSON *chat_member_bannedJSON);

cJSON *chat_member_banned_convertToJSON(chat_member_banned_t *chat_member_banned);

#endif /* _chat_member_banned_H_ */

