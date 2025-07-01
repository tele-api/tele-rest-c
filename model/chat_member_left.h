/*
 * chat_member_left.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that isn&#39;t currently a member of the chat, but may join it themselves.
 */

#ifndef _chat_member_left_H_
#define _chat_member_left_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_left_t chat_member_left_t;

#include "user.h"



typedef struct chat_member_left_t {
    char *status; // string
    struct user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_left_t;

__attribute__((deprecated)) chat_member_left_t *chat_member_left_create(
    char *status,
    user_t *user
);

void chat_member_left_free(chat_member_left_t *chat_member_left);

chat_member_left_t *chat_member_left_parseFromJSON(cJSON *chat_member_leftJSON);

cJSON *chat_member_left_convertToJSON(chat_member_left_t *chat_member_left);

#endif /* _chat_member_left_H_ */

