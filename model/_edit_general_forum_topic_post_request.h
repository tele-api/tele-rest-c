/*
 * _edit_general_forum_topic_post_request.h
 *
 * 
 */

#ifndef __edit_general_forum_topic_post_request_H_
#define __edit_general_forum_topic_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_general_forum_topic_post_request_t _edit_general_forum_topic_post_request_t;

#include "_restrict_chat_member_post_request_chat_id.h"



typedef struct _edit_general_forum_topic_post_request_t {
    struct _restrict_chat_member_post_request_chat_id_t *chat_id; //model
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_general_forum_topic_post_request_t;

__attribute__((deprecated)) _edit_general_forum_topic_post_request_t *_edit_general_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    char *name
);

void _edit_general_forum_topic_post_request_free(_edit_general_forum_topic_post_request_t *_edit_general_forum_topic_post_request);

_edit_general_forum_topic_post_request_t *_edit_general_forum_topic_post_request_parseFromJSON(cJSON *_edit_general_forum_topic_post_requestJSON);

cJSON *_edit_general_forum_topic_post_request_convertToJSON(_edit_general_forum_topic_post_request_t *_edit_general_forum_topic_post_request);

#endif /* __edit_general_forum_topic_post_request_H_ */

