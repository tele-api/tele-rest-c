#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pin_chat_message_request.h"



static pin_chat_message_request_t *pin_chat_message_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    pin_chat_message_request_t *pin_chat_message_request_local_var = malloc(sizeof(pin_chat_message_request_t));
    if (!pin_chat_message_request_local_var) {
        return NULL;
    }
    pin_chat_message_request_local_var->chat_id = chat_id;
    pin_chat_message_request_local_var->message_id = message_id;
    pin_chat_message_request_local_var->business_connection_id = business_connection_id;
    pin_chat_message_request_local_var->disable_notification = disable_notification;

    pin_chat_message_request_local_var->_library_owned = 1;
    return pin_chat_message_request_local_var;
}

__attribute__((deprecated)) pin_chat_message_request_t *pin_chat_message_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    return pin_chat_message_request_create_internal (
        chat_id,
        message_id,
        business_connection_id,
        disable_notification
        );
}

void pin_chat_message_request_free(pin_chat_message_request_t *pin_chat_message_request) {
    if(NULL == pin_chat_message_request){
        return ;
    }
    if(pin_chat_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pin_chat_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pin_chat_message_request->chat_id) {
        send_message_request_chat_id_free(pin_chat_message_request->chat_id);
        pin_chat_message_request->chat_id = NULL;
    }
    if (pin_chat_message_request->business_connection_id) {
        free(pin_chat_message_request->business_connection_id);
        pin_chat_message_request->business_connection_id = NULL;
    }
    free(pin_chat_message_request);
}

cJSON *pin_chat_message_request_convertToJSON(pin_chat_message_request_t *pin_chat_message_request) {
    cJSON *item = cJSON_CreateObject();

    // pin_chat_message_request->chat_id
    if (!pin_chat_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(pin_chat_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // pin_chat_message_request->message_id
    if (!pin_chat_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", pin_chat_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // pin_chat_message_request->business_connection_id
    if(pin_chat_message_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", pin_chat_message_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // pin_chat_message_request->disable_notification
    if(pin_chat_message_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", pin_chat_message_request->disable_notification) == NULL) {
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

pin_chat_message_request_t *pin_chat_message_request_parseFromJSON(cJSON *pin_chat_message_requestJSON){

    pin_chat_message_request_t *pin_chat_message_request_local_var = NULL;

    // define the local variable for pin_chat_message_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // pin_chat_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(pin_chat_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // pin_chat_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(pin_chat_message_requestJSON, "message_id");
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

    // pin_chat_message_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(pin_chat_message_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // pin_chat_message_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(pin_chat_message_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }


    pin_chat_message_request_local_var = pin_chat_message_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0
        );

    return pin_chat_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
