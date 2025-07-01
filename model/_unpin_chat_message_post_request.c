#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_unpin_chat_message_post_request.h"



static _unpin_chat_message_post_request_t *_unpin_chat_message_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    _unpin_chat_message_post_request_t *_unpin_chat_message_post_request_local_var = malloc(sizeof(_unpin_chat_message_post_request_t));
    if (!_unpin_chat_message_post_request_local_var) {
        return NULL;
    }
    _unpin_chat_message_post_request_local_var->chat_id = chat_id;
    _unpin_chat_message_post_request_local_var->business_connection_id = business_connection_id;
    _unpin_chat_message_post_request_local_var->message_id = message_id;

    _unpin_chat_message_post_request_local_var->_library_owned = 1;
    return _unpin_chat_message_post_request_local_var;
}

__attribute__((deprecated)) _unpin_chat_message_post_request_t *_unpin_chat_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *business_connection_id,
    int message_id
    ) {
    return _unpin_chat_message_post_request_create_internal (
        chat_id,
        business_connection_id,
        message_id
        );
}

void _unpin_chat_message_post_request_free(_unpin_chat_message_post_request_t *_unpin_chat_message_post_request) {
    if(NULL == _unpin_chat_message_post_request){
        return ;
    }
    if(_unpin_chat_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_unpin_chat_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_unpin_chat_message_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_unpin_chat_message_post_request->chat_id);
        _unpin_chat_message_post_request->chat_id = NULL;
    }
    if (_unpin_chat_message_post_request->business_connection_id) {
        free(_unpin_chat_message_post_request->business_connection_id);
        _unpin_chat_message_post_request->business_connection_id = NULL;
    }
    free(_unpin_chat_message_post_request);
}

cJSON *_unpin_chat_message_post_request_convertToJSON(_unpin_chat_message_post_request_t *_unpin_chat_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _unpin_chat_message_post_request->chat_id
    if (!_unpin_chat_message_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_unpin_chat_message_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _unpin_chat_message_post_request->business_connection_id
    if(_unpin_chat_message_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _unpin_chat_message_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _unpin_chat_message_post_request->message_id
    if(_unpin_chat_message_post_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", _unpin_chat_message_post_request->message_id) == NULL) {
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

_unpin_chat_message_post_request_t *_unpin_chat_message_post_request_parseFromJSON(cJSON *_unpin_chat_message_post_requestJSON){

    _unpin_chat_message_post_request_t *_unpin_chat_message_post_request_local_var = NULL;

    // define the local variable for _unpin_chat_message_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _unpin_chat_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_unpin_chat_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _unpin_chat_message_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_unpin_chat_message_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _unpin_chat_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_unpin_chat_message_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }


    _unpin_chat_message_post_request_local_var = _unpin_chat_message_post_request_create_internal (
        chat_id_local_nonprim,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_id ? message_id->valuedouble : 0
        );

    return _unpin_chat_message_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
