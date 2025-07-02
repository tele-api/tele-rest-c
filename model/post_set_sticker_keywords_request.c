#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_keywords_request.h"



static post_set_sticker_keywords_request_t *post_set_sticker_keywords_request_create_internal(
    char *sticker,
    list_t *keywords
    ) {
    post_set_sticker_keywords_request_t *post_set_sticker_keywords_request_local_var = malloc(sizeof(post_set_sticker_keywords_request_t));
    if (!post_set_sticker_keywords_request_local_var) {
        return NULL;
    }
    post_set_sticker_keywords_request_local_var->sticker = sticker;
    post_set_sticker_keywords_request_local_var->keywords = keywords;

    post_set_sticker_keywords_request_local_var->_library_owned = 1;
    return post_set_sticker_keywords_request_local_var;
}

__attribute__((deprecated)) post_set_sticker_keywords_request_t *post_set_sticker_keywords_request_create(
    char *sticker,
    list_t *keywords
    ) {
    return post_set_sticker_keywords_request_create_internal (
        sticker,
        keywords
        );
}

void post_set_sticker_keywords_request_free(post_set_sticker_keywords_request_t *post_set_sticker_keywords_request) {
    if(NULL == post_set_sticker_keywords_request){
        return ;
    }
    if(post_set_sticker_keywords_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_keywords_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_sticker_keywords_request->sticker) {
        free(post_set_sticker_keywords_request->sticker);
        post_set_sticker_keywords_request->sticker = NULL;
    }
    if (post_set_sticker_keywords_request->keywords) {
        list_ForEach(listEntry, post_set_sticker_keywords_request->keywords) {
            free(listEntry->data);
        }
        list_freeList(post_set_sticker_keywords_request->keywords);
        post_set_sticker_keywords_request->keywords = NULL;
    }
    free(post_set_sticker_keywords_request);
}

cJSON *post_set_sticker_keywords_request_convertToJSON(post_set_sticker_keywords_request_t *post_set_sticker_keywords_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_sticker_keywords_request->sticker
    if (!post_set_sticker_keywords_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", post_set_sticker_keywords_request->sticker) == NULL) {
    goto fail; //String
    }


    // post_set_sticker_keywords_request->keywords
    if(post_set_sticker_keywords_request->keywords) {
    cJSON *keywords = cJSON_AddArrayToObject(item, "keywords");
    if(keywords == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keywordsListEntry;
    list_ForEach(keywordsListEntry, post_set_sticker_keywords_request->keywords) {
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

post_set_sticker_keywords_request_t *post_set_sticker_keywords_request_parseFromJSON(cJSON *post_set_sticker_keywords_requestJSON){

    post_set_sticker_keywords_request_t *post_set_sticker_keywords_request_local_var = NULL;

    // define the local list for post_set_sticker_keywords_request->keywords
    list_t *keywordsList = NULL;

    // post_set_sticker_keywords_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(post_set_sticker_keywords_requestJSON, "sticker");
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

    // post_set_sticker_keywords_request->keywords
    cJSON *keywords = cJSON_GetObjectItemCaseSensitive(post_set_sticker_keywords_requestJSON, "keywords");
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


    post_set_sticker_keywords_request_local_var = post_set_sticker_keywords_request_create_internal (
        strdup(sticker->valuestring),
        keywords ? keywordsList : NULL
        );

    return post_set_sticker_keywords_request_local_var;
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
