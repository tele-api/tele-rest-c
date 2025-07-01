#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_save_prepared_inline_message_post_request.h"



static _save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_create_internal(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    _save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_local_var = malloc(sizeof(_save_prepared_inline_message_post_request_t));
    if (!_save_prepared_inline_message_post_request_local_var) {
        return NULL;
    }
    _save_prepared_inline_message_post_request_local_var->user_id = user_id;
    _save_prepared_inline_message_post_request_local_var->result = result;
    _save_prepared_inline_message_post_request_local_var->allow_user_chats = allow_user_chats;
    _save_prepared_inline_message_post_request_local_var->allow_bot_chats = allow_bot_chats;
    _save_prepared_inline_message_post_request_local_var->allow_group_chats = allow_group_chats;
    _save_prepared_inline_message_post_request_local_var->allow_channel_chats = allow_channel_chats;

    _save_prepared_inline_message_post_request_local_var->_library_owned = 1;
    return _save_prepared_inline_message_post_request_local_var;
}

__attribute__((deprecated)) _save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    return _save_prepared_inline_message_post_request_create_internal (
        user_id,
        result,
        allow_user_chats,
        allow_bot_chats,
        allow_group_chats,
        allow_channel_chats
        );
}

void _save_prepared_inline_message_post_request_free(_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request) {
    if(NULL == _save_prepared_inline_message_post_request){
        return ;
    }
    if(_save_prepared_inline_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_save_prepared_inline_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_save_prepared_inline_message_post_request->result) {
        inline_query_result_free(_save_prepared_inline_message_post_request->result);
        _save_prepared_inline_message_post_request->result = NULL;
    }
    free(_save_prepared_inline_message_post_request);
}

cJSON *_save_prepared_inline_message_post_request_convertToJSON(_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _save_prepared_inline_message_post_request->user_id
    if (!_save_prepared_inline_message_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _save_prepared_inline_message_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _save_prepared_inline_message_post_request->result
    if (!_save_prepared_inline_message_post_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(_save_prepared_inline_message_post_request->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _save_prepared_inline_message_post_request->allow_user_chats
    if(_save_prepared_inline_message_post_request->allow_user_chats) {
    if(cJSON_AddBoolToObject(item, "allow_user_chats", _save_prepared_inline_message_post_request->allow_user_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // _save_prepared_inline_message_post_request->allow_bot_chats
    if(_save_prepared_inline_message_post_request->allow_bot_chats) {
    if(cJSON_AddBoolToObject(item, "allow_bot_chats", _save_prepared_inline_message_post_request->allow_bot_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // _save_prepared_inline_message_post_request->allow_group_chats
    if(_save_prepared_inline_message_post_request->allow_group_chats) {
    if(cJSON_AddBoolToObject(item, "allow_group_chats", _save_prepared_inline_message_post_request->allow_group_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // _save_prepared_inline_message_post_request->allow_channel_chats
    if(_save_prepared_inline_message_post_request->allow_channel_chats) {
    if(cJSON_AddBoolToObject(item, "allow_channel_chats", _save_prepared_inline_message_post_request->allow_channel_chats) == NULL) {
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

_save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_parseFromJSON(cJSON *_save_prepared_inline_message_post_requestJSON){

    _save_prepared_inline_message_post_request_t *_save_prepared_inline_message_post_request_local_var = NULL;

    // define the local variable for _save_prepared_inline_message_post_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // _save_prepared_inline_message_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "user_id");
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

    // _save_prepared_inline_message_post_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive

    // _save_prepared_inline_message_post_request->allow_user_chats
    cJSON *allow_user_chats = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "allow_user_chats");
    if (cJSON_IsNull(allow_user_chats)) {
        allow_user_chats = NULL;
    }
    if (allow_user_chats) { 
    if(!cJSON_IsBool(allow_user_chats))
    {
    goto end; //Bool
    }
    }

    // _save_prepared_inline_message_post_request->allow_bot_chats
    cJSON *allow_bot_chats = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "allow_bot_chats");
    if (cJSON_IsNull(allow_bot_chats)) {
        allow_bot_chats = NULL;
    }
    if (allow_bot_chats) { 
    if(!cJSON_IsBool(allow_bot_chats))
    {
    goto end; //Bool
    }
    }

    // _save_prepared_inline_message_post_request->allow_group_chats
    cJSON *allow_group_chats = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "allow_group_chats");
    if (cJSON_IsNull(allow_group_chats)) {
        allow_group_chats = NULL;
    }
    if (allow_group_chats) { 
    if(!cJSON_IsBool(allow_group_chats))
    {
    goto end; //Bool
    }
    }

    // _save_prepared_inline_message_post_request->allow_channel_chats
    cJSON *allow_channel_chats = cJSON_GetObjectItemCaseSensitive(_save_prepared_inline_message_post_requestJSON, "allow_channel_chats");
    if (cJSON_IsNull(allow_channel_chats)) {
        allow_channel_chats = NULL;
    }
    if (allow_channel_chats) { 
    if(!cJSON_IsBool(allow_channel_chats))
    {
    goto end; //Bool
    }
    }


    _save_prepared_inline_message_post_request_local_var = _save_prepared_inline_message_post_request_create_internal (
        user_id->valuedouble,
        result_local_nonprim,
        allow_user_chats ? allow_user_chats->valueint : 0,
        allow_bot_chats ? allow_bot_chats->valueint : 0,
        allow_group_chats ? allow_group_chats->valueint : 0,
        allow_channel_chats ? allow_channel_chats->valueint : 0
        );

    return _save_prepared_inline_message_post_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
