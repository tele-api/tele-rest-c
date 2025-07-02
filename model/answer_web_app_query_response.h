/*
 * answer_web_app_query_response.h
 *
 * 
 */

#ifndef _answer_web_app_query_response_H_
#define _answer_web_app_query_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct answer_web_app_query_response_t answer_web_app_query_response_t;

#include "sent_web_app_message.h"



typedef struct answer_web_app_query_response_t {
    int ok; //boolean
    struct sent_web_app_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} answer_web_app_query_response_t;

__attribute__((deprecated)) answer_web_app_query_response_t *answer_web_app_query_response_create(
    int ok,
    sent_web_app_message_t *result
);

void answer_web_app_query_response_free(answer_web_app_query_response_t *answer_web_app_query_response);

answer_web_app_query_response_t *answer_web_app_query_response_parseFromJSON(cJSON *answer_web_app_query_responseJSON);

cJSON *answer_web_app_query_response_convertToJSON(answer_web_app_query_response_t *answer_web_app_query_response);

#endif /* _answer_web_app_query_response_H_ */

