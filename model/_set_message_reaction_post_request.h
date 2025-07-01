/*
 * _set_message_reaction_post_request.h
 *
 * 
 */

#ifndef __set_message_reaction_post_request_H_
#define __set_message_reaction_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_message_reaction_post_request_t _set_message_reaction_post_request_t;

#include "_send_message_post_request_chat_id.h"
#include "reaction_type.h"



typedef struct _set_message_reaction_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    list_t *reaction; //nonprimitive container
    int is_big; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _set_message_reaction_post_request_t;

__attribute__((deprecated)) _set_message_reaction_post_request_t *_set_message_reaction_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
);

void _set_message_reaction_post_request_free(_set_message_reaction_post_request_t *_set_message_reaction_post_request);

_set_message_reaction_post_request_t *_set_message_reaction_post_request_parseFromJSON(cJSON *_set_message_reaction_post_requestJSON);

cJSON *_set_message_reaction_post_request_convertToJSON(_set_message_reaction_post_request_t *_set_message_reaction_post_request);

#endif /* __set_message_reaction_post_request_H_ */

