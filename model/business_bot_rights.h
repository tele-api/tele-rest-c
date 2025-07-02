/*
 * business_bot_rights.h
 *
 * Represents the rights of a business bot.
 */

#ifndef _business_bot_rights_H_
#define _business_bot_rights_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_bot_rights_t business_bot_rights_t;




typedef struct business_bot_rights_t {
    int can_reply; //boolean
    int can_read_messages; //boolean
    int can_delete_outgoing_messages; //boolean
    int can_delete_all_messages; //boolean
    int can_edit_name; //boolean
    int can_edit_bio; //boolean
    int can_edit_profile_photo; //boolean
    int can_edit_username; //boolean
    int can_change_gift_settings; //boolean
    int can_view_gifts_and_stars; //boolean
    int can_convert_gifts_to_stars; //boolean
    int can_transfer_and_upgrade_gifts; //boolean
    int can_transfer_stars; //boolean
    int can_manage_stories; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} business_bot_rights_t;

__attribute__((deprecated)) business_bot_rights_t *business_bot_rights_create(
    int can_reply,
    int can_read_messages,
    int can_delete_outgoing_messages,
    int can_delete_all_messages,
    int can_edit_name,
    int can_edit_bio,
    int can_edit_profile_photo,
    int can_edit_username,
    int can_change_gift_settings,
    int can_view_gifts_and_stars,
    int can_convert_gifts_to_stars,
    int can_transfer_and_upgrade_gifts,
    int can_transfer_stars,
    int can_manage_stories
);

void business_bot_rights_free(business_bot_rights_t *business_bot_rights);

business_bot_rights_t *business_bot_rights_parseFromJSON(cJSON *business_bot_rightsJSON);

cJSON *business_bot_rights_convertToJSON(business_bot_rights_t *business_bot_rights);

#endif /* _business_bot_rights_H_ */

