/*
 * answer_inline_query_request.h
 *
 * Request parameters for answerInlineQuery
 */

#ifndef _answer_inline_query_request_H_
#define _answer_inline_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_inline_query_request_t answer_inline_query_request_t;

#include "inline_query_result.h"
#include "inline_query_results_button.h"



typedef struct answer_inline_query_request_t {
    char *inline_query_id; // string
    list_t *results; //nonprimitive container
    int cache_time; //numeric
    int is_personal; //boolean
    char *next_offset; // string
    struct inline_query_results_button_t *button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} answer_inline_query_request_t;

__attribute__((deprecated)) answer_inline_query_request_t *answer_inline_query_request_create(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
);

void answer_inline_query_request_free(answer_inline_query_request_t *answer_inline_query_request);

answer_inline_query_request_t *answer_inline_query_request_parseFromJSON(cJSON *answer_inline_query_requestJSON);

cJSON *answer_inline_query_request_convertToJSON(answer_inline_query_request_t *answer_inline_query_request);

#endif /* _answer_inline_query_request_H_ */

