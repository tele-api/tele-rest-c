#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_approve_chat_join_request_post_request.h"



static _approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    int user_id
    ) {
    _approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_local_var = malloc(sizeof(_approve_chat_join_request_post_request_t));
    if (!_approve_chat_join_request_post_request_local_var) {
        return NULL;
    }
    _approve_chat_join_request_post_request_local_var->chat_id = chat_id;
    _approve_chat_join_request_post_request_local_var->user_id = user_id;

    _approve_chat_join_request_post_request_local_var->_library_owned = 1;
    return _approve_chat_join_request_post_request_local_var;
}

__attribute__((deprecated)) _approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int user_id
    ) {
    return _approve_chat_join_request_post_request_create_internal (
        chat_id,
        user_id
        );
}

void _approve_chat_join_request_post_request_free(_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request) {
    if(NULL == _approve_chat_join_request_post_request){
        return ;
    }
    if(_approve_chat_join_request_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_approve_chat_join_request_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_approve_chat_join_request_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_approve_chat_join_request_post_request->chat_id);
        _approve_chat_join_request_post_request->chat_id = NULL;
    }
    free(_approve_chat_join_request_post_request);
}

cJSON *_approve_chat_join_request_post_request_convertToJSON(_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _approve_chat_join_request_post_request->chat_id
    if (!_approve_chat_join_request_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_approve_chat_join_request_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _approve_chat_join_request_post_request->user_id
    if (!_approve_chat_join_request_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _approve_chat_join_request_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_parseFromJSON(cJSON *_approve_chat_join_request_post_requestJSON){

    _approve_chat_join_request_post_request_t *_approve_chat_join_request_post_request_local_var = NULL;

    // define the local variable for _approve_chat_join_request_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _approve_chat_join_request_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_approve_chat_join_request_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _approve_chat_join_request_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_approve_chat_join_request_post_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }


    _approve_chat_join_request_post_request_local_var = _approve_chat_join_request_post_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble
        );

    return _approve_chat_join_request_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
