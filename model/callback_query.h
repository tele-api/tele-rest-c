/*
 * callback_query.h
 *
 * This object represents an incoming callback query from a callback button in an [inline keyboard](https://core.telegram.org/bots/features#inline-keyboards). If the button that originated the query was attached to a message sent by the bot, the field *message* will be present. If the button was attached to a message sent via the bot (in [inline mode](https://core.telegram.org/bots/api/#inline-mode)), the field *inline\\_message\\_id* will be present. Exactly one of the fields *data* or *game\\_short\\_name* will be present.
 */

#ifndef _callback_query_H_
#define _callback_query_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct callback_query_t callback_query_t;

#include "maybe_inaccessible_message.h"
#include "user.h"



typedef struct callback_query_t {
    char *id; // string
    struct user_t *from; //model
    char *chat_instance; // string
    struct maybe_inaccessible_message_t *message; //model
    char *inline_message_id; // string
    char *data; // string
    char *game_short_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} callback_query_t;

__attribute__((deprecated)) callback_query_t *callback_query_create(
    char *id,
    user_t *from,
    char *chat_instance,
    maybe_inaccessible_message_t *message,
    char *inline_message_id,
    char *data,
    char *game_short_name
);

void callback_query_free(callback_query_t *callback_query);

callback_query_t *callback_query_parseFromJSON(cJSON *callback_queryJSON);

cJSON *callback_query_convertToJSON(callback_query_t *callback_query);

#endif /* _callback_query_H_ */

