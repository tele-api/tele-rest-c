#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_story_request.h"



static edit_story_request_t *edit_story_request_create_internal(
    char *business_connection_id,
    int story_id,
    input_story_content_t *content,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas
    ) {
    edit_story_request_t *edit_story_request_local_var = malloc(sizeof(edit_story_request_t));
    if (!edit_story_request_local_var) {
        return NULL;
    }
    edit_story_request_local_var->business_connection_id = business_connection_id;
    edit_story_request_local_var->story_id = story_id;
    edit_story_request_local_var->content = content;
    edit_story_request_local_var->caption = caption;
    edit_story_request_local_var->parse_mode = parse_mode;
    edit_story_request_local_var->caption_entities = caption_entities;
    edit_story_request_local_var->areas = areas;

    edit_story_request_local_var->_library_owned = 1;
    return edit_story_request_local_var;
}

__attribute__((deprecated)) edit_story_request_t *edit_story_request_create(
    char *business_connection_id,
    int story_id,
    input_story_content_t *content,
    char *caption,
    char *parse_mode,
    list_t *caption_entities,
    list_t *areas
    ) {
    return edit_story_request_create_internal (
        business_connection_id,
        story_id,
        content,
        caption,
        parse_mode,
        caption_entities,
        areas
        );
}

void edit_story_request_free(edit_story_request_t *edit_story_request) {
    if(NULL == edit_story_request){
        return ;
    }
    if(edit_story_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_story_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_story_request->business_connection_id) {
        free(edit_story_request->business_connection_id);
        edit_story_request->business_connection_id = NULL;
    }
    if (edit_story_request->content) {
        input_story_content_free(edit_story_request->content);
        edit_story_request->content = NULL;
    }
    if (edit_story_request->caption) {
        free(edit_story_request->caption);
        edit_story_request->caption = NULL;
    }
    if (edit_story_request->parse_mode) {
        free(edit_story_request->parse_mode);
        edit_story_request->parse_mode = NULL;
    }
    if (edit_story_request->caption_entities) {
        list_ForEach(listEntry, edit_story_request->caption_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(edit_story_request->caption_entities);
        edit_story_request->caption_entities = NULL;
    }
    if (edit_story_request->areas) {
        list_ForEach(listEntry, edit_story_request->areas) {
            story_area_free(listEntry->data);
        }
        list_freeList(edit_story_request->areas);
        edit_story_request->areas = NULL;
    }
    free(edit_story_request);
}

cJSON *edit_story_request_convertToJSON(edit_story_request_t *edit_story_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_story_request->business_connection_id
    if (!edit_story_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", edit_story_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // edit_story_request->story_id
    if (!edit_story_request->story_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "story_id", edit_story_request->story_id) == NULL) {
    goto fail; //Numeric
    }


    // edit_story_request->content
    if (!edit_story_request->content) {
        goto fail;
    }
    cJSON *content_local_JSON = input_story_content_convertToJSON(edit_story_request->content);
    if(content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "content", content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // edit_story_request->caption
    if(edit_story_request->caption) {
    if(cJSON_AddStringToObject(item, "caption", edit_story_request->caption) == NULL) {
    goto fail; //String
    }
    }


    // edit_story_request->parse_mode
    if(edit_story_request->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", edit_story_request->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // edit_story_request->caption_entities
    if(edit_story_request->caption_entities) {
    cJSON *caption_entities = cJSON_AddArrayToObject(item, "caption_entities");
    if(caption_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *caption_entitiesListEntry;
    if (edit_story_request->caption_entities) {
    list_ForEach(caption_entitiesListEntry, edit_story_request->caption_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(caption_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(caption_entities, itemLocal);
    }
    }
    }


    // edit_story_request->areas
    if(edit_story_request->areas) {
    cJSON *areas = cJSON_AddArrayToObject(item, "areas");
    if(areas == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *areasListEntry;
    if (edit_story_request->areas) {
    list_ForEach(areasListEntry, edit_story_request->areas) {
    cJSON *itemLocal = story_area_convertToJSON(areasListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(areas, itemLocal);
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

edit_story_request_t *edit_story_request_parseFromJSON(cJSON *edit_story_requestJSON){

    edit_story_request_t *edit_story_request_local_var = NULL;

    // define the local variable for edit_story_request->content
    input_story_content_t *content_local_nonprim = NULL;

    // define the local list for edit_story_request->caption_entities
    list_t *caption_entitiesList = NULL;

    // define the local list for edit_story_request->areas
    list_t *areasList = NULL;

    // edit_story_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "business_connection_id");
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

    // edit_story_request->story_id
    cJSON *story_id = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "story_id");
    if (cJSON_IsNull(story_id)) {
        story_id = NULL;
    }
    if (!story_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(story_id))
    {
    goto end; //Numeric
    }

    // edit_story_request->content
    cJSON *content = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "content");
    if (cJSON_IsNull(content)) {
        content = NULL;
    }
    if (!content) {
        goto end;
    }

    
    content_local_nonprim = input_story_content_parseFromJSON(content); //nonprimitive

    // edit_story_request->caption
    cJSON *caption = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "caption");
    if (cJSON_IsNull(caption)) {
        caption = NULL;
    }
    if (caption) { 
    if(!cJSON_IsString(caption) && !cJSON_IsNull(caption))
    {
    goto end; //String
    }
    }

    // edit_story_request->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // edit_story_request->caption_entities
    cJSON *caption_entities = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "caption_entities");
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

    // edit_story_request->areas
    cJSON *areas = cJSON_GetObjectItemCaseSensitive(edit_story_requestJSON, "areas");
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


    edit_story_request_local_var = edit_story_request_create_internal (
        strdup(business_connection_id->valuestring),
        story_id->valuedouble,
        content_local_nonprim,
        caption && !cJSON_IsNull(caption) ? strdup(caption->valuestring) : NULL,
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        caption_entities ? caption_entitiesList : NULL,
        areas ? areasList : NULL
        );

    return edit_story_request_local_var;
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
