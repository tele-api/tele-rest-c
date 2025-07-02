/*
 * post_edit_chat_invite_link_request.h
 *
 * 
 */

#ifndef _post_edit_chat_invite_link_request_H_
#define _post_edit_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_chat_invite_link_request_t post_edit_chat_invite_link_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_edit_chat_invite_link_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model
    char *invite_link; // string
    char *name; // string
    int expire_date; //numeric
    int member_limit; //numeric
    int creates_join_request; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_chat_invite_link_request_t;

__attribute__((deprecated)) post_edit_chat_invite_link_request_t *post_edit_chat_invite_link_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
);

void post_edit_chat_invite_link_request_free(post_edit_chat_invite_link_request_t *post_edit_chat_invite_link_request);

post_edit_chat_invite_link_request_t *post_edit_chat_invite_link_request_parseFromJSON(cJSON *post_edit_chat_invite_link_requestJSON);

cJSON *post_edit_chat_invite_link_request_convertToJSON(post_edit_chat_invite_link_request_t *post_edit_chat_invite_link_request);

#endif /* _post_edit_chat_invite_link_request_H_ */

