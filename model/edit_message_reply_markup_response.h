/*
 * edit_message_reply_markup_response.h
 *
 * 
 */

#ifndef _edit_message_reply_markup_response_H_
#define _edit_message_reply_markup_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_message_reply_markup_response_t edit_message_reply_markup_response_t;

#include "edit_message_text_response_result.h"



typedef struct edit_message_reply_markup_response_t {
    int ok; //boolean
    struct edit_message_text_response_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} edit_message_reply_markup_response_t;

__attribute__((deprecated)) edit_message_reply_markup_response_t *edit_message_reply_markup_response_create(
    int ok,
    edit_message_text_response_result_t *result
);

void edit_message_reply_markup_response_free(edit_message_reply_markup_response_t *edit_message_reply_markup_response);

edit_message_reply_markup_response_t *edit_message_reply_markup_response_parseFromJSON(cJSON *edit_message_reply_markup_responseJSON);

cJSON *edit_message_reply_markup_response_convertToJSON(edit_message_reply_markup_response_t *edit_message_reply_markup_response);

#endif /* _edit_message_reply_markup_response_H_ */

