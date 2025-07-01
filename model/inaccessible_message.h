/*
 * inaccessible_message.h
 *
 * This object describes a message that was deleted or is otherwise inaccessible to the bot.
 */

#ifndef _inaccessible_message_H_
#define _inaccessible_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct inaccessible_message_t inaccessible_message_t;

#include "chat.h"



typedef struct inaccessible_message_t {
    struct chat_t *chat; //model
    int message_id; //numeric
    int date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} inaccessible_message_t;

__attribute__((deprecated)) inaccessible_message_t *inaccessible_message_create(
    chat_t *chat,
    int message_id,
    int date
);

void inaccessible_message_free(inaccessible_message_t *inaccessible_message);

inaccessible_message_t *inaccessible_message_parseFromJSON(cJSON *inaccessible_messageJSON);

cJSON *inaccessible_message_convertToJSON(inaccessible_message_t *inaccessible_message);

#endif /* _inaccessible_message_H_ */

