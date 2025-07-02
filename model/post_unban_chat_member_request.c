#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_unban_chat_member_request.h"



static post_unban_chat_member_request_t *post_unban_chat_member_request_create_internal(
    post_ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    post_unban_chat_member_request_t *post_unban_chat_member_request_local_var = malloc(sizeof(post_unban_chat_member_request_t));
    if (!post_unban_chat_member_request_local_var) {
        return NULL;
    }
    post_unban_chat_member_request_local_var->chat_id = chat_id;
    post_unban_chat_member_request_local_var->user_id = user_id;
    post_unban_chat_member_request_local_var->only_if_banned = only_if_banned;

    post_unban_chat_member_request_local_var->_library_owned = 1;
    return post_unban_chat_member_request_local_var;
}

__attribute__((deprecated)) post_unban_chat_member_request_t *post_unban_chat_member_request_create(
    post_ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    return post_unban_chat_member_request_create_internal (
        chat_id,
        user_id,
        only_if_banned
        );
}

void post_unban_chat_member_request_free(post_unban_chat_member_request_t *post_unban_chat_member_request) {
    if(NULL == post_unban_chat_member_request){
        return ;
    }
    if(post_unban_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_unban_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_unban_chat_member_request->chat_id) {
        post_ban_chat_member_request_chat_id_free(post_unban_chat_member_request->chat_id);
        post_unban_chat_member_request->chat_id = NULL;
    }
    free(post_unban_chat_member_request);
}

cJSON *post_unban_chat_member_request_convertToJSON(post_unban_chat_member_request_t *post_unban_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // post_unban_chat_member_request->chat_id
    if (!post_unban_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_ban_chat_member_request_chat_id_convertToJSON(post_unban_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_unban_chat_member_request->user_id
    if (!post_unban_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_unban_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_unban_chat_member_request->only_if_banned
    if(post_unban_chat_member_request->only_if_banned) {
    if(cJSON_AddBoolToObject(item, "only_if_banned", post_unban_chat_member_request->only_if_banned) == NULL) {
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

post_unban_chat_member_request_t *post_unban_chat_member_request_parseFromJSON(cJSON *post_unban_chat_member_requestJSON){

    post_unban_chat_member_request_t *post_unban_chat_member_request_local_var = NULL;

    // define the local variable for post_unban_chat_member_request->chat_id
    post_ban_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_unban_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_unban_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_ban_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_unban_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_unban_chat_member_requestJSON, "user_id");
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

    // post_unban_chat_member_request->only_if_banned
    cJSON *only_if_banned = cJSON_GetObjectItemCaseSensitive(post_unban_chat_member_requestJSON, "only_if_banned");
    if (cJSON_IsNull(only_if_banned)) {
        only_if_banned = NULL;
    }
    if (only_if_banned) { 
    if(!cJSON_IsBool(only_if_banned))
    {
    goto end; //Bool
    }
    }


    post_unban_chat_member_request_local_var = post_unban_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        only_if_banned ? only_if_banned->valueint : 0
        );

    return post_unban_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_ban_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
