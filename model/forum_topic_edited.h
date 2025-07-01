/*
 * forum_topic_edited.h
 *
 * This object represents a service message about an edited forum topic.
 */

#ifndef _forum_topic_edited_H_
#define _forum_topic_edited_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct forum_topic_edited_t forum_topic_edited_t;




typedef struct forum_topic_edited_t {
    char *name; // string
    char *icon_custom_emoji_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} forum_topic_edited_t;

__attribute__((deprecated)) forum_topic_edited_t *forum_topic_edited_create(
    char *name,
    char *icon_custom_emoji_id
);

void forum_topic_edited_free(forum_topic_edited_t *forum_topic_edited);

forum_topic_edited_t *forum_topic_edited_parseFromJSON(cJSON *forum_topic_editedJSON);

cJSON *forum_topic_edited_convertToJSON(forum_topic_edited_t *forum_topic_edited);

#endif /* _forum_topic_edited_H_ */

