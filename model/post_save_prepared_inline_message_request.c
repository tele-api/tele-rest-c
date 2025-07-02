#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_save_prepared_inline_message_request.h"



static post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_create_internal(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_local_var = malloc(sizeof(post_save_prepared_inline_message_request_t));
    if (!post_save_prepared_inline_message_request_local_var) {
        return NULL;
    }
    post_save_prepared_inline_message_request_local_var->user_id = user_id;
    post_save_prepared_inline_message_request_local_var->result = result;
    post_save_prepared_inline_message_request_local_var->allow_user_chats = allow_user_chats;
    post_save_prepared_inline_message_request_local_var->allow_bot_chats = allow_bot_chats;
    post_save_prepared_inline_message_request_local_var->allow_group_chats = allow_group_chats;
    post_save_prepared_inline_message_request_local_var->allow_channel_chats = allow_channel_chats;

    post_save_prepared_inline_message_request_local_var->_library_owned = 1;
    return post_save_prepared_inline_message_request_local_var;
}

__attribute__((deprecated)) post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_create(
    int user_id,
    inline_query_result_t *result,
    int allow_user_chats,
    int allow_bot_chats,
    int allow_group_chats,
    int allow_channel_chats
    ) {
    return post_save_prepared_inline_message_request_create_internal (
        user_id,
        result,
        allow_user_chats,
        allow_bot_chats,
        allow_group_chats,
        allow_channel_chats
        );
}

void post_save_prepared_inline_message_request_free(post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request) {
    if(NULL == post_save_prepared_inline_message_request){
        return ;
    }
    if(post_save_prepared_inline_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_save_prepared_inline_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_save_prepared_inline_message_request->result) {
        inline_query_result_free(post_save_prepared_inline_message_request->result);
        post_save_prepared_inline_message_request->result = NULL;
    }
    free(post_save_prepared_inline_message_request);
}

cJSON *post_save_prepared_inline_message_request_convertToJSON(post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request) {
    cJSON *item = cJSON_CreateObject();

    // post_save_prepared_inline_message_request->user_id
    if (!post_save_prepared_inline_message_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_save_prepared_inline_message_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_save_prepared_inline_message_request->result
    if (!post_save_prepared_inline_message_request->result) {
        goto fail;
    }
    cJSON *result_local_JSON = inline_query_result_convertToJSON(post_save_prepared_inline_message_request->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_save_prepared_inline_message_request->allow_user_chats
    if(post_save_prepared_inline_message_request->allow_user_chats) {
    if(cJSON_AddBoolToObject(item, "allow_user_chats", post_save_prepared_inline_message_request->allow_user_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // post_save_prepared_inline_message_request->allow_bot_chats
    if(post_save_prepared_inline_message_request->allow_bot_chats) {
    if(cJSON_AddBoolToObject(item, "allow_bot_chats", post_save_prepared_inline_message_request->allow_bot_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // post_save_prepared_inline_message_request->allow_group_chats
    if(post_save_prepared_inline_message_request->allow_group_chats) {
    if(cJSON_AddBoolToObject(item, "allow_group_chats", post_save_prepared_inline_message_request->allow_group_chats) == NULL) {
    goto fail; //Bool
    }
    }


    // post_save_prepared_inline_message_request->allow_channel_chats
    if(post_save_prepared_inline_message_request->allow_channel_chats) {
    if(cJSON_AddBoolToObject(item, "allow_channel_chats", post_save_prepared_inline_message_request->allow_channel_chats) == NULL) {
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

post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_parseFromJSON(cJSON *post_save_prepared_inline_message_requestJSON){

    post_save_prepared_inline_message_request_t *post_save_prepared_inline_message_request_local_var = NULL;

    // define the local variable for post_save_prepared_inline_message_request->result
    inline_query_result_t *result_local_nonprim = NULL;

    // post_save_prepared_inline_message_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "user_id");
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

    // post_save_prepared_inline_message_request->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = inline_query_result_parseFromJSON(result); //nonprimitive

    // post_save_prepared_inline_message_request->allow_user_chats
    cJSON *allow_user_chats = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "allow_user_chats");
    if (cJSON_IsNull(allow_user_chats)) {
        allow_user_chats = NULL;
    }
    if (allow_user_chats) { 
    if(!cJSON_IsBool(allow_user_chats))
    {
    goto end; //Bool
    }
    }

    // post_save_prepared_inline_message_request->allow_bot_chats
    cJSON *allow_bot_chats = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "allow_bot_chats");
    if (cJSON_IsNull(allow_bot_chats)) {
        allow_bot_chats = NULL;
    }
    if (allow_bot_chats) { 
    if(!cJSON_IsBool(allow_bot_chats))
    {
    goto end; //Bool
    }
    }

    // post_save_prepared_inline_message_request->allow_group_chats
    cJSON *allow_group_chats = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "allow_group_chats");
    if (cJSON_IsNull(allow_group_chats)) {
        allow_group_chats = NULL;
    }
    if (allow_group_chats) { 
    if(!cJSON_IsBool(allow_group_chats))
    {
    goto end; //Bool
    }
    }

    // post_save_prepared_inline_message_request->allow_channel_chats
    cJSON *allow_channel_chats = cJSON_GetObjectItemCaseSensitive(post_save_prepared_inline_message_requestJSON, "allow_channel_chats");
    if (cJSON_IsNull(allow_channel_chats)) {
        allow_channel_chats = NULL;
    }
    if (allow_channel_chats) { 
    if(!cJSON_IsBool(allow_channel_chats))
    {
    goto end; //Bool
    }
    }


    post_save_prepared_inline_message_request_local_var = post_save_prepared_inline_message_request_create_internal (
        user_id->valuedouble,
        result_local_nonprim,
        allow_user_chats ? allow_user_chats->valueint : 0,
        allow_bot_chats ? allow_bot_chats->valueint : 0,
        allow_group_chats ? allow_group_chats->valueint : 0,
        allow_channel_chats ? allow_channel_chats->valueint : 0
        );

    return post_save_prepared_inline_message_request_local_var;
end:
    if (result_local_nonprim) {
        inline_query_result_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
