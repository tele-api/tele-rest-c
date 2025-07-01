/*
 * _answer_web_app_query_post_request.h
 *
 * 
 */

#ifndef __answer_web_app_query_post_request_H_
#define __answer_web_app_query_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _answer_web_app_query_post_request_t _answer_web_app_query_post_request_t;

#include "inline_query_result.h"



typedef struct _answer_web_app_query_post_request_t {
    char *web_app_query_id; // string
    struct inline_query_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _answer_web_app_query_post_request_t;

__attribute__((deprecated)) _answer_web_app_query_post_request_t *_answer_web_app_query_post_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
);

void _answer_web_app_query_post_request_free(_answer_web_app_query_post_request_t *_answer_web_app_query_post_request);

_answer_web_app_query_post_request_t *_answer_web_app_query_post_request_parseFromJSON(cJSON *_answer_web_app_query_post_requestJSON);

cJSON *_answer_web_app_query_post_request_convertToJSON(_answer_web_app_query_post_request_t *_answer_web_app_query_post_request);

#endif /* __answer_web_app_query_post_request_H_ */

