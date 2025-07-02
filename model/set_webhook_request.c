#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_webhook_request.h"



static set_webhook_request_t *set_webhook_request_create_internal(
    char *url,
    any_type_t *certificate,
    char *ip_address,
    int max_connections,
    list_t *allowed_updates,
    int drop_pending_updates,
    char *secret_token
    ) {
    set_webhook_request_t *set_webhook_request_local_var = malloc(sizeof(set_webhook_request_t));
    if (!set_webhook_request_local_var) {
        return NULL;
    }
    set_webhook_request_local_var->url = url;
    set_webhook_request_local_var->certificate = certificate;
    set_webhook_request_local_var->ip_address = ip_address;
    set_webhook_request_local_var->max_connections = max_connections;
    set_webhook_request_local_var->allowed_updates = allowed_updates;
    set_webhook_request_local_var->drop_pending_updates = drop_pending_updates;
    set_webhook_request_local_var->secret_token = secret_token;

    set_webhook_request_local_var->_library_owned = 1;
    return set_webhook_request_local_var;
}

__attribute__((deprecated)) set_webhook_request_t *set_webhook_request_create(
    char *url,
    any_type_t *certificate,
    char *ip_address,
    int max_connections,
    list_t *allowed_updates,
    int drop_pending_updates,
    char *secret_token
    ) {
    return set_webhook_request_create_internal (
        url,
        certificate,
        ip_address,
        max_connections,
        allowed_updates,
        drop_pending_updates,
        secret_token
        );
}

void set_webhook_request_free(set_webhook_request_t *set_webhook_request) {
    if(NULL == set_webhook_request){
        return ;
    }
    if(set_webhook_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_webhook_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_webhook_request->url) {
        free(set_webhook_request->url);
        set_webhook_request->url = NULL;
    }
    if (set_webhook_request->certificate) {
        _free(set_webhook_request->certificate);
        set_webhook_request->certificate = NULL;
    }
    if (set_webhook_request->ip_address) {
        free(set_webhook_request->ip_address);
        set_webhook_request->ip_address = NULL;
    }
    if (set_webhook_request->allowed_updates) {
        list_ForEach(listEntry, set_webhook_request->allowed_updates) {
            free(listEntry->data);
        }
        list_freeList(set_webhook_request->allowed_updates);
        set_webhook_request->allowed_updates = NULL;
    }
    if (set_webhook_request->secret_token) {
        free(set_webhook_request->secret_token);
        set_webhook_request->secret_token = NULL;
    }
    free(set_webhook_request);
}

cJSON *set_webhook_request_convertToJSON(set_webhook_request_t *set_webhook_request) {
    cJSON *item = cJSON_CreateObject();

    // set_webhook_request->url
    if (!set_webhook_request->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", set_webhook_request->url) == NULL) {
    goto fail; //String
    }


    // set_webhook_request->certificate
    if(set_webhook_request->certificate) {
    cJSON *certificate_local_JSON = _convertToJSON(set_webhook_request->certificate);
    if(certificate_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "certificate", certificate_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // set_webhook_request->ip_address
    if(set_webhook_request->ip_address) {
    if(cJSON_AddStringToObject(item, "ip_address", set_webhook_request->ip_address) == NULL) {
    goto fail; //String
    }
    }


    // set_webhook_request->max_connections
    if(set_webhook_request->max_connections) {
    if(cJSON_AddNumberToObject(item, "max_connections", set_webhook_request->max_connections) == NULL) {
    goto fail; //Numeric
    }
    }


    // set_webhook_request->allowed_updates
    if(set_webhook_request->allowed_updates) {
    cJSON *allowed_updates = cJSON_AddArrayToObject(item, "allowed_updates");
    if(allowed_updates == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_updatesListEntry;
    list_ForEach(allowed_updatesListEntry, set_webhook_request->allowed_updates) {
    if(cJSON_AddStringToObject(allowed_updates, "", allowed_updatesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // set_webhook_request->drop_pending_updates
    if(set_webhook_request->drop_pending_updates) {
    if(cJSON_AddBoolToObject(item, "drop_pending_updates", set_webhook_request->drop_pending_updates) == NULL) {
    goto fail; //Bool
    }
    }


    // set_webhook_request->secret_token
    if(set_webhook_request->secret_token) {
    if(cJSON_AddStringToObject(item, "secret_token", set_webhook_request->secret_token) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

set_webhook_request_t *set_webhook_request_parseFromJSON(cJSON *set_webhook_requestJSON){

    set_webhook_request_t *set_webhook_request_local_var = NULL;

    // define the local variable for set_webhook_request->certificate
    _t *certificate_local_nonprim = NULL;

    // define the local list for set_webhook_request->allowed_updates
    list_t *allowed_updatesList = NULL;

    // set_webhook_request->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // set_webhook_request->certificate
    cJSON *certificate = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "certificate");
    if (cJSON_IsNull(certificate)) {
        certificate = NULL;
    }
    if (certificate) { 
    certificate_local_nonprim = _parseFromJSON(certificate); //custom
    }

    // set_webhook_request->ip_address
    cJSON *ip_address = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "ip_address");
    if (cJSON_IsNull(ip_address)) {
        ip_address = NULL;
    }
    if (ip_address) { 
    if(!cJSON_IsString(ip_address) && !cJSON_IsNull(ip_address))
    {
    goto end; //String
    }
    }

    // set_webhook_request->max_connections
    cJSON *max_connections = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "max_connections");
    if (cJSON_IsNull(max_connections)) {
        max_connections = NULL;
    }
    if (max_connections) { 
    if(!cJSON_IsNumber(max_connections))
    {
    goto end; //Numeric
    }
    }

    // set_webhook_request->allowed_updates
    cJSON *allowed_updates = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "allowed_updates");
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

    // set_webhook_request->drop_pending_updates
    cJSON *drop_pending_updates = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "drop_pending_updates");
    if (cJSON_IsNull(drop_pending_updates)) {
        drop_pending_updates = NULL;
    }
    if (drop_pending_updates) { 
    if(!cJSON_IsBool(drop_pending_updates))
    {
    goto end; //Bool
    }
    }

    // set_webhook_request->secret_token
    cJSON *secret_token = cJSON_GetObjectItemCaseSensitive(set_webhook_requestJSON, "secret_token");
    if (cJSON_IsNull(secret_token)) {
        secret_token = NULL;
    }
    if (secret_token) { 
    if(!cJSON_IsString(secret_token) && !cJSON_IsNull(secret_token))
    {
    goto end; //String
    }
    }


    set_webhook_request_local_var = set_webhook_request_create_internal (
        strdup(url->valuestring),
        certificate ? certificate_local_nonprim : NULL,
        ip_address && !cJSON_IsNull(ip_address) ? strdup(ip_address->valuestring) : NULL,
        max_connections ? max_connections->valuedouble : 0,
        allowed_updates ? allowed_updatesList : NULL,
        drop_pending_updates ? drop_pending_updates->valueint : 0,
        secret_token && !cJSON_IsNull(secret_token) ? strdup(secret_token->valuestring) : NULL
        );

    return set_webhook_request_local_var;
end:
    if (certificate_local_nonprim) {
        _free(certificate_local_nonprim);
        certificate_local_nonprim = NULL;
    }
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
