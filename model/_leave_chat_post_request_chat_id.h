/*
 * _leave_chat_post_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup or channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __leave_chat_post_request_chat_id_H_
#define __leave_chat_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _leave_chat_post_request_chat_id_t _leave_chat_post_request_chat_id_t;




typedef struct _leave_chat_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _leave_chat_post_request_chat_id_t;

__attribute__((deprecated)) _leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_create(
);

void _leave_chat_post_request_chat_id_free(_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id);

_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_parseFromJSON(cJSON *_leave_chat_post_request_chat_idJSON);

cJSON *_leave_chat_post_request_chat_id_convertToJSON(_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id);

#endif /* __leave_chat_post_request_chat_id_H_ */

