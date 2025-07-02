/*
 * delete_chat_sticker_set_request.h
 *
 * Request parameters for deleteChatStickerSet
 */

#ifndef _delete_chat_sticker_set_request_H_
#define _delete_chat_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_chat_sticker_set_request_t delete_chat_sticker_set_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct delete_chat_sticker_set_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} delete_chat_sticker_set_request_t;

__attribute__((deprecated)) delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
);

void delete_chat_sticker_set_request_free(delete_chat_sticker_set_request_t *delete_chat_sticker_set_request);

delete_chat_sticker_set_request_t *delete_chat_sticker_set_request_parseFromJSON(cJSON *delete_chat_sticker_set_requestJSON);

cJSON *delete_chat_sticker_set_request_convertToJSON(delete_chat_sticker_set_request_t *delete_chat_sticker_set_request);

#endif /* _delete_chat_sticker_set_request_H_ */

