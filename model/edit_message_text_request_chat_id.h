/*
 * edit_message_text_request_chat_id.h
 *
 * Required if *inline\\_message\\_id* is not specified. Unique identifier for the target chat or username of the target channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _edit_message_text_request_chat_id_H_
#define _edit_message_text_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_message_text_request_chat_id_t edit_message_text_request_chat_id_t;




typedef struct edit_message_text_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} edit_message_text_request_chat_id_t;

__attribute__((deprecated)) edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_create(
);

void edit_message_text_request_chat_id_free(edit_message_text_request_chat_id_t *edit_message_text_request_chat_id);

edit_message_text_request_chat_id_t *edit_message_text_request_chat_id_parseFromJSON(cJSON *edit_message_text_request_chat_idJSON);

cJSON *edit_message_text_request_chat_id_convertToJSON(edit_message_text_request_chat_id_t *edit_message_text_request_chat_id);

#endif /* _edit_message_text_request_chat_id_H_ */

