/*
 * answer_pre_checkout_query_request.h
 *
 * Request parameters for answerPreCheckoutQuery
 */

#ifndef _answer_pre_checkout_query_request_H_
#define _answer_pre_checkout_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_pre_checkout_query_request_t answer_pre_checkout_query_request_t;




typedef struct answer_pre_checkout_query_request_t {
    char *pre_checkout_query_id; // string
    int ok; //boolean
    char *error_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} answer_pre_checkout_query_request_t;

__attribute__((deprecated)) answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_create(
    char *pre_checkout_query_id,
    int ok,
    char *error_message
);

void answer_pre_checkout_query_request_free(answer_pre_checkout_query_request_t *answer_pre_checkout_query_request);

answer_pre_checkout_query_request_t *answer_pre_checkout_query_request_parseFromJSON(cJSON *answer_pre_checkout_query_requestJSON);

cJSON *answer_pre_checkout_query_request_convertToJSON(answer_pre_checkout_query_request_t *answer_pre_checkout_query_request);

#endif /* _answer_pre_checkout_query_request_H_ */

