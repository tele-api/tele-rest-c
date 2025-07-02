/*
 * post_edit_message_caption_request.h
 *
 * 
 */

#ifndef _post_edit_message_caption_request_H_
#define _post_edit_message_caption_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_message_caption_request_t post_edit_message_caption_request_t;

#include "inline_keyboard_markup.h"
#include "message_entity.h"
#include "post_edit_message_text_request_chat_id.h"



typedef struct post_edit_message_caption_request_t {
    char *business_connection_id; // string
    struct post_edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    char *caption; // string
    char *parse_mode; // string
    list_t *caption_entities; //nonprimitive container
    int show_caption_above_media; //boolean
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_message_caption_request_t;

__attribute__((deprecated)) post_edit_message_caption_request_t *post_edit_message_caption_request_create(
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    int show_caption_above_media,
    inline_keyboard_markup_t *reply_markup
);

void post_edit_message_caption_request_free(post_edit_message_caption_request_t *post_edit_message_caption_request);

post_edit_message_caption_request_t *post_edit_message_caption_request_parseFromJSON(cJSON *post_edit_message_caption_requestJSON);

cJSON *post_edit_message_caption_request_convertToJSON(post_edit_message_caption_request_t *post_edit_message_caption_request);

#endif /* _post_edit_message_caption_request_H_ */

