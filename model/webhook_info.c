#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "webhook_info.h"



static webhook_info_t *webhook_info_create_internal(
    char *url,
    int has_custom_certificate,
    int pending_update_count,
    char *ip_address,
    int last_error_date,
    char *last_error_message,
    int last_synchronization_error_date,
    int max_connections,
    list_t *allowed_updates
    ) {
    webhook_info_t *webhook_info_local_var = malloc(sizeof(webhook_info_t));
    if (!webhook_info_local_var) {
        return NULL;
    }
    webhook_info_local_var->url = url;
    webhook_info_local_var->has_custom_certificate = has_custom_certificate;
    webhook_info_local_var->pending_update_count = pending_update_count;
    webhook_info_local_var->ip_address = ip_address;
    webhook_info_local_var->last_error_date = last_error_date;
    webhook_info_local_var->last_error_message = last_error_message;
    webhook_info_local_var->last_synchronization_error_date = last_synchronization_error_date;
    webhook_info_local_var->max_connections = max_connections;
    webhook_info_local_var->allowed_updates = allowed_updates;

    webhook_info_local_var->_library_owned = 1;
    return webhook_info_local_var;
}

__attribute__((deprecated)) webhook_info_t *webhook_info_create(
    char *url,
    int has_custom_certificate,
    int pending_update_count,
    char *ip_address,
    int last_error_date,
    char *last_error_message,
    int last_synchronization_error_date,
    int max_connections,
    list_t *allowed_updates
    ) {
    return webhook_info_create_internal (
        url,
        has_custom_certificate,
        pending_update_count,
        ip_address,
        last_error_date,
        last_error_message,
        last_synchronization_error_date,
        max_connections,
        allowed_updates
        );
}

void webhook_info_free(webhook_info_t *webhook_info) {
    if(NULL == webhook_info){
        return ;
    }
    if(webhook_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "webhook_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (webhook_info->url) {
        free(webhook_info->url);
        webhook_info->url = NULL;
    }
    if (webhook_info->ip_address) {
        free(webhook_info->ip_address);
        webhook_info->ip_address = NULL;
    }
    if (webhook_info->last_error_message) {
        free(webhook_info->last_error_message);
        webhook_info->last_error_message = NULL;
    }
    if (webhook_info->allowed_updates) {
        list_ForEach(listEntry, webhook_info->allowed_updates) {
            free(listEntry->data);
        }
        list_freeList(webhook_info->allowed_updates);
        webhook_info->allowed_updates = NULL;
    }
    free(webhook_info);
}

