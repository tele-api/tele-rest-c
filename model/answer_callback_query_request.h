/*
 * answer_callback_query_request.h
 *
 * Request parameters for answerCallbackQuery
 */

#ifndef _answer_callback_query_request_H_
#define _answer_callback_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_callback_query_request_t answer_callback_query_request_t;




typedef struct answer_callback_query_request_t {
    char *callback_query_id; // string
    char *text; // string
    int show_alert; //boolean
    char *url; // string
    int cache_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} answer_callback_query_request_t;

__attribute__((deprecated)) answer_callback_query_request_t *answer_callback_query_request_create(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
);

void answer_callback_query_request_free(answer_callback_query_request_t *answer_callback_query_request);

answer_callback_query_request_t *answer_callback_query_request_parseFromJSON(cJSON *answer_callback_query_requestJSON);

cJSON *answer_callback_query_request_convertToJSON(answer_callback_query_request_t *answer_callback_query_request);

#endif /* _answer_callback_query_request_H_ */

