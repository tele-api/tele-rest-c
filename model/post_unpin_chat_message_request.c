#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_unpin_chat_message_request.h"



static post_unpin_chat_message_request_t *post_unpin_chat_message_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    post_unpin_chat_message_request_t *post_unpin_chat_message_request_local_var = malloc(sizeof(post_unpin_chat_message_request_t));
    if (!post_unpin_chat_message_request_local_var) {
        return NULL;
    }
    post_unpin_chat_message_request_local_var->chat_id = chat_id;
    post_unpin_chat_message_request_local_var->business_connection_id = business_connection_id;
    post_unpin_chat_message_request_local_var->message_id = message_id;

    post_unpin_chat_message_request_local_var->_library_owned = 1;
    return post_unpin_chat_message_request_local_var;
}

__attribute__((deprecated)) post_unpin_chat_message_request_t *post_unpin_chat_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    return post_unpin_chat_message_request_create_internal (
        chat_id,
        business_connection_id,
        message_id
        );
}

void post_unpin_chat_message_request_free(post_unpin_chat_message_request_t *post_unpin_chat_message_request) {
    if(NULL == post_unpin_chat_message_request){
        return ;
    }
    if(post_unpin_chat_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_unpin_chat_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_unpin_chat_message_request->chat_id) {
        post_send_message_request_chat_id_free(post_unpin_chat_message_request->chat_id);
        post_unpin_chat_message_request->chat_id = NULL;
    }
    if (post_unpin_chat_message_request->business_connection_id) {
        free(post_unpin_chat_message_request->business_connection_id);
        post_unpin_chat_message_request->business_connection_id = NULL;
    }
    free(post_unpin_chat_message_request);
}

cJSON *post_unpin_chat_message_request_convertToJSON(post_unpin_chat_message_request_t *post_unpin_chat_message_request) {
    cJSON *item = cJSON_CreateObject();

    // post_unpin_chat_message_request->chat_id
    if (!post_unpin_chat_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_unpin_chat_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_unpin_chat_message_request->business_connection_id
    if(post_unpin_chat_message_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_unpin_chat_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_unpin_chat_message_request->message_id
    if(post_unpin_chat_message_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", post_unpin_chat_message_request->message_id) == NULL) {
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

post_unpin_chat_message_request_t *post_unpin_chat_message_request_parseFromJSON(cJSON *post_unpin_chat_message_requestJSON){

    post_unpin_chat_message_request_t *post_unpin_chat_message_request_local_var = NULL;

    // define the local variable for post_unpin_chat_message_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_unpin_chat_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_unpin_chat_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_unpin_chat_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_unpin_chat_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_unpin_chat_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_unpin_chat_message_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }


    post_unpin_chat_message_request_local_var = post_unpin_chat_message_request_create_internal (
        chat_id_local_nonprim,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_id ? message_id->valuedouble : 0
        );

    return post_unpin_chat_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
