#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "approve_chat_join_request_request.h"



static approve_chat_join_request_request_t *approve_chat_join_request_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int user_id
    ) {
    approve_chat_join_request_request_t *approve_chat_join_request_request_local_var = malloc(sizeof(approve_chat_join_request_request_t));
    if (!approve_chat_join_request_request_local_var) {
        return NULL;
    }
    approve_chat_join_request_request_local_var->chat_id = chat_id;
    approve_chat_join_request_request_local_var->user_id = user_id;

    approve_chat_join_request_request_local_var->_library_owned = 1;
    return approve_chat_join_request_request_local_var;
}

__attribute__((deprecated)) approve_chat_join_request_request_t *approve_chat_join_request_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id
    ) {
    return approve_chat_join_request_request_create_internal (
        chat_id,
        user_id
        );
}

void approve_chat_join_request_request_free(approve_chat_join_request_request_t *approve_chat_join_request_request) {
    if(NULL == approve_chat_join_request_request){
        return ;
    }
    if(approve_chat_join_request_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "approve_chat_join_request_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (approve_chat_join_request_request->chat_id) {
        send_message_request_chat_id_free(approve_chat_join_request_request->chat_id);
        approve_chat_join_request_request->chat_id = NULL;
    }
    free(approve_chat_join_request_request);
}

cJSON *approve_chat_join_request_request_convertToJSON(approve_chat_join_request_request_t *approve_chat_join_request_request) {
    cJSON *item = cJSON_CreateObject();

    // approve_chat_join_request_request->chat_id
    if (!approve_chat_join_request_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(approve_chat_join_request_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // approve_chat_join_request_request->user_id
    if (!approve_chat_join_request_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", approve_chat_join_request_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

approve_chat_join_request_request_t *approve_chat_join_request_request_parseFromJSON(cJSON *approve_chat_join_request_requestJSON){

    approve_chat_join_request_request_t *approve_chat_join_request_request_local_var = NULL;

    // define the local variable for approve_chat_join_request_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // approve_chat_join_request_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(approve_chat_join_request_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // approve_chat_join_request_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(approve_chat_join_request_requestJSON, "user_id");
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


    approve_chat_join_request_request_local_var = approve_chat_join_request_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble
        );

    return approve_chat_join_request_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
