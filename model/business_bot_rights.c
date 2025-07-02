#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_bot_rights.h"



static business_bot_rights_t *business_bot_rights_create_internal(
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
    ) {
    business_bot_rights_t *business_bot_rights_local_var = malloc(sizeof(business_bot_rights_t));
    if (!business_bot_rights_local_var) {
        return NULL;
    }
    business_bot_rights_local_var->can_reply = can_reply;
    business_bot_rights_local_var->can_read_messages = can_read_messages;
    business_bot_rights_local_var->can_delete_outgoing_messages = can_delete_outgoing_messages;
    business_bot_rights_local_var->can_delete_all_messages = can_delete_all_messages;
    business_bot_rights_local_var->can_edit_name = can_edit_name;
    business_bot_rights_local_var->can_edit_bio = can_edit_bio;
    business_bot_rights_local_var->can_edit_profile_photo = can_edit_profile_photo;
    business_bot_rights_local_var->can_edit_username = can_edit_username;
    business_bot_rights_local_var->can_change_gift_settings = can_change_gift_settings;
    business_bot_rights_local_var->can_view_gifts_and_stars = can_view_gifts_and_stars;
    business_bot_rights_local_var->can_convert_gifts_to_stars = can_convert_gifts_to_stars;
    business_bot_rights_local_var->can_transfer_and_upgrade_gifts = can_transfer_and_upgrade_gifts;
    business_bot_rights_local_var->can_transfer_stars = can_transfer_stars;
    business_bot_rights_local_var->can_manage_stories = can_manage_stories;

    business_bot_rights_local_var->_library_owned = 1;
    return business_bot_rights_local_var;
}

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
    ) {
    return business_bot_rights_create_internal (
        can_reply,
        can_read_messages,
        can_delete_outgoing_messages,
        can_delete_all_messages,
        can_edit_name,
        can_edit_bio,
        can_edit_profile_photo,
        can_edit_username,
        can_change_gift_settings,
        can_view_gifts_and_stars,
        can_convert_gifts_to_stars,
        can_transfer_and_upgrade_gifts,
        can_transfer_stars,
        can_manage_stories
        );
}

void business_bot_rights_free(business_bot_rights_t *business_bot_rights) {
    if(NULL == business_bot_rights){
        return ;
    }
    if(business_bot_rights->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_bot_rights_free");
        return ;
    }
    listEntry_t *listEntry;
    free(business_bot_rights);
}

