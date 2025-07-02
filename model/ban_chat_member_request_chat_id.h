/*
 * ban_chat_member_request_chat_id.h
 *
 * Unique identifier for the target group or username of the target supergroup or channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _ban_chat_member_request_chat_id_H_
#define _ban_chat_member_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ban_chat_member_request_chat_id_t ban_chat_member_request_chat_id_t;




typedef struct ban_chat_member_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ban_chat_member_request_chat_id_t;

__attribute__((deprecated)) ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_create(
);

void ban_chat_member_request_chat_id_free(ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id);

ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id_parseFromJSON(cJSON *ban_chat_member_request_chat_idJSON);

cJSON *ban_chat_member_request_chat_id_convertToJSON(ban_chat_member_request_chat_id_t *ban_chat_member_request_chat_id);

#endif /* _ban_chat_member_request_chat_id_H_ */

