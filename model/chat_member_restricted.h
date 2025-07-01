/*
 * chat_member_restricted.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that is under certain restrictions in the chat. Supergroups only.
 */

#ifndef _chat_member_restricted_H_
#define _chat_member_restricted_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_restricted_t chat_member_restricted_t;

#include "user.h"



typedef struct chat_member_restricted_t {
    char *status; // string
    struct user_t *user; //model
    int is_member; //boolean
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
    int until_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_restricted_t;

__attribute__((deprecated)) chat_member_restricted_t *chat_member_restricted_create(
    char *status,
    user_t *user,
    int is_member,
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
    int can_manage_topics,
    int until_date
);

void chat_member_restricted_free(chat_member_restricted_t *chat_member_restricted);

chat_member_restricted_t *chat_member_restricted_parseFromJSON(cJSON *chat_member_restrictedJSON);

cJSON *chat_member_restricted_convertToJSON(chat_member_restricted_t *chat_member_restricted);

#endif /* _chat_member_restricted_H_ */

