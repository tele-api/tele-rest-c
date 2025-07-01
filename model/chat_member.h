/*
 * chat_member.h
 *
 * This object contains information about one member of a chat. Currently, the following 6 types of chat members are supported:  * [ChatMemberOwner](https://core.telegram.org/bots/api/#chatmemberowner) * [ChatMemberAdministrator](https://core.telegram.org/bots/api/#chatmemberadministrator) * [ChatMemberMember](https://core.telegram.org/bots/api/#chatmembermember) * [ChatMemberRestricted](https://core.telegram.org/bots/api/#chatmemberrestricted) * [ChatMemberLeft](https://core.telegram.org/bots/api/#chatmemberleft) * [ChatMemberBanned](https://core.telegram.org/bots/api/#chatmemberbanned)
 */

#ifndef _chat_member_H_
#define _chat_member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_t chat_member_t;

#include "chat_member_administrator.h"
#include "chat_member_banned.h"
#include "chat_member_left.h"
#include "chat_member_member.h"
#include "chat_member_owner.h"
#include "chat_member_restricted.h"
#include "user.h"



typedef struct chat_member_t {
    char *status; // string
    struct user_t *user; //model
    int is_anonymous; //boolean
    int can_be_edited; //boolean
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
    int can_pin_messages; //boolean
    int can_manage_topics; //boolean
    int until_date; //numeric
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
    char *custom_title; // string
    int can_post_messages; //boolean
    int can_edit_messages; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_t;

__attribute__((deprecated)) chat_member_t *chat_member_create(
    char *status,
    user_t *user,
    int is_anonymous,
    int can_be_edited,
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
    int can_pin_messages,
    int can_manage_topics,
    int until_date,
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
    char *custom_title,
    int can_post_messages,
    int can_edit_messages
);

void chat_member_free(chat_member_t *chat_member);

chat_member_t *chat_member_parseFromJSON(cJSON *chat_memberJSON);

cJSON *chat_member_convertToJSON(chat_member_t *chat_member);

#endif /* _chat_member_H_ */

