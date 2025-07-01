/*
 * _answer_callback_query_post_request.h
 *
 * 
 */

#ifndef __answer_callback_query_post_request_H_
#define __answer_callback_query_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _answer_callback_query_post_request_t _answer_callback_query_post_request_t;




typedef struct _answer_callback_query_post_request_t {
    char *callback_query_id; // string
    char *text; // string
    int show_alert; //boolean
    char *url; // string
    int cache_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _answer_callback_query_post_request_t;

__attribute__((deprecated)) _answer_callback_query_post_request_t *_answer_callback_query_post_request_create(
    char *callback_query_id,
    char *text,
    int show_alert,
    char *url,
    int cache_time
);

void _answer_callback_query_post_request_free(_answer_callback_query_post_request_t *_answer_callback_query_post_request);

_answer_callback_query_post_request_t *_answer_callback_query_post_request_parseFromJSON(cJSON *_answer_callback_query_post_requestJSON);

cJSON *_answer_callback_query_post_request_convertToJSON(_answer_callback_query_post_request_t *_answer_callback_query_post_request);

#endif /* __answer_callback_query_post_request_H_ */

