/*
 * post_close_forum_topic_request.h
 *
 * 
 */

#ifndef _post_close_forum_topic_request_H_
#define _post_close_forum_topic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_close_forum_topic_request_t post_close_forum_topic_request_t;

#include "post_restrict_chat_member_request_chat_id.h"



typedef struct post_close_forum_topic_request_t {
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model
    int message_thread_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_close_forum_topic_request_t;

__attribute__((deprecated)) post_close_forum_topic_request_t *post_close_forum_topic_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int message_thread_id
);

void post_close_forum_topic_request_free(post_close_forum_topic_request_t *post_close_forum_topic_request);

post_close_forum_topic_request_t *post_close_forum_topic_request_parseFromJSON(cJSON *post_close_forum_topic_requestJSON);

cJSON *post_close_forum_topic_request_convertToJSON(post_close_forum_topic_request_t *post_close_forum_topic_request);

#endif /* _post_close_forum_topic_request_H_ */

