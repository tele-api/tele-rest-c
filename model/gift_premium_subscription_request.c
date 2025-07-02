#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gift_premium_subscription_request.h"


char* gift_premium_subscription_request_month_count_ToString(telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_e month_count) {
    char* month_countArray[] =  { "NULL", "3", "6", "12" };
    return month_countArray[month_count];
}

telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_e gift_premium_subscription_request_month_count_FromString(char* month_count){
    int stringToReturn = 0;
    char *month_countArray[] =  { "NULL", "3", "6", "12" };
    size_t sizeofArray = sizeof(month_countArray) / sizeof(month_countArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(month_count, month_countArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static gift_premium_subscription_request_t *gift_premium_subscription_request_create_internal(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    gift_premium_subscription_request_t *gift_premium_subscription_request_local_var = malloc(sizeof(gift_premium_subscription_request_t));
    if (!gift_premium_subscription_request_local_var) {
        return NULL;
    }
    gift_premium_subscription_request_local_var->user_id = user_id;
    gift_premium_subscription_request_local_var->month_count = month_count;
    gift_premium_subscription_request_local_var->star_count = star_count;
    gift_premium_subscription_request_local_var->text = text;
    gift_premium_subscription_request_local_var->text_parse_mode = text_parse_mode;
    gift_premium_subscription_request_local_var->text_entities = text_entities;

    gift_premium_subscription_request_local_var->_library_owned = 1;
    return gift_premium_subscription_request_local_var;
}

__attribute__((deprecated)) gift_premium_subscription_request_t *gift_premium_subscription_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    return gift_premium_subscription_request_create_internal (
        user_id,
        month_count,
        star_count,
        text,
        text_parse_mode,
        text_entities
        );
}

void gift_premium_subscription_request_free(gift_premium_subscription_request_t *gift_premium_subscription_request) {
    if(NULL == gift_premium_subscription_request){
        return ;
    }
    if(gift_premium_subscription_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gift_premium_subscription_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gift_premium_subscription_request->text) {
        free(gift_premium_subscription_request->text);
        gift_premium_subscription_request->text = NULL;
    }
    if (gift_premium_subscription_request->text_parse_mode) {
        free(gift_premium_subscription_request->text_parse_mode);
        gift_premium_subscription_request->text_parse_mode = NULL;
    }
    if (gift_premium_subscription_request->text_entities) {
        list_ForEach(listEntry, gift_premium_subscription_request->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(gift_premium_subscription_request->text_entities);
        gift_premium_subscription_request->text_entities = NULL;
    }
    free(gift_premium_subscription_request);
}

cJSON *gift_premium_subscription_request_convertToJSON(gift_premium_subscription_request_t *gift_premium_subscription_request) {
    cJSON *item = cJSON_CreateObject();

    // gift_premium_subscription_request->user_id
    if (!gift_premium_subscription_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", gift_premium_subscription_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // gift_premium_subscription_request->month_count
    if (telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_NULL == gift_premium_subscription_request->month_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month_count", gift_premium_subscription_request->month_count) == NULL) {
    goto fail; //Numeric
    }


    // gift_premium_subscription_request->star_count
    if (!gift_premium_subscription_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", gift_premium_subscription_request->star_count) == NULL) {
    goto fail; //Numeric
    }


    // gift_premium_subscription_request->text
    if(gift_premium_subscription_request->text) {
    if(cJSON_AddStringToObject(item, "text", gift_premium_subscription_request->text) == NULL) {
    goto fail; //String
    }
    }


    // gift_premium_subscription_request->text_parse_mode
    if(gift_premium_subscription_request->text_parse_mode) {
    if(cJSON_AddStringToObject(item, "text_parse_mode", gift_premium_subscription_request->text_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // gift_premium_subscription_request->text_entities
    if(gift_premium_subscription_request->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (gift_premium_subscription_request->text_entities) {
    list_ForEach(text_entitiesListEntry, gift_premium_subscription_request->text_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(text_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(text_entities, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gift_premium_subscription_request_t *gift_premium_subscription_request_parseFromJSON(cJSON *gift_premium_subscription_requestJSON){

    gift_premium_subscription_request_t *gift_premium_subscription_request_local_var = NULL;

    // define the local list for gift_premium_subscription_request->text_entities
    list_t *text_entitiesList = NULL;

    // gift_premium_subscription_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // gift_premium_subscription_request->month_count
    cJSON *month_count = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "month_count");
    if (cJSON_IsNull(month_count)) {
        month_count = NULL;
    }
    if (!month_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(month_count))
    {
    goto end; //Numeric
    }

    // gift_premium_subscription_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }

    // gift_premium_subscription_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // gift_premium_subscription_request->text_parse_mode
    cJSON *text_parse_mode = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "text_parse_mode");
    if (cJSON_IsNull(text_parse_mode)) {
        text_parse_mode = NULL;
    }
    if (text_parse_mode) { 
    if(!cJSON_IsString(text_parse_mode) && !cJSON_IsNull(text_parse_mode))
    {
    goto end; //String
    }
    }

    // gift_premium_subscription_request->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_requestJSON, "text_entities");
    if (cJSON_IsNull(text_entities)) {
        text_entities = NULL;
    }
    if (text_entities) { 
    cJSON *text_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(text_entities)){
        goto end; //nonprimitive container
    }

    text_entitiesList = list_createList();

    cJSON_ArrayForEach(text_entities_local_nonprimitive,text_entities )
    {
        if(!cJSON_IsObject(text_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *text_entitiesItem = message_entity_parseFromJSON(text_entities_local_nonprimitive);

        list_addElement(text_entitiesList, text_entitiesItem);
    }
    }


    gift_premium_subscription_request_local_var = gift_premium_subscription_request_create_internal (
        user_id->valuedouble,
        month_count->valuedouble,
        star_count->valuedouble,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        text_parse_mode && !cJSON_IsNull(text_parse_mode) ? strdup(text_parse_mode->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL
        );

    return gift_premium_subscription_request_local_var;
end:
    if (text_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, text_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(text_entitiesList);
        text_entitiesList = NULL;
    }
    return NULL;

}
