#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "text_quote.h"



static text_quote_t *text_quote_create_internal(
    char *text,
    int position,
    list_t *entities,
    int is_manual
    ) {
    text_quote_t *text_quote_local_var = malloc(sizeof(text_quote_t));
    if (!text_quote_local_var) {
        return NULL;
    }
    text_quote_local_var->text = text;
    text_quote_local_var->position = position;
    text_quote_local_var->entities = entities;
    text_quote_local_var->is_manual = is_manual;

    text_quote_local_var->_library_owned = 1;
    return text_quote_local_var;
}

__attribute__((deprecated)) text_quote_t *text_quote_create(
    char *text,
    int position,
    list_t *entities,
    int is_manual
    ) {
    return text_quote_create_internal (
        text,
        position,
        entities,
        is_manual
        );
}

void text_quote_free(text_quote_t *text_quote) {
    if(NULL == text_quote){
        return ;
    }
    if(text_quote->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "text_quote_free");
        return ;
    }
    listEntry_t *listEntry;
    if (text_quote->text) {
        free(text_quote->text);
        text_quote->text = NULL;
    }
    if (text_quote->entities) {
        list_ForEach(listEntry, text_quote->entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(text_quote->entities);
        text_quote->entities = NULL;
    }
    free(text_quote);
}

cJSON *text_quote_convertToJSON(text_quote_t *text_quote) {
    cJSON *item = cJSON_CreateObject();

    // text_quote->text
    if (!text_quote->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", text_quote->text) == NULL) {
    goto fail; //String
    }


    // text_quote->position
    if (!text_quote->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", text_quote->position) == NULL) {
    goto fail; //Numeric
    }


    // text_quote->entities
    if(text_quote->entities) {
    cJSON *entities = cJSON_AddArrayToObject(item, "entities");
    if(entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *entitiesListEntry;
    if (text_quote->entities) {
    list_ForEach(entitiesListEntry, text_quote->entities) {
    cJSON *itemLocal = message_entity_convertToJSON(entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(entities, itemLocal);
    }
    }
    }


    // text_quote->is_manual
    if(text_quote->is_manual) {
    if(cJSON_AddBoolToObject(item, "is_manual", text_quote->is_manual) == NULL) {
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

text_quote_t *text_quote_parseFromJSON(cJSON *text_quoteJSON){

    text_quote_t *text_quote_local_var = NULL;

    // define the local list for text_quote->entities
    list_t *entitiesList = NULL;

    // text_quote->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(text_quoteJSON, "text");
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

    // text_quote->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(text_quoteJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }

    // text_quote->entities
    cJSON *entities = cJSON_GetObjectItemCaseSensitive(text_quoteJSON, "entities");
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

    // text_quote->is_manual
    cJSON *is_manual = cJSON_GetObjectItemCaseSensitive(text_quoteJSON, "is_manual");
    if (cJSON_IsNull(is_manual)) {
        is_manual = NULL;
    }
    if (is_manual) { 
    if(!cJSON_IsBool(is_manual))
    {
    goto end; //Bool
    }
    }


    text_quote_local_var = text_quote_create_internal (
        strdup(text->valuestring),
        position->valuedouble,
        entities ? entitiesList : NULL,
        is_manual ? is_manual->valueint : 0
        );

    return text_quote_local_var;
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
    return NULL;

}
