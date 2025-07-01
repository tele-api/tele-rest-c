/*
 * _save_prepared_inline_message_post_request.h
 *
 * 
 */

#ifndef __save_prepared_inline_message_post_request_H_
#define __save_prepared_inline_message_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _save_prepared_inline_message_post_request_t _save_prepared_inline_message_post_request_t;

#include "inline_query_result.h"



typedef struct _save_prepared_inline_message_post_request_t {
    int user_id; //numeric
    struct inline_query_result_t *result; //model
    int allow_user_chats; //boolean
    int allow_bot_chats; //boolean
    int allow_group_chats; //boolean
    int allow_channel_chats; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _save_prepared_inline_message_post_request_t;

__attribute__((deprecated)) _save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
);

void _save_prepared_inline_message_post_request_free(_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request);

_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_parseFromJSON(cJSON *_save_prepared_inline_message_post_requestJSON);

cJSON *_save_prepared_inline_message_post_request_convertToJSON(_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request);

#endif /* __save_prepared_inline_message_post_request_H_ */

