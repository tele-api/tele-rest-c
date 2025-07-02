/*
 * save_prepared_inline_message_request.h
 *
 * Request parameters for savePreparedInlineMessage
 */

#ifndef _save_prepared_inline_message_request_H_
#define _save_prepared_inline_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct save_prepared_inline_message_request_t save_prepared_inline_message_request_t;

#include "inline_query_result.h"



typedef struct save_prepared_inline_message_request_t {
    int user_id; //numeric
    struct inline_query_result_t *result; //model
    int allow_user_chats; //boolean
    int allow_bot_chats; //boolean
    int allow_group_chats; //boolean
    int allow_channel_chats; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} save_prepared_inline_message_request_t;

__attribute__((deprecated)) save_prepared_inline_message_request_t *save_prepared_inline_message_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
);

void save_prepared_inline_message_request_free(save_prepared_inline_message_request_t *save_prepared_inline_message_request);

save_prepared_inline_message_request_t *save_prepared_inline_message_request_parseFromJSON(cJSON *save_prepared_inline_message_requestJSON);

cJSON *save_prepared_inline_message_request_convertToJSON(save_prepared_inline_message_request_t *save_prepared_inline_message_request);

#endif /* _save_prepared_inline_message_request_H_ */

