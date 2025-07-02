/*
 * post_answer_web_app_query_request.h
 *
 * 
 */

#ifndef _post_answer_web_app_query_request_H_
#define _post_answer_web_app_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_answer_web_app_query_request_t post_answer_web_app_query_request_t;

#include "inline_query_result.h"



typedef struct post_answer_web_app_query_request_t {
    char *web_app_query_id; // string
    struct inline_query_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_answer_web_app_query_request_t;

__attribute__((deprecated)) post_answer_web_app_query_request_t *post_answer_web_app_query_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
);

void post_answer_web_app_query_request_free(post_answer_web_app_query_request_t *post_answer_web_app_query_request);

post_answer_web_app_query_request_t *post_answer_web_app_query_request_parseFromJSON(cJSON *post_answer_web_app_query_requestJSON);

cJSON *post_answer_web_app_query_request_convertToJSON(post_answer_web_app_query_request_t *post_answer_web_app_query_request);

#endif /* _post_answer_web_app_query_request_H_ */

