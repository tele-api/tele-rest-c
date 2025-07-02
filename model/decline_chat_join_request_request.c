#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "decline_chat_join_request_request.h"



static decline_chat_join_request_request_t *decline_chat_join_request_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int user_id
    ) {
    decline_chat_join_request_request_t *decline_chat_join_request_request_local_var = malloc(sizeof(decline_chat_join_request_request_t));
    if (!decline_chat_join_request_request_local_var) {
        return NULL;
    }
    decline_chat_join_request_request_local_var->chat_id = chat_id;
    decline_chat_join_request_request_local_var->user_id = user_id;

    decline_chat_join_request_request_local_var->_library_owned = 1;
    return decline_chat_join_request_request_local_var;
}

__attribute__((deprecated)) decline_chat_join_request_request_t *decline_chat_join_request_request_create(
    send_message_request_chat_id_t *chat_id,
    int user_id
    ) {
    return decline_chat_join_request_request_create_internal (
        chat_id,
        user_id
        );
}

void decline_chat_join_request_request_free(decline_chat_join_request_request_t *decline_chat_join_request_request) {
    if(NULL == decline_chat_join_request_request){
        return ;
    }
    if(decline_chat_join_request_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "decline_chat_join_request_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (decline_chat_join_request_request->chat_id) {
        send_message_request_chat_id_free(decline_chat_join_request_request->chat_id);
        decline_chat_join_request_request->chat_id = NULL;
    }
    free(decline_chat_join_request_request);
}

cJSON *decline_chat_join_request_request_convertToJSON(decline_chat_join_request_request_t *decline_chat_join_request_request) {
    cJSON *item = cJSON_CreateObject();

    // decline_chat_join_request_request->chat_id
    if (!decline_chat_join_request_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(decline_chat_join_request_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // decline_chat_join_request_request->user_id
    if (!decline_chat_join_request_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", decline_chat_join_request_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

decline_chat_join_request_request_t *decline_chat_join_request_request_parseFromJSON(cJSON *decline_chat_join_request_requestJSON){

    decline_chat_join_request_request_t *decline_chat_join_request_request_local_var = NULL;

    // define the local variable for decline_chat_join_request_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // decline_chat_join_request_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(decline_chat_join_request_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // decline_chat_join_request_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(decline_chat_join_request_requestJSON, "user_id");
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


    decline_chat_join_request_request_local_var = decline_chat_join_request_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble
        );

    return decline_chat_join_request_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
