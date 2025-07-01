/*
 * message_origin_hidden_user.h
 *
 * The message was originally sent by an unknown user.
 */

#ifndef _message_origin_hidden_user_H_
#define _message_origin_hidden_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_origin_hidden_user_t message_origin_hidden_user_t;




typedef struct message_origin_hidden_user_t {
    char *type; // string
    int date; //numeric
    char *sender_user_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_origin_hidden_user_t;

__attribute__((deprecated)) message_origin_hidden_user_t *message_origin_hidden_user_create(
    char *type,
    int date,
    char *sender_user_name
);

void message_origin_hidden_user_free(message_origin_hidden_user_t *message_origin_hidden_user);

message_origin_hidden_user_t *message_origin_hidden_user_parseFromJSON(cJSON *message_origin_hidden_userJSON);

cJSON *message_origin_hidden_user_convertToJSON(message_origin_hidden_user_t *message_origin_hidden_user);

#endif /* _message_origin_hidden_user_H_ */

