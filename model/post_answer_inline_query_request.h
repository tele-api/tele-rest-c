/*
 * post_answer_inline_query_request.h
 *
 * 
 */

#ifndef _post_answer_inline_query_request_H_
#define _post_answer_inline_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_answer_inline_query_request_t post_answer_inline_query_request_t;

#include "inline_query_result.h"
#include "inline_query_results_button.h"



typedef struct post_answer_inline_query_request_t {
    char *inline_query_id; // string
    list_t *results; //nonprimitive container
    int cache_time; //numeric
    int is_personal; //boolean
    char *next_offset; // string
    struct inline_query_results_button_t *button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_answer_inline_query_request_t;

__attribute__((deprecated)) post_answer_inline_query_request_t *post_answer_inline_query_request_create(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
);

void post_answer_inline_query_request_free(post_answer_inline_query_request_t *post_answer_inline_query_request);

post_answer_inline_query_request_t *post_answer_inline_query_request_parseFromJSON(cJSON *post_answer_inline_query_requestJSON);

cJSON *post_answer_inline_query_request_convertToJSON(post_answer_inline_query_request_t *post_answer_inline_query_request);

#endif /* _post_answer_inline_query_request_H_ */

