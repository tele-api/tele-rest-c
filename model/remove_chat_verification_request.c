#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "remove_chat_verification_request.h"



static remove_chat_verification_request_t *remove_chat_verification_request_create_internal(
    send_message_request_chat_id_t *chat_id
    ) {
    remove_chat_verification_request_t *remove_chat_verification_request_local_var = malloc(sizeof(remove_chat_verification_request_t));
    if (!remove_chat_verification_request_local_var) {
        return NULL;
    }
    remove_chat_verification_request_local_var->chat_id = chat_id;

    remove_chat_verification_request_local_var->_library_owned = 1;
    return remove_chat_verification_request_local_var;
}

__attribute__((deprecated)) remove_chat_verification_request_t *remove_chat_verification_request_create(
    send_message_request_chat_id_t *chat_id
    ) {
    return remove_chat_verification_request_create_internal (
        chat_id
        );
}

void remove_chat_verification_request_free(remove_chat_verification_request_t *remove_chat_verification_request) {
    if(NULL == remove_chat_verification_request){
        return ;
    }
    if(remove_chat_verification_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "remove_chat_verification_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (remove_chat_verification_request->chat_id) {
        send_message_request_chat_id_free(remove_chat_verification_request->chat_id);
        remove_chat_verification_request->chat_id = NULL;
    }
    free(remove_chat_verification_request);
}

cJSON *remove_chat_verification_request_convertToJSON(remove_chat_verification_request_t *remove_chat_verification_request) {
    cJSON *item = cJSON_CreateObject();

    // remove_chat_verification_request->chat_id
    if (!remove_chat_verification_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(remove_chat_verification_request->chat_id);
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

remove_chat_verification_request_t *remove_chat_verification_request_parseFromJSON(cJSON *remove_chat_verification_requestJSON){

    remove_chat_verification_request_t *remove_chat_verification_request_local_var = NULL;

    // define the local variable for remove_chat_verification_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // remove_chat_verification_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(remove_chat_verification_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    remove_chat_verification_request_local_var = remove_chat_verification_request_create_internal (
        chat_id_local_nonprim
        );

    return remove_chat_verification_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
