/*
 * _leave_chat_post_request.h
 *
 * 
 */

#ifndef __leave_chat_post_request_H_
#define __leave_chat_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _leave_chat_post_request_t _leave_chat_post_request_t;

#include "_leave_chat_post_request_chat_id.h"



typedef struct _leave_chat_post_request_t {
    struct _leave_chat_post_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _leave_chat_post_request_t;

__attribute__((deprecated)) _leave_chat_post_request_t *_leave_chat_post_request_create(
    _leave_chat_post_request_chat_id_t *chat_id
);

void _leave_chat_post_request_free(_leave_chat_post_request_t *_leave_chat_post_request);

_leave_chat_post_request_t *_leave_chat_post_request_parseFromJSON(cJSON *_leave_chat_post_requestJSON);

cJSON *_leave_chat_post_request_convertToJSON(_leave_chat_post_request_t *_leave_chat_post_request);

#endif /* __leave_chat_post_request_H_ */

