/*
 * post_save_prepared_inline_message_request.h
 *
 * 
 */

#ifndef _post_save_prepared_inline_message_request_H_
#define _post_save_prepared_inline_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_save_prepared_inline_message_request_t post_save_prepared_inline_message_request_t;

#include "inline_query_result.h"



typedef struct post_save_prepared_inline_message_request_t {
    int user_id; //numeric
    struct inline_query_result_t *result; //model
    int allow_user_chats; //boolean
    int allow_bot_chats; //boolean
    int allow_group_chats; //boolean
    int allow_channel_chats; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_save_prepared_inline_message_request_t;

__attribute__((deprecated)) post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
);

void post_save_prepared_inline_message_request_free(post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request);

post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_parseFromJSON(cJSON *post_save_prepared_inline_message_requestJSON);

cJSON *post_save_prepared_inline_message_request_convertToJSON(post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request);

#endif /* _post_save_prepared_inline_message_request_H_ */

