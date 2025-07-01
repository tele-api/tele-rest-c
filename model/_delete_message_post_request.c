#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_message_post_request.h"



static _delete_message_post_request_t *_delete_message_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id
    ) {
    _delete_message_post_request_t *_delete_message_post_request_local_var = malloc(sizeof(_delete_message_post_request_t));
    if (!_delete_message_post_request_local_var) {
        return NULL;
    }
    _delete_message_post_request_local_var->chat_id = chat_id;
    _delete_message_post_request_local_var->message_id = message_id;

    _delete_message_post_request_local_var->_library_owned = 1;
    return _delete_message_post_request_local_var;
}

__attribute__((deprecated)) _delete_message_post_request_t *_delete_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id
    ) {
    return _delete_message_post_request_create_internal (
        chat_id,
        message_id
        );
}

void _delete_message_post_request_free(_delete_message_post_request_t *_delete_message_post_request) {
    if(NULL == _delete_message_post_request){
        return ;
    }
    if(_delete_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_message_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_delete_message_post_request->chat_id);
        _delete_message_post_request->chat_id = NULL;
    }
    free(_delete_message_post_request);
}

cJSON *_delete_message_post_request_convertToJSON(_delete_message_post_request_t *_delete_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_message_post_request->chat_id
    if (!_delete_message_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_delete_message_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _delete_message_post_request->message_id
    if (!_delete_message_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _delete_message_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_delete_message_post_request_t *_delete_message_post_request_parseFromJSON(cJSON *_delete_message_post_requestJSON){

    _delete_message_post_request_t *_delete_message_post_request_local_var = NULL;

    // define the local variable for _delete_message_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _delete_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_delete_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _delete_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_delete_message_post_requestJSON, "message_id");
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


    _delete_message_post_request_local_var = _delete_message_post_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble
        );

    return _delete_message_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
