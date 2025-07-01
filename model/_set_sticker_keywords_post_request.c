#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_keywords_post_request.h"



static _set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request_create_internal(
    char *sticker,
    list_t *keywords
    ) {
    _set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request_local_var = malloc(sizeof(_set_sticker_keywords_post_request_t));
    if (!_set_sticker_keywords_post_request_local_var) {
        return NULL;
    }
    _set_sticker_keywords_post_request_local_var->sticker = sticker;
    _set_sticker_keywords_post_request_local_var->keywords = keywords;

    _set_sticker_keywords_post_request_local_var->_library_owned = 1;
    return _set_sticker_keywords_post_request_local_var;
}

__attribute__((deprecated)) _set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request_create(
    char *sticker,
    list_t *keywords
    ) {
    return _set_sticker_keywords_post_request_create_internal (
        sticker,
        keywords
        );
}

void _set_sticker_keywords_post_request_free(_set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request) {
    if(NULL == _set_sticker_keywords_post_request){
        return ;
    }
    if(_set_sticker_keywords_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_keywords_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_sticker_keywords_post_request->sticker) {
        free(_set_sticker_keywords_post_request->sticker);
        _set_sticker_keywords_post_request->sticker = NULL;
    }
    if (_set_sticker_keywords_post_request->keywords) {
        list_ForEach(listEntry, _set_sticker_keywords_post_request->keywords) {
            free(listEntry->data);
        }
        list_freeList(_set_sticker_keywords_post_request->keywords);
        _set_sticker_keywords_post_request->keywords = NULL;
    }
    free(_set_sticker_keywords_post_request);
}

cJSON *_set_sticker_keywords_post_request_convertToJSON(_set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_sticker_keywords_post_request->sticker
    if (!_set_sticker_keywords_post_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", _set_sticker_keywords_post_request->sticker) == NULL) {
    goto fail; //String
    }


    // _set_sticker_keywords_post_request->keywords
    if(_set_sticker_keywords_post_request->keywords) {
    cJSON *keywords = cJSON_AddArrayToObject(item, "keywords");
    if(keywords == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *keywordsListEntry;
    list_ForEach(keywordsListEntry, _set_sticker_keywords_post_request->keywords) {
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

_set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request_parseFromJSON(cJSON *_set_sticker_keywords_post_requestJSON){

    _set_sticker_keywords_post_request_t *_set_sticker_keywords_post_request_local_var = NULL;

    // define the local list for _set_sticker_keywords_post_request->keywords
    list_t *keywordsList = NULL;

    // _set_sticker_keywords_post_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_set_sticker_keywords_post_requestJSON, "sticker");
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

    // _set_sticker_keywords_post_request->keywords
    cJSON *keywords = cJSON_GetObjectItemCaseSensitive(_set_sticker_keywords_post_requestJSON, "keywords");
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


    _set_sticker_keywords_post_request_local_var = _set_sticker_keywords_post_request_create_internal (
        strdup(sticker->valuestring),
        keywords ? keywordsList : NULL
        );

    return _set_sticker_keywords_post_request_local_var;
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
