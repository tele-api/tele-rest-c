/*
 * _verify_chat_post_request.h
 *
 * 
 */

#ifndef __verify_chat_post_request_H_
#define __verify_chat_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _verify_chat_post_request_t _verify_chat_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _verify_chat_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *custom_description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _verify_chat_post_request_t;

__attribute__((deprecated)) _verify_chat_post_request_t *_verify_chat_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *custom_description
);

void _verify_chat_post_request_free(_verify_chat_post_request_t *_verify_chat_post_request);

_verify_chat_post_request_t *_verify_chat_post_request_parseFromJSON(cJSON *_verify_chat_post_requestJSON);

cJSON *_verify_chat_post_request_convertToJSON(_verify_chat_post_request_t *_verify_chat_post_request);

#endif /* __verify_chat_post_request_H_ */

