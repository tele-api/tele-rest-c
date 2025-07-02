#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "save_prepared_inline_message_request.h"



static save_prepared_inline_message_request_t *save_prepared_inline_message_request_create_internal(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    save_prepared_inline_message_request_t *save_prepared_inline_message_request_local_var = malloc(sizeof(save_prepared_inline_message_request_t));
    if (!save_prepared_inline_message_request_local_var) {
        return NULL;
    }
    save_prepared_inline_message_request_local_var->user_id = user_id;
    save_prepared_inline_message_request_local_var->result = result;
    save_prepared_inline_message_request_local_var->allow_user_chats = allow_user_chats;
    save_prepared_inline_message_request_local_var->allow_bot_chats = allow_bot_chats;
    save_prepared_inline_message_request_local_var->allow_group_chats = allow_group_chats;
    save_prepared_inline_message_request_local_var->allow_channel_chats = allow_channel_chats;

    save_prepared_inline_message_request_local_var->_library_owned = 1;
    return save_prepared_inline_message_request_local_var;
}

__attribute__((deprecated)) save_prepared_inline_message_request_t *save_prepared_inline_message_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    return save_prepared_inline_message_request_create_internal (
        user_id,
        result,
        allow_user_chats,
        allow_bot_chats,
        allow_group_chats,
        allow_channel_chats
        );
}

void save_prepared_inline_message_request_free(save_prepared_inline_message_request_t *save_prepared_inline_message_request) {
    if(NULL == save_prepared_inline_message_request){
        return ;
    }
    if(save_prepared_inline_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "save_prepared_inline_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (save_prepared_inline_message_request->result) {
        inline_query_result_free(save_prepared_inline_message_request->result);
        save_prepared_inline_message_request->result = NULL;
    }
    free(save_prepared_inline_message_request);
}

cJSON *save_prepared_inline_message_request_convertToJSON(save_prepared_inline_message_request_t *save_prepared_inline_message_request) {
    cJSON *item = cJSON_CreateObject();

    // save_prepared_inline_message_request->user_id
    if (!save_prepared_inline_message_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", save_prepared_inline_message_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // save_prepared_inline_message_request->result
    if (!save_prepared_inline_message_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(save_prepared_inline_message_request->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // save_prepared_inline_message_request->allow_user_chats
    if(save_prepared_inline_message_request->allow_user_chats) {
    if(cJSON_AddBoolToObject(item, "allow_user_chats", save_prepared_inline_message_request->allow_user_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // save_prepared_inline_message_request->allow_bot_chats
    if(save_prepared_inline_message_request->allow_bot_chats) {
    if(cJSON_AddBoolToObject(item, "allow_bot_chats", save_prepared_inline_message_request->allow_bot_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // save_prepared_inline_message_request->allow_group_chats
    if(save_prepared_inline_message_request->allow_group_chats) {
    if(cJSON_AddBoolToObject(item, "allow_group_chats", save_prepared_inline_message_request->allow_group_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // save_prepared_inline_message_request->allow_channel_chats
    if(save_prepared_inline_message_request->allow_channel_chats) {
    if(cJSON_AddBoolToObject(item, "allow_channel_chats", save_prepared_inline_message_request->allow_channel_chats) == NULL) {
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

save_prepared_inline_message_request_t *save_prepared_inline_message_request_parseFromJSON(cJSON *save_prepared_inline_message_requestJSON){

    save_prepared_inline_message_request_t *save_prepared_inline_message_request_local_var = NULL;

    // define the local variable for save_prepared_inline_message_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // save_prepared_inline_message_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "user_id");
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

    // save_prepared_inline_message_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive

    // save_prepared_inline_message_request->allow_user_chats
    cJSON *allow_user_chats = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "allow_user_chats");
    if (cJSON_IsNull(allow_user_chats)) {
        allow_user_chats = NULL;
    }
    if (allow_user_chats) { 
    if(!cJSON_IsBool(allow_user_chats))
    {
    goto end; //Bool
    }
    }

    // save_prepared_inline_message_request->allow_bot_chats
    cJSON *allow_bot_chats = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "allow_bot_chats");
    if (cJSON_IsNull(allow_bot_chats)) {
        allow_bot_chats = NULL;
    }
    if (allow_bot_chats) { 
    if(!cJSON_IsBool(allow_bot_chats))
    {
    goto end; //Bool
    }
    }

    // save_prepared_inline_message_request->allow_group_chats
    cJSON *allow_group_chats = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "allow_group_chats");
    if (cJSON_IsNull(allow_group_chats)) {
        allow_group_chats = NULL;
    }
    if (allow_group_chats) { 
    if(!cJSON_IsBool(allow_group_chats))
    {
    goto end; //Bool
    }
    }

    // save_prepared_inline_message_request->allow_channel_chats
    cJSON *allow_channel_chats = cJSON_GetObjectItemCaseSensitive(save_prepared_inline_message_requestJSON, "allow_channel_chats");
    if (cJSON_IsNull(allow_channel_chats)) {
        allow_channel_chats = NULL;
    }
    if (allow_channel_chats) { 
    if(!cJSON_IsBool(allow_channel_chats))
    {
    goto end; //Bool
    }
    }


    save_prepared_inline_message_request_local_var = save_prepared_inline_message_request_create_internal (
        user_id->valuedouble,
        result_local_nonprim,
        allow_user_chats ? allow_user_chats->valueint : 0,
        allow_bot_chats ? allow_bot_chats->valueint : 0,
        allow_group_chats ? allow_group_chats->valueint : 0,
        allow_channel_chats ? allow_channel_chats->valueint : 0
        );

    return save_prepared_inline_message_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
