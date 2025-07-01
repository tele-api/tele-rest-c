/*
 * user_chat_boosts.h
 *
 * This object represents a list of boosts added to a chat by a user.
 */

#ifndef _user_chat_boosts_H_
#define _user_chat_boosts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_chat_boosts_t user_chat_boosts_t;

#include "chat_boost.h"



typedef struct user_chat_boosts_t {
    list_t *boosts; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_chat_boosts_t;

__attribute__((deprecated)) user_chat_boosts_t *user_chat_boosts_create(
    list_t *boosts
);

void user_chat_boosts_free(user_chat_boosts_t *user_chat_boosts);

user_chat_boosts_t *user_chat_boosts_parseFromJSON(cJSON *user_chat_boostsJSON);

cJSON *user_chat_boosts_convertToJSON(user_chat_boosts_t *user_chat_boosts);

#endif /* _user_chat_boosts_H_ */

