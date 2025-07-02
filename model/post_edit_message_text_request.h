/*
 * post_edit_message_text_request.h
 *
 * 
 */

#ifndef _post_edit_message_text_request_H_
#define _post_edit_message_text_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_message_text_request_t post_edit_message_text_request_t;

#include "inline_keyboard_markup.h"
#include "link_preview_options.h"
#include "message_entity.h"
#include "post_edit_message_text_request_chat_id.h"



typedef struct post_edit_message_text_request_t {
    char *text; // string
    char *business_connection_id; // string
    struct post_edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    char *parse_mode; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_message_text_request_t;

__attribute__((deprecated)) post_edit_message_text_request_t *post_edit_message_text_request_create(
    char *text,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
);

void post_edit_message_text_request_free(post_edit_message_text_request_t *post_edit_message_text_request);

post_edit_message_text_request_t *post_edit_message_text_request_parseFromJSON(cJSON *post_edit_message_text_requestJSON);

cJSON *post_edit_message_text_request_convertToJSON(post_edit_message_text_request_t *post_edit_message_text_request);

#endif /* _post_edit_message_text_request_H_ */

