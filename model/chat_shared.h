/*
 * chat_shared.h
 *
 * This object contains information about a chat that was shared with the bot using a [KeyboardButtonRequestChat](https://core.telegram.org/bots/api/#keyboardbuttonrequestchat) button.
 */

#ifndef _chat_shared_H_
#define _chat_shared_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_shared_t chat_shared_t;

#include "photo_size.h"



typedef struct chat_shared_t {
    int request_id; //numeric
    int chat_id; //numeric
    char *title; // string
    char *username; // string
    list_t *photo; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} chat_shared_t;

__attribute__((deprecated)) chat_shared_t *chat_shared_create(
    int request_id,
    int chat_id,
    char *title,
    char *username,
    list_t *photo
);

void chat_shared_free(chat_shared_t *chat_shared);

chat_shared_t *chat_shared_parseFromJSON(cJSON *chat_sharedJSON);

cJSON *chat_shared_convertToJSON(chat_shared_t *chat_shared);

#endif /* _chat_shared_H_ */

