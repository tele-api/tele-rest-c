#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ban_chat_member_request.h"



static ban_chat_member_request_t *ban_chat_member_request_create_internal(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
    ) {
    ban_chat_member_request_t *ban_chat_member_request_local_var = malloc(sizeof(ban_chat_member_request_t));
    if (!ban_chat_member_request_local_var) {
        return NULL;
    }
    ban_chat_member_request_local_var->chat_id = chat_id;
    ban_chat_member_request_local_var->user_id = user_id;
    ban_chat_member_request_local_var->until_date = until_date;
    ban_chat_member_request_local_var->revoke_messages = revoke_messages;

    ban_chat_member_request_local_var->_library_owned = 1;
    return ban_chat_member_request_local_var;
}

__attribute__((deprecated)) ban_chat_member_request_t *ban_chat_member_request_create(
    ban_chat_member_request_chat_id_t *chat_id,
    int user_id,
    int until_date,
    int revoke_messages
    ) {
    return ban_chat_member_request_create_internal (
        chat_id,
        user_id,
        until_date,
        revoke_messages
        );
}

void ban_chat_member_request_free(ban_chat_member_request_t *ban_chat_member_request) {
    if(NULL == ban_chat_member_request){
        return ;
    }
    if(ban_chat_member_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ban_chat_member_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ban_chat_member_request->chat_id) {
        ban_chat_member_request_chat_id_free(ban_chat_member_request->chat_id);
        ban_chat_member_request->chat_id = NULL;
    }
    free(ban_chat_member_request);
}

cJSON *ban_chat_member_request_convertToJSON(ban_chat_member_request_t *ban_chat_member_request) {
    cJSON *item = cJSON_CreateObject();

    // ban_chat_member_request->chat_id
    if (!ban_chat_member_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = ban_chat_member_request_chat_id_convertToJSON(ban_chat_member_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ban_chat_member_request->user_id
    if (!ban_chat_member_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", ban_chat_member_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // ban_chat_member_request->until_date
    if(ban_chat_member_request->until_date) {
    if(cJSON_AddNumberToObject(item, "until_date", ban_chat_member_request->until_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // ban_chat_member_request->revoke_messages
    if(ban_chat_member_request->revoke_messages) {
    if(cJSON_AddBoolToObject(item, "revoke_messages", ban_chat_member_request->revoke_messages) == NULL) {
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

ban_chat_member_request_t *ban_chat_member_request_parseFromJSON(cJSON *ban_chat_member_requestJSON){

    ban_chat_member_request_t *ban_chat_member_request_local_var = NULL;

    // define the local variable for ban_chat_member_request->chat_id
    ban_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // ban_chat_member_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(ban_chat_member_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = ban_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // ban_chat_member_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(ban_chat_member_requestJSON, "user_id");
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

    // ban_chat_member_request->until_date
    cJSON *until_date = cJSON_GetObjectItemCaseSensitive(ban_chat_member_requestJSON, "until_date");
    if (cJSON_IsNull(until_date)) {
        until_date = NULL;
    }
    if (until_date) { 
    if(!cJSON_IsNumber(until_date))
    {
    goto end; //Numeric
    }
    }

    // ban_chat_member_request->revoke_messages
    cJSON *revoke_messages = cJSON_GetObjectItemCaseSensitive(ban_chat_member_requestJSON, "revoke_messages");
    if (cJSON_IsNull(revoke_messages)) {
        revoke_messages = NULL;
    }
    if (revoke_messages) { 
    if(!cJSON_IsBool(revoke_messages))
    {
    goto end; //Bool
    }
    }


    ban_chat_member_request_local_var = ban_chat_member_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        until_date ? until_date->valuedouble : 0,
        revoke_messages ? revoke_messages->valueint : 0
        );

    return ban_chat_member_request_local_var;
end:
    if (chat_id_local_nonprim) {
        ban_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
