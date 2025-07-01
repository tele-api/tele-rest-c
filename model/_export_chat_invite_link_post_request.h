/*
 * _export_chat_invite_link_post_request.h
 *
 * 
 */

#ifndef __export_chat_invite_link_post_request_H_
#define __export_chat_invite_link_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _export_chat_invite_link_post_request_t _export_chat_invite_link_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _export_chat_invite_link_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _export_chat_invite_link_post_request_t;

__attribute__((deprecated)) _export_chat_invite_link_post_request_t *_export_chat_invite_link_post_request_create(
    _send_message_post_request_chat_id_t *chat_id
);

void _export_chat_invite_link_post_request_free(_export_chat_invite_link_post_request_t *_export_chat_invite_link_post_request);

_export_chat_invite_link_post_request_t *_export_chat_invite_link_post_request_parseFromJSON(cJSON *_export_chat_invite_link_post_requestJSON);

cJSON *_export_chat_invite_link_post_request_convertToJSON(_export_chat_invite_link_post_request_t *_export_chat_invite_link_post_request);

#endif /* __export_chat_invite_link_post_request_H_ */

