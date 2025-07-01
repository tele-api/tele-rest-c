/*
 * message_origin.h
 *
 * This object describes the origin of a message. It can be one of  * [MessageOriginUser](https://core.telegram.org/bots/api/#messageoriginuser) * [MessageOriginHiddenUser](https://core.telegram.org/bots/api/#messageoriginhiddenuser) * [MessageOriginChat](https://core.telegram.org/bots/api/#messageoriginchat) * [MessageOriginChannel](https://core.telegram.org/bots/api/#messageoriginchannel)
 */

#ifndef _message_origin_H_
#define _message_origin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_origin_t message_origin_t;

#include "chat.h"
#include "message_origin_channel.h"
#include "message_origin_chat.h"
#include "message_origin_hidden_user.h"
#include "message_origin_user.h"
#include "user.h"



typedef struct message_origin_t {
    char *type; // string
    int date; //numeric
    struct user_t *sender_user; //model
    char *sender_user_name; // string
    struct chat_t *sender_chat; //model
    struct chat_t *chat; //model
    int message_id; //numeric
    char *author_signature; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_origin_t;

__attribute__((deprecated)) message_origin_t *message_origin_create(
    char *type,
    int date,
    user_t *sender_user,
    char *sender_user_name,
    chat_t *sender_chat,
    chat_t *chat,
    int message_id,
    char *author_signature
);

void message_origin_free(message_origin_t *message_origin);

message_origin_t *message_origin_parseFromJSON(cJSON *message_originJSON);

cJSON *message_origin_convertToJSON(message_origin_t *message_origin);

#endif /* _message_origin_H_ */

