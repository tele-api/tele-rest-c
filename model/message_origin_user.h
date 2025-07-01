/*
 * message_origin_user.h
 *
 * The message was originally sent by a known user.
 */

#ifndef _message_origin_user_H_
#define _message_origin_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_origin_user_t message_origin_user_t;

#include "user.h"



typedef struct message_origin_user_t {
    char *type; // string
    int date; //numeric
    struct user_t *sender_user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} message_origin_user_t;

__attribute__((deprecated)) message_origin_user_t *message_origin_user_create(
    char *type,
    int date,
    user_t *sender_user
);

void message_origin_user_free(message_origin_user_t *message_origin_user);

message_origin_user_t *message_origin_user_parseFromJSON(cJSON *message_origin_userJSON);

cJSON *message_origin_user_convertToJSON(message_origin_user_t *message_origin_user);

#endif /* _message_origin_user_H_ */

