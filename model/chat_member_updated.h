/*
 * chat_member_updated.h
 *
 * This object represents changes in the status of a chat member.
 */

#ifndef _chat_member_updated_H_
#define _chat_member_updated_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chat_member_updated_t chat_member_updated_t;

#include "chat.h"
#include "chat_invite_link.h"
#include "chat_member.h"
#include "user.h"



typedef struct chat_member_updated_t {
    struct chat_t *chat; //model
    struct user_t *from; //model
    int date; //numeric
    struct chat_member_t *old_chat_member; //model
    struct chat_member_t *new_chat_member; //model
    struct chat_invite_link_t *invite_link; //model
    int via_join_request; //boolean
    int via_chat_folder_invite_link; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} chat_member_updated_t;

__attribute__((deprecated)) chat_member_updated_t *chat_member_updated_create(
    chat_t *chat,
    user_t *from,
    int date,
    chat_member_t *old_chat_member,
    chat_member_t *new_chat_member,
    chat_invite_link_t *invite_link,
    int via_join_request,
    int via_chat_folder_invite_link
);

void chat_member_updated_free(chat_member_updated_t *chat_member_updated);

chat_member_updated_t *chat_member_updated_parseFromJSON(cJSON *chat_member_updatedJSON);

cJSON *chat_member_updated_convertToJSON(chat_member_updated_t *chat_member_updated);

#endif /* _chat_member_updated_H_ */

