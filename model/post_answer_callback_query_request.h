/*
 * post_answer_callback_query_request.h
 *
 * 
 */

#ifndef _post_answer_callback_query_request_H_
#define _post_answer_callback_query_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_answer_callback_query_request_t post_answer_callback_query_request_t;




typedef struct post_answer_callback_query_request_t {
    char *callback_query_id; // string
    char *text; // string
    int show_alert; //boolean
    char *url; // string
    int cache_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_answer_callback_query_request_t;

__attribute__((deprecated)) post_answer_callback_query_request_t *post_answer_callback_query_request_create(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
);

void post_answer_callback_query_request_free(post_answer_callback_query_request_t *post_answer_callback_query_request);

post_answer_callback_query_request_t *post_answer_callback_query_request_parseFromJSON(cJSON *post_answer_callback_query_requestJSON);

cJSON *post_answer_callback_query_request_convertToJSON(post_answer_callback_query_request_t *post_answer_callback_query_request);

#endif /* _post_answer_callback_query_request_H_ */

