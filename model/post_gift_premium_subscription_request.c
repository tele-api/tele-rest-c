#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_gift_premium_subscription_request.h"


char* post_gift_premium_subscription_request_month_count_ToString(telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_e month_count) {
    char* month_countArray[] =  { "NULL", "3", "6", "12" };
    return month_countArray[month_count];
}

telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_e post_gift_premium_subscription_request_month_count_FromString(char* month_count){
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

static post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_create_internal(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_local_var = malloc(sizeof(post_gift_premium_subscription_request_t));
    if (!post_gift_premium_subscription_request_local_var) {
        return NULL;
    }
    post_gift_premium_subscription_request_local_var->user_id = user_id;
    post_gift_premium_subscription_request_local_var->month_count = month_count;
    post_gift_premium_subscription_request_local_var->star_count = star_count;
    post_gift_premium_subscription_request_local_var->text = text;
    post_gift_premium_subscription_request_local_var->text_parse_mode = text_parse_mode;
    post_gift_premium_subscription_request_local_var->text_entities = text_entities;

    post_gift_premium_subscription_request_local_var->_library_owned = 1;
    return post_gift_premium_subscription_request_local_var;
}

__attribute__((deprecated)) post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    return post_gift_premium_subscription_request_create_internal (
        user_id,
        month_count,
        star_count,
        text,
        text_parse_mode,
        text_entities
        );
}

void post_gift_premium_subscription_request_free(post_gift_premium_subscription_request_t *post_gift_premium_subscription_request) {
    if(NULL == post_gift_premium_subscription_request){
        return ;
    }
    if(post_gift_premium_subscription_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_gift_premium_subscription_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_gift_premium_subscription_request->text) {
        free(post_gift_premium_subscription_request->text);
        post_gift_premium_subscription_request->text = NULL;
    }
    if (post_gift_premium_subscription_request->text_parse_mode) {
        free(post_gift_premium_subscription_request->text_parse_mode);
        post_gift_premium_subscription_request->text_parse_mode = NULL;
    }
    if (post_gift_premium_subscription_request->text_entities) {
        list_ForEach(listEntry, post_gift_premium_subscription_request->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(post_gift_premium_subscription_request->text_entities);
        post_gift_premium_subscription_request->text_entities = NULL;
    }
    free(post_gift_premium_subscription_request);
}

cJSON *post_gift_premium_subscription_request_convertToJSON(post_gift_premium_subscription_request_t *post_gift_premium_subscription_request) {
    cJSON *item = cJSON_CreateObject();

    // post_gift_premium_subscription_request->user_id
    if (!post_gift_premium_subscription_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_gift_premium_subscription_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_gift_premium_subscription_request->month_count
    if (telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_NULL == post_gift_premium_subscription_request->month_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month_count", post_gift_premium_subscription_request->month_count) == NULL) {
    goto fail; //Numeric
    }


    // post_gift_premium_subscription_request->star_count
    if (!post_gift_premium_subscription_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", post_gift_premium_subscription_request->star_count) == NULL) {
    goto fail; //Numeric
    }


    // post_gift_premium_subscription_request->text
    if(post_gift_premium_subscription_request->text) {
    if(cJSON_AddStringToObject(item, "text", post_gift_premium_subscription_request->text) == NULL) {
    goto fail; //String
    }
    }


    // post_gift_premium_subscription_request->text_parse_mode
    if(post_gift_premium_subscription_request->text_parse_mode) {
    if(cJSON_AddStringToObject(item, "text_parse_mode", post_gift_premium_subscription_request->text_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // post_gift_premium_subscription_request->text_entities
    if(post_gift_premium_subscription_request->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (post_gift_premium_subscription_request->text_entities) {
    list_ForEach(text_entitiesListEntry, post_gift_premium_subscription_request->text_entities) {
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

post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_parseFromJSON(cJSON *post_gift_premium_subscription_requestJSON){

    post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_local_var = NULL;

    // define the local list for post_gift_premium_subscription_request->text_entities
    list_t *text_entitiesList = NULL;

    // post_gift_premium_subscription_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "user_id");
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

    // post_gift_premium_subscription_request->month_count
    cJSON *month_count = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "month_count");
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

    // post_gift_premium_subscription_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "star_count");
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

    // post_gift_premium_subscription_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // post_gift_premium_subscription_request->text_parse_mode
    cJSON *text_parse_mode = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "text_parse_mode");
    if (cJSON_IsNull(text_parse_mode)) {
        text_parse_mode = NULL;
    }
    if (text_parse_mode) { 
    if(!cJSON_IsString(text_parse_mode) && !cJSON_IsNull(text_parse_mode))
    {
    goto end; //String
    }
    }

    // post_gift_premium_subscription_request->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(post_gift_premium_subscription_requestJSON, "text_entities");
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


    post_gift_premium_subscription_request_local_var = post_gift_premium_subscription_request_create_internal (
        user_id->valuedouble,
        month_count->valuedouble,
        star_count->valuedouble,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        text_parse_mode && !cJSON_IsNull(text_parse_mode) ? strdup(text_parse_mode->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL
        );

    return post_gift_premium_subscription_request_local_var;
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
