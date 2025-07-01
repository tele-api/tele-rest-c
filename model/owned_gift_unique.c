#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "owned_gift_unique.h"



static owned_gift_unique_t *owned_gift_unique_create_internal(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    int is_saved,
    int can_be_transferred,
    int transfer_star_count
    ) {
    owned_gift_unique_t *owned_gift_unique_local_var = malloc(sizeof(owned_gift_unique_t));
    if (!owned_gift_unique_local_var) {
        return NULL;
    }
    owned_gift_unique_local_var->type = type;
    owned_gift_unique_local_var->gift = gift;
    owned_gift_unique_local_var->send_date = send_date;
    owned_gift_unique_local_var->owned_gift_id = owned_gift_id;
    owned_gift_unique_local_var->sender_user = sender_user;
    owned_gift_unique_local_var->is_saved = is_saved;
    owned_gift_unique_local_var->can_be_transferred = can_be_transferred;
    owned_gift_unique_local_var->transfer_star_count = transfer_star_count;

    owned_gift_unique_local_var->_library_owned = 1;
    return owned_gift_unique_local_var;
}

__attribute__((deprecated)) owned_gift_unique_t *owned_gift_unique_create(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    int is_saved,
    int can_be_transferred,
    int transfer_star_count
    ) {
    return owned_gift_unique_create_internal (
        type,
        gift,
        send_date,
        owned_gift_id,
        sender_user,
        is_saved,
        can_be_transferred,
        transfer_star_count
        );
}

void owned_gift_unique_free(owned_gift_unique_t *owned_gift_unique) {
    if(NULL == owned_gift_unique){
        return ;
    }
    if(owned_gift_unique->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "owned_gift_unique_free");
        return ;
    }
    listEntry_t *listEntry;
    if (owned_gift_unique->type) {
        free(owned_gift_unique->type);
        owned_gift_unique->type = NULL;
    }
    if (owned_gift_unique->gift) {
        unique_gift_free(owned_gift_unique->gift);
        owned_gift_unique->gift = NULL;
    }
    if (owned_gift_unique->owned_gift_id) {
        free(owned_gift_unique->owned_gift_id);
        owned_gift_unique->owned_gift_id = NULL;
    }
    if (owned_gift_unique->sender_user) {
        user_free(owned_gift_unique->sender_user);
        owned_gift_unique->sender_user = NULL;
    }
    free(owned_gift_unique);
}

cJSON *owned_gift_unique_convertToJSON(owned_gift_unique_t *owned_gift_unique) {
    cJSON *item = cJSON_CreateObject();

    // owned_gift_unique->type
    if (!owned_gift_unique->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", owned_gift_unique->type) == NULL) {
    goto fail; //String
    }


    // owned_gift_unique->gift
    if (!owned_gift_unique->gift) {
        goto fail;
    }
    cJSON *gift_local_JSON = unique_gift_convertToJSON(owned_gift_unique->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // owned_gift_unique->send_date
    if (!owned_gift_unique->send_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "send_date", owned_gift_unique->send_date) == NULL) {
    goto fail; //Numeric
    }


    // owned_gift_unique->owned_gift_id
    if(owned_gift_unique->owned_gift_id) {
    if(cJSON_AddStringToObject(item, "owned_gift_id", owned_gift_unique->owned_gift_id) == NULL) {
    goto fail; //String
    }
    }


    // owned_gift_unique->sender_user
    if(owned_gift_unique->sender_user) {
    cJSON *sender_user_local_JSON = user_convertToJSON(owned_gift_unique->sender_user);
    if(sender_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_user", sender_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // owned_gift_unique->is_saved
    if(owned_gift_unique->is_saved) {
    if(cJSON_AddBoolToObject(item, "is_saved", owned_gift_unique->is_saved) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift_unique->can_be_transferred
    if(owned_gift_unique->can_be_transferred) {
    if(cJSON_AddBoolToObject(item, "can_be_transferred", owned_gift_unique->can_be_transferred) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift_unique->transfer_star_count
    if(owned_gift_unique->transfer_star_count) {
    if(cJSON_AddNumberToObject(item, "transfer_star_count", owned_gift_unique->transfer_star_count) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

owned_gift_unique_t *owned_gift_unique_parseFromJSON(cJSON *owned_gift_uniqueJSON){

    owned_gift_unique_t *owned_gift_unique_local_var = NULL;

    // define the local variable for owned_gift_unique->gift
    unique_gift_t *gift_local_nonprim = NULL;

    // define the local variable for owned_gift_unique->sender_user
    user_t *sender_user_local_nonprim = NULL;

    // owned_gift_unique->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // owned_gift_unique->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (!gift) {
        goto end;
    }

    
    gift_local_nonprim = unique_gift_parseFromJSON(gift); //nonprimitive

    // owned_gift_unique->send_date
    cJSON *send_date = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "send_date");
    if (cJSON_IsNull(send_date)) {
        send_date = NULL;
    }
    if (!send_date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(send_date))
    {
    goto end; //Numeric
    }

    // owned_gift_unique->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (owned_gift_id) { 
    if(!cJSON_IsString(owned_gift_id) && !cJSON_IsNull(owned_gift_id))
    {
    goto end; //String
    }
    }

    // owned_gift_unique->sender_user
    cJSON *sender_user = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "sender_user");
    if (cJSON_IsNull(sender_user)) {
        sender_user = NULL;
    }
    if (sender_user) { 
    sender_user_local_nonprim = user_parseFromJSON(sender_user); //nonprimitive
    }

    // owned_gift_unique->is_saved
    cJSON *is_saved = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "is_saved");
    if (cJSON_IsNull(is_saved)) {
        is_saved = NULL;
    }
    if (is_saved) { 
    if(!cJSON_IsBool(is_saved))
    {
    goto end; //Bool
    }
    }

    // owned_gift_unique->can_be_transferred
    cJSON *can_be_transferred = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "can_be_transferred");
    if (cJSON_IsNull(can_be_transferred)) {
        can_be_transferred = NULL;
    }
    if (can_be_transferred) { 
    if(!cJSON_IsBool(can_be_transferred))
    {
    goto end; //Bool
    }
    }

    // owned_gift_unique->transfer_star_count
    cJSON *transfer_star_count = cJSON_GetObjectItemCaseSensitive(owned_gift_uniqueJSON, "transfer_star_count");
    if (cJSON_IsNull(transfer_star_count)) {
        transfer_star_count = NULL;
    }
    if (transfer_star_count) { 
    if(!cJSON_IsNumber(transfer_star_count))
    {
    goto end; //Numeric
    }
    }


    owned_gift_unique_local_var = owned_gift_unique_create_internal (
        strdup(type->valuestring),
        gift_local_nonprim,
        send_date->valuedouble,
        owned_gift_id && !cJSON_IsNull(owned_gift_id) ? strdup(owned_gift_id->valuestring) : NULL,
        sender_user ? sender_user_local_nonprim : NULL,
        is_saved ? is_saved->valueint : 0,
        can_be_transferred ? can_be_transferred->valueint : 0,
        transfer_star_count ? transfer_star_count->valuedouble : 0
        );

    return owned_gift_unique_local_var;
end:
    if (gift_local_nonprim) {
        unique_gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    if (sender_user_local_nonprim) {
        user_free(sender_user_local_nonprim);
        sender_user_local_nonprim = NULL;
    }
    return NULL;

}
