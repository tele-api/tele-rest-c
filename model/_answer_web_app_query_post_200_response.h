/*
 * _answer_web_app_query_post_200_response.h
 *
 * 
 */

#ifndef __answer_web_app_query_post_200_response_H_
#define __answer_web_app_query_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _answer_web_app_query_post_200_response_t _answer_web_app_query_post_200_response_t;

#include "sent_web_app_message.h"



typedef struct _answer_web_app_query_post_200_response_t {
    int ok; //boolean
    struct sent_web_app_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _answer_web_app_query_post_200_response_t;

__attribute__((deprecated)) _answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_create(
    int ok,
    sent_web_app_message_t *result
);

void _answer_web_app_query_post_200_response_free(_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response);

_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response_parseFromJSON(cJSON *_answer_web_app_query_post_200_responseJSON);

cJSON *_answer_web_app_query_post_200_response_convertToJSON(_answer_web_app_query_post_200_response_t *_answer_web_app_query_post_200_response);

#endif /* __answer_web_app_query_post_200_response_H_ */

