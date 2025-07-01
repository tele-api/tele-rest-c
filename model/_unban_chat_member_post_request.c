#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_unban_chat_member_post_request.h"



static _unban_chat_member_post_request_t *_unban_chat_member_post_request_create_internal(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    _unban_chat_member_post_request_t *_unban_chat_member_post_request_local_var = malloc(sizeof(_unban_chat_member_post_request_t));
    if (!_unban_chat_member_post_request_local_var) {
        return NULL;
    }
    _unban_chat_member_post_request_local_var->chat_id = chat_id;
    _unban_chat_member_post_request_local_var->user_id = user_id;
    _unban_chat_member_post_request_local_var->only_if_banned = only_if_banned;

    _unban_chat_member_post_request_local_var->_library_owned = 1;
    return _unban_chat_member_post_request_local_var;
}

__attribute__((deprecated)) _unban_chat_member_post_request_t *_unban_chat_member_post_request_create(
    _ban_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    return _unban_chat_member_post_request_create_internal (
        chat_id,
        user_id,
        only_if_banned
        );
}

void _unban_chat_member_post_request_free(_unban_chat_member_post_request_t *_unban_chat_member_post_request) {
    if(NULL == _unban_chat_member_post_request){
        return ;
    }
    if(_unban_chat_member_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_unban_chat_member_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_unban_chat_member_post_request->chat_id) {
        _ban_chat_member_post_request_chat_id_free(_unban_chat_member_post_request->chat_id);
        _unban_chat_member_post_request->chat_id = NULL;
    }
    free(_unban_chat_member_post_request);
}

cJSON *_unban_chat_member_post_request_convertToJSON(_unban_chat_member_post_request_t *_unban_chat_member_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _unban_chat_member_post_request->chat_id
    if (!_unban_chat_member_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _ban_chat_member_post_request_chat_id_convertToJSON(_unban_chat_member_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _unban_chat_member_post_request->user_id
    if (!_unban_chat_member_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _unban_chat_member_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _unban_chat_member_post_request->only_if_banned
    if(_unban_chat_member_post_request->only_if_banned) {
    if(cJSON_AddBoolToObject(item, "only_if_banned", _unban_chat_member_post_request->only_if_banned) == NULL) {
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

_unban_chat_member_post_request_t *_unban_chat_member_post_request_parseFromJSON(cJSON *_unban_chat_member_post_requestJSON){

    _unban_chat_member_post_request_t *_unban_chat_member_post_request_local_var = NULL;

    // define the local variable for _unban_chat_member_post_request->chat_id
    _ban_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _unban_chat_member_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_unban_chat_member_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _ban_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _unban_chat_member_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_unban_chat_member_post_requestJSON, "user_id");
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

    // _unban_chat_member_post_request->only_if_banned
    cJSON *only_if_banned = cJSON_GetObjectItemCaseSensitive(_unban_chat_member_post_requestJSON, "only_if_banned");
    if (cJSON_IsNull(only_if_banned)) {
        only_if_banned = NULL;
    }
    if (only_if_banned) { 
    if(!cJSON_IsBool(only_if_banned))
    {
    goto end; //Bool
    }
    }


    _unban_chat_member_post_request_local_var = _unban_chat_member_post_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        only_if_banned ? only_if_banned->valueint : 0
        );

    return _unban_chat_member_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _ban_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
