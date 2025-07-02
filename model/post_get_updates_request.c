#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_updates_request.h"



static post_get_updates_request_t *post_get_updates_request_create_internal(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    post_get_updates_request_t *post_get_updates_request_local_var = malloc(sizeof(post_get_updates_request_t));
    if (!post_get_updates_request_local_var) {
        return NULL;
    }
    post_get_updates_request_local_var->offset = offset;
    post_get_updates_request_local_var->limit = limit;
    post_get_updates_request_local_var->timeout = timeout;
    post_get_updates_request_local_var->allowed_updates = allowed_updates;

    post_get_updates_request_local_var->_library_owned = 1;
    return post_get_updates_request_local_var;
}

__attribute__((deprecated)) post_get_updates_request_t *post_get_updates_request_create(
    int offset,
    int limit,
    int timeout,
    list_t *allowed_updates
    ) {
    return post_get_updates_request_create_internal (
        offset,
        limit,
        timeout,
        allowed_updates
        );
}

void post_get_updates_request_free(post_get_updates_request_t *post_get_updates_request) {
    if(NULL == post_get_updates_request){
        return ;
    }
    if(post_get_updates_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_updates_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_updates_request->allowed_updates) {
        list_ForEach(listEntry, post_get_updates_request->allowed_updates) {
            free(listEntry->data);
        }
        list_freeList(post_get_updates_request->allowed_updates);
        post_get_updates_request->allowed_updates = NULL;
    }
    free(post_get_updates_request);
}

cJSON *post_get_updates_request_convertToJSON(post_get_updates_request_t *post_get_updates_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_updates_request->offset
    if(post_get_updates_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", post_get_updates_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_get_updates_request->limit
    if(post_get_updates_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", post_get_updates_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_get_updates_request->timeout
    if(post_get_updates_request->timeout) {
    if(cJSON_AddNumberToObject(item, "timeout", post_get_updates_request->timeout) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_get_updates_request->allowed_updates
    if(post_get_updates_request->allowed_updates) {
    cJSON *allowed_updates = cJSON_AddArrayToObject(item, "allowed_updates");
    if(allowed_updates == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_updatesListEntry;
    list_ForEach(allowed_updatesListEntry, post_get_updates_request->allowed_updates) {
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

post_get_updates_request_t *post_get_updates_request_parseFromJSON(cJSON *post_get_updates_requestJSON){

    post_get_updates_request_t *post_get_updates_request_local_var = NULL;

    // define the local list for post_get_updates_request->allowed_updates
    list_t *allowed_updatesList = NULL;

    // post_get_updates_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(post_get_updates_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // post_get_updates_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(post_get_updates_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }

    // post_get_updates_request->timeout
    cJSON *timeout = cJSON_GetObjectItemCaseSensitive(post_get_updates_requestJSON, "timeout");
    if (cJSON_IsNull(timeout)) {
        timeout = NULL;
    }
    if (timeout) { 
    if(!cJSON_IsNumber(timeout))
    {
    goto end; //Numeric
    }
    }

    // post_get_updates_request->allowed_updates
    cJSON *allowed_updates = cJSON_GetObjectItemCaseSensitive(post_get_updates_requestJSON, "allowed_updates");
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


    post_get_updates_request_local_var = post_get_updates_request_create_internal (
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0,
        timeout ? timeout->valuedouble : 0,
        allowed_updates ? allowed_updatesList : NULL
        );

    return post_get_updates_request_local_var;
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
