/*
 * _create_chat_invite_link_post_request.h
 *
 * 
 */

#ifndef __create_chat_invite_link_post_request_H_
#define __create_chat_invite_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _create_chat_invite_link_post_request_t _create_chat_invite_link_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _create_chat_invite_link_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
    char *name; // string
    int expire_date; //numeric
    int member_limit; //numeric
    int creates_join_request; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _create_chat_invite_link_post_request_t;

__attribute__((deprecated)) _create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
);

void _create_chat_invite_link_post_request_free(_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request);

_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_parseFromJSON(cJSON *_create_chat_invite_link_post_requestJSON);

cJSON *_create_chat_invite_link_post_request_convertToJSON(_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request);

#endif /* __create_chat_invite_link_post_request_H_ */

