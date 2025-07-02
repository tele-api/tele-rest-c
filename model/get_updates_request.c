#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_updates_request.h"



static get_updates_request_t *get_updates_request_create_internal(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    get_updates_request_t *get_updates_request_local_var = malloc(sizeof(get_updates_request_t));
    if (!get_updates_request_local_var) {
        return NULL;
    }
    get_updates_request_local_var->offset = offset;
    get_updates_request_local_var->limit = limit;
    get_updates_request_local_var->timeout = timeout;
    get_updates_request_local_var->allowed_updates = allowed_updates;

    get_updates_request_local_var->_library_owned = 1;
    return get_updates_request_local_var;
}

__attribute__((deprecated)) get_updates_request_t *get_updates_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    return get_updates_request_create_internal (
        offset,
        limit,
        timeout,
        allowed_updates
        );
}

void get_updates_request_free(get_updates_request_t *get_updates_request) {
    if(NULL == get_updates_request){
        return ;
    }
    if(get_updates_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_updates_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_updates_request->allowed_updates) {
        list_ForEach(listEntry, get_updates_request->allowed_updates) {
            free(listEntry->data);
        }
        list_freeList(get_updates_request->allowed_updates);
        get_updates_request->allowed_updates = NULL;
    }
    free(get_updates_request);
}

cJSON *get_updates_request_convertToJSON(get_updates_request_t *get_updates_request) {
    cJSON *item = cJSON_CreateObject();

    // get_updates_request->offset
    if(get_updates_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", get_updates_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_updates_request->limit
    if(get_updates_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", get_updates_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_updates_request->timeout
    if(get_updates_request->timeout) {
    if(cJSON_AddNumberToObject(item, "timeout", get_updates_request->timeout) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_updates_request->allowed_updates
    if(get_updates_request->allowed_updates) {
    cJSON *allowed_updates = cJSON_AddArrayToObject(item, "allowed_updates");
    if(allowed_updates == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_updatesListEntry;
    list_ForEach(allowed_updatesListEntry, get_updates_request->allowed_updates) {
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

get_updates_request_t *get_updates_request_parseFromJSON(cJSON *get_updates_requestJSON){

    get_updates_request_t *get_updates_request_local_var = NULL;

    // define the local list for get_updates_request->allowed_updates
    list_t *allowed_updatesList = NULL;

    // get_updates_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_updates_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // get_updates_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_updates_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // get_updates_request->timeout
    cJSON *timeout = cJSON_GetObjectItemCaseSensitive(get_updates_requestJSON, "timeout");
    if (cJSON_IsNull(timeout)) {
        timeout = NULL;
    }
    if (timeout) { 
    if(!cJSON_IsNumber(timeout))
    {
    goto end; //Numeric
    }
    }

    // get_updates_request->allowed_updates
    cJSON *allowed_updates = cJSON_GetObjectItemCaseSensitive(get_updates_requestJSON, "allowed_updates");
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


    get_updates_request_local_var = get_updates_request_create_internal (
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0,
        timeout ? timeout->valuedouble : 0,
        allowed_updates ? allowed_updatesList : NULL
        );

    return get_updates_request_local_var;
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
