/*
 * _delete_message_post_request.h
 *
 * 
 */

#ifndef __delete_message_post_request_H_
#define __delete_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _delete_message_post_request_t _delete_message_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _delete_message_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _delete_message_post_request_t;

__attribute__((deprecated)) _delete_message_post_request_t *_delete_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id
);

void _delete_message_post_request_free(_delete_message_post_request_t *_delete_message_post_request);

_delete_message_post_request_t *_delete_message_post_request_parseFromJSON(cJSON *_delete_message_post_requestJSON);

cJSON *_delete_message_post_request_convertToJSON(_delete_message_post_request_t *_delete_message_post_request);

#endif /* __delete_message_post_request_H_ */

