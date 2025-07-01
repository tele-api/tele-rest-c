/*
 * chat_boost_removed.h
 *
 * This object represents a boost removed from a chat.
 */

#ifndef _chat_boost_removed_H_
#define _chat_boost_removed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_removed_t chat_boost_removed_t;

#include "chat.h"
#include "chat_boost_source.h"



typedef struct chat_boost_removed_t {
    struct chat_t *chat; //model
    char *boost_id; // string
    int remove_date; //numeric
    struct chat_boost_source_t *source; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_removed_t;

__attribute__((deprecated)) chat_boost_removed_t *chat_boost_removed_create(
    chat_t *chat,
    char *boost_id,
    int remove_date,
    chat_boost_source_t *source
);

void chat_boost_removed_free(chat_boost_removed_t *chat_boost_removed);

chat_boost_removed_t *chat_boost_removed_parseFromJSON(cJSON *chat_boost_removedJSON);

cJSON *chat_boost_removed_convertToJSON(chat_boost_removed_t *chat_boost_removed);

#endif /* _chat_boost_removed_H_ */

