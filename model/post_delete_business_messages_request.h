/*
 * post_delete_business_messages_request.h
 *
 * 
 */

#ifndef _post_delete_business_messages_request_H_
#define _post_delete_business_messages_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_delete_business_messages_request_t post_delete_business_messages_request_t;




typedef struct post_delete_business_messages_request_t {
    char *business_connection_id; // string
    list_t *message_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_delete_business_messages_request_t;

__attribute__((deprecated)) post_delete_business_messages_request_t *post_delete_business_messages_request_create(
    char *business_connection_id,
    list_t *message_ids
);

void post_delete_business_messages_request_free(post_delete_business_messages_request_t *post_delete_business_messages_request);

post_delete_business_messages_request_t *post_delete_business_messages_request_parseFromJSON(cJSON *post_delete_business_messages_requestJSON);

cJSON *post_delete_business_messages_request_convertToJSON(post_delete_business_messages_request_t *post_delete_business_messages_request);

#endif /* _post_delete_business_messages_request_H_ */

