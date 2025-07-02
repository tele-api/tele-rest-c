/*
 * answer_inline_query_response.h
 *
 * 
 */

#ifndef _answer_inline_query_response_H_
#define _answer_inline_query_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_inline_query_response_t answer_inline_query_response_t;




typedef struct answer_inline_query_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} answer_inline_query_response_t;

__attribute__((deprecated)) answer_inline_query_response_t *answer_inline_query_response_create(
    int ok,
    int result
);

void answer_inline_query_response_free(answer_inline_query_response_t *answer_inline_query_response);

answer_inline_query_response_t *answer_inline_query_response_parseFromJSON(cJSON *answer_inline_query_responseJSON);

cJSON *answer_inline_query_response_convertToJSON(answer_inline_query_response_t *answer_inline_query_response);

#endif /* _answer_inline_query_response_H_ */

