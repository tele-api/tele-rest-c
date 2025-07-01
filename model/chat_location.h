/*
 * chat_location.h
 *
 * Represents a location to which a chat is connected.
 */

#ifndef _chat_location_H_
#define _chat_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_location_t chat_location_t;

#include "location.h"



typedef struct chat_location_t {
    struct location_t *location; //model
    char *address; // string

    int _library_owned; // Is the library responsible for freeing this object?
} chat_location_t;

__attribute__((deprecated)) chat_location_t *chat_location_create(
    location_t *location,
    char *address
);

void chat_location_free(chat_location_t *chat_location);

chat_location_t *chat_location_parseFromJSON(cJSON *chat_locationJSON);

cJSON *chat_location_convertToJSON(chat_location_t *chat_location);

#endif /* _chat_location_H_ */

