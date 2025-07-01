/*
 * _save_prepared_inline_message_post_200_response.h
 *
 * 
 */

#ifndef __save_prepared_inline_message_post_200_response_H_
#define __save_prepared_inline_message_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _save_prepared_inline_message_post_200_response_t _save_prepared_inline_message_post_200_response_t;

#include "prepared_inline_message.h"



typedef struct _save_prepared_inline_message_post_200_response_t {
    int ok; //boolean
    struct prepared_inline_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _save_prepared_inline_message_post_200_response_t;

__attribute__((deprecated)) _save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_create(
    int ok,
    prepared_inline_message_t *result
);

void _save_prepared_inline_message_post_200_response_free(_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response);

_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response_parseFromJSON(cJSON *_save_prepared_inline_message_post_200_responseJSON);

cJSON *_save_prepared_inline_message_post_200_response_convertToJSON(_save_prepared_inline_message_post_200_response_t *_save_prepared_inline_message_post_200_response);

#endif /* __save_prepared_inline_message_post_200_response_H_ */

