#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "owned_gift.h"



static owned_gift_t *owned_gift_create_internal(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    char *text,
    list_t *entities,
    int is_private,
    int is_saved,
    int can_be_upgraded,
    int was_refunded,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_transferred,
    int transfer_star_count
    ) {
    owned_gift_t *owned_gift_local_var = malloc(sizeof(owned_gift_t));
    if (!owned_gift_local_var) {
        return NULL;
    }
    owned_gift_local_var->type = type;
    owned_gift_local_var->gift = gift;
    owned_gift_local_var->send_date = send_date;
    owned_gift_local_var->owned_gift_id = owned_gift_id;
    owned_gift_local_var->sender_user = sender_user;
    owned_gift_local_var->text = text;
    owned_gift_local_var->entities = entities;
    owned_gift_local_var->is_private = is_private;
    owned_gift_local_var->is_saved = is_saved;
    owned_gift_local_var->can_be_upgraded = can_be_upgraded;
    owned_gift_local_var->was_refunded = was_refunded;
    owned_gift_local_var->convert_star_count = convert_star_count;
    owned_gift_local_var->prepaid_upgrade_star_count = prepaid_upgrade_star_count;
    owned_gift_local_var->can_be_transferred = can_be_transferred;
    owned_gift_local_var->transfer_star_count = transfer_star_count;

    owned_gift_local_var->_library_owned = 1;
    return owned_gift_local_var;
}

__attribute__((deprecated)) owned_gift_t *owned_gift_create(
    char *type,
    unique_gift_t *gift,
    int send_date,
    char *owned_gift_id,
    user_t *sender_user,
    char *text,
    list_t *entities,
    int is_private,
    int is_saved,
    int can_be_upgraded,
    int was_refunded,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_transferred,
    int transfer_star_count
    ) {
    return owned_gift_create_internal (
        type,
        gift,
        send_date,
        owned_gift_id,
        sender_user,
        text,
        entities,
        is_private,
        is_saved,
        can_be_upgraded,
        was_refunded,
        convert_star_count,
        prepaid_upgrade_star_count,
        can_be_transferred,
        transfer_star_count
        );
}

void owned_gift_free(owned_gift_t *owned_gift) {
    if(NULL == owned_gift){
        return ;
    }
    if(owned_gift->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "owned_gift_free");
        return ;
    }
    listEntry_t *listEntry;
    if (owned_gift->type) {
        free(owned_gift->type);
        owned_gift->type = NULL;
    }
    if (owned_gift->gift) {
        unique_gift_free(owned_gift->gift);
        owned_gift->gift = NULL;
    }
    if (owned_gift->owned_gift_id) {
        free(owned_gift->owned_gift_id);
        owned_gift->owned_gift_id = NULL;
    }
    if (owned_gift->sender_user) {
        user_free(owned_gift->sender_user);
        owned_gift->sender_user = NULL;
    }
    if (owned_gift->text) {
        free(owned_gift->text);
        owned_gift->text = NULL;
    }
    if (owned_gift->entities) {
        list_ForEach(listEntry, owned_gift->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(owned_gift->entities);
        owned_gift->entities = NULL;
    }
    free(owned_gift);
}

