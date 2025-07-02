/*
 * edit_message_reply_markup_request.h
 *
 * Request parameters for editMessageReplyMarkup
 */

#ifndef _edit_message_reply_markup_request_H_
#define _edit_message_reply_markup_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_message_reply_markup_request_t edit_message_reply_markup_request_t;

#include "edit_message_text_request_chat_id.h"
#include "inline_keyboard_markup.h"



typedef struct edit_message_reply_markup_request_t {
    char *business_connection_id; // string
    struct edit_message_text_request_chat_id_t *chat_id; //model
    int message_id; //numeric
    char *inline_message_id; // string
    struct inline_keyboard_markup_t *reply_markup; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_message_reply_markup_request_t;

__attribute__((deprecated)) edit_message_reply_markup_request_t *edit_message_reply_markup_request_create(
    char *business_connection_id,
    edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    inline_keyboard_markup_t *reply_markup
);

void edit_message_reply_markup_request_free(edit_message_reply_markup_request_t *edit_message_reply_markup_request);

edit_message_reply_markup_request_t *edit_message_reply_markup_request_parseFromJSON(cJSON *edit_message_reply_markup_requestJSON);

cJSON *edit_message_reply_markup_request_convertToJSON(edit_message_reply_markup_request_t *edit_message_reply_markup_request);

#endif /* _edit_message_reply_markup_request_H_ */

