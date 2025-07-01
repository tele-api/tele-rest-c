#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ban_chat_sender_chat_post_request.h"



static _ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    _ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_local_var = malloc(sizeof(_ban_chat_sender_chat_post_request_t));
    if (!_ban_chat_sender_chat_post_request_local_var) {
        return NULL;
    }
    _ban_chat_sender_chat_post_request_local_var->chat_id = chat_id;
    _ban_chat_sender_chat_post_request_local_var->sender_chat_id = sender_chat_id;

    _ban_chat_sender_chat_post_request_local_var->_library_owned = 1;
    return _ban_chat_sender_chat_post_request_local_var;
}

__attribute__((deprecated)) _ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    return _ban_chat_sender_chat_post_request_create_internal (
        chat_id,
        sender_chat_id
        );
}

void _ban_chat_sender_chat_post_request_free(_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request) {
    if(NULL == _ban_chat_sender_chat_post_request){
        return ;
    }
    if(_ban_chat_sender_chat_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_ban_chat_sender_chat_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_ban_chat_sender_chat_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_ban_chat_sender_chat_post_request->chat_id);
        _ban_chat_sender_chat_post_request->chat_id = NULL;
    }
    free(_ban_chat_sender_chat_post_request);
}

cJSON *_ban_chat_sender_chat_post_request_convertToJSON(_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _ban_chat_sender_chat_post_request->chat_id
    if (!_ban_chat_sender_chat_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_ban_chat_sender_chat_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _ban_chat_sender_chat_post_request->sender_chat_id
    if (!_ban_chat_sender_chat_post_request->sender_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sender_chat_id", _ban_chat_sender_chat_post_request->sender_chat_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_parseFromJSON(cJSON *_ban_chat_sender_chat_post_requestJSON){

    _ban_chat_sender_chat_post_request_t *_ban_chat_sender_chat_post_request_local_var = NULL;

    // define the local variable for _ban_chat_sender_chat_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _ban_chat_sender_chat_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_ban_chat_sender_chat_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _ban_chat_sender_chat_post_request->sender_chat_id
    cJSON *sender_chat_id = cJSON_GetObjectItemCaseSensitive(_ban_chat_sender_chat_post_requestJSON, "sender_chat_id");
    if (cJSON_IsNull(sender_chat_id)) {
        sender_chat_id = NULL;
    }
    if (!sender_chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(sender_chat_id))
    {
    goto end; //Numeric
    }


    _ban_chat_sender_chat_post_request_local_var = _ban_chat_sender_chat_post_request_create_internal (
        chat_id_local_nonprim,
        sender_chat_id->valuedouble
        );

    return _ban_chat_sender_chat_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
