/*
 * chat_permissions.h
 *
 * Describes actions that a non-administrator user is allowed to take in a chat.
 */

#ifndef _chat_permissions_H_
#define _chat_permissions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_permissions_t chat_permissions_t;




typedef struct chat_permissions_t {
    int can_send_messages; //boolean
    int can_send_audios; //boolean
    int can_send_documents; //boolean
    int can_send_photos; //boolean
    int can_send_videos; //boolean
    int can_send_video_notes; //boolean
    int can_send_voice_notes; //boolean
    int can_send_polls; //boolean
    int can_send_other_messages; //boolean
    int can_add_web_page_previews; //boolean
    int can_change_info; //boolean
    int can_invite_users; //boolean
    int can_pin_messages; //boolean
    int can_manage_topics; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_permissions_t;

__attribute__((deprecated)) chat_permissions_t *chat_permissions_create(
    int can_send_messages,
    int can_send_audios,
    int can_send_documents,
    int can_send_photos,
    int can_send_videos,
    int can_send_video_notes,
    int can_send_voice_notes,
    int can_send_polls,
    int can_send_other_messages,
    int can_add_web_page_previews,
    int can_change_info,
    int can_invite_users,
    int can_pin_messages,
    int can_manage_topics
);

void chat_permissions_free(chat_permissions_t *chat_permissions);

chat_permissions_t *chat_permissions_parseFromJSON(cJSON *chat_permissionsJSON);

cJSON *chat_permissions_convertToJSON(chat_permissions_t *chat_permissions);

#endif /* _chat_permissions_H_ */

