#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_gift_premium_subscription_post_request.h"


char* _gift_premium_subscription_post_request_month_count_ToString(telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_e month_count) {
    char* month_countArray[] =  { "NULL", "3", "6", "12" };
    return month_countArray[month_count];
}

telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_e _gift_premium_subscription_post_request_month_count_FromString(char* month_count){
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

static _gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_create_internal(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    _gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_local_var = malloc(sizeof(_gift_premium_subscription_post_request_t));
    if (!_gift_premium_subscription_post_request_local_var) {
        return NULL;
    }
    _gift_premium_subscription_post_request_local_var->user_id = user_id;
    _gift_premium_subscription_post_request_local_var->month_count = month_count;
    _gift_premium_subscription_post_request_local_var->star_count = star_count;
    _gift_premium_subscription_post_request_local_var->text = text;
    _gift_premium_subscription_post_request_local_var->text_parse_mode = text_parse_mode;
    _gift_premium_subscription_post_request_local_var->text_entities = text_entities;

    _gift_premium_subscription_post_request_local_var->_library_owned = 1;
    return _gift_premium_subscription_post_request_local_var;
}

__attribute__((deprecated)) _gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    return _gift_premium_subscription_post_request_create_internal (
        user_id,
        month_count,
        star_count,
        text,
        text_parse_mode,
        text_entities
        );
}

void _gift_premium_subscription_post_request_free(_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request) {
    if(NULL == _gift_premium_subscription_post_request){
        return ;
    }
    if(_gift_premium_subscription_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_gift_premium_subscription_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_gift_premium_subscription_post_request->text) {
        free(_gift_premium_subscription_post_request->text);
        _gift_premium_subscription_post_request->text = NULL;
    }
    if (_gift_premium_subscription_post_request->text_parse_mode) {
        free(_gift_premium_subscription_post_request->text_parse_mode);
        _gift_premium_subscription_post_request->text_parse_mode = NULL;
    }
    if (_gift_premium_subscription_post_request->text_entities) {
        list_ForEach(listEntry, _gift_premium_subscription_post_request->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_gift_premium_subscription_post_request->text_entities);
        _gift_premium_subscription_post_request->text_entities = NULL;
    }
    free(_gift_premium_subscription_post_request);
}

cJSON *_gift_premium_subscription_post_request_convertToJSON(_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _gift_premium_subscription_post_request->user_id
    if (!_gift_premium_subscription_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _gift_premium_subscription_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _gift_premium_subscription_post_request->month_count
    if (telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_NULL == _gift_premium_subscription_post_request->month_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "month_count", _gift_premium_subscription_post_request->month_count) == NULL) {
    goto fail; //Numeric
    }


    // _gift_premium_subscription_post_request->star_count
    if (!_gift_premium_subscription_post_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", _gift_premium_subscription_post_request->star_count) == NULL) {
    goto fail; //Numeric
    }


    // _gift_premium_subscription_post_request->text
    if(_gift_premium_subscription_post_request->text) {
    if(cJSON_AddStringToObject(item, "text", _gift_premium_subscription_post_request->text) == NULL) {
    goto fail; //String
    }
    }


    // _gift_premium_subscription_post_request->text_parse_mode
    if(_gift_premium_subscription_post_request->text_parse_mode) {
    if(cJSON_AddStringToObject(item, "text_parse_mode", _gift_premium_subscription_post_request->text_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _gift_premium_subscription_post_request->text_entities
    if(_gift_premium_subscription_post_request->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (_gift_premium_subscription_post_request->text_entities) {
    list_ForEach(text_entitiesListEntry, _gift_premium_subscription_post_request->text_entities) {
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

_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_parseFromJSON(cJSON *_gift_premium_subscription_post_requestJSON){

    _gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_local_var = NULL;

    // define the local list for _gift_premium_subscription_post_request->text_entities
    list_t *text_entitiesList = NULL;

    // _gift_premium_subscription_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "user_id");
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

    // _gift_premium_subscription_post_request->month_count
    cJSON *month_count = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "month_count");
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

    // _gift_premium_subscription_post_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "star_count");
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

    // _gift_premium_subscription_post_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // _gift_premium_subscription_post_request->text_parse_mode
    cJSON *text_parse_mode = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "text_parse_mode");
    if (cJSON_IsNull(text_parse_mode)) {
        text_parse_mode = NULL;
    }
    if (text_parse_mode) { 
    if(!cJSON_IsString(text_parse_mode) && !cJSON_IsNull(text_parse_mode))
    {
    goto end; //String
    }
    }

    // _gift_premium_subscription_post_request->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(_gift_premium_subscription_post_requestJSON, "text_entities");
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


    _gift_premium_subscription_post_request_local_var = _gift_premium_subscription_post_request_create_internal (
        user_id->valuedouble,
        month_count->valuedouble,
        star_count->valuedouble,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        text_parse_mode && !cJSON_IsNull(text_parse_mode) ? strdup(text_parse_mode->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL
        );

    return _gift_premium_subscription_post_request_local_var;
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
