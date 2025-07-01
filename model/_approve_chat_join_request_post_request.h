/*
 * _approve_chat_join_request_post_request.h
 *
 * 
 */

#ifndef __approve_chat_join_request_post_request_H_
#define __approve_chat_join_request_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _approve_chat_join_request_post_request_t _approve_chat_join_request_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _approve_chat_join_request_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _approve_chat_join_request_post_request_t;

__attribute__((deprecated)) _approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int user_id
);

void _approve_chat_join_request_post_request_free(_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request);

_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_parseFromJSON(cJSON *_approve_chat_join_request_post_requestJSON);

cJSON *_approve_chat_join_request_post_request_convertToJSON(_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request);

#endif /* __approve_chat_join_request_post_request_H_ */

