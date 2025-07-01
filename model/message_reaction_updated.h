/*
 * message_reaction_updated.h
 *
 * This object represents a change of a reaction on a message performed by a user.
 */

#ifndef _message_reaction_updated_H_
#define _message_reaction_updated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_reaction_updated_t message_reaction_updated_t;

#include "chat.h"
#include "reaction_type.h"
#include "user.h"



typedef struct message_reaction_updated_t {
    struct chat_t *chat; //model
    int message_id; //numeric
    int date; //numeric
    list_t *old_reaction; //nonprimitive container
    list_t *new_reaction; //nonprimitive container
    struct user_t *user; //model
    struct chat_t *actor_chat; //model

    int _library_owned; // Is the library responsible for freeing this object?
} message_reaction_updated_t;

__attribute__((deprecated)) message_reaction_updated_t *message_reaction_updated_create(
    chat_t *chat,
    int message_id,
    int date,
    list_t *old_reaction,
    list_t *new_reaction,
    user_t *user,
    chat_t *actor_chat
);

void message_reaction_updated_free(message_reaction_updated_t *message_reaction_updated);

message_reaction_updated_t *message_reaction_updated_parseFromJSON(cJSON *message_reaction_updatedJSON);

cJSON *message_reaction_updated_convertToJSON(message_reaction_updated_t *message_reaction_updated);

#endif /* _message_reaction_updated_H_ */