cJSON *webhook_info_convertToJSON(webhook_info_t *webhook_info) {
    cJSON *item = cJSON_CreateObject();

    // webhook_info->url
    if (!webhook_info->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", webhook_info->url) == NULL) {
    goto fail; //String
    }


    // webhook_info->has_custom_certificate
    if (!webhook_info->has_custom_certificate) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "has_custom_certificate", webhook_info->has_custom_certificate) == NULL) {
    goto fail; //Bool
    }


    // webhook_info->pending_update_count
    if (!webhook_info->pending_update_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "pending_update_count", webhook_info->pending_update_count) == NULL) {
    goto fail; //Numeric
    }


    // webhook_info->ip_address
    if(webhook_info->ip_address) {
    if(cJSON_AddStringToObject(item, "ip_address", webhook_info->ip_address) == NULL) {
    goto fail; //String
    }
    }


    // webhook_info->last_error_date
    if(webhook_info->last_error_date) {
    if(cJSON_AddNumberToObject(item, "last_error_date", webhook_info->last_error_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // webhook_info->last_error_message
    if(webhook_info->last_error_message) {
    if(cJSON_AddStringToObject(item, "last_error_message", webhook_info->last_error_message) == NULL) {
    goto fail; //String
    }
    }


    // webhook_info->last_synchronization_error_date
    if(webhook_info->last_synchronization_error_date) {
    if(cJSON_AddNumberToObject(item, "last_synchronization_error_date", webhook_info->last_synchronization_error_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // webhook_info->max_connections
    if(webhook_info->max_connections) {
    if(cJSON_AddNumberToObject(item, "max_connections", webhook_info->max_connections) == NULL) {
    goto fail; //Numeric
    }
    }


    // webhook_info->allowed_updates
    if(webhook_info->allowed_updates) {
    cJSON *allowed_updates = cJSON_AddArrayToObject(item, "allowed_updates");
    if(allowed_updates == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *allowed_updatesListEntry;
    list_ForEach(allowed_updatesListEntry, webhook_info->allowed_updates) {
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

webhook_info_t *webhook_info_parseFromJSON(cJSON *webhook_infoJSON){

    webhook_info_t *webhook_info_local_var = NULL;

    // define the local list for webhook_info->allowed_updates
    list_t *allowed_updatesList = NULL;

    // webhook_info->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "url");
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

    // webhook_info->has_custom_certificate
    cJSON *has_custom_certificate = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "has_custom_certificate");
    if (cJSON_IsNull(has_custom_certificate)) {
        has_custom_certificate = NULL;
    }
    if (!has_custom_certificate) {
        goto end;
    }

    
    if(!cJSON_IsBool(has_custom_certificate))
    {
    goto end; //Bool
    }

    // webhook_info->pending_update_count
    cJSON *pending_update_count = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "pending_update_count");
    if (cJSON_IsNull(pending_update_count)) {
        pending_update_count = NULL;
    }
    if (!pending_update_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(pending_update_count))
    {
    goto end; //Numeric
    }

    // webhook_info->ip_address
    cJSON *ip_address = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "ip_address");
    if (cJSON_IsNull(ip_address)) {
        ip_address = NULL;
    }
    if (ip_address) { 
    if(!cJSON_IsString(ip_address) && !cJSON_IsNull(ip_address))
    {
    goto end; //String
    }
    }

    // webhook_info->last_error_date
    cJSON *last_error_date = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "last_error_date");
    if (cJSON_IsNull(last_error_date)) {
        last_error_date = NULL;
    }
    if (last_error_date) { 
    if(!cJSON_IsNumber(last_error_date))
    {
    goto end; //Numeric
    }
    }

    // webhook_info->last_error_message
    cJSON *last_error_message = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "last_error_message");
    if (cJSON_IsNull(last_error_message)) {
        last_error_message = NULL;
    }
    if (last_error_message) { 
    if(!cJSON_IsString(last_error_message) && !cJSON_IsNull(last_error_message))
    {
    goto end; //String
    }
    }

    // webhook_info->last_synchronization_error_date
    cJSON *last_synchronization_error_date = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "last_synchronization_error_date");
    if (cJSON_IsNull(last_synchronization_error_date)) {
        last_synchronization_error_date = NULL;
    }
    if (last_synchronization_error_date) { 
    if(!cJSON_IsNumber(last_synchronization_error_date))
    {
    goto end; //Numeric
    }
    }

    // webhook_info->max_connections
    cJSON *max_connections = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "max_connections");
    if (cJSON_IsNull(max_connections)) {
        max_connections = NULL;
    }
    if (max_connections) { 
    if(!cJSON_IsNumber(max_connections))
    {
    goto end; //Numeric
    }
    }

    // webhook_info->allowed_updates
    cJSON *allowed_updates = cJSON_GetObjectItemCaseSensitive(webhook_infoJSON, "allowed_updates");
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


    webhook_info_local_var = webhook_info_create_internal (
        strdup(url->valuestring),
        has_custom_certificate->valueint,
        pending_update_count->valuedouble,
        ip_address && !cJSON_IsNull(ip_address) ? strdup(ip_address->valuestring) : NULL,
        last_error_date ? last_error_date->valuedouble : 0,
        last_error_message && !cJSON_IsNull(last_error_message) ? strdup(last_error_message->valuestring) : NULL,
        last_synchronization_error_date ? last_synchronization_error_date->valuedouble : 0,
        max_connections ? max_connections->valuedouble : 0,
        allowed_updates ? allowed_updatesList : NULL
        );

    return webhook_info_local_var;
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
