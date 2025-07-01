/*
 * forum_topic_created.h
 *
 * This object represents a service message about a new forum topic created in the chat.
 */

#ifndef _forum_topic_created_H_
#define _forum_topic_created_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forum_topic_created_t forum_topic_created_t;




typedef struct forum_topic_created_t {
    char *name; // string
    int icon_color; //numeric
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} forum_topic_created_t;

__attribute__((deprecated)) forum_topic_created_t *forum_topic_created_create(
    char *name,
    int icon_color,
    char *icon_custom_emoji_id
);

void forum_topic_created_free(forum_topic_created_t *forum_topic_created);

forum_topic_created_t *forum_topic_created_parseFromJSON(cJSON *forum_topic_createdJSON);

cJSON *forum_topic_created_convertToJSON(forum_topic_created_t *forum_topic_created);

#endif /* _forum_topic_created_H_ */

