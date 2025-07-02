/*
 * edit_message_text_request.h
 *
 * Request parameters for editMessageText
 */

#ifndef _edit_message_text_request_H_
#define _edit_message_text_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_message_text_request_t edit_message_text_request_t;

#include "edit_message_text_request_chat_id.h"
#include "inline_keyboard_markup.h"
#include "link_preview_options.h"
#include "message_entity.h"



typedef struct edit_message_text_request_t {
    char *text; // string
    char *business_connection_id; // string
    struct edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    char *parse_mode; // string
    list_t *entities; //nonprimitive container
    struct link_preview_options_t *link_preview_options; //model
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_message_text_request_t;

__attribute__((deprecated)) edit_message_text_request_t *edit_message_text_request_create(
    char *text,
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options,
    inline_keyboard_markup_t *reply_markup
);

void edit_message_text_request_free(edit_message_text_request_t *edit_message_text_request);

edit_message_text_request_t *edit_message_text_request_parseFromJSON(cJSON *edit_message_text_requestJSON);

cJSON *edit_message_text_request_convertToJSON(edit_message_text_request_t *edit_message_text_request);

#endif /* _edit_message_text_request_H_ */

