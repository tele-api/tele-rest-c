/*
 * reply_parameters.h
 *
 * Describes reply parameters for the message that is being sent.
 */

#ifndef _reply_parameters_H_
#define _reply_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reply_parameters_t reply_parameters_t;

#include "message_entity.h"
#include "reply_parameters_chat_id.h"



typedef struct reply_parameters_t {
    int message_id; //numeric
    struct reply_parameters_chat_id_t *chat_id; //model
    int allow_sending_without_reply; //boolean
    char *quote; // string
    char *quote_parse_mode; // string
    list_t *quote_entities; //nonprimitive container
    int quote_position; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} reply_parameters_t;

__attribute__((deprecated)) reply_parameters_t *reply_parameters_create(
    int message_id,
    reply_parameters_chat_id_t *chat_id,
    int allow_sending_without_reply,
    char *quote,
    char *quote_parse_mode,
    list_t *quote_entities,
    int quote_position
);

void reply_parameters_free(reply_parameters_t *reply_parameters);

reply_parameters_t *reply_parameters_parseFromJSON(cJSON *reply_parametersJSON);

cJSON *reply_parameters_convertToJSON(reply_parameters_t *reply_parameters);

#endif /* _reply_parameters_H_ */

