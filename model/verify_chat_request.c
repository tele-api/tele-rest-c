#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "verify_chat_request.h"



static verify_chat_request_t *verify_chat_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    verify_chat_request_t *verify_chat_request_local_var = malloc(sizeof(verify_chat_request_t));
    if (!verify_chat_request_local_var) {
        return NULL;
    }
    verify_chat_request_local_var->chat_id = chat_id;
    verify_chat_request_local_var->custom_description = custom_description;

    verify_chat_request_local_var->_library_owned = 1;
    return verify_chat_request_local_var;
}

__attribute__((deprecated)) verify_chat_request_t *verify_chat_request_create(
    send_message_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    return verify_chat_request_create_internal (
        chat_id,
        custom_description
        );
}

void verify_chat_request_free(verify_chat_request_t *verify_chat_request) {
    if(NULL == verify_chat_request){
        return ;
    }
    if(verify_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "verify_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (verify_chat_request->chat_id) {
        send_message_request_chat_id_free(verify_chat_request->chat_id);
        verify_chat_request->chat_id = NULL;
    }
    if (verify_chat_request->custom_description) {
        free(verify_chat_request->custom_description);
        verify_chat_request->custom_description = NULL;
    }
    free(verify_chat_request);
}

cJSON *verify_chat_request_convertToJSON(verify_chat_request_t *verify_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // verify_chat_request->chat_id
    if (!verify_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(verify_chat_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // verify_chat_request->custom_description
    if(verify_chat_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", verify_chat_request->custom_description) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

verify_chat_request_t *verify_chat_request_parseFromJSON(cJSON *verify_chat_requestJSON){

    verify_chat_request_t *verify_chat_request_local_var = NULL;

    // define the local variable for verify_chat_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // verify_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(verify_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // verify_chat_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(verify_chat_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    verify_chat_request_local_var = verify_chat_request_create_internal (
        chat_id_local_nonprim,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return verify_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
