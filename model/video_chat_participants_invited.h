/*
 * video_chat_participants_invited.h
 *
 * This object represents a service message about new members invited to a video chat.
 */

#ifndef _video_chat_participants_invited_H_
#define _video_chat_participants_invited_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct video_chat_participants_invited_t video_chat_participants_invited_t;

#include "user.h"



typedef struct video_chat_participants_invited_t {
    list_t *users; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} video_chat_participants_invited_t;

__attribute__((deprecated)) video_chat_participants_invited_t *video_chat_participants_invited_create(
    list_t *users
);

void video_chat_participants_invited_free(video_chat_participants_invited_t *video_chat_participants_invited);

video_chat_participants_invited_t *video_chat_participants_invited_parseFromJSON(cJSON *video_chat_participants_invitedJSON);

cJSON *video_chat_participants_invited_convertToJSON(video_chat_participants_invited_t *video_chat_participants_invited);

#endif /* _video_chat_participants_invited_H_ */

