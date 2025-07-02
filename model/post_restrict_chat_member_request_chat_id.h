/*
 * post_restrict_chat_member_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup (in the format &#x60;@supergroupusername&#x60;)
 */

#ifndef _post_restrict_chat_member_request_chat_id_H_
#define _post_restrict_chat_member_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_restrict_chat_member_request_chat_id_t post_restrict_chat_member_request_chat_id_t;




typedef struct post_restrict_chat_member_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_restrict_chat_member_request_chat_id_t;

__attribute__((deprecated)) post_restrict_chat_member_request_chat_id_t *post_restrict_chat_member_request_chat_id_create(
);

void post_restrict_chat_member_request_chat_id_free(post_restrict_chat_member_request_chat_id_t *post_restrict_chat_member_request_chat_id);

post_restrict_chat_member_request_chat_id_t *post_restrict_chat_member_request_chat_id_parseFromJSON(cJSON *post_restrict_chat_member_request_chat_idJSON);

cJSON *post_restrict_chat_member_request_chat_id_convertToJSON(post_restrict_chat_member_request_chat_id_t *post_restrict_chat_member_request_chat_id);

#endif /* _post_restrict_chat_member_request_chat_id_H_ */

