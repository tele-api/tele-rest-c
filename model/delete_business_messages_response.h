/*
 * delete_business_messages_response.h
 *
 * 
 */

#ifndef _delete_business_messages_response_H_
#define _delete_business_messages_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_business_messages_response_t delete_business_messages_response_t;




typedef struct delete_business_messages_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_business_messages_response_t;

__attribute__((deprecated)) delete_business_messages_response_t *delete_business_messages_response_create(
    int ok,
    int result
);

void delete_business_messages_response_free(delete_business_messages_response_t *delete_business_messages_response);

delete_business_messages_response_t *delete_business_messages_response_parseFromJSON(cJSON *delete_business_messages_responseJSON);

cJSON *delete_business_messages_response_convertToJSON(delete_business_messages_response_t *delete_business_messages_response);

#endif /* _delete_business_messages_response_H_ */

