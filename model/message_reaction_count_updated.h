/*
 * message_reaction_count_updated.h
 *
 * This object represents reaction changes on a message with anonymous reactions.
 */

#ifndef _message_reaction_count_updated_H_
#define _message_reaction_count_updated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_reaction_count_updated_t message_reaction_count_updated_t;

#include "chat.h"
#include "reaction_count.h"



typedef struct message_reaction_count_updated_t {
    struct chat_t *chat; //model
    int message_id; //numeric
    int date; //numeric
    list_t *reactions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} message_reaction_count_updated_t;

__attribute__((deprecated)) message_reaction_count_updated_t *message_reaction_count_updated_create(
    chat_t *chat,
    int message_id,
    int date,
    list_t *reactions
);

void message_reaction_count_updated_free(message_reaction_count_updated_t *message_reaction_count_updated);

message_reaction_count_updated_t *message_reaction_count_updated_parseFromJSON(cJSON *message_reaction_count_updatedJSON);

cJSON *message_reaction_count_updated_convertToJSON(message_reaction_count_updated_t *message_reaction_count_updated);

#endif /* _message_reaction_count_updated_H_ */

