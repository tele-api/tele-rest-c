/*
 * chat_boost_added.h
 *
 * This object represents a service message about a user boosting a chat.
 */

#ifndef _chat_boost_added_H_
#define _chat_boost_added_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_added_t chat_boost_added_t;




typedef struct chat_boost_added_t {
    int boost_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_added_t;

__attribute__((deprecated)) chat_boost_added_t *chat_boost_added_create(
    int boost_count
);

void chat_boost_added_free(chat_boost_added_t *chat_boost_added);

chat_boost_added_t *chat_boost_added_parseFromJSON(cJSON *chat_boost_addedJSON);

cJSON *chat_boost_added_convertToJSON(chat_boost_added_t *chat_boost_added);

#endif /* _chat_boost_added_H_ */

