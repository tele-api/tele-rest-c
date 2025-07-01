/*
 * _send_message_post_200_response.h
 *
 * 
 */

#ifndef __send_message_post_200_response_H_
#define __send_message_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_message_post_200_response_t _send_message_post_200_response_t;

#include "message.h"



typedef struct _send_message_post_200_response_t {
    int ok; //boolean
    struct message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _send_message_post_200_response_t;

__attribute__((deprecated)) _send_message_post_200_response_t *_send_message_post_200_response_create(
    int ok,
    message_t *result
);

void _send_message_post_200_response_free(_send_message_post_200_response_t *_send_message_post_200_response);

_send_message_post_200_response_t *_send_message_post_200_response_parseFromJSON(cJSON *_send_message_post_200_responseJSON);

cJSON *_send_message_post_200_response_convertToJSON(_send_message_post_200_response_t *_send_message_post_200_response);

#endif /* __send_message_post_200_response_H_ */

