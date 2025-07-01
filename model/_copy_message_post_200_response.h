/*
 * _copy_message_post_200_response.h
 *
 * 
 */

#ifndef __copy_message_post_200_response_H_
#define __copy_message_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _copy_message_post_200_response_t _copy_message_post_200_response_t;

#include "message_id.h"



typedef struct _copy_message_post_200_response_t {
    int ok; //boolean
    struct message_id_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _copy_message_post_200_response_t;

__attribute__((deprecated)) _copy_message_post_200_response_t *_copy_message_post_200_response_create(
    int ok,
    message_id_t *result
);

void _copy_message_post_200_response_free(_copy_message_post_200_response_t *_copy_message_post_200_response);

_copy_message_post_200_response_t *_copy_message_post_200_response_parseFromJSON(cJSON *_copy_message_post_200_responseJSON);

cJSON *_copy_message_post_200_response_convertToJSON(_copy_message_post_200_response_t *_copy_message_post_200_response);

#endif /* __copy_message_post_200_response_H_ */

