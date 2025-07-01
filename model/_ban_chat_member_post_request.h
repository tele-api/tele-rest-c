/*
 * _ban_chat_member_post_request.h
 *
 * 
 */

#ifndef __ban_chat_member_post_request_H_
#define __ban_chat_member_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ban_chat_member_post_request_t _ban_chat_member_post_request_t;

#include "_ban_chat_member_post_request_chat_id.h"



typedef struct _ban_chat_member_post_request_t {
    struct _ban_chat_member_post_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    int until_date; //numeric
    int revoke_messages; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _ban_chat_member_post_request_t;

__attribute__((deprecated)) _ban_chat_member_post_request_t *_ban_chat_member_post_request_create(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
);

void _ban_chat_member_post_request_free(_ban_chat_member_post_request_t *_ban_chat_member_post_request);

_ban_chat_member_post_request_t *_ban_chat_member_post_request_parseFromJSON(cJSON *_ban_chat_member_post_requestJSON);

cJSON *_ban_chat_member_post_request_convertToJSON(_ban_chat_member_post_request_t *_ban_chat_member_post_request);

#endif /* __ban_chat_member_post_request_H_ */

