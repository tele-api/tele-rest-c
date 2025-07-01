/*
 * _close_forum_topic_post_request.h
 *
 * 
 */

#ifndef __close_forum_topic_post_request_H_
#define __close_forum_topic_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _close_forum_topic_post_request_t _close_forum_topic_post_request_t;

#include "_restrict_chat_member_post_request_chat_id.h"



typedef struct _close_forum_topic_post_request_t {
    struct _restrict_chat_member_post_request_chat_id_t *chat_id; //model
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _close_forum_topic_post_request_t;

__attribute__((deprecated)) _close_forum_topic_post_request_t *_close_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int message_thread_id
);

void _close_forum_topic_post_request_free(_close_forum_topic_post_request_t *_close_forum_topic_post_request);

_close_forum_topic_post_request_t *_close_forum_topic_post_request_parseFromJSON(cJSON *_close_forum_topic_post_requestJSON);

cJSON *_close_forum_topic_post_request_convertToJSON(_close_forum_topic_post_request_t *_close_forum_topic_post_request);

#endif /* __close_forum_topic_post_request_H_ */

