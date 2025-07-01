/*
 * chat_boost_updated.h
 *
 * This object represents a boost added to a chat or changed.
 */

#ifndef _chat_boost_updated_H_
#define _chat_boost_updated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_updated_t chat_boost_updated_t;

#include "chat.h"
#include "chat_boost.h"



typedef struct chat_boost_updated_t {
    struct chat_t *chat; //model
    struct chat_boost_t *boost; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_updated_t;

__attribute__((deprecated)) chat_boost_updated_t *chat_boost_updated_create(
    chat_t *chat,
    chat_boost_t *boost
);

void chat_boost_updated_free(chat_boost_updated_t *chat_boost_updated);

chat_boost_updated_t *chat_boost_updated_parseFromJSON(cJSON *chat_boost_updatedJSON);

cJSON *chat_boost_updated_convertToJSON(chat_boost_updated_t *chat_boost_updated);

#endif /* _chat_boost_updated_H_ */

