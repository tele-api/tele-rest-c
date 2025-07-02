/*
 * delete_message_response.h
 *
 * 
 */

#ifndef _delete_message_response_H_
#define _delete_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_message_response_t delete_message_response_t;




typedef struct delete_message_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_message_response_t;

__attribute__((deprecated)) delete_message_response_t *delete_message_response_create(
    int ok,
    int result
);

void delete_message_response_free(delete_message_response_t *delete_message_response);

delete_message_response_t *delete_message_response_parseFromJSON(cJSON *delete_message_responseJSON);

cJSON *delete_message_response_convertToJSON(delete_message_response_t *delete_message_response);

#endif /* _delete_message_response_H_ */

