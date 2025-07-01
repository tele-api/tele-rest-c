/*
 * message_origin_chat.h
 *
 * The message was originally sent on behalf of a chat to a group chat.
 */

#ifndef _message_origin_chat_H_
#define _message_origin_chat_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_origin_chat_t message_origin_chat_t;

#include "chat.h"



typedef struct message_origin_chat_t {
    char *type; // string
    int date; //numeric
    struct chat_t *sender_chat; //model
    char *author_signature; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_origin_chat_t;

__attribute__((deprecated)) message_origin_chat_t *message_origin_chat_create(
    char *type,
    int date,
    chat_t *sender_chat,
    char *author_signature
);

void message_origin_chat_free(message_origin_chat_t *message_origin_chat);

message_origin_chat_t *message_origin_chat_parseFromJSON(cJSON *message_origin_chatJSON);

cJSON *message_origin_chat_convertToJSON(message_origin_chat_t *message_origin_chat);

#endif /* _message_origin_chat_H_ */

