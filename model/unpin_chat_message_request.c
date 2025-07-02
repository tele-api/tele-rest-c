#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpin_chat_message_request.h"



static unpin_chat_message_request_t *unpin_chat_message_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    unpin_chat_message_request_t *unpin_chat_message_request_local_var = malloc(sizeof(unpin_chat_message_request_t));
    if (!unpin_chat_message_request_local_var) {
        return NULL;
    }
    unpin_chat_message_request_local_var->chat_id = chat_id;
    unpin_chat_message_request_local_var->business_connection_id = business_connection_id;
    unpin_chat_message_request_local_var->message_id = message_id;

    unpin_chat_message_request_local_var->_library_owned = 1;
    return unpin_chat_message_request_local_var;
}

__attribute__((deprecated)) unpin_chat_message_request_t *unpin_chat_message_request_create(
    send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    return unpin_chat_message_request_create_internal (
        chat_id,
        business_connection_id,
        message_id
        );
}

void unpin_chat_message_request_free(unpin_chat_message_request_t *unpin_chat_message_request) {
    if(NULL == unpin_chat_message_request){
        return ;
    }
    if(unpin_chat_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unpin_chat_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unpin_chat_message_request->chat_id) {
        send_message_request_chat_id_free(unpin_chat_message_request->chat_id);
        unpin_chat_message_request->chat_id = NULL;
    }
    if (unpin_chat_message_request->business_connection_id) {
        free(unpin_chat_message_request->business_connection_id);
        unpin_chat_message_request->business_connection_id = NULL;
    }
    free(unpin_chat_message_request);
}

cJSON *unpin_chat_message_request_convertToJSON(unpin_chat_message_request_t *unpin_chat_message_request) {
    cJSON *item = cJSON_CreateObject();

    // unpin_chat_message_request->chat_id
    if (!unpin_chat_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(unpin_chat_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unpin_chat_message_request->business_connection_id
    if(unpin_chat_message_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", unpin_chat_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // unpin_chat_message_request->message_id
    if(unpin_chat_message_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", unpin_chat_message_request->message_id) == NULL) {
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

unpin_chat_message_request_t *unpin_chat_message_request_parseFromJSON(cJSON *unpin_chat_message_requestJSON){

    unpin_chat_message_request_t *unpin_chat_message_request_local_var = NULL;

    // define the local variable for unpin_chat_message_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // unpin_chat_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unpin_chat_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // unpin_chat_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(unpin_chat_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // unpin_chat_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(unpin_chat_message_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }


    unpin_chat_message_request_local_var = unpin_chat_message_request_create_internal (
        chat_id_local_nonprim,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_id ? message_id->valuedouble : 0
        );

    return unpin_chat_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
