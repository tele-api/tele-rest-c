/*
 * _forward_messages_post_200_response.h
 *
 * 
 */

#ifndef __forward_messages_post_200_response_H_
#define __forward_messages_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _forward_messages_post_200_response_t _forward_messages_post_200_response_t;

#include "message_id.h"



typedef struct _forward_messages_post_200_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} _forward_messages_post_200_response_t;

__attribute__((deprecated)) _forward_messages_post_200_response_t *_forward_messages_post_200_response_create(
    int ok,
    list_t *result
);

void _forward_messages_post_200_response_free(_forward_messages_post_200_response_t *_forward_messages_post_200_response);

_forward_messages_post_200_response_t *_forward_messages_post_200_response_parseFromJSON(cJSON *_forward_messages_post_200_responseJSON);

cJSON *_forward_messages_post_200_response_convertToJSON(_forward_messages_post_200_response_t *_forward_messages_post_200_response);

#endif /* __forward_messages_post_200_response_H_ */

