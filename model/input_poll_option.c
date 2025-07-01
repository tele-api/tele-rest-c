#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_poll_option.h"



static input_poll_option_t *input_poll_option_create_internal(
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    input_poll_option_t *input_poll_option_local_var = malloc(sizeof(input_poll_option_t));
    if (!input_poll_option_local_var) {
        return NULL;
    }
    input_poll_option_local_var->text = text;
    input_poll_option_local_var->text_parse_mode = text_parse_mode;
    input_poll_option_local_var->text_entities = text_entities;

    input_poll_option_local_var->_library_owned = 1;
    return input_poll_option_local_var;
}

__attribute__((deprecated)) input_poll_option_t *input_poll_option_create(
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    return input_poll_option_create_internal (
        text,
        text_parse_mode,
        text_entities
        );
}

void input_poll_option_free(input_poll_option_t *input_poll_option) {
    if(NULL == input_poll_option){
        return ;
    }
    if(input_poll_option->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_poll_option_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_poll_option->text) {
        free(input_poll_option->text);
        input_poll_option->text = NULL;
    }
    if (input_poll_option->text_parse_mode) {
        free(input_poll_option->text_parse_mode);
        input_poll_option->text_parse_mode = NULL;
    }
    if (input_poll_option->text_entities) {
        list_ForEach(listEntry, input_poll_option->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(input_poll_option->text_entities);
        input_poll_option->text_entities = NULL;
    }
    free(input_poll_option);
}

cJSON *input_poll_option_convertToJSON(input_poll_option_t *input_poll_option) {
    cJSON *item = cJSON_CreateObject();

    // input_poll_option->text
    if (!input_poll_option->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", input_poll_option->text) == NULL) {
    goto fail; //String
    }


    // input_poll_option->text_parse_mode
    if(input_poll_option->text_parse_mode) {
    if(cJSON_AddStringToObject(item, "text_parse_mode", input_poll_option->text_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // input_poll_option->text_entities
    if(input_poll_option->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (input_poll_option->text_entities) {
    list_ForEach(text_entitiesListEntry, input_poll_option->text_entities) {
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

input_poll_option_t *input_poll_option_parseFromJSON(cJSON *input_poll_optionJSON){

    input_poll_option_t *input_poll_option_local_var = NULL;

    // define the local list for input_poll_option->text_entities
    list_t *text_entitiesList = NULL;

    // input_poll_option->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(input_poll_optionJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }

    // input_poll_option->text_parse_mode
    cJSON *text_parse_mode = cJSON_GetObjectItemCaseSensitive(input_poll_optionJSON, "text_parse_mode");
    if (cJSON_IsNull(text_parse_mode)) {
        text_parse_mode = NULL;
    }
    if (text_parse_mode) { 
    if(!cJSON_IsString(text_parse_mode) && !cJSON_IsNull(text_parse_mode))
    {
    goto end; //String
    }
    }

    // input_poll_option->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(input_poll_optionJSON, "text_entities");
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


    input_poll_option_local_var = input_poll_option_create_internal (
        strdup(text->valuestring),
        text_parse_mode && !cJSON_IsNull(text_parse_mode) ? strdup(text_parse_mode->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL
        );

    return input_poll_option_local_var;
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
