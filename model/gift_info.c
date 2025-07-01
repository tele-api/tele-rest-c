#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gift_info.h"



static gift_info_t *gift_info_create_internal(
    gift_t *gift,
    char *owned_gift_id,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_upgraded,
    char *text,
    list_t *entities,
    int is_private
    ) {
    gift_info_t *gift_info_local_var = malloc(sizeof(gift_info_t));
    if (!gift_info_local_var) {
        return NULL;
    }
    gift_info_local_var->gift = gift;
    gift_info_local_var->owned_gift_id = owned_gift_id;
    gift_info_local_var->convert_star_count = convert_star_count;
    gift_info_local_var->prepaid_upgrade_star_count = prepaid_upgrade_star_count;
    gift_info_local_var->can_be_upgraded = can_be_upgraded;
    gift_info_local_var->text = text;
    gift_info_local_var->entities = entities;
    gift_info_local_var->is_private = is_private;

    gift_info_local_var->_library_owned = 1;
    return gift_info_local_var;
}

__attribute__((deprecated)) gift_info_t *gift_info_create(
    gift_t *gift,
    char *owned_gift_id,
    int convert_star_count,
    int prepaid_upgrade_star_count,
    int can_be_upgraded,
    char *text,
    list_t *entities,
    int is_private
    ) {
    return gift_info_create_internal (
        gift,
        owned_gift_id,
        convert_star_count,
        prepaid_upgrade_star_count,
        can_be_upgraded,
        text,
        entities,
        is_private
        );
}

void gift_info_free(gift_info_t *gift_info) {
    if(NULL == gift_info){
        return ;
    }
    if(gift_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gift_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gift_info->gift) {
        gift_free(gift_info->gift);
        gift_info->gift = NULL;
    }
    if (gift_info->owned_gift_id) {
        free(gift_info->owned_gift_id);
        gift_info->owned_gift_id = NULL;
    }
    if (gift_info->text) {
        free(gift_info->text);
        gift_info->text = NULL;
    }
    if (gift_info->entities) {
        list_ForEach(listEntry, gift_info->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(gift_info->entities);
        gift_info->entities = NULL;
    }
    free(gift_info);
}

cJSON *gift_info_convertToJSON(gift_info_t *gift_info) {
    cJSON *item = cJSON_CreateObject();

    // gift_info->gift
    if (!gift_info->gift) {
        goto fail;
    }
    cJSON *gift_local_JSON = gift_convertToJSON(gift_info->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // gift_info->owned_gift_id
    if(gift_info->owned_gift_id) {
    if(cJSON_AddStringToObject(item, "owned_gift_id", gift_info->owned_gift_id) == NULL) {
    goto fail; //String
    }
    }


    // gift_info->convert_star_count
    if(gift_info->convert_star_count) {
    if(cJSON_AddNumberToObject(item, "convert_star_count", gift_info->convert_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // gift_info->prepaid_upgrade_star_count
    if(gift_info->prepaid_upgrade_star_count) {
    if(cJSON_AddNumberToObject(item, "prepaid_upgrade_star_count", gift_info->prepaid_upgrade_star_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // gift_info->can_be_upgraded
    if(gift_info->can_be_upgraded) {
    if(cJSON_AddBoolToObject(item, "can_be_upgraded", gift_info->can_be_upgraded) == NULL) {
    goto fail; //Bool
    }
    }


    // gift_info->text
    if(gift_info->text) {
    if(cJSON_AddStringToObject(item, "text", gift_info->text) == NULL) {
    goto fail; //String
    }
    }


    // gift_info->entities
    if(gift_info->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (gift_info->entities) {
    list_ForEach(entitiesListEntry, gift_info->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // gift_info->is_private
    if(gift_info->is_private) {
    if(cJSON_AddBoolToObject(item, "is_private", gift_info->is_private) == NULL) {
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

gift_info_t *gift_info_parseFromJSON(cJSON *gift_infoJSON){

    gift_info_t *gift_info_local_var = NULL;

    // define the local variable for gift_info->gift
    gift_t *gift_local_nonprim = NULL;

    // define the local list for gift_info->entities
    list_t *entitiesList = NULL;

    // gift_info->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (!gift) {
        goto end;
    }

    
    gift_local_nonprim = gift_parseFromJSON(gift); //nonprimitive

    // gift_info->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (owned_gift_id) { 
    if(!cJSON_IsString(owned_gift_id) && !cJSON_IsNull(owned_gift_id))
    {
    goto end; //String
    }
    }

    // gift_info->convert_star_count
    cJSON *convert_star_count = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "convert_star_count");
    if (cJSON_IsNull(convert_star_count)) {
        convert_star_count = NULL;
    }
    if (convert_star_count) { 
    if(!cJSON_IsNumber(convert_star_count))
    {
    goto end; //Numeric
    }
    }

    // gift_info->prepaid_upgrade_star_count
    cJSON *prepaid_upgrade_star_count = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "prepaid_upgrade_star_count");
    if (cJSON_IsNull(prepaid_upgrade_star_count)) {
        prepaid_upgrade_star_count = NULL;
    }
    if (prepaid_upgrade_star_count) { 
    if(!cJSON_IsNumber(prepaid_upgrade_star_count))
    {
    goto end; //Numeric
    }
    }

    // gift_info->can_be_upgraded
    cJSON *can_be_upgraded = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "can_be_upgraded");
    if (cJSON_IsNull(can_be_upgraded)) {
        can_be_upgraded = NULL;
    }
    if (can_be_upgraded) { 
    if(!cJSON_IsBool(can_be_upgraded))
    {
    goto end; //Bool
    }
    }

    // gift_info->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // gift_info->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "entities");
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

    // gift_info->is_private
    cJSON *is_private = cJSON_GetObjectItemCaseSensitive(gift_infoJSON, "is_private");
    if (cJSON_IsNull(is_private)) {
        is_private = NULL;
    }
    if (is_private) { 
    if(!cJSON_IsBool(is_private))
    {
    goto end; //Bool
    }
    }


    gift_info_local_var = gift_info_create_internal (
        gift_local_nonprim,
        owned_gift_id && !cJSON_IsNull(owned_gift_id) ? strdup(owned_gift_id->valuestring) : NULL,
        convert_star_count ? convert_star_count->valuedouble : 0,
        prepaid_upgrade_star_count ? prepaid_upgrade_star_count->valuedouble : 0,
        can_be_upgraded ? can_be_upgraded->valueint : 0,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        entities ? entitiesList : NULL,
        is_private ? is_private->valueint : 0
        );

    return gift_info_local_var;
end:
    if (gift_local_nonprim) {
        gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
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
