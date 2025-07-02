/*
 * delete_my_commands_response.h
 *
 * 
 */

#ifndef _delete_my_commands_response_H_
#define _delete_my_commands_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_my_commands_response_t delete_my_commands_response_t;




typedef struct delete_my_commands_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_my_commands_response_t;

__attribute__((deprecated)) delete_my_commands_response_t *delete_my_commands_response_create(
    int ok,
    int result
);

void delete_my_commands_response_free(delete_my_commands_response_t *delete_my_commands_response);

delete_my_commands_response_t *delete_my_commands_response_parseFromJSON(cJSON *delete_my_commands_responseJSON);

cJSON *delete_my_commands_response_convertToJSON(delete_my_commands_response_t *delete_my_commands_response);

#endif /* _delete_my_commands_response_H_ */

