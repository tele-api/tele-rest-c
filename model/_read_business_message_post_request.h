/*
 * _read_business_message_post_request.h
 *
 * 
 */

#ifndef __read_business_message_post_request_H_
#define __read_business_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _read_business_message_post_request_t _read_business_message_post_request_t;




typedef struct _read_business_message_post_request_t {
    char *business_connection_id; // string
    int chat_id; //numeric
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _read_business_message_post_request_t;

__attribute__((deprecated)) _read_business_message_post_request_t *_read_business_message_post_request_create(
    char *business_connection_id,
    int chat_id,
    int message_id
);

void _read_business_message_post_request_free(_read_business_message_post_request_t *_read_business_message_post_request);

_read_business_message_post_request_t *_read_business_message_post_request_parseFromJSON(cJSON *_read_business_message_post_requestJSON);

cJSON *_read_business_message_post_request_convertToJSON(_read_business_message_post_request_t *_read_business_message_post_request);

#endif /* __read_business_message_post_request_H_ */

