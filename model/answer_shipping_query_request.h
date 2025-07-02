/*
 * answer_shipping_query_request.h
 *
 * Request parameters for answerShippingQuery
 */

#ifndef _answer_shipping_query_request_H_
#define _answer_shipping_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_shipping_query_request_t answer_shipping_query_request_t;

#include "shipping_option.h"



typedef struct answer_shipping_query_request_t {
    char *shipping_query_id; // string
    int ok; //boolean
    list_t *shipping_options; //nonprimitive container
    char *error_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} answer_shipping_query_request_t;

__attribute__((deprecated)) answer_shipping_query_request_t *answer_shipping_query_request_create(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
);

void answer_shipping_query_request_free(answer_shipping_query_request_t *answer_shipping_query_request);

answer_shipping_query_request_t *answer_shipping_query_request_parseFromJSON(cJSON *answer_shipping_query_requestJSON);

cJSON *answer_shipping_query_request_convertToJSON(answer_shipping_query_request_t *answer_shipping_query_request);

#endif /* _answer_shipping_query_request_H_ */

