/*
 * save_prepared_inline_message_response.h
 *
 * 
 */

#ifndef _save_prepared_inline_message_response_H_
#define _save_prepared_inline_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct save_prepared_inline_message_response_t save_prepared_inline_message_response_t;

#include "prepared_inline_message.h"



typedef struct save_prepared_inline_message_response_t {
    int ok; //boolean
    struct prepared_inline_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} save_prepared_inline_message_response_t;

__attribute__((deprecated)) save_prepared_inline_message_response_t *save_prepared_inline_message_response_create(
    int ok,
    prepared_inline_message_t *result
);

void save_prepared_inline_message_response_free(save_prepared_inline_message_response_t *save_prepared_inline_message_response);

save_prepared_inline_message_response_t *save_prepared_inline_message_response_parseFromJSON(cJSON *save_prepared_inline_message_responseJSON);

cJSON *save_prepared_inline_message_response_convertToJSON(save_prepared_inline_message_response_t *save_prepared_inline_message_response);

#endif /* _save_prepared_inline_message_response_H_ */

