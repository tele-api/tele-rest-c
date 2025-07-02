/*
 * set_chat_sticker_set_request.h
 *
 * Request parameters for setChatStickerSet
 */

#ifndef _set_chat_sticker_set_request_H_
#define _set_chat_sticker_set_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_sticker_set_request_t set_chat_sticker_set_request_t;

#include "bot_command_scope_chat_chat_id.h"



typedef struct set_chat_sticker_set_request_t {
    struct bot_command_scope_chat_chat_id_t *chat_id; //model
    char *sticker_set_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_sticker_set_request_t;

__attribute__((deprecated)) set_chat_sticker_set_request_t *set_chat_sticker_set_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    char *sticker_set_name
);

void set_chat_sticker_set_request_free(set_chat_sticker_set_request_t *set_chat_sticker_set_request);

set_chat_sticker_set_request_t *set_chat_sticker_set_request_parseFromJSON(cJSON *set_chat_sticker_set_requestJSON);

cJSON *set_chat_sticker_set_request_convertToJSON(set_chat_sticker_set_request_t *set_chat_sticker_set_request);

#endif /* _set_chat_sticker_set_request_H_ */

