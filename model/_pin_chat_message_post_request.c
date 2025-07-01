#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_pin_chat_message_post_request.h"



static _pin_chat_message_post_request_t *_pin_chat_message_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    _pin_chat_message_post_request_t *_pin_chat_message_post_request_local_var = malloc(sizeof(_pin_chat_message_post_request_t));
    if (!_pin_chat_message_post_request_local_var) {
        return NULL;
    }
    _pin_chat_message_post_request_local_var->chat_id = chat_id;
    _pin_chat_message_post_request_local_var->message_id = message_id;
    _pin_chat_message_post_request_local_var->business_connection_id = business_connection_id;
    _pin_chat_message_post_request_local_var->disable_notification = disable_notification;

    _pin_chat_message_post_request_local_var->_library_owned = 1;
    return _pin_chat_message_post_request_local_var;
}

__attribute__((deprecated)) _pin_chat_message_post_request_t *_pin_chat_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    int disable_notification
    ) {
    return _pin_chat_message_post_request_create_internal (
        chat_id,
        message_id,
        business_connection_id,
        disable_notification
        );
}

void _pin_chat_message_post_request_free(_pin_chat_message_post_request_t *_pin_chat_message_post_request) {
    if(NULL == _pin_chat_message_post_request){
        return ;
    }
    if(_pin_chat_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_pin_chat_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_pin_chat_message_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_pin_chat_message_post_request->chat_id);
        _pin_chat_message_post_request->chat_id = NULL;
    }
    if (_pin_chat_message_post_request->business_connection_id) {
        free(_pin_chat_message_post_request->business_connection_id);
        _pin_chat_message_post_request->business_connection_id = NULL;
    }
    free(_pin_chat_message_post_request);
}

cJSON *_pin_chat_message_post_request_convertToJSON(_pin_chat_message_post_request_t *_pin_chat_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _pin_chat_message_post_request->chat_id
    if (!_pin_chat_message_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_pin_chat_message_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _pin_chat_message_post_request->message_id
    if (!_pin_chat_message_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _pin_chat_message_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // _pin_chat_message_post_request->business_connection_id
    if(_pin_chat_message_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _pin_chat_message_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _pin_chat_message_post_request->disable_notification
    if(_pin_chat_message_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _pin_chat_message_post_request->disable_notification) == NULL) {
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

_pin_chat_message_post_request_t *_pin_chat_message_post_request_parseFromJSON(cJSON *_pin_chat_message_post_requestJSON){

    _pin_chat_message_post_request_t *_pin_chat_message_post_request_local_var = NULL;

    // define the local variable for _pin_chat_message_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _pin_chat_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_pin_chat_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _pin_chat_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_pin_chat_message_post_requestJSON, "message_id");
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

    // _pin_chat_message_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_pin_chat_message_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _pin_chat_message_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_pin_chat_message_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }


    _pin_chat_message_post_request_local_var = _pin_chat_message_post_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0
        );

    return _pin_chat_message_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
