/*
 * chat_administrator_rights.h
 *
 * Represents the rights of an administrator in a chat.
 */

#ifndef _chat_administrator_rights_H_
#define _chat_administrator_rights_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_administrator_rights_t chat_administrator_rights_t;




typedef struct chat_administrator_rights_t {
    int is_anonymous; //boolean
    int can_manage_chat; //boolean
    int can_delete_messages; //boolean
    int can_manage_video_chats; //boolean
    int can_restrict_members; //boolean
    int can_promote_members; //boolean
    int can_change_info; //boolean
    int can_invite_users; //boolean
    int can_post_stories; //boolean
    int can_edit_stories; //boolean
    int can_delete_stories; //boolean
    int can_post_messages; //boolean
    int can_edit_messages; //boolean
    int can_pin_messages; //boolean
    int can_manage_topics; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_administrator_rights_t;

__attribute__((deprecated)) chat_administrator_rights_t *chat_administrator_rights_create(
    int is_anonymous,
    int can_manage_chat,
    int can_delete_messages,
    int can_manage_video_chats,
    int can_restrict_members,
    int can_promote_members,
    int can_change_info,
    int can_invite_users,
    int can_post_stories,
    int can_edit_stories,
    int can_delete_stories,
    int can_post_messages,
    int can_edit_messages,
    int can_pin_messages,
    int can_manage_topics
);

void chat_administrator_rights_free(chat_administrator_rights_t *chat_administrator_rights);

chat_administrator_rights_t *chat_administrator_rights_parseFromJSON(cJSON *chat_administrator_rightsJSON);

cJSON *chat_administrator_rights_convertToJSON(chat_administrator_rights_t *chat_administrator_rights);

#endif /* _chat_administrator_rights_H_ */

