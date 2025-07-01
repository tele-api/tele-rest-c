#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "poll_option.h"



static poll_option_t *poll_option_create_internal(
    char *text,
    int voter_count,
    list_t *text_entities
    ) {
    poll_option_t *poll_option_local_var = malloc(sizeof(poll_option_t));
    if (!poll_option_local_var) {
        return NULL;
    }
    poll_option_local_var->text = text;
    poll_option_local_var->voter_count = voter_count;
    poll_option_local_var->text_entities = text_entities;

    poll_option_local_var->_library_owned = 1;
    return poll_option_local_var;
}

__attribute__((deprecated)) poll_option_t *poll_option_create(
    char *text,
    int voter_count,
    list_t *text_entities
    ) {
    return poll_option_create_internal (
        text,
        voter_count,
        text_entities
        );
}

void poll_option_free(poll_option_t *poll_option) {
    if(NULL == poll_option){
        return ;
    }
    if(poll_option->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "poll_option_free");
        return ;
    }
    listEntry_t *listEntry;
    if (poll_option->text) {
        free(poll_option->text);
        poll_option->text = NULL;
    }
    if (poll_option->text_entities) {
        list_ForEach(listEntry, poll_option->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(poll_option->text_entities);
        poll_option->text_entities = NULL;
    }
    free(poll_option);
}

cJSON *poll_option_convertToJSON(poll_option_t *poll_option) {
    cJSON *item = cJSON_CreateObject();

    // poll_option->text
    if (!poll_option->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", poll_option->text) == NULL) {
    goto fail; //String
    }


    // poll_option->voter_count
    if (!poll_option->voter_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "voter_count", poll_option->voter_count) == NULL) {
    goto fail; //Numeric
    }


    // poll_option->text_entities
    if(poll_option->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (poll_option->text_entities) {
    list_ForEach(text_entitiesListEntry, poll_option->text_entities) {
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

poll_option_t *poll_option_parseFromJSON(cJSON *poll_optionJSON){

    poll_option_t *poll_option_local_var = NULL;

    // define the local list for poll_option->text_entities
    list_t *text_entitiesList = NULL;

    // poll_option->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(poll_optionJSON, "text");
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

    // poll_option->voter_count
    cJSON *voter_count = cJSON_GetObjectItemCaseSensitive(poll_optionJSON, "voter_count");
    if (cJSON_IsNull(voter_count)) {
        voter_count = NULL;
    }
    if (!voter_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(voter_count))
    {
    goto end; //Numeric
    }

    // poll_option->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(poll_optionJSON, "text_entities");
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


    poll_option_local_var = poll_option_create_internal (
        strdup(text->valuestring),
        voter_count->valuedouble,
        text_entities ? text_entitiesList : NULL
        );

    return poll_option_local_var;
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
