#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ban_chat_member_post_request.h"



static _ban_chat_member_post_request_t *_ban_chat_member_post_request_create_internal(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
    ) {
    _ban_chat_member_post_request_t *_ban_chat_member_post_request_local_var = malloc(sizeof(_ban_chat_member_post_request_t));
    if (!_ban_chat_member_post_request_local_var) {
        return NULL;
    }
    _ban_chat_member_post_request_local_var->chat_id = chat_id;
    _ban_chat_member_post_request_local_var->user_id = user_id;
    _ban_chat_member_post_request_local_var->until_date = until_date;
    _ban_chat_member_post_request_local_var->revoke_messages = revoke_messages;

    _ban_chat_member_post_request_local_var->_library_owned = 1;
    return _ban_chat_member_post_request_local_var;
}

__attribute__((deprecated)) _ban_chat_member_post_request_t *_ban_chat_member_post_request_create(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
    ) {
    return _ban_chat_member_post_request_create_internal (
        chat_id,
        user_id,
        until_date,
        revoke_messages
        );
}

void _ban_chat_member_post_request_free(_ban_chat_member_post_request_t *_ban_chat_member_post_request) {
    if(NULL == _ban_chat_member_post_request){
        return ;
    }
    if(_ban_chat_member_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_ban_chat_member_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_ban_chat_member_post_request->chat_id) {
        _ban_chat_member_post_request_chat_id_free(_ban_chat_member_post_request->chat_id);
        _ban_chat_member_post_request->chat_id = NULL;
    }
    free(_ban_chat_member_post_request);
}

cJSON *_ban_chat_member_post_request_convertToJSON(_ban_chat_member_post_request_t *_ban_chat_member_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _ban_chat_member_post_request->chat_id
    if (!_ban_chat_member_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _ban_chat_member_post_request_chat_id_convertToJSON(_ban_chat_member_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _ban_chat_member_post_request->user_id
    if (!_ban_chat_member_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _ban_chat_member_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _ban_chat_member_post_request->until_date
    if(_ban_chat_member_post_request->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", _ban_chat_member_post_request->until_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // _ban_chat_member_post_request->revoke_messages
    if(_ban_chat_member_post_request->revoke_messages) {
    if(cJSON_AddBoolToObject(item, "revoke_messages", _ban_chat_member_post_request->revoke_messages) == NULL) {
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

_ban_chat_member_post_request_t *_ban_chat_member_post_request_parseFromJSON(cJSON *_ban_chat_member_post_requestJSON){

    _ban_chat_member_post_request_t *_ban_chat_member_post_request_local_var = NULL;

    // define the local variable for _ban_chat_member_post_request->chat_id
    _ban_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _ban_chat_member_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_ban_chat_member_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _ban_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _ban_chat_member_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_ban_chat_member_post_requestJSON, "user_id");
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

    // _ban_chat_member_post_request->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(_ban_chat_member_post_requestJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }

    // _ban_chat_member_post_request->revoke_messages
    cJSON *revoke_messages = cJSON_GetObjectItemCaseSensitive(_ban_chat_member_post_requestJSON, "revoke_messages");
    if (cJSON_IsNull(revoke_messages)) {
        revoke_messages = NULL;
    }
    if (revoke_messages) { 
    if(!cJSON_IsBool(revoke_messages))
    {
    goto end; //Bool
    }
    }


    _ban_chat_member_post_request_local_var = _ban_chat_member_post_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        until_date ? until_date->valuedouble : 0,
        revoke_messages ? revoke_messages->valueint : 0
        );

    return _ban_chat_member_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _ban_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
