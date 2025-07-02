/*
 * post_save_prepared_inline_message_200_response.h
 *
 * 
 */

#ifndef _post_save_prepared_inline_message_200_response_H_
#define _post_save_prepared_inline_message_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_save_prepared_inline_message_200_response_t post_save_prepared_inline_message_200_response_t;

#include "prepared_inline_message.h"



typedef struct post_save_prepared_inline_message_200_response_t {
    int ok; //boolean
    struct prepared_inline_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_save_prepared_inline_message_200_response_t;

__attribute__((deprecated)) post_save_prepared_inline_message_200_response_t *post_save_prepared_inline_message_200_response_create(
    int ok,
    prepared_inline_message_t *result
);

void post_save_prepared_inline_message_200_response_free(post_save_prepared_inline_message_200_response_t *post_save_prepared_inline_message_200_response);

post_save_prepared_inline_message_200_response_t *post_save_prepared_inline_message_200_response_parseFromJSON(cJSON *post_save_prepared_inline_message_200_responseJSON);

cJSON *post_save_prepared_inline_message_200_response_convertToJSON(post_save_prepared_inline_message_200_response_t *post_save_prepared_inline_message_200_response);

#endif /* _post_save_prepared_inline_message_200_response_H_ */

