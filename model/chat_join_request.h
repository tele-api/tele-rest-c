/*
 * chat_join_request.h
 *
 * Represents a join request sent to a chat.
 */

#ifndef _chat_join_request_H_
#define _chat_join_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_join_request_t chat_join_request_t;

#include "chat.h"
#include "chat_invite_link.h"
#include "user.h"



typedef struct chat_join_request_t {
    struct chat_t *chat; //model
    struct user_t *from; //model
    int user_chat_id; //numeric
    int date; //numeric
    char *bio; // string
    struct chat_invite_link_t *invite_link; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_join_request_t;

__attribute__((deprecated)) chat_join_request_t *chat_join_request_create(
    chat_t *chat,
    user_t *from,
    int user_chat_id,
    int date,
    char *bio,
    chat_invite_link_t *invite_link
);

void chat_join_request_free(chat_join_request_t *chat_join_request);

chat_join_request_t *chat_join_request_parseFromJSON(cJSON *chat_join_requestJSON);

cJSON *chat_join_request_convertToJSON(chat_join_request_t *chat_join_request);

#endif /* _chat_join_request_H_ */

