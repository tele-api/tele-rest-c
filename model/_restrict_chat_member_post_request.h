/*
 * _restrict_chat_member_post_request.h
 *
 * 
 */

#ifndef __restrict_chat_member_post_request_H_
#define __restrict_chat_member_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _restrict_chat_member_post_request_t _restrict_chat_member_post_request_t;

#include "_restrict_chat_member_post_request_chat_id.h"
#include "chat_permissions.h"



typedef struct _restrict_chat_member_post_request_t {
    struct _restrict_chat_member_post_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    struct chat_permissions_t *permissions; //model
    int use_independent_chat_permissions; //boolean
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _restrict_chat_member_post_request_t;

__attribute__((deprecated)) _restrict_chat_member_post_request_t *_restrict_chat_member_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    chat_permissions_t *permissions,
    int use_independent_chat_permissions,
    int until_date
);

void _restrict_chat_member_post_request_free(_restrict_chat_member_post_request_t *_restrict_chat_member_post_request);

_restrict_chat_member_post_request_t *_restrict_chat_member_post_request_parseFromJSON(cJSON *_restrict_chat_member_post_requestJSON);

cJSON *_restrict_chat_member_post_request_convertToJSON(_restrict_chat_member_post_request_t *_restrict_chat_member_post_request);

#endif /* __restrict_chat_member_post_request_H_ */

