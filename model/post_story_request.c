#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_story_request.h"


char* post_story_request_active_period_ToString(telegram_bot_api_post_story_request_ACTIVEPERIOD_e active_period) {
    char* active_periodArray[] =  { "NULL", "86400" };
    return active_periodArray[active_period];
}

telegram_bot_api_post_story_request_ACTIVEPERIOD_e post_story_request_active_period_FromString(char* active_period){
    int stringToReturn = 0;
    char *active_periodArray[] =  { "NULL", "86400" };
    size_t sizeofArray = sizeof(active_periodArray) / sizeof(active_periodArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(active_period, active_periodArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static post_story_request_t *post_story_request_create_internal(
    char *business_connection_id,
    input_story_content_t *content,
    int active_period,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas,
    int post_to_chat_page,
    int protect_content
    ) {
    post_story_request_t *post_story_request_local_var = malloc(sizeof(post_story_request_t));
    if (!post_story_request_local_var) {
        return NULL;
    }
    post_story_request_local_var->business_connection_id = business_connection_id;
    post_story_request_local_var->content = content;
    post_story_request_local_var->active_period = active_period;
    post_story_request_local_var->caption = caption;
    post_story_request_local_var->parse_mode = parse_mode;
    post_story_request_local_var->caption_entities = caption_entities;
    post_story_request_local_var->areas = areas;
    post_story_request_local_var->post_to_chat_page = post_to_chat_page;
    post_story_request_local_var->protect_content = protect_content;

    post_story_request_local_var->_library_owned = 1;
    return post_story_request_local_var;
}

__attribute__((deprecated)) post_story_request_t *post_story_request_create(
    char *business_connection_id,
    input_story_content_t *content,
    int active_period,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas,
    int post_to_chat_page,
    int protect_content
    ) {
    return post_story_request_create_internal (
        business_connection_id,
        content,
        active_period,
        caption,
        parse_mode,
        caption_entities,
        areas,
        post_to_chat_page,
        protect_content
        );
}

void post_story_request_free(post_story_request_t *post_story_request) {
    if(NULL == post_story_request){
        return ;
    }
    if(post_story_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_story_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_story_request->business_connection_id) {
        free(post_story_request->business_connection_id);
        post_story_request->business_connection_id = NULL;
    }
    if (post_story_request->content) {
        input_story_content_free(post_story_request->content);
        post_story_request->content = NULL;
    }
    if (post_story_request->caption) {
        free(post_story_request->caption);
        post_story_request->caption = NULL;
    }
    if (post_story_request->parse_mode) {
        free(post_story_request->parse_mode);
        post_story_request->parse_mode = NULL;
    }
    if (post_story_request->caption_entities) {
        list_ForEach(listEntry, post_story_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(post_story_request->caption_entities);
        post_story_request->caption_entities = NULL;
    }
    if (post_story_request->areas) {
        list_ForEach(listEntry, post_story_request->areas) {
            story_area_free(listEntry->data);
        }
        list_freeList(post_story_request->areas);
        post_story_request->areas = NULL;
    }
    free(post_story_request);
}

cJSON *post_story_request_convertToJSON(post_story_request_t *post_story_request) {
    cJSON *item = cJSON_CreateObject();

    // post_story_request->business_connection_id
    if (!post_story_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_story_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_story_request->content
    if (!post_story_request->content) {
        goto fail;
    }
    cJSON *content_local_JSON = input_story_content_convertToJSON(post_story_request->content);
    if(content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "content", content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_story_request->active_period
    if (telegram_bot_api_post_story_request_ACTIVEPERIOD_NULL == post_story_request->active_period) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "active_period", post_story_request->active_period) == NULL) {
    goto fail; //Numeric
    }


    // post_story_request->caption
    if(post_story_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", post_story_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // post_story_request->parse_mode
    if(post_story_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", post_story_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // post_story_request->caption_entities
    if(post_story_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (post_story_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, post_story_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // post_story_request->areas
    if(post_story_request->areas) {
    cJSON *areas = cJSON_AddArrayToObject(item, "areas");
    if(areas == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *areasListEntry;
    if (post_story_request->areas) {
    list_ForEach(areasListEntry, post_story_request->areas) {
    cJSON *itemLocal = story_area_convertToJSON(areasListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(areas, itemLocal);
    }
    }
    }


    // post_story_request->post_to_chat_page
    if(post_story_request->post_to_chat_page) {
    if(cJSON_AddBoolToObject(item, "post_to_chat_page", post_story_request->post_to_chat_page) == NULL) {
    goto fail; //Bool
    }
    }


    // post_story_request->protect_content
    if(post_story_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", post_story_request->protect_content) == NULL) {
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

post_story_request_t *post_story_request_parseFromJSON(cJSON *post_story_requestJSON){

    post_story_request_t *post_story_request_local_var = NULL;

    // define the local variable for post_story_request->content
    input_story_content_t *content_local_nonprim = NULL;

    // define the local list for post_story_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local list for post_story_request->areas
    list_t *areasList = NULL;

    // post_story_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // post_story_request->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "content");
    if (cJSON_IsNull(content)) {
        content = NULL;
    }
    if (!content) {
        goto end;
    }

    
    content_local_nonprim = input_story_content_parseFromJSON(content); //nonprimitive

    // post_story_request->active_period
    cJSON *active_period = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "active_period");
    if (cJSON_IsNull(active_period)) {
        active_period = NULL;
    }
    if (!active_period) {
        goto end;
    }

    
    if(!cJSON_IsNumber(active_period))
    {
    goto end; //Numeric
    }

    // post_story_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // post_story_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // post_story_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "caption_entities");
    if (cJSON_IsNull(caption_entities)) {
        caption_entities = NULL;
    }
    if (caption_entities) { 
    cJSON *caption_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(caption_entities)){
        goto end; //nonprimitive container
    }

    caption_entitiesList = list_createList();

    cJSON_ArrayForEach(caption_entities_local_nonprimitive,caption_entities )
    {
        if(!cJSON_IsObject(caption_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *caption_entitiesItem = message_entity_parseFromJSON(caption_entities_local_nonprimitive);

        list_addElement(caption_entitiesList, caption_entitiesItem);
    }
    }

    // post_story_request->areas
    cJSON *areas = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "areas");
    if (cJSON_IsNull(areas)) {
        areas = NULL;
    }
    if (areas) { 
    cJSON *areas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(areas)){
        goto end; //nonprimitive container
    }

    areasList = list_createList();

    cJSON_ArrayForEach(areas_local_nonprimitive,areas )
    {
        if(!cJSON_IsObject(areas_local_nonprimitive)){
            goto end;
        }
        story_area_t *areasItem = story_area_parseFromJSON(areas_local_nonprimitive);

        list_addElement(areasList, areasItem);
    }
    }

    // post_story_request->post_to_chat_page
    cJSON *post_to_chat_page = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "post_to_chat_page");
    if (cJSON_IsNull(post_to_chat_page)) {
        post_to_chat_page = NULL;
    }
    if (post_to_chat_page) { 
    if(!cJSON_IsBool(post_to_chat_page))
    {
    goto end; //Bool
    }
    }

    // post_story_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(post_story_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }


    post_story_request_local_var = post_story_request_create_internal (
        strdup(business_connection_id->valuestring),
        content_local_nonprim,
        active_period->valuedouble,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        areas ? areasList : NULL,
        post_to_chat_page ? post_to_chat_page->valueint : 0,
        protect_content ? protect_content->valueint : 0
        );

    return post_story_request_local_var;
end:
    if (content_local_nonprim) {
        input_story_content_free(content_local_nonprim);
        content_local_nonprim = NULL;
    }
    if (caption_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, caption_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(caption_entitiesList);
        caption_entitiesList = NULL;
    }
    if (areasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, areasList) {
            story_area_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(areasList);
        areasList = NULL;
    }
    return NULL;

}
