/*
 * reopen_forum_topic_response.h
 *
 * 
 */

#ifndef _reopen_forum_topic_response_H_
#define _reopen_forum_topic_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reopen_forum_topic_response_t reopen_forum_topic_response_t;




typedef struct reopen_forum_topic_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} reopen_forum_topic_response_t;

__attribute__((deprecated)) reopen_forum_topic_response_t *reopen_forum_topic_response_create(
    int ok,
    int result
);

void reopen_forum_topic_response_free(reopen_forum_topic_response_t *reopen_forum_topic_response);

reopen_forum_topic_response_t *reopen_forum_topic_response_parseFromJSON(cJSON *reopen_forum_topic_responseJSON);

cJSON *reopen_forum_topic_response_convertToJSON(reopen_forum_topic_response_t *reopen_forum_topic_response);

#endif /* _reopen_forum_topic_response_H_ */

