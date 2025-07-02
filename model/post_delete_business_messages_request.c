#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_business_messages_request.h"



static post_delete_business_messages_request_t *post_delete_business_messages_request_create_internal(
    char *business_connection_id,
    list_t *message_ids
    ) {
    post_delete_business_messages_request_t *post_delete_business_messages_request_local_var = malloc(sizeof(post_delete_business_messages_request_t));
    if (!post_delete_business_messages_request_local_var) {
        return NULL;
    }
    post_delete_business_messages_request_local_var->business_connection_id = business_connection_id;
    post_delete_business_messages_request_local_var->message_ids = message_ids;

    post_delete_business_messages_request_local_var->_library_owned = 1;
    return post_delete_business_messages_request_local_var;
}

__attribute__((deprecated)) post_delete_business_messages_request_t *post_delete_business_messages_request_create(
    char *business_connection_id,
    list_t *message_ids
    ) {
    return post_delete_business_messages_request_create_internal (
        business_connection_id,
        message_ids
        );
}

void post_delete_business_messages_request_free(post_delete_business_messages_request_t *post_delete_business_messages_request) {
    if(NULL == post_delete_business_messages_request){
        return ;
    }
    if(post_delete_business_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_business_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_business_messages_request->business_connection_id) {
        free(post_delete_business_messages_request->business_connection_id);
        post_delete_business_messages_request->business_connection_id = NULL;
    }
    if (post_delete_business_messages_request->message_ids) {
        list_ForEach(listEntry, post_delete_business_messages_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(post_delete_business_messages_request->message_ids);
        post_delete_business_messages_request->message_ids = NULL;
    }
    free(post_delete_business_messages_request);
}

cJSON *post_delete_business_messages_request_convertToJSON(post_delete_business_messages_request_t *post_delete_business_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_business_messages_request->business_connection_id
    if (!post_delete_business_messages_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", post_delete_business_messages_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // post_delete_business_messages_request->message_ids
    if (!post_delete_business_messages_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, post_delete_business_messages_request->message_ids) {
    if(cJSON_AddNumberToObject(message_ids, "", *(double *)message_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_delete_business_messages_request_t *post_delete_business_messages_request_parseFromJSON(cJSON *post_delete_business_messages_requestJSON){

    post_delete_business_messages_request_t *post_delete_business_messages_request_local_var = NULL;

    // define the local list for post_delete_business_messages_request->message_ids
    list_t *message_idsList = NULL;

    // post_delete_business_messages_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_delete_business_messages_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // post_delete_business_messages_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(post_delete_business_messages_requestJSON, "message_ids");
    if (cJSON_IsNull(message_ids)) {
        message_ids = NULL;
    }
    if (!message_ids) {
        goto end;
    }

    
    cJSON *message_ids_local = NULL;
    if(!cJSON_IsArray(message_ids)) {
        goto end;//primitive container
    }
    message_idsList = list_createList();

    cJSON_ArrayForEach(message_ids_local, message_ids)
    {
        if(!cJSON_IsNumber(message_ids_local))
        {
            goto end;
        }
        double *message_ids_local_value = calloc(1, sizeof(double));
        if(!message_ids_local_value)
        {
            goto end;
        }
        *message_ids_local_value = message_ids_local->valuedouble;
        list_addElement(message_idsList , message_ids_local_value);
    }


    post_delete_business_messages_request_local_var = post_delete_business_messages_request_create_internal (
        strdup(business_connection_id->valuestring),
        message_idsList
        );

    return post_delete_business_messages_request_local_var;
end:
    if (message_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, message_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(message_idsList);
        message_idsList = NULL;
    }
    return NULL;

}
