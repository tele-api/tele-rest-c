#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_pin_chat_message_request.h"



static post_pin_chat_message_request_t *post_pin_chat_message_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    post_pin_chat_message_request_t *post_pin_chat_message_request_local_var = malloc(sizeof(post_pin_chat_message_request_t));
    if (!post_pin_chat_message_request_local_var) {
        return NULL;
    }
    post_pin_chat_message_request_local_var->chat_id = chat_id;
    post_pin_chat_message_request_local_var->message_id = message_id;
    post_pin_chat_message_request_local_var->business_connection_id = business_connection_id;
    post_pin_chat_message_request_local_var->disable_notification = disable_notification;

    post_pin_chat_message_request_local_var->_library_owned = 1;
    return post_pin_chat_message_request_local_var;
}

__attribute__((deprecated)) post_pin_chat_message_request_t *post_pin_chat_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    return post_pin_chat_message_request_create_internal (
        chat_id,
        message_id,
        business_connection_id,
        disable_notification
        );
}

void post_pin_chat_message_request_free(post_pin_chat_message_request_t *post_pin_chat_message_request) {
    if(NULL == post_pin_chat_message_request){
        return ;
    }
    if(post_pin_chat_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_pin_chat_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_pin_chat_message_request->chat_id) {
        post_send_message_request_chat_id_free(post_pin_chat_message_request->chat_id);
        post_pin_chat_message_request->chat_id = NULL;
    }
    if (post_pin_chat_message_request->business_connection_id) {
        free(post_pin_chat_message_request->business_connection_id);
        post_pin_chat_message_request->business_connection_id = NULL;
    }
    free(post_pin_chat_message_request);
}

cJSON *post_pin_chat_message_request_convertToJSON(post_pin_chat_message_request_t *post_pin_chat_message_request) {
    cJSON *item = cJSON_CreateObject();

    // post_pin_chat_message_request->chat_id
    if (!post_pin_chat_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_pin_chat_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_pin_chat_message_request->message_id
    if (!post_pin_chat_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", post_pin_chat_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // post_pin_chat_message_request->business_connection_id
    if(post_pin_chat_message_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_pin_chat_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_pin_chat_message_request->disable_notification
    if(post_pin_chat_message_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", post_pin_chat_message_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_pin_chat_message_request_t *post_pin_chat_message_request_parseFromJSON(cJSON *post_pin_chat_message_requestJSON){

    post_pin_chat_message_request_t *post_pin_chat_message_request_local_var = NULL;

    // define the local variable for post_pin_chat_message_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_pin_chat_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_pin_chat_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_pin_chat_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_pin_chat_message_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // post_pin_chat_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_pin_chat_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_pin_chat_message_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(post_pin_chat_message_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }


    post_pin_chat_message_request_local_var = post_pin_chat_message_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0
        );

    return post_pin_chat_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
