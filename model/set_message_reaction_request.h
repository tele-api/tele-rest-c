/*
 * set_message_reaction_request.h
 *
 * Request parameters for setMessageReaction
 */

#ifndef _set_message_reaction_request_H_
#define _set_message_reaction_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_message_reaction_request_t set_message_reaction_request_t;

#include "reaction_type.h"
#include "send_message_request_chat_id.h"



typedef struct set_message_reaction_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    list_t *reaction; //nonprimitive container
    int is_big; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_message_reaction_request_t;

__attribute__((deprecated)) set_message_reaction_request_t *set_message_reaction_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
);

void set_message_reaction_request_free(set_message_reaction_request_t *set_message_reaction_request);

set_message_reaction_request_t *set_message_reaction_request_parseFromJSON(cJSON *set_message_reaction_requestJSON);

cJSON *set_message_reaction_request_convertToJSON(set_message_reaction_request_t *set_message_reaction_request);

#endif /* _set_message_reaction_request_H_ */

