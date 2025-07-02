/*
 * promote_chat_member_request.h
 *
 * Request parameters for promoteChatMember
 */

#ifndef _promote_chat_member_request_H_
#define _promote_chat_member_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct promote_chat_member_request_t promote_chat_member_request_t;

#include "send_message_request_chat_id.h"



typedef struct promote_chat_member_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    int user_id; //numeric
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
} promote_chat_member_request_t;

__attribute__((deprecated)) promote_chat_member_request_t *promote_chat_member_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id,
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

void promote_chat_member_request_free(promote_chat_member_request_t *promote_chat_member_request);

promote_chat_member_request_t *promote_chat_member_request_parseFromJSON(cJSON *promote_chat_member_requestJSON);

cJSON *promote_chat_member_request_convertToJSON(promote_chat_member_request_t *promote_chat_member_request);

#endif /* _promote_chat_member_request_H_ */

