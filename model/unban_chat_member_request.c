#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unban_chat_member_request.h"



static unban_chat_member_request_t *unban_chat_member_request_create_internal(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    unban_chat_member_request_t *unban_chat_member_request_local_var = malloc(sizeof(unban_chat_member_request_t));
    if (!unban_chat_member_request_local_var) {
        return NULL;
    }
    unban_chat_member_request_local_var->chat_id = chat_id;
    unban_chat_member_request_local_var->user_id = user_id;
    unban_chat_member_request_local_var->only_if_banned = only_if_banned;

    unban_chat_member_request_local_var->_library_owned = 1;
    return unban_chat_member_request_local_var;
}

__attribute__((deprecated)) unban_chat_member_request_t *unban_chat_member_request_create(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int only_if_banned
    ) {
    return unban_chat_member_request_create_internal (
        chat_id,
        user_id,
        only_if_banned
        );
}

void unban_chat_member_request_free(unban_chat_member_request_t *unban_chat_member_request) {
    if(NULL == unban_chat_member_request){
        return ;
    }
    if(unban_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unban_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unban_chat_member_request->chat_id) {
        ban_chat_member_request_chat_id_free(unban_chat_member_request->chat_id);
        unban_chat_member_request->chat_id = NULL;
    }
    free(unban_chat_member_request);
}

cJSON *unban_chat_member_request_convertToJSON(unban_chat_member_request_t *unban_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // unban_chat_member_request->chat_id
    if (!unban_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = ban_chat_member_request_chat_id_convertToJSON(unban_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unban_chat_member_request->user_id
    if (!unban_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", unban_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // unban_chat_member_request->only_if_banned
    if(unban_chat_member_request->only_if_banned) {
    if(cJSON_AddBoolToObject(item, "only_if_banned", unban_chat_member_request->only_if_banned) == NULL) {
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

unban_chat_member_request_t *unban_chat_member_request_parseFromJSON(cJSON *unban_chat_member_requestJSON){

    unban_chat_member_request_t *unban_chat_member_request_local_var = NULL;

    // define the local variable for unban_chat_member_request->chat_id
    ban_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // unban_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unban_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = ban_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // unban_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(unban_chat_member_requestJSON, "user_id");
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

    // unban_chat_member_request->only_if_banned
    cJSON *only_if_banned = cJSON_GetObjectItemCaseSensitive(unban_chat_member_requestJSON, "only_if_banned");
    if (cJSON_IsNull(only_if_banned)) {
        only_if_banned = NULL;
    }
    if (only_if_banned) { 
    if(!cJSON_IsBool(only_if_banned))
    {
    goto end; //Bool
    }
    }


    unban_chat_member_request_local_var = unban_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        only_if_banned ? only_if_banned->valueint : 0
        );

    return unban_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        ban_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
