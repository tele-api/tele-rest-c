/*
 * _edit_message_text_post_request_chat_id.h
 *
 * Required if *inline\\_message\\_id* is not specified. Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __edit_message_text_post_request_chat_id_H_
#define __edit_message_text_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_message_text_post_request_chat_id_t _edit_message_text_post_request_chat_id_t;




typedef struct _edit_message_text_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_message_text_post_request_chat_id_t;

__attribute__((deprecated)) _edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_create(
);

void _edit_message_text_post_request_chat_id_free(_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id);

_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_parseFromJSON(cJSON *_edit_message_text_post_request_chat_idJSON);

cJSON *_edit_message_text_post_request_chat_id_convertToJSON(_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id);

#endif /* __edit_message_text_post_request_chat_id_H_ */

