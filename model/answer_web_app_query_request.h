/*
 * answer_web_app_query_request.h
 *
 * Request parameters for answerWebAppQuery
 */

#ifndef _answer_web_app_query_request_H_
#define _answer_web_app_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_web_app_query_request_t answer_web_app_query_request_t;

#include "inline_query_result.h"



typedef struct answer_web_app_query_request_t {
    char *web_app_query_id; // string
    struct inline_query_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} answer_web_app_query_request_t;

__attribute__((deprecated)) answer_web_app_query_request_t *answer_web_app_query_request_create(
    char *web_app_query_id,
    inline_query_result_t *result
);

void answer_web_app_query_request_free(answer_web_app_query_request_t *answer_web_app_query_request);

answer_web_app_query_request_t *answer_web_app_query_request_parseFromJSON(cJSON *answer_web_app_query_requestJSON);

cJSON *answer_web_app_query_request_convertToJSON(answer_web_app_query_request_t *answer_web_app_query_request);

#endif /* _answer_web_app_query_request_H_ */

