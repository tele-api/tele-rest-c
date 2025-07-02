#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpin_all_chat_messages_request.h"



static unpin_all_chat_messages_request_t *unpin_all_chat_messages_request_create_internal(
    send_message_request_chat_id_t *chat_id
    ) {
    unpin_all_chat_messages_request_t *unpin_all_chat_messages_request_local_var = malloc(sizeof(unpin_all_chat_messages_request_t));
    if (!unpin_all_chat_messages_request_local_var) {
        return NULL;
    }
    unpin_all_chat_messages_request_local_var->chat_id = chat_id;

    unpin_all_chat_messages_request_local_var->_library_owned = 1;
    return unpin_all_chat_messages_request_local_var;
}

__attribute__((deprecated)) unpin_all_chat_messages_request_t *unpin_all_chat_messages_request_create(
    send_message_request_chat_id_t *chat_id
    ) {
    return unpin_all_chat_messages_request_create_internal (
        chat_id
        );
}

void unpin_all_chat_messages_request_free(unpin_all_chat_messages_request_t *unpin_all_chat_messages_request) {
    if(NULL == unpin_all_chat_messages_request){
        return ;
    }
    if(unpin_all_chat_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unpin_all_chat_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unpin_all_chat_messages_request->chat_id) {
        send_message_request_chat_id_free(unpin_all_chat_messages_request->chat_id);
        unpin_all_chat_messages_request->chat_id = NULL;
    }
    free(unpin_all_chat_messages_request);
}

cJSON *unpin_all_chat_messages_request_convertToJSON(unpin_all_chat_messages_request_t *unpin_all_chat_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // unpin_all_chat_messages_request->chat_id
    if (!unpin_all_chat_messages_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(unpin_all_chat_messages_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unpin_all_chat_messages_request_t *unpin_all_chat_messages_request_parseFromJSON(cJSON *unpin_all_chat_messages_requestJSON){

    unpin_all_chat_messages_request_t *unpin_all_chat_messages_request_local_var = NULL;

    // define the local variable for unpin_all_chat_messages_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // unpin_all_chat_messages_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unpin_all_chat_messages_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    unpin_all_chat_messages_request_local_var = unpin_all_chat_messages_request_create_internal (
        chat_id_local_nonprim
        );

    return unpin_all_chat_messages_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
