/*
 * post_unban_chat_member_request.h
 *
 * 
 */

#ifndef _post_unban_chat_member_request_H_
#define _post_unban_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_unban_chat_member_request_t post_unban_chat_member_request_t;

#include "post_ban_chat_member_request_chat_id.h"



typedef struct post_unban_chat_member_request_t {
    struct post_ban_chat_member_request_chat_id_t *chat_id; //model
    int user_id; //numeric
    int only_if_banned; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_unban_chat_member_request_t;

__attribute__((deprecated)) post_unban_chat_member_request_t *post_unban_chat_member_request_create(
    post_ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
);

void post_unban_chat_member_request_free(post_unban_chat_member_request_t *post_unban_chat_member_request);

post_unban_chat_member_request_t *post_unban_chat_member_request_parseFromJSON(cJSON *post_unban_chat_member_requestJSON);

cJSON *post_unban_chat_member_request_convertToJSON(post_unban_chat_member_request_t *post_unban_chat_member_request);

#endif /* _post_unban_chat_member_request_H_ */

