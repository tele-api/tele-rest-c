/*
 * _set_webhook_post_200_response.h
 *
 * 
 */

#ifndef __set_webhook_post_200_response_H_
#define __set_webhook_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_webhook_post_200_response_t _set_webhook_post_200_response_t;




typedef struct _set_webhook_post_200_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _set_webhook_post_200_response_t;

__attribute__((deprecated)) _set_webhook_post_200_response_t *_set_webhook_post_200_response_create(
    int ok,
    int result
);

void _set_webhook_post_200_response_free(_set_webhook_post_200_response_t *_set_webhook_post_200_response);

_set_webhook_post_200_response_t *_set_webhook_post_200_response_parseFromJSON(cJSON *_set_webhook_post_200_responseJSON);

cJSON *_set_webhook_post_200_response_convertToJSON(_set_webhook_post_200_response_t *_set_webhook_post_200_response);

#endif /* __set_webhook_post_200_response_H_ */

