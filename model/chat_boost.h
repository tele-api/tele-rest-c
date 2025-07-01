/*
 * chat_boost.h
 *
 * This object contains information about a chat boost.
 */

#ifndef _chat_boost_H_
#define _chat_boost_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_boost_t chat_boost_t;

#include "chat_boost_source.h"



typedef struct chat_boost_t {
    char *boost_id; // string
    int add_date; //numeric
    int expiration_date; //numeric
    struct chat_boost_source_t *source; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_boost_t;

__attribute__((deprecated)) chat_boost_t *chat_boost_create(
    char *boost_id,
    int add_date,
    int expiration_date,
    chat_boost_source_t *source
);

void chat_boost_free(chat_boost_t *chat_boost);

chat_boost_t *chat_boost_parseFromJSON(cJSON *chat_boostJSON);

cJSON *chat_boost_convertToJSON(chat_boost_t *chat_boost);

#endif /* _chat_boost_H_ */

