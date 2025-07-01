/*
 * chat_member_member.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that has no additional privileges or restrictions.
 */

#ifndef _chat_member_member_H_
#define _chat_member_member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_member_t chat_member_member_t;

#include "user.h"



typedef struct chat_member_member_t {
    char *status; // string
    struct user_t *user; //model
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_member_t;

__attribute__((deprecated)) chat_member_member_t *chat_member_member_create(
    char *status,
    user_t *user,
    int until_date
);

void chat_member_member_free(chat_member_member_t *chat_member_member);

chat_member_member_t *chat_member_member_parseFromJSON(cJSON *chat_member_memberJSON);

cJSON *chat_member_member_convertToJSON(chat_member_member_t *chat_member_member);

#endif /* _chat_member_member_H_ */

