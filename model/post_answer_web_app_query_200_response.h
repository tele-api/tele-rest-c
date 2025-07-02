/*
 * post_answer_web_app_query_200_response.h
 *
 * 
 */

#ifndef _post_answer_web_app_query_200_response_H_
#define _post_answer_web_app_query_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_answer_web_app_query_200_response_t post_answer_web_app_query_200_response_t;

#include "sent_web_app_message.h"



typedef struct post_answer_web_app_query_200_response_t {
    int ok; //boolean
    struct sent_web_app_message_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_answer_web_app_query_200_response_t;

__attribute__((deprecated)) post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_create(
    int ok,
    sent_web_app_message_t *result
);

void post_answer_web_app_query_200_response_free(post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response);

post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response_parseFromJSON(cJSON *post_answer_web_app_query_200_responseJSON);

cJSON *post_answer_web_app_query_200_response_convertToJSON(post_answer_web_app_query_200_response_t *post_answer_web_app_query_200_response);

#endif /* _post_answer_web_app_query_200_response_H_ */

