/*
 * post_forward_messages_200_response.h
 *
 * 
 */

#ifndef _post_forward_messages_200_response_H_
#define _post_forward_messages_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_forward_messages_200_response_t post_forward_messages_200_response_t;

#include "message_id.h"



typedef struct post_forward_messages_200_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_forward_messages_200_response_t;

__attribute__((deprecated)) post_forward_messages_200_response_t *post_forward_messages_200_response_create(
    int ok,
    list_t *result
);

void post_forward_messages_200_response_free(post_forward_messages_200_response_t *post_forward_messages_200_response);

post_forward_messages_200_response_t *post_forward_messages_200_response_parseFromJSON(cJSON *post_forward_messages_200_responseJSON);

cJSON *post_forward_messages_200_response_convertToJSON(post_forward_messages_200_response_t *post_forward_messages_200_response);

#endif /* _post_forward_messages_200_response_H_ */

