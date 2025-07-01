/*
 * _restrict_chat_member_post_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup (in the format &#x60;@supergroupusername&#x60;)
 */

#ifndef __restrict_chat_member_post_request_chat_id_H_
#define __restrict_chat_member_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _restrict_chat_member_post_request_chat_id_t _restrict_chat_member_post_request_chat_id_t;




typedef struct _restrict_chat_member_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _restrict_chat_member_post_request_chat_id_t;

__attribute__((deprecated)) _restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_create(
);

void _restrict_chat_member_post_request_chat_id_free(_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id);

_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_parseFromJSON(cJSON *_restrict_chat_member_post_request_chat_idJSON);

cJSON *_restrict_chat_member_post_request_chat_id_convertToJSON(_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id);

#endif /* __restrict_chat_member_post_request_chat_id_H_ */

