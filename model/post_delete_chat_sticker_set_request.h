/*
 * post_delete_chat_sticker_set_request.h
 *
 * 
 */

#ifndef _post_delete_chat_sticker_set_request_H_
#define _post_delete_chat_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_delete_chat_sticker_set_request_t post_delete_chat_sticker_set_request_t;

#include "post_restrict_chat_member_request_chat_id.h"



typedef struct post_delete_chat_sticker_set_request_t {
    struct post_restrict_chat_member_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_delete_chat_sticker_set_request_t;

__attribute__((deprecated)) post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id
);

void post_delete_chat_sticker_set_request_free(post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request);

post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_parseFromJSON(cJSON *post_delete_chat_sticker_set_requestJSON);

cJSON *post_delete_chat_sticker_set_request_convertToJSON(post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request);

#endif /* _post_delete_chat_sticker_set_request_H_ */

