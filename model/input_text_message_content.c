#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_text_message_content.h"



static input_text_message_content_t *input_text_message_content_create_internal(
    char *message_text,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options
    ) {
    input_text_message_content_t *input_text_message_content_local_var = malloc(sizeof(input_text_message_content_t));
    if (!input_text_message_content_local_var) {
        return NULL;
    }
    input_text_message_content_local_var->message_text = message_text;
    input_text_message_content_local_var->parse_mode = parse_mode;
    input_text_message_content_local_var->entities = entities;
    input_text_message_content_local_var->link_preview_options = link_preview_options;

    input_text_message_content_local_var->_library_owned = 1;
    return input_text_message_content_local_var;
}

__attribute__((deprecated)) input_text_message_content_t *input_text_message_content_create(
    char *message_text,
    char *parse_mode,
    list_t *entities,
    link_preview_options_t *link_preview_options
    ) {
    return input_text_message_content_create_internal (
        message_text,
        parse_mode,
        entities,
        link_preview_options
        );
}

void input_text_message_content_free(input_text_message_content_t *input_text_message_content) {
    if(NULL == input_text_message_content){
        return ;
    }
    if(input_text_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_text_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_text_message_content->message_text) {
        free(input_text_message_content->message_text);
        input_text_message_content->message_text = NULL;
    }
    if (input_text_message_content->parse_mode) {
        free(input_text_message_content->parse_mode);
        input_text_message_content->parse_mode = NULL;
    }
    if (input_text_message_content->entities) {
        list_ForEach(listEntry, input_text_message_content->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_text_message_content->entities);
        input_text_message_content->entities = NULL;
    }
    if (input_text_message_content->link_preview_options) {
        link_preview_options_free(input_text_message_content->link_preview_options);
        input_text_message_content->link_preview_options = NULL;
    }
    free(input_text_message_content);
}

cJSON *input_text_message_content_convertToJSON(input_text_message_content_t *input_text_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_text_message_content->message_text
    if (!input_text_message_content->message_text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message_text", input_text_message_content->message_text) == NULL) {
    goto fail; //String
    }


    // input_text_message_content->parse_mode
    if(input_text_message_content->parse_mode) {
    if(cJSON_AddStringToObject(item, "parse_mode", input_text_message_content->parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_text_message_content->entities
    if(input_text_message_content->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (input_text_message_content->entities) {
    list_ForEach(entitiesListEntry, input_text_message_content->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // input_text_message_content->link_preview_options
    if(input_text_message_content->link_preview_options) {
    cJSON *link_preview_options_local_JSON = link_preview_options_convertToJSON(input_text_message_content->link_preview_options);
    if(link_preview_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "link_preview_options", link_preview_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_text_message_content_t *input_text_message_content_parseFromJSON(cJSON *input_text_message_contentJSON){

    input_text_message_content_t *input_text_message_content_local_var = NULL;

    // define the local list for input_text_message_content->entities
    list_t *entitiesList = NULL;

    // define the local variable for input_text_message_content->link_preview_options
    link_preview_options_t *link_preview_options_local_nonprim = NULL;

    // input_text_message_content->message_text
    cJSON *message_text = cJSON_GetObjectItemCaseSensitive(input_text_message_contentJSON, "message_text");
    if (cJSON_IsNull(message_text)) {
        message_text = NULL;
    }
    if (!message_text) {
        goto end;
    }

    
    if(!cJSON_IsString(message_text))
    {
    goto end; //String
    }

    // input_text_message_content->parse_mode
    cJSON *parse_mode = cJSON_GetObjectItemCaseSensitive(input_text_message_contentJSON, "parse_mode");
    if (cJSON_IsNull(parse_mode)) {
        parse_mode = NULL;
    }
    if (parse_mode) { 
    if(!cJSON_IsString(parse_mode) && !cJSON_IsNull(parse_mode))
    {
    goto end; //String
    }
    }

    // input_text_message_content->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(input_text_message_contentJSON, "entities");
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

    // input_text_message_content->link_preview_options
    cJSON *link_preview_options = cJSON_GetObjectItemCaseSensitive(input_text_message_contentJSON, "link_preview_options");
    if (cJSON_IsNull(link_preview_options)) {
        link_preview_options = NULL;
    }
    if (link_preview_options) { 
    link_preview_options_local_nonprim = link_preview_options_parseFromJSON(link_preview_options); //nonprimitive
    }


    input_text_message_content_local_var = input_text_message_content_create_internal (
        strdup(message_text->valuestring),
        parse_mode && !cJSON_IsNull(parse_mode) ? strdup(parse_mode->valuestring) : NULL,
        entities ? entitiesList : NULL,
        link_preview_options ? link_preview_options_local_nonprim : NULL
        );

    return input_text_message_content_local_var;
end:
    if (entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(entitiesList);
        entitiesList = NULL;
    }
    if (link_preview_options_local_nonprim) {
        link_preview_options_free(link_preview_options_local_nonprim);
        link_preview_options_local_nonprim = NULL;
    }
    return NULL;

}
