/*
 * post_leave_chat_request_chat_id.h
 *
 * Unique identifier for the target chat or username of the target supergroup or channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _post_leave_chat_request_chat_id_H_
#define _post_leave_chat_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_leave_chat_request_chat_id_t post_leave_chat_request_chat_id_t;




typedef struct post_leave_chat_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} post_leave_chat_request_chat_id_t;

__attribute__((deprecated)) post_leave_chat_request_chat_id_t *post_leave_chat_request_chat_id_create(
);

void post_leave_chat_request_chat_id_free(post_leave_chat_request_chat_id_t *post_leave_chat_request_chat_id);

post_leave_chat_request_chat_id_t *post_leave_chat_request_chat_id_parseFromJSON(cJSON *post_leave_chat_request_chat_idJSON);

cJSON *post_leave_chat_request_chat_id_convertToJSON(post_leave_chat_request_chat_id_t *post_leave_chat_request_chat_id);

#endif /* _post_leave_chat_request_chat_id_H_ */

