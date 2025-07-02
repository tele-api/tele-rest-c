/*
 * post_read_business_message_request.h
 *
 * 
 */

#ifndef _post_read_business_message_request_H_
#define _post_read_business_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_read_business_message_request_t post_read_business_message_request_t;




typedef struct post_read_business_message_request_t {
    char *business_connection_id; // string
    int chat_id; //numeric
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_read_business_message_request_t;

__attribute__((deprecated)) post_read_business_message_request_t *post_read_business_message_request_create(
    char *business_connection_id,
    int chat_id,
    int message_id
);

void post_read_business_message_request_free(post_read_business_message_request_t *post_read_business_message_request);

post_read_business_message_request_t *post_read_business_message_request_parseFromJSON(cJSON *post_read_business_message_requestJSON);

cJSON *post_read_business_message_request_convertToJSON(post_read_business_message_request_t *post_read_business_message_request);

#endif /* _post_read_business_message_request_H_ */

