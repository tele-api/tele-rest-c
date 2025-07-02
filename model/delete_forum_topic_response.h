/*
 * delete_forum_topic_response.h
 *
 * 
 */

#ifndef _delete_forum_topic_response_H_
#define _delete_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_forum_topic_response_t delete_forum_topic_response_t;




typedef struct delete_forum_topic_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_forum_topic_response_t;

__attribute__((deprecated)) delete_forum_topic_response_t *delete_forum_topic_response_create(
    int ok,
    int result
);

void delete_forum_topic_response_free(delete_forum_topic_response_t *delete_forum_topic_response);

delete_forum_topic_response_t *delete_forum_topic_response_parseFromJSON(cJSON *delete_forum_topic_responseJSON);

cJSON *delete_forum_topic_response_convertToJSON(delete_forum_topic_response_t *delete_forum_topic_response);

#endif /* _delete_forum_topic_response_H_ */

