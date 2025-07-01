/*
 * _answer_inline_query_post_request.h
 *
 * 
 */

#ifndef __answer_inline_query_post_request_H_
#define __answer_inline_query_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _answer_inline_query_post_request_t _answer_inline_query_post_request_t;

#include "inline_query_result.h"
#include "inline_query_results_button.h"



typedef struct _answer_inline_query_post_request_t {
    char *inline_query_id; // string
    list_t *results; //nonprimitive container
    int cache_time; //numeric
    int is_personal; //boolean
    char *next_offset; // string
    struct inline_query_results_button_t *button; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _answer_inline_query_post_request_t;

__attribute__((deprecated)) _answer_inline_query_post_request_t *_answer_inline_query_post_request_create(
    char *inline_query_id,
    list_t *results,
    int cache_time,
    int is_personal,
    char *next_offset,
    inline_query_results_button_t *button
);

void _answer_inline_query_post_request_free(_answer_inline_query_post_request_t *_answer_inline_query_post_request);

_answer_inline_query_post_request_t *_answer_inline_query_post_request_parseFromJSON(cJSON *_answer_inline_query_post_requestJSON);

cJSON *_answer_inline_query_post_request_convertToJSON(_answer_inline_query_post_request_t *_answer_inline_query_post_request);

#endif /* __answer_inline_query_post_request_H_ */

