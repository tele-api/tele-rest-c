/*
 * export_chat_invite_link_request.h
 *
 * Request parameters for exportChatInviteLink
 */

#ifndef _export_chat_invite_link_request_H_
#define _export_chat_invite_link_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct export_chat_invite_link_request_t export_chat_invite_link_request_t;

#include "send_message_request_chat_id.h"



typedef struct export_chat_invite_link_request_t {
    struct send_message_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} export_chat_invite_link_request_t;

__attribute__((deprecated)) export_chat_invite_link_request_t *export_chat_invite_link_request_create(
    send_message_request_chat_id_t *chat_id
);

void export_chat_invite_link_request_free(export_chat_invite_link_request_t *export_chat_invite_link_request);

export_chat_invite_link_request_t *export_chat_invite_link_request_parseFromJSON(cJSON *export_chat_invite_link_requestJSON);

cJSON *export_chat_invite_link_request_convertToJSON(export_chat_invite_link_request_t *export_chat_invite_link_request);

#endif /* _export_chat_invite_link_request_H_ */

