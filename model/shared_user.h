/*
 * shared_user.h
 *
 * This object contains information about a user that was shared with the bot using a [KeyboardButtonRequestUsers](https://core.telegram.org/bots/api/#keyboardbuttonrequestusers) button.
 */

#ifndef _shared_user_H_
#define _shared_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shared_user_t shared_user_t;

#include "photo_size.h"



typedef struct shared_user_t {
    int user_id; //numeric
    char *first_name; // string
    char *last_name; // string
    char *username; // string
    list_t *photo; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} shared_user_t;

__attribute__((deprecated)) shared_user_t *shared_user_create(
    int user_id,
    char *first_name,
    char *last_name,
    char *username,
    list_t *photo
);

void shared_user_free(shared_user_t *shared_user);

shared_user_t *shared_user_parseFromJSON(cJSON *shared_userJSON);

cJSON *shared_user_convertToJSON(shared_user_t *shared_user);

#endif /* _shared_user_H_ */

