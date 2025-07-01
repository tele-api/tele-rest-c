/*
 * _unban_chat_member_post_request.h
 *
 * 
 */

#ifndef __unban_chat_member_post_request_H_
#define __unban_chat_member_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _unban_chat_member_post_request_t _unban_chat_member_post_request_t;

#include "_ban_chat_member_post_request_chat_id.h"



typedef struct _unban_chat_member_post_request_t {
    struct _ban_chat_member_post_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    int only_if_banned; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _unban_chat_member_post_request_t;

__attribute__((deprecated)) _unban_chat_member_post_request_t *_unban_chat_member_post_request_create(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
);

void _unban_chat_member_post_request_free(_unban_chat_member_post_request_t *_unban_chat_member_post_request);

_unban_chat_member_post_request_t *_unban_chat_member_post_request_parseFromJSON(cJSON *_unban_chat_member_post_requestJSON);

cJSON *_unban_chat_member_post_request_convertToJSON(_unban_chat_member_post_request_t *_unban_chat_member_post_request);

#endif /* __unban_chat_member_post_request_H_ */

