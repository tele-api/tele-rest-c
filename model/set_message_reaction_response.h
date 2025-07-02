/*
 * set_message_reaction_response.h
 *
 * 
 */

#ifndef _set_message_reaction_response_H_
#define _set_message_reaction_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_message_reaction_response_t set_message_reaction_response_t;




typedef struct set_message_reaction_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_message_reaction_response_t;

__attribute__((deprecated)) set_message_reaction_response_t *set_message_reaction_response_create(
    int ok,
    int result
);

void set_message_reaction_response_free(set_message_reaction_response_t *set_message_reaction_response);

set_message_reaction_response_t *set_message_reaction_response_parseFromJSON(cJSON *set_message_reaction_responseJSON);

cJSON *set_message_reaction_response_convertToJSON(set_message_reaction_response_t *set_message_reaction_response);

#endif /* _set_message_reaction_response_H_ */

