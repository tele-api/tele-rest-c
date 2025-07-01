#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unique_gift_info.h"


char* unique_gift_info_origin_ToString(telegram_bot_api_unique_gift_info_ORIGIN_e origin) {
    char* originArray[] =  { "NULL", "upgrade", "transfer" };
    return originArray[origin];
}

telegram_bot_api_unique_gift_info_ORIGIN_e unique_gift_info_origin_FromString(char* origin){
    int stringToReturn = 0;
    char *originArray[] =  { "NULL", "upgrade", "transfer" };
    size_t sizeofArray = sizeof(originArray) / sizeof(originArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(origin, originArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static unique_gift_info_t *unique_gift_info_create_internal(
    unique_gift_t *gift,
    telegram_bot_api_unique_gift_info_ORIGIN_e origin,
    char *owned_gift_id,
    int transfer_star_count
    ) {
    unique_gift_info_t *unique_gift_info_local_var = malloc(sizeof(unique_gift_info_t));
    if (!unique_gift_info_local_var) {
        return NULL;
    }
    unique_gift_info_local_var->gift = gift;
    unique_gift_info_local_var->origin = origin;
    unique_gift_info_local_var->owned_gift_id = owned_gift_id;
    unique_gift_info_local_var->transfer_star_count = transfer_star_count;

    unique_gift_info_local_var->_library_owned = 1;
    return unique_gift_info_local_var;
}

__attribute__((deprecated)) unique_gift_info_t *unique_gift_info_create(
    unique_gift_t *gift,
    telegram_bot_api_unique_gift_info_ORIGIN_e origin,
    char *owned_gift_id,
    int transfer_star_count
    ) {
    return unique_gift_info_create_internal (
        gift,
        origin,
        owned_gift_id,
        transfer_star_count
        );
}

void unique_gift_info_free(unique_gift_info_t *unique_gift_info) {
    if(NULL == unique_gift_info){
        return ;
    }
    if(unique_gift_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unique_gift_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unique_gift_info->gift) {
        unique_gift_free(unique_gift_info->gift);
        unique_gift_info->gift = NULL;
    }
    if (unique_gift_info->owned_gift_id) {
        free(unique_gift_info->owned_gift_id);
        unique_gift_info->owned_gift_id = NULL;
    }
    free(unique_gift_info);
}

cJSON *unique_gift_info_convertToJSON(unique_gift_info_t *unique_gift_info) {
    cJSON *item = cJSON_CreateObject();

    // unique_gift_info->gift
    if (!unique_gift_info->gift) {
        goto fail;
    }
    cJSON *gift_local_JSON = unique_gift_convertToJSON(unique_gift_info->gift);
    if(gift_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gift", gift_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unique_gift_info->origin
    if (telegram_bot_api_unique_gift_info_ORIGIN_NULL == unique_gift_info->origin) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "origin", unique_gift_info_origin_ToString(unique_gift_info->origin)) == NULL)
    {
    goto fail; //Enum
    }


    // unique_gift_info->owned_gift_id
    if(unique_gift_info->owned_gift_id) {
    if(cJSON_AddStringToObject(item, "owned_gift_id", unique_gift_info->owned_gift_id) == NULL) {
    goto fail; //String
    }
    }


    // unique_gift_info->transfer_star_count
    if(unique_gift_info->transfer_star_count) {
    if(cJSON_AddNumberToObject(item, "transfer_star_count", unique_gift_info->transfer_star_count) == NULL) {
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

unique_gift_info_t *unique_gift_info_parseFromJSON(cJSON *unique_gift_infoJSON){

    unique_gift_info_t *unique_gift_info_local_var = NULL;

    // define the local variable for unique_gift_info->gift
    unique_gift_t *gift_local_nonprim = NULL;

    // unique_gift_info->gift
    cJSON *gift = cJSON_GetObjectItemCaseSensitive(unique_gift_infoJSON, "gift");
    if (cJSON_IsNull(gift)) {
        gift = NULL;
    }
    if (!gift) {
        goto end;
    }

    
    gift_local_nonprim = unique_gift_parseFromJSON(gift); //nonprimitive

    // unique_gift_info->origin
    cJSON *origin = cJSON_GetObjectItemCaseSensitive(unique_gift_infoJSON, "origin");
    if (cJSON_IsNull(origin)) {
        origin = NULL;
    }
    if (!origin) {
        goto end;
    }

    telegram_bot_api_unique_gift_info_ORIGIN_e originVariable;
    
    if(!cJSON_IsString(origin))
    {
    goto end; //Enum
    }
    originVariable = unique_gift_info_origin_FromString(origin->valuestring);

    // unique_gift_info->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(unique_gift_infoJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (owned_gift_id) { 
    if(!cJSON_IsString(owned_gift_id) && !cJSON_IsNull(owned_gift_id))
    {
    goto end; //String
    }
    }

    // unique_gift_info->transfer_star_count
    cJSON *transfer_star_count = cJSON_GetObjectItemCaseSensitive(unique_gift_infoJSON, "transfer_star_count");
    if (cJSON_IsNull(transfer_star_count)) {
        transfer_star_count = NULL;
    }
    if (transfer_star_count) { 
    if(!cJSON_IsNumber(transfer_star_count))
    {
    goto end; //Numeric
    }
    }


    unique_gift_info_local_var = unique_gift_info_create_internal (
        gift_local_nonprim,
        originVariable,
        owned_gift_id && !cJSON_IsNull(owned_gift_id) ? strdup(owned_gift_id->valuestring) : NULL,
        transfer_star_count ? transfer_star_count->valuedouble : 0
        );

    return unique_gift_info_local_var;
end:
    if (gift_local_nonprim) {
        unique_gift_free(gift_local_nonprim);
        gift_local_nonprim = NULL;
    }
    return NULL;

}
