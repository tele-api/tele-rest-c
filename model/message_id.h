/*
 * message_id.h
 *
 * This object represents a unique message identifier.
 */

#ifndef _message_id_H_
#define _message_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_id_t message_id_t;




typedef struct message_id_t {
    int message_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} message_id_t;

__attribute__((deprecated)) message_id_t *message_id_create(
    int message_id
);

void message_id_free(message_id_t *message_id);

message_id_t *message_id_parseFromJSON(cJSON *message_idJSON);

cJSON *message_id_convertToJSON(message_id_t *message_id);

#endif /* _message_id_H_ */