cJSON *owned_gift_convertToJSON(owned_gift_t *owned_gift) {
    cJSON *item = cJSON_CreateObject();

    // owned_gift->type
    if (!owned_gift->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", owned_gift->type) == NULL) {
    goto fail; //String
    }


    // owned_gift->gift
    if (!owned_gift->gift) {
        goto fail;
    }
    cJSON *gift_local_JSON = unique_gift_convertToJSON(owned_gift->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // owned_gift->send_date
    if (!owned_gift->send_date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "send_date", owned_gift->send_date) == NULL) {
    goto fail; //Numeric
    }


    // owned_gift->owned_gift_id
    if(owned_gift->owned_gift_id) {
    if(cJSON_AddStringToObject(item, "owned_gift_id", owned_gift->owned_gift_id) == NULL) {
    goto fail; //String
    }
    }


    // owned_gift->sender_user
    if(owned_gift->sender_user) {
    cJSON *sender_user_local_JSON = user_convertToJSON(owned_gift->sender_user);
    if(sender_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sender_user", sender_user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // owned_gift->text
    if(owned_gift->text) {
    if(cJSON_AddStringToObject(item, "text", owned_gift->text) == NULL) {
    goto fail; //String
    }
    }


    // owned_gift->entities
    if(owned_gift->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (owned_gift->entities) {
    list_ForEach(entitiesListEntry, owned_gift->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // owned_gift->is_private
    if(owned_gift->is_private) {
    if(cJSON_AddBoolToObject(item, "is_private", owned_gift->is_private) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift->is_saved
    if(owned_gift->is_saved) {
    if(cJSON_AddBoolToObject(item, "is_saved", owned_gift->is_saved) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift->can_be_upgraded
    if(owned_gift->can_be_upgraded) {
    if(cJSON_AddBoolToObject(item, "can_be_upgraded", owned_gift->can_be_upgraded) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift->was_refunded
    if(owned_gift->was_refunded) {
    if(cJSON_AddBoolToObject(item, "was_refunded", owned_gift->was_refunded) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift->convert_star_count
    if(owned_gift->convert_star_count) {
    if(cJSON_AddNumberToObject(item, "convert_star_count", owned_gift->convert_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // owned_gift->prepaid_upgrade_star_count
    if(owned_gift->prepaid_upgrade_star_count) {
    if(cJSON_AddNumberToObject(item, "prepaid_upgrade_star_count", owned_gift->prepaid_upgrade_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // owned_gift->can_be_transferred
    if(owned_gift->can_be_transferred) {
    if(cJSON_AddBoolToObject(item, "can_be_transferred", owned_gift->can_be_transferred) == NULL) {
    goto fail; //Bool
    }
    }


    // owned_gift->transfer_star_count
    if(owned_gift->transfer_star_count) {
    if(cJSON_AddNumberToObject(item, "transfer_star_count", owned_gift->transfer_star_count) == NULL) {
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

owned_gift_t *owned_gift_parseFromJSON(cJSON *owned_giftJSON){

    owned_gift_t *owned_gift_local_var = NULL;

    // define the local variable for owned_gift->gift
    unique_gift_t *gift_local_nonprim = NULL;

    // define the local variable for owned_gift->sender_user
    user_t *sender_user_local_nonprim = NULL;

    // define the local list for owned_gift->entities
    list_t *entitiesList = NULL;

    // owned_gift->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "type");
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

    // owned_gift->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (!gift) {
        goto end;
    }

    
    gift_local_nonprim = unique_gift_parseFromJSON(gift); //nonprimitive

    // owned_gift->send_date
    cJSON *send_date = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "send_date");
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

    // owned_gift->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (owned_gift_id) { 
    if(!cJSON_IsString(owned_gift_id) && !cJSON_IsNull(owned_gift_id))
    {
    goto end; //String
    }
    }

    // owned_gift->sender_user
    cJSON *sender_user = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "sender_user");
    if (cJSON_IsNull(sender_user)) {
        sender_user = NULL;
    }
    if (sender_user) { 
    sender_user_local_nonprim = user_parseFromJSON(sender_user); //nonprimitive
    }

    // owned_gift->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // owned_gift->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "entities");
    if (cJSON_IsNull(entities)) {
        entities = NULL;
    }
    if (entities) { 
    cJSON *entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(entities)){
        goto end; //nonprimitive container
    }

    entitiesList = list_createList();

    cJSON_ArrayForEach(entities_local_nonprimitive,entities )
    {
        if(!cJSON_IsObject(entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *entitiesItem = message_entity_parseFromJSON(entities_local_nonprimitive);

        list_addElement(entitiesList, entitiesItem);
    }
    }

    // owned_gift->is_private
    cJSON *is_private = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "is_private");
    if (cJSON_IsNull(is_private)) {
        is_private = NULL;
    }
    if (is_private) { 
    if(!cJSON_IsBool(is_private))
    {
    goto end; //Bool
    }
    }

    // owned_gift->is_saved
    cJSON *is_saved = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "is_saved");
    if (cJSON_IsNull(is_saved)) {
        is_saved = NULL;
    }
    if (is_saved) { 
    if(!cJSON_IsBool(is_saved))
    {
    goto end; //Bool
    }
    }

    // owned_gift->can_be_upgraded
    cJSON *can_be_upgraded = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "can_be_upgraded");
    if (cJSON_IsNull(can_be_upgraded)) {
        can_be_upgraded = NULL;
    }
    if (can_be_upgraded) { 
    if(!cJSON_IsBool(can_be_upgraded))
    {
    goto end; //Bool
    }
    }

    // owned_gift->was_refunded
    cJSON *was_refunded = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "was_refunded");
    if (cJSON_IsNull(was_refunded)) {
        was_refunded = NULL;
    }
    if (was_refunded) { 
    if(!cJSON_IsBool(was_refunded))
    {
    goto end; //Bool
    }
    }

    // owned_gift->convert_star_count
    cJSON *convert_star_count = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "convert_star_count");
    if (cJSON_IsNull(convert_star_count)) {
        convert_star_count = NULL;
    }
    if (convert_star_count) { 
    if(!cJSON_IsNumber(convert_star_count))
    {
    goto end; //Numeric
    }
    }

    // owned_gift->prepaid_upgrade_star_count
    cJSON *prepaid_upgrade_star_count = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "prepaid_upgrade_star_count");
    if (cJSON_IsNull(prepaid_upgrade_star_count)) {
        prepaid_upgrade_star_count = NULL;
    }
    if (prepaid_upgrade_star_count) { 
    if(!cJSON_IsNumber(prepaid_upgrade_star_count))
    {
    goto end; //Numeric
    }
    }

    // owned_gift->can_be_transferred
    cJSON *can_be_transferred = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "can_be_transferred");
    if (cJSON_IsNull(can_be_transferred)) {
        can_be_transferred = NULL;
    }
    if (can_be_transferred) { 
    if(!cJSON_IsBool(can_be_transferred))
    {
    goto end; //Bool
    }
    }

    // owned_gift->transfer_star_count
    cJSON *transfer_star_count = cJSON_GetObjectItemCaseSensitive(owned_giftJSON, "transfer_star_count");
    if (cJSON_IsNull(transfer_star_count)) {
        transfer_star_count = NULL;
    }
    if (transfer_star_count) { 
    if(!cJSON_IsNumber(transfer_star_count))
    {
    goto end; //Numeric
    }
    }


    owned_gift_local_var = owned_gift_create_internal (
        strdup(type->valuestring),
        gift_local_nonprim,
        send_date->valuedouble,
        owned_gift_id && !cJSON_IsNull(owned_gift_id) ? strdup(owned_gift_id->valuestring) : NULL,
        sender_user ? sender_user_local_nonprim : NULL,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        entities ? entitiesList : NULL,
        is_private ? is_private->valueint : 0,
        is_saved ? is_saved->valueint : 0,
        can_be_upgraded ? can_be_upgraded->valueint : 0,
        was_refunded ? was_refunded->valueint : 0,
        convert_star_count ? convert_star_count->valuedouble : 0,
        prepaid_upgrade_star_count ? prepaid_upgrade_star_count->valuedouble : 0,
        can_be_transferred ? can_be_transferred->valueint : 0,
        transfer_star_count ? transfer_star_count->valuedouble : 0
        );

    return owned_gift_local_var;
end:
    if (gift_local_nonprim) {
        unique_gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    if (sender_user_local_nonprim) {
        user_free(sender_user_local_nonprim);
        sender_user_local_nonprim = NULL;
    }
    if (entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entitiesList);
        entitiesList = NULL;
    }
    return NULL;

}
