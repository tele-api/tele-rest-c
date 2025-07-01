/*
 * chat_member_administrator.h
 *
 * Represents a [chat member](https://core.telegram.org/bots/api/#chatmember) that has some additional privileges.
 */

#ifndef _chat_member_administrator_H_
#define _chat_member_administrator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_administrator_t chat_member_administrator_t;

#include "user.h"



typedef struct chat_member_administrator_t {
    char *status; // string
    struct user_t *user; //model
    int can_be_edited; //boolean
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
    char *custom_title; // string

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_administrator_t;

__attribute__((deprecated)) chat_member_administrator_t *chat_member_administrator_create(
    char *status,
    user_t *user,
    int can_be_edited,
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
    int can_manage_topics,
    char *custom_title
);

void chat_member_administrator_free(chat_member_administrator_t *chat_member_administrator);

chat_member_administrator_t *chat_member_administrator_parseFromJSON(cJSON *chat_member_administratorJSON);

cJSON *chat_member_administrator_convertToJSON(chat_member_administrator_t *chat_member_administrator);

#endif /* _chat_member_administrator_H_ */

