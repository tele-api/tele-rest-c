/*
 * forum_topic.h
 *
 * This object represents a forum topic.
 */

#ifndef _forum_topic_H_
#define _forum_topic_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forum_topic_t forum_topic_t;




typedef struct forum_topic_t {
    int message_thread_id; //numeric
    char *name; // string
    int icon_color; //numeric
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} forum_topic_t;

__attribute__((deprecated)) forum_topic_t *forum_topic_create(
    int message_thread_id,
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
);

void forum_topic_free(forum_topic_t *forum_topic);

forum_topic_t *forum_topic_parseFromJSON(cJSON *forum_topicJSON);

cJSON *forum_topic_convertToJSON(forum_topic_t *forum_topic);

#endif /* _forum_topic_H_ */

