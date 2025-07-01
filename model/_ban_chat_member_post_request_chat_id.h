/*
 * _ban_chat_member_post_request_chat_id.h
 *
 * Unique identifier for the target group or username of the target supergroup or channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __ban_chat_member_post_request_chat_id_H_
#define __ban_chat_member_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _ban_chat_member_post_request_chat_id_t _ban_chat_member_post_request_chat_id_t;




typedef struct _ban_chat_member_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _ban_chat_member_post_request_chat_id_t;

__attribute__((deprecated)) _ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_create(
);

void _ban_chat_member_post_request_chat_id_free(_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id);

_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_parseFromJSON(cJSON *_ban_chat_member_post_request_chat_idJSON);

cJSON *_ban_chat_member_post_request_chat_id_convertToJSON(_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id);

#endif /* __ban_chat_member_post_request_chat_id_H_ */

