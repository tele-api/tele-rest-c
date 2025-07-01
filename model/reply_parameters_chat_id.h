/*
 * reply_parameters_chat_id.h
 *
 * *Optional*. If the message to be replied to is from a different chat, unique identifier for the chat or username of the channel (in the format &#x60;@channelusername&#x60;). Not supported for messages sent on behalf of a business account.
 */

#ifndef _reply_parameters_chat_id_H_
#define _reply_parameters_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reply_parameters_chat_id_t reply_parameters_chat_id_t;




typedef struct reply_parameters_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} reply_parameters_chat_id_t;

__attribute__((deprecated)) reply_parameters_chat_id_t *reply_parameters_chat_id_create(
);

void reply_parameters_chat_id_free(reply_parameters_chat_id_t *reply_parameters_chat_id);

reply_parameters_chat_id_t *reply_parameters_chat_id_parseFromJSON(cJSON *reply_parameters_chat_idJSON);

cJSON *reply_parameters_chat_id_convertToJSON(reply_parameters_chat_id_t *reply_parameters_chat_id);

#endif /* _reply_parameters_chat_id_H_ */