cJSON *business_bot_rights_convertToJSON(business_bot_rights_t *business_bot_rights) {
    cJSON *item = cJSON_CreateObject();

    // business_bot_rights->can_reply
    if(business_bot_rights->can_reply) {
    if(cJSON_AddBoolToObject(item, "can_reply", business_bot_rights->can_reply) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_read_messages
    if(business_bot_rights->can_read_messages) {
    if(cJSON_AddBoolToObject(item, "can_read_messages", business_bot_rights->can_read_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_delete_outgoing_messages
    if(business_bot_rights->can_delete_outgoing_messages) {
    if(cJSON_AddBoolToObject(item, "can_delete_outgoing_messages", business_bot_rights->can_delete_outgoing_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_delete_all_messages
    if(business_bot_rights->can_delete_all_messages) {
    if(cJSON_AddBoolToObject(item, "can_delete_all_messages", business_bot_rights->can_delete_all_messages) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_edit_name
    if(business_bot_rights->can_edit_name) {
    if(cJSON_AddBoolToObject(item, "can_edit_name", business_bot_rights->can_edit_name) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_edit_bio
    if(business_bot_rights->can_edit_bio) {
    if(cJSON_AddBoolToObject(item, "can_edit_bio", business_bot_rights->can_edit_bio) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_edit_profile_photo
    if(business_bot_rights->can_edit_profile_photo) {
    if(cJSON_AddBoolToObject(item, "can_edit_profile_photo", business_bot_rights->can_edit_profile_photo) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_edit_username
    if(business_bot_rights->can_edit_username) {
    if(cJSON_AddBoolToObject(item, "can_edit_username", business_bot_rights->can_edit_username) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_change_gift_settings
    if(business_bot_rights->can_change_gift_settings) {
    if(cJSON_AddBoolToObject(item, "can_change_gift_settings", business_bot_rights->can_change_gift_settings) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_view_gifts_and_stars
    if(business_bot_rights->can_view_gifts_and_stars) {
    if(cJSON_AddBoolToObject(item, "can_view_gifts_and_stars", business_bot_rights->can_view_gifts_and_stars) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_convert_gifts_to_stars
    if(business_bot_rights->can_convert_gifts_to_stars) {
    if(cJSON_AddBoolToObject(item, "can_convert_gifts_to_stars", business_bot_rights->can_convert_gifts_to_stars) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_transfer_and_upgrade_gifts
    if(business_bot_rights->can_transfer_and_upgrade_gifts) {
    if(cJSON_AddBoolToObject(item, "can_transfer_and_upgrade_gifts", business_bot_rights->can_transfer_and_upgrade_gifts) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_transfer_stars
    if(business_bot_rights->can_transfer_stars) {
    if(cJSON_AddBoolToObject(item, "can_transfer_stars", business_bot_rights->can_transfer_stars) == NULL) {
    goto fail; //Bool
    }
    }


    // business_bot_rights->can_manage_stories
    if(business_bot_rights->can_manage_stories) {
    if(cJSON_AddBoolToObject(item, "can_manage_stories", business_bot_rights->can_manage_stories) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

business_bot_rights_t *business_bot_rights_parseFromJSON(cJSON *business_bot_rightsJSON){

    business_bot_rights_t *business_bot_rights_local_var = NULL;

    // business_bot_rights->can_reply
    cJSON *can_reply = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_reply");
    if (cJSON_IsNull(can_reply)) {
        can_reply = NULL;
    }
    if (can_reply) { 
    if(!cJSON_IsBool(can_reply))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_read_messages
    cJSON *can_read_messages = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_read_messages");
    if (cJSON_IsNull(can_read_messages)) {
        can_read_messages = NULL;
    }
    if (can_read_messages) { 
    if(!cJSON_IsBool(can_read_messages))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_delete_outgoing_messages
    cJSON *can_delete_outgoing_messages = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_delete_outgoing_messages");
    if (cJSON_IsNull(can_delete_outgoing_messages)) {
        can_delete_outgoing_messages = NULL;
    }
    if (can_delete_outgoing_messages) { 
    if(!cJSON_IsBool(can_delete_outgoing_messages))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_delete_all_messages
    cJSON *can_delete_all_messages = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_delete_all_messages");
    if (cJSON_IsNull(can_delete_all_messages)) {
        can_delete_all_messages = NULL;
    }
    if (can_delete_all_messages) { 
    if(!cJSON_IsBool(can_delete_all_messages))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_edit_name
    cJSON *can_edit_name = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_edit_name");
    if (cJSON_IsNull(can_edit_name)) {
        can_edit_name = NULL;
    }
    if (can_edit_name) { 
    if(!cJSON_IsBool(can_edit_name))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_edit_bio
    cJSON *can_edit_bio = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_edit_bio");
    if (cJSON_IsNull(can_edit_bio)) {
        can_edit_bio = NULL;
    }
    if (can_edit_bio) { 
    if(!cJSON_IsBool(can_edit_bio))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_edit_profile_photo
    cJSON *can_edit_profile_photo = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_edit_profile_photo");
    if (cJSON_IsNull(can_edit_profile_photo)) {
        can_edit_profile_photo = NULL;
    }
    if (can_edit_profile_photo) { 
    if(!cJSON_IsBool(can_edit_profile_photo))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_edit_username
    cJSON *can_edit_username = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_edit_username");
    if (cJSON_IsNull(can_edit_username)) {
        can_edit_username = NULL;
    }
    if (can_edit_username) { 
    if(!cJSON_IsBool(can_edit_username))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_change_gift_settings
    cJSON *can_change_gift_settings = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_change_gift_settings");
    if (cJSON_IsNull(can_change_gift_settings)) {
        can_change_gift_settings = NULL;
    }
    if (can_change_gift_settings) { 
    if(!cJSON_IsBool(can_change_gift_settings))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_view_gifts_and_stars
    cJSON *can_view_gifts_and_stars = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_view_gifts_and_stars");
    if (cJSON_IsNull(can_view_gifts_and_stars)) {
        can_view_gifts_and_stars = NULL;
    }
    if (can_view_gifts_and_stars) { 
    if(!cJSON_IsBool(can_view_gifts_and_stars))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_convert_gifts_to_stars
    cJSON *can_convert_gifts_to_stars = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_convert_gifts_to_stars");
    if (cJSON_IsNull(can_convert_gifts_to_stars)) {
        can_convert_gifts_to_stars = NULL;
    }
    if (can_convert_gifts_to_stars) { 
    if(!cJSON_IsBool(can_convert_gifts_to_stars))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_transfer_and_upgrade_gifts
    cJSON *can_transfer_and_upgrade_gifts = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_transfer_and_upgrade_gifts");
    if (cJSON_IsNull(can_transfer_and_upgrade_gifts)) {
        can_transfer_and_upgrade_gifts = NULL;
    }
    if (can_transfer_and_upgrade_gifts) { 
    if(!cJSON_IsBool(can_transfer_and_upgrade_gifts))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_transfer_stars
    cJSON *can_transfer_stars = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_transfer_stars");
    if (cJSON_IsNull(can_transfer_stars)) {
        can_transfer_stars = NULL;
    }
    if (can_transfer_stars) { 
    if(!cJSON_IsBool(can_transfer_stars))
    {
    goto end; //Bool
    }
    }

    // business_bot_rights->can_manage_stories
    cJSON *can_manage_stories = cJSON_GetObjectItemCaseSensitive(business_bot_rightsJSON, "can_manage_stories");
    if (cJSON_IsNull(can_manage_stories)) {
        can_manage_stories = NULL;
    }
    if (can_manage_stories) { 
    if(!cJSON_IsBool(can_manage_stories))
    {
    goto end; //Bool
    }
    }


    business_bot_rights_local_var = business_bot_rights_create_internal (
        can_reply ? can_reply->valueint : 0,
        can_read_messages ? can_read_messages->valueint : 0,
        can_delete_outgoing_messages ? can_delete_outgoing_messages->valueint : 0,
        can_delete_all_messages ? can_delete_all_messages->valueint : 0,
        can_edit_name ? can_edit_name->valueint : 0,
        can_edit_bio ? can_edit_bio->valueint : 0,
        can_edit_profile_photo ? can_edit_profile_photo->valueint : 0,
        can_edit_username ? can_edit_username->valueint : 0,
        can_change_gift_settings ? can_change_gift_settings->valueint : 0,
        can_view_gifts_and_stars ? can_view_gifts_and_stars->valueint : 0,
        can_convert_gifts_to_stars ? can_convert_gifts_to_stars->valueint : 0,
        can_transfer_and_upgrade_gifts ? can_transfer_and_upgrade_gifts->valueint : 0,
        can_transfer_stars ? can_transfer_stars->valueint : 0,
        can_manage_stories ? can_manage_stories->valueint : 0
        );

    return business_bot_rights_local_var;
end:
    return NULL;

}
