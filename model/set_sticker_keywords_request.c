#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_keywords_request.h"



static set_sticker_keywords_request_t *set_sticker_keywords_request_create_internal(
    char *sticker,
    list_t *keywords
    ) {
    set_sticker_keywords_request_t *set_sticker_keywords_request_local_var = malloc(sizeof(set_sticker_keywords_request_t));
    if (!set_sticker_keywords_request_local_var) {
        return NULL;
    }
    set_sticker_keywords_request_local_var->sticker = sticker;
    set_sticker_keywords_request_local_var->keywords = keywords;

    set_sticker_keywords_request_local_var->_library_owned = 1;
    return set_sticker_keywords_request_local_var;
}

__attribute__((deprecated)) set_sticker_keywords_request_t *set_sticker_keywords_request_create(
    char *sticker,
    list_t *keywords
    ) {
    return set_sticker_keywords_request_create_internal (
        sticker,
        keywords
        );
}

void set_sticker_keywords_request_free(set_sticker_keywords_request_t *set_sticker_keywords_request) {
    if(NULL == set_sticker_keywords_request){
        return ;
    }
    if(set_sticker_keywords_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_keywords_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_keywords_request->sticker) {
        free(set_sticker_keywords_request->sticker);
        set_sticker_keywords_request->sticker = NULL;
    }
    if (set_sticker_keywords_request->keywords) {
        list_ForEach(listEntry, set_sticker_keywords_request->keywords) {
            free(listEntry->data);
        }
        list_freeList(set_sticker_keywords_request->keywords);
        set_sticker_keywords_request->keywords = NULL;
    }
    free(set_sticker_keywords_request);
}

cJSON *set_sticker_keywords_request_convertToJSON(set_sticker_keywords_request_t *set_sticker_keywords_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_keywords_request->sticker
    if (!set_sticker_keywords_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", set_sticker_keywords_request->sticker) == NULL) {
    goto fail; //String
    }


    // set_sticker_keywords_request->keywords
    if(set_sticker_keywords_request->keywords) {
    cJSON *keywords = cJSON_AddArrayToObject(item, "keywords");
    if(keywords == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keywordsListEntry;
    list_ForEach(keywordsListEntry, set_sticker_keywords_request->keywords) {
    if(cJSON_AddStringToObject(keywords, "", keywordsListEntry->data) == NULL)
    {
        goto fail;
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

set_sticker_keywords_request_t *set_sticker_keywords_request_parseFromJSON(cJSON *set_sticker_keywords_requestJSON){

    set_sticker_keywords_request_t *set_sticker_keywords_request_local_var = NULL;

    // define the local list for set_sticker_keywords_request->keywords
    list_t *keywordsList = NULL;

    // set_sticker_keywords_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(set_sticker_keywords_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }

    // set_sticker_keywords_request->keywords
    cJSON *keywords = cJSON_GetObjectItemCaseSensitive(set_sticker_keywords_requestJSON, "keywords");
    if (cJSON_IsNull(keywords)) {
        keywords = NULL;
    }
    if (keywords) { 
    cJSON *keywords_local = NULL;
    if(!cJSON_IsArray(keywords)) {
        goto end;//primitive container
    }
    keywordsList = list_createList();

    cJSON_ArrayForEach(keywords_local, keywords)
    {
        if(!cJSON_IsString(keywords_local))
        {
            goto end;
        }
        list_addElement(keywordsList , strdup(keywords_local->valuestring));
    }
    }


    set_sticker_keywords_request_local_var = set_sticker_keywords_request_create_internal (
        strdup(sticker->valuestring),
        keywords ? keywordsList : NULL
        );

    return set_sticker_keywords_request_local_var;
end:
    if (keywordsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, keywordsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(keywordsList);
        keywordsList = NULL;
    }
    return NULL;

}
