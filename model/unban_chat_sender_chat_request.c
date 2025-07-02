#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unban_chat_sender_chat_request.h"



static unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_local_var = malloc(sizeof(unban_chat_sender_chat_request_t));
    if (!unban_chat_sender_chat_request_local_var) {
        return NULL;
    }
    unban_chat_sender_chat_request_local_var->chat_id = chat_id;
    unban_chat_sender_chat_request_local_var->sender_chat_id = sender_chat_id;

    unban_chat_sender_chat_request_local_var->_library_owned = 1;
    return unban_chat_sender_chat_request_local_var;
}

__attribute__((deprecated)) unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_create(
    send_message_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    return unban_chat_sender_chat_request_create_internal (
        chat_id,
        sender_chat_id
        );
}

void unban_chat_sender_chat_request_free(unban_chat_sender_chat_request_t *unban_chat_sender_chat_request) {
    if(NULL == unban_chat_sender_chat_request){
        return ;
    }
    if(unban_chat_sender_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unban_chat_sender_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unban_chat_sender_chat_request->chat_id) {
        send_message_request_chat_id_free(unban_chat_sender_chat_request->chat_id);
        unban_chat_sender_chat_request->chat_id = NULL;
    }
    free(unban_chat_sender_chat_request);
}

cJSON *unban_chat_sender_chat_request_convertToJSON(unban_chat_sender_chat_request_t *unban_chat_sender_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // unban_chat_sender_chat_request->chat_id
    if (!unban_chat_sender_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(unban_chat_sender_chat_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unban_chat_sender_chat_request->sender_chat_id
    if (!unban_chat_sender_chat_request->sender_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sender_chat_id", unban_chat_sender_chat_request->sender_chat_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_parseFromJSON(cJSON *unban_chat_sender_chat_requestJSON){

    unban_chat_sender_chat_request_t *unban_chat_sender_chat_request_local_var = NULL;

    // define the local variable for unban_chat_sender_chat_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // unban_chat_sender_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unban_chat_sender_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // unban_chat_sender_chat_request->sender_chat_id
    cJSON *sender_chat_id = cJSON_GetObjectItemCaseSensitive(unban_chat_sender_chat_requestJSON, "sender_chat_id");
    if (cJSON_IsNull(sender_chat_id)) {
        sender_chat_id = NULL;
    }
    if (!sender_chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(sender_chat_id))
    {
    goto end; //Numeric
    }


    unban_chat_sender_chat_request_local_var = unban_chat_sender_chat_request_create_internal (
        chat_id_local_nonprim,
        sender_chat_id->valuedouble
        );

    return unban_chat_sender_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
