/*
 * users_shared.h
 *
 * This object contains information about the users whose identifiers were shared with the bot using a [KeyboardButtonRequestUsers](https://core.telegram.org/bots/api/#keyboardbuttonrequestusers) button.
 */

#ifndef _users_shared_H_
#define _users_shared_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct users_shared_t users_shared_t;

#include "shared_user.h"



typedef struct users_shared_t {
    int request_id; //numeric
    list_t *users; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} users_shared_t;

__attribute__((deprecated)) users_shared_t *users_shared_create(
    int request_id,
    list_t *users
);

void users_shared_free(users_shared_t *users_shared);

users_shared_t *users_shared_parseFromJSON(cJSON *users_sharedJSON);

cJSON *users_shared_convertToJSON(users_shared_t *users_shared);

#endif /* _users_shared_H_ */

