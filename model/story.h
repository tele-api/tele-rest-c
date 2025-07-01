/*
 * story.h
 *
 * This object represents a story.
 */

#ifndef _story_H_
#define _story_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct story_t story_t;

#include "chat.h"



typedef struct story_t {
    struct chat_t *chat; //model
    int id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} story_t;

__attribute__((deprecated)) story_t *story_create(
    chat_t *chat,
    int id
);

void story_free(story_t *story);

story_t *story_parseFromJSON(cJSON *storyJSON);

cJSON *story_convertToJSON(story_t *story);

#endif /* _story_H_ */

