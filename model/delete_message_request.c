#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_message_request.h"



static delete_message_request_t *delete_message_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int message_id
    ) {
    delete_message_request_t *delete_message_request_local_var = malloc(sizeof(delete_message_request_t));
    if (!delete_message_request_local_var) {
        return NULL;
    }
    delete_message_request_local_var->chat_id = chat_id;
    delete_message_request_local_var->message_id = message_id;

    delete_message_request_local_var->_library_owned = 1;
    return delete_message_request_local_var;
}

__attribute__((deprecated)) delete_message_request_t *delete_message_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id
    ) {
    return delete_message_request_create_internal (
        chat_id,
        message_id
        );
}

void delete_message_request_free(delete_message_request_t *delete_message_request) {
    if(NULL == delete_message_request){
        return ;
    }
    if(delete_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_message_request->chat_id) {
        send_message_request_chat_id_free(delete_message_request->chat_id);
        delete_message_request->chat_id = NULL;
    }
    free(delete_message_request);
}

cJSON *delete_message_request_convertToJSON(delete_message_request_t *delete_message_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_message_request->chat_id
    if (!delete_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(delete_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // delete_message_request->message_id
    if (!delete_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", delete_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_message_request_t *delete_message_request_parseFromJSON(cJSON *delete_message_requestJSON){

    delete_message_request_t *delete_message_request_local_var = NULL;

    // define the local variable for delete_message_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // delete_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(delete_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // delete_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(delete_message_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }


    delete_message_request_local_var = delete_message_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble
        );

    return delete_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
