/*
 * _edit_chat_invite_link_post_request.h
 *
 * 
 */

#ifndef __edit_chat_invite_link_post_request_H_
#define __edit_chat_invite_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_chat_invite_link_post_request_t _edit_chat_invite_link_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _edit_chat_invite_link_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *invite_link; // string
    char *name; // string
    int expire_date; //numeric
    int member_limit; //numeric
    int creates_join_request; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_chat_invite_link_post_request_t;

__attribute__((deprecated)) _edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
);

void _edit_chat_invite_link_post_request_free(_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request);

_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_parseFromJSON(cJSON *_edit_chat_invite_link_post_requestJSON);

cJSON *_edit_chat_invite_link_post_request_convertToJSON(_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request);

#endif /* __edit_chat_invite_link_post_request_H_ */

