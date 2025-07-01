/*
 * video_chat_ended.h
 *
 * This object represents a service message about a video chat ended in the chat.
 */

#ifndef _video_chat_ended_H_
#define _video_chat_ended_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct video_chat_ended_t video_chat_ended_t;




typedef struct video_chat_ended_t {
    int duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} video_chat_ended_t;

__attribute__((deprecated)) video_chat_ended_t *video_chat_ended_create(
    int duration
);

void video_chat_ended_free(video_chat_ended_t *video_chat_ended);

video_chat_ended_t *video_chat_ended_parseFromJSON(cJSON *video_chat_endedJSON);

cJSON *video_chat_ended_convertToJSON(video_chat_ended_t *video_chat_ended);

#endif /* _video_chat_ended_H_ */

