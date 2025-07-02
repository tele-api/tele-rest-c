#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transfer_gift_request.h"



static transfer_gift_request_t *transfer_gift_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id,
    int new_owner_chat_id,
    int star_count
    ) {
    transfer_gift_request_t *transfer_gift_request_local_var = malloc(sizeof(transfer_gift_request_t));
    if (!transfer_gift_request_local_var) {
        return NULL;
    }
    transfer_gift_request_local_var->business_connection_id = business_connection_id;
    transfer_gift_request_local_var->owned_gift_id = owned_gift_id;
    transfer_gift_request_local_var->new_owner_chat_id = new_owner_chat_id;
    transfer_gift_request_local_var->star_count = star_count;

    transfer_gift_request_local_var->_library_owned = 1;
    return transfer_gift_request_local_var;
}

__attribute__((deprecated)) transfer_gift_request_t *transfer_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int new_owner_chat_id,
    int star_count
    ) {
    return transfer_gift_request_create_internal (
        business_connection_id,
        owned_gift_id,
        new_owner_chat_id,
        star_count
        );
}

void transfer_gift_request_free(transfer_gift_request_t *transfer_gift_request) {
    if(NULL == transfer_gift_request){
        return ;
    }
    if(transfer_gift_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transfer_gift_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transfer_gift_request->business_connection_id) {
        free(transfer_gift_request->business_connection_id);
        transfer_gift_request->business_connection_id = NULL;
    }
    if (transfer_gift_request->owned_gift_id) {
        free(transfer_gift_request->owned_gift_id);
        transfer_gift_request->owned_gift_id = NULL;
    }
    free(transfer_gift_request);
}

cJSON *transfer_gift_request_convertToJSON(transfer_gift_request_t *transfer_gift_request) {
    cJSON *item = cJSON_CreateObject();

    // transfer_gift_request->business_connection_id
    if (!transfer_gift_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", transfer_gift_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // transfer_gift_request->owned_gift_id
    if (!transfer_gift_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", transfer_gift_request->owned_gift_id) == NULL) {
    goto fail; //String
    }


    // transfer_gift_request->new_owner_chat_id
    if (!transfer_gift_request->new_owner_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "new_owner_chat_id", transfer_gift_request->new_owner_chat_id) == NULL) {
    goto fail; //Numeric
    }


    // transfer_gift_request->star_count
    if(transfer_gift_request->star_count) {
    if(cJSON_AddNumberToObject(item, "star_count", transfer_gift_request->star_count) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transfer_gift_request_t *transfer_gift_request_parseFromJSON(cJSON *transfer_gift_requestJSON){

    transfer_gift_request_t *transfer_gift_request_local_var = NULL;

    // transfer_gift_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(transfer_gift_requestJSON, "business_connection_id");
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

    // transfer_gift_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(transfer_gift_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }

    // transfer_gift_request->new_owner_chat_id
    cJSON *new_owner_chat_id = cJSON_GetObjectItemCaseSensitive(transfer_gift_requestJSON, "new_owner_chat_id");
    if (cJSON_IsNull(new_owner_chat_id)) {
        new_owner_chat_id = NULL;
    }
    if (!new_owner_chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(new_owner_chat_id))
    {
    goto end; //Numeric
    }

    // transfer_gift_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(transfer_gift_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (star_count) { 
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }
    }


    transfer_gift_request_local_var = transfer_gift_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring),
        new_owner_chat_id->valuedouble,
        star_count ? star_count->valuedouble : 0
        );

    return transfer_gift_request_local_var;
end:
    return NULL;

}
