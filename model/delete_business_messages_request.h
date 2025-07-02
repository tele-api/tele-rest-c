/*
 * delete_business_messages_request.h
 *
 * Request parameters for deleteBusinessMessages
 */

#ifndef _delete_business_messages_request_H_
#define _delete_business_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_business_messages_request_t delete_business_messages_request_t;




typedef struct delete_business_messages_request_t {
    char *business_connection_id; // string
    list_t *message_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} delete_business_messages_request_t;

__attribute__((deprecated)) delete_business_messages_request_t *delete_business_messages_request_create(
    char *business_connection_id,
    list_t *message_ids
);

void delete_business_messages_request_free(delete_business_messages_request_t *delete_business_messages_request);

delete_business_messages_request_t *delete_business_messages_request_parseFromJSON(cJSON *delete_business_messages_requestJSON);

cJSON *delete_business_messages_request_convertToJSON(delete_business_messages_request_t *delete_business_messages_request);

#endif /* _delete_business_messages_request_H_ */

