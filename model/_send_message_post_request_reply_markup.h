/*
 * _send_message_post_request_reply_markup.h
 *
 * Additional interface options. A JSON-serialized object for an [inline keyboard](https://core.telegram.org/bots/features#inline-keyboards), [custom reply keyboard](https://core.telegram.org/bots/features#keyboards), instructions to remove a reply keyboard or to force a reply from the user
 */

#ifndef __send_message_post_request_reply_markup_H_
#define __send_message_post_request_reply_markup_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_message_post_request_reply_markup_t _send_message_post_request_reply_markup_t;

#include "force_reply.h"
#include "inline_keyboard_button.h"
#include "inline_keyboard_markup.h"
#include "keyboard_button.h"
#include "reply_keyboard_markup.h"
#include "reply_keyboard_remove.h"



typedef struct _send_message_post_request_reply_markup_t {
    list_t *inline_keyboard; //primitive container
    list_t *keyboard; //primitive container
    int remove_keyboard; //boolean
    int force_reply; //boolean
    int is_persistent; //boolean
    int resize_keyboard; //boolean
    int one_time_keyboard; //boolean
    char *input_field_placeholder; // string
    int selective; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _send_message_post_request_reply_markup_t;

__attribute__((deprecated)) _send_message_post_request_reply_markup_t *_send_message_post_request_reply_markup_create(
    list_t *inline_keyboard,
    list_t *keyboard,
    int remove_keyboard,
    int force_reply,
    int is_persistent,
    int resize_keyboard,
    int one_time_keyboard,
    char *input_field_placeholder,
    int selective
);

void _send_message_post_request_reply_markup_free(_send_message_post_request_reply_markup_t *_send_message_post_request_reply_markup);

_send_message_post_request_reply_markup_t *_send_message_post_request_reply_markup_parseFromJSON(cJSON *_send_message_post_request_reply_markupJSON);

cJSON *_send_message_post_request_reply_markup_convertToJSON(_send_message_post_request_reply_markup_t *_send_message_post_request_reply_markup);

#endif /* __send_message_post_request_reply_markup_H_ */

