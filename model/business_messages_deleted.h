/*
 * business_messages_deleted.h
 *
 * This object is received when messages are deleted from a connected business account.
 */

#ifndef _business_messages_deleted_H_
#define _business_messages_deleted_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_messages_deleted_t business_messages_deleted_t;

#include "chat.h"



typedef struct business_messages_deleted_t {
    char *business_connection_id; // string
    struct chat_t *chat; //model
    list_t *message_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} business_messages_deleted_t;

__attribute__((deprecated)) business_messages_deleted_t *business_messages_deleted_create(
    char *business_connection_id,
    chat_t *chat,
    list_t *message_ids
);

void business_messages_deleted_free(business_messages_deleted_t *business_messages_deleted);

business_messages_deleted_t *business_messages_deleted_parseFromJSON(cJSON *business_messages_deletedJSON);

cJSON *business_messages_deleted_convertToJSON(business_messages_deleted_t *business_messages_deleted);

#endif /* _business_messages_deleted_H_ */

