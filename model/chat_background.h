/*
 * chat_background.h
 *
 * This object represents a chat background.
 */

#ifndef _chat_background_H_
#define _chat_background_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_background_t chat_background_t;

#include "background_type.h"



typedef struct chat_background_t {
    struct background_type_t *type; //model

    int _library_owned; // Is the library responsible for freeing this object?
} chat_background_t;

__attribute__((deprecated)) chat_background_t *chat_background_create(
    background_type_t *type
);

void chat_background_free(chat_background_t *chat_background);

chat_background_t *chat_background_parseFromJSON(cJSON *chat_backgroundJSON);

cJSON *chat_background_convertToJSON(chat_background_t *chat_background);

#endif /* _chat_background_H_ */

