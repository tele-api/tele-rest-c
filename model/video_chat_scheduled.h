/*
 * video_chat_scheduled.h
 *
 * This object represents a service message about a video chat scheduled in the chat.
 */

#ifndef _video_chat_scheduled_H_
#define _video_chat_scheduled_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct video_chat_scheduled_t video_chat_scheduled_t;




typedef struct video_chat_scheduled_t {
    int start_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} video_chat_scheduled_t;

__attribute__((deprecated)) video_chat_scheduled_t *video_chat_scheduled_create(
    int start_date
);

void video_chat_scheduled_free(video_chat_scheduled_t *video_chat_scheduled);

video_chat_scheduled_t *video_chat_scheduled_parseFromJSON(cJSON *video_chat_scheduledJSON);

cJSON *video_chat_scheduled_convertToJSON(video_chat_scheduled_t *video_chat_scheduled);

#endif /* _video_chat_scheduled_H_ */

