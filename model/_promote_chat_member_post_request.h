/*
 * _promote_chat_member_post_request.h
 *
 * 
 */

#ifndef __promote_chat_member_post_request_H_
#define __promote_chat_member_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _promote_chat_member_post_request_t _promote_chat_member_post_request_t;

#include "_send_message_post_request_chat_id.h"



typedef struct _promote_chat_member_post_request_t {
    struct _send_message_post_request_chat_id_t *chat_id; //model
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
} _promote_chat_member_post_request_t;

__attribute__((deprecated)) _promote_chat_member_post_request_t *_promote_chat_member_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
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

void _promote_chat_member_post_request_free(_promote_chat_member_post_request_t *_promote_chat_member_post_request);

_promote_chat_member_post_request_t *_promote_chat_member_post_request_parseFromJSON(cJSON *_promote_chat_member_post_requestJSON);

cJSON *_promote_chat_member_post_request_convertToJSON(_promote_chat_member_post_request_t *_promote_chat_member_post_request);

#endif /* __promote_chat_member_post_request_H_ */

