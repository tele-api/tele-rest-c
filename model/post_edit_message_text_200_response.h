/*
 * post_edit_message_text_200_response.h
 *
 * 
 */

#ifndef _post_edit_message_text_200_response_H_
#define _post_edit_message_text_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_message_text_200_response_t post_edit_message_text_200_response_t;

#include "post_edit_message_text_200_response_result.h"



typedef struct post_edit_message_text_200_response_t {
    int ok; //boolean
    struct post_edit_message_text_200_response_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_message_text_200_response_t;

__attribute__((deprecated)) post_edit_message_text_200_response_t *post_edit_message_text_200_response_create(
    int ok,
    post_edit_message_text_200_response_result_t *result
);

void post_edit_message_text_200_response_free(post_edit_message_text_200_response_t *post_edit_message_text_200_response);

post_edit_message_text_200_response_t *post_edit_message_text_200_response_parseFromJSON(cJSON *post_edit_message_text_200_responseJSON);

cJSON *post_edit_message_text_200_response_convertToJSON(post_edit_message_text_200_response_t *post_edit_message_text_200_response);

#endif /* _post_edit_message_text_200_response_H_ */

