/*
 * message_origin_channel.h
 *
 * The message was originally sent to a channel chat.
 */

#ifndef _message_origin_channel_H_
#define _message_origin_channel_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_origin_channel_t message_origin_channel_t;

#include "chat.h"



typedef struct message_origin_channel_t {
    char *type; // string
    int date; //numeric
    struct chat_t *chat; //model
    int message_id; //numeric
    char *author_signature; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_origin_channel_t;

__attribute__((deprecated)) message_origin_channel_t *message_origin_channel_create(
    char *type,
    int date,
    chat_t *chat,
    int message_id,
    char *author_signature
);

void message_origin_channel_free(message_origin_channel_t *message_origin_channel);

message_origin_channel_t *message_origin_channel_parseFromJSON(cJSON *message_origin_channelJSON);

cJSON *message_origin_channel_convertToJSON(message_origin_channel_t *message_origin_channel);

#endif /* _message_origin_channel_H_ */

