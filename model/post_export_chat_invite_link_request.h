/*
 * post_export_chat_invite_link_request.h
 *
 * 
 */

#ifndef _post_export_chat_invite_link_request_H_
#define _post_export_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_export_chat_invite_link_request_t post_export_chat_invite_link_request_t;

#include "post_send_message_request_chat_id.h"



typedef struct post_export_chat_invite_link_request_t {
    struct post_send_message_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_export_chat_invite_link_request_t;

__attribute__((deprecated)) post_export_chat_invite_link_request_t *post_export_chat_invite_link_request_create(
    post_send_message_request_chat_id_t *chat_id
);

void post_export_chat_invite_link_request_free(post_export_chat_invite_link_request_t *post_export_chat_invite_link_request);

post_export_chat_invite_link_request_t *post_export_chat_invite_link_request_parseFromJSON(cJSON *post_export_chat_invite_link_requestJSON);

cJSON *post_export_chat_invite_link_request_convertToJSON(post_export_chat_invite_link_request_t *post_export_chat_invite_link_request);

#endif /* _post_export_chat_invite_link_request_H_ */

