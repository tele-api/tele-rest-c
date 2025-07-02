/*
 * set_my_commands_response.h
 *
 * 
 */

#ifndef _set_my_commands_response_H_
#define _set_my_commands_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_my_commands_response_t set_my_commands_response_t;




typedef struct set_my_commands_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_my_commands_response_t;

__attribute__((deprecated)) set_my_commands_response_t *set_my_commands_response_create(
    int ok,
    int result
);

void set_my_commands_response_free(set_my_commands_response_t *set_my_commands_response);

set_my_commands_response_t *set_my_commands_response_parseFromJSON(cJSON *set_my_commands_responseJSON);

cJSON *set_my_commands_response_convertToJSON(set_my_commands_response_t *set_my_commands_response);

#endif /* _set_my_commands_response_H_ */

