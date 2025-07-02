/*
 * post_answer_shipping_query_request.h
 *
 * 
 */

#ifndef _post_answer_shipping_query_request_H_
#define _post_answer_shipping_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_answer_shipping_query_request_t post_answer_shipping_query_request_t;

#include "shipping_option.h"



typedef struct post_answer_shipping_query_request_t {
    char *shipping_query_id; // string
    int ok; //boolean
    list_t *shipping_options; //nonprimitive container
    char *error_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_answer_shipping_query_request_t;

__attribute__((deprecated)) post_answer_shipping_query_request_t *post_answer_shipping_query_request_create(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
);

void post_answer_shipping_query_request_free(post_answer_shipping_query_request_t *post_answer_shipping_query_request);

post_answer_shipping_query_request_t *post_answer_shipping_query_request_parseFromJSON(cJSON *post_answer_shipping_query_requestJSON);

cJSON *post_answer_shipping_query_request_convertToJSON(post_answer_shipping_query_request_t *post_answer_shipping_query_request);

#endif /* _post_answer_shipping_query_request_H_ */

