/*
 * force_reply.h
 *
 * Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot&#39;s message and tapped &#39;Reply&#39;). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice [privacy mode](https://core.telegram.org/bots/features#privacy-mode). Not supported in channels and for messages sent on behalf of a Telegram Business account.
 */

#ifndef _force_reply_H_
#define _force_reply_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct force_reply_t force_reply_t;




typedef struct force_reply_t {
    int force_reply; //boolean
    char *input_field_placeholder; // string
    int selective; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} force_reply_t;

__attribute__((deprecated)) force_reply_t *force_reply_create(
    int force_reply,
    char *input_field_placeholder,
    int selective
);

void force_reply_free(force_reply_t *force_reply);

force_reply_t *force_reply_parseFromJSON(cJSON *force_replyJSON);

cJSON *force_reply_convertToJSON(force_reply_t *force_reply);

#endif /* _force_reply_H_ */

