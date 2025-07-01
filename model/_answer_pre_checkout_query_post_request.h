/*
 * _answer_pre_checkout_query_post_request.h
 *
 * 
 */

#ifndef __answer_pre_checkout_query_post_request_H_
#define __answer_pre_checkout_query_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _answer_pre_checkout_query_post_request_t _answer_pre_checkout_query_post_request_t;




typedef struct _answer_pre_checkout_query_post_request_t {
    char *pre_checkout_query_id; // string
    int ok; //boolean
    char *error_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _answer_pre_checkout_query_post_request_t;

__attribute__((deprecated)) _answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_create(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
);

void _answer_pre_checkout_query_post_request_free(_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request);

_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request_parseFromJSON(cJSON *_answer_pre_checkout_query_post_requestJSON);

cJSON *_answer_pre_checkout_query_post_request_convertToJSON(_answer_pre_checkout_query_post_request_t *_answer_pre_checkout_query_post_request);

#endif /* __answer_pre_checkout_query_post_request_H_ */

