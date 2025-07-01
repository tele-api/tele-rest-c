/*
 * _edit_message_text_post_200_response.h
 *
 * 
 */

#ifndef __edit_message_text_post_200_response_H_
#define __edit_message_text_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_message_text_post_200_response_t _edit_message_text_post_200_response_t;

#include "_edit_message_text_post_200_response_result.h"



typedef struct _edit_message_text_post_200_response_t {
    int ok; //boolean
    struct _edit_message_text_post_200_response_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_message_text_post_200_response_t;

__attribute__((deprecated)) _edit_message_text_post_200_response_t *_edit_message_text_post_200_response_create(
    int ok,
    _edit_message_text_post_200_response_result_t *result
);

void _edit_message_text_post_200_response_free(_edit_message_text_post_200_response_t *_edit_message_text_post_200_response);

_edit_message_text_post_200_response_t *_edit_message_text_post_200_response_parseFromJSON(cJSON *_edit_message_text_post_200_responseJSON);

cJSON *_edit_message_text_post_200_response_convertToJSON(_edit_message_text_post_200_response_t *_edit_message_text_post_200_response);

#endif /* __edit_message_text_post_200_response_H_ */

