#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_updates_post_request.h"



static _get_updates_post_request_t *_get_updates_post_request_create_internal(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    _get_updates_post_request_t *_get_updates_post_request_local_var = malloc(sizeof(_get_updates_post_request_t));
    if (!_get_updates_post_request_local_var) {
        return NULL;
    }
    _get_updates_post_request_local_var->offset = offset;
    _get_updates_post_request_local_var->limit = limit;
    _get_updates_post_request_local_var->timeout = timeout;
    _get_updates_post_request_local_var->allowed_updates = allowed_updates;

    _get_updates_post_request_local_var->_library_owned = 1;
    return _get_updates_post_request_local_var;
}

__attribute__((deprecated)) _get_updates_post_request_t *_get_updates_post_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    return _get_updates_post_request_create_internal (
        offset,
        limit,
        timeout,
        allowed_updates
        );
}

void _get_updates_post_request_free(_get_updates_post_request_t *_get_updates_post_request) {
    if(NULL == _get_updates_post_request){
        return ;
    }
    if(_get_updates_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_updates_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_updates_post_request->allowed_updates) {
        list_ForEach(listEntry, _get_updates_post_request->allowed_updates) {
            free(listEntry->data);
        }
        list_freeList(_get_updates_post_request->allowed_updates);
        _get_updates_post_request->allowed_updates = NULL;
    }
    free(_get_updates_post_request);
}

cJSON *_get_updates_post_request_convertToJSON(_get_updates_post_request_t *_get_updates_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_updates_post_request->offset
    if(_get_updates_post_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", _get_updates_post_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_updates_post_request->limit
    if(_get_updates_post_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", _get_updates_post_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_updates_post_request->timeout
    if(_get_updates_post_request->timeout) {
    if(cJSON_AddNumberToObject(item, "timeout", _get_updates_post_request->timeout) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_updates_post_request->allowed_updates
    if(_get_updates_post_request->allowed_updates) {
    cJSON *allowed_updates = cJSON_AddArrayToObject(item, "allowed_updates");
    if(allowed_updates == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_updatesListEntry;
    list_ForEach(allowed_updatesListEntry, _get_updates_post_request->allowed_updates) {
    if(cJSON_AddStringToObject(allowed_updates, "", allowed_updatesListEntry->data) == NULL)
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

_get_updates_post_request_t *_get_updates_post_request_parseFromJSON(cJSON *_get_updates_post_requestJSON){

    _get_updates_post_request_t *_get_updates_post_request_local_var = NULL;

    // define the local list for _get_updates_post_request->allowed_updates
    list_t *allowed_updatesList = NULL;

    // _get_updates_post_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(_get_updates_post_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // _get_updates_post_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(_get_updates_post_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // _get_updates_post_request->timeout
    cJSON *timeout = cJSON_GetObjectItemCaseSensitive(_get_updates_post_requestJSON, "timeout");
    if (cJSON_IsNull(timeout)) {
        timeout = NULL;
    }
    if (timeout) { 
    if(!cJSON_IsNumber(timeout))
    {
    goto end; //Numeric
    }
    }

    // _get_updates_post_request->allowed_updates
    cJSON *allowed_updates = cJSON_GetObjectItemCaseSensitive(_get_updates_post_requestJSON, "allowed_updates");
    if (cJSON_IsNull(allowed_updates)) {
        allowed_updates = NULL;
    }
    if (allowed_updates) { 
    cJSON *allowed_updates_local = NULL;
    if(!cJSON_IsArray(allowed_updates)) {
        goto end;//primitive container
    }
    allowed_updatesList = list_createList();

    cJSON_ArrayForEach(allowed_updates_local, allowed_updates)
    {
        if(!cJSON_IsString(allowed_updates_local))
        {
            goto end;
        }
        list_addElement(allowed_updatesList , strdup(allowed_updates_local->valuestring));
    }
    }


    _get_updates_post_request_local_var = _get_updates_post_request_create_internal (
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0,
        timeout ? timeout->valuedouble : 0,
        allowed_updates ? allowed_updatesList : NULL
        );

    return _get_updates_post_request_local_var;
end:
    if (allowed_updatesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, allowed_updatesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(allowed_updatesList);
        allowed_updatesList = NULL;
    }
    return NULL;

}
