#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_verify_chat_request.h"



static post_verify_chat_request_t *post_verify_chat_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    post_verify_chat_request_t *post_verify_chat_request_local_var = malloc(sizeof(post_verify_chat_request_t));
    if (!post_verify_chat_request_local_var) {
        return NULL;
    }
    post_verify_chat_request_local_var->chat_id = chat_id;
    post_verify_chat_request_local_var->custom_description = custom_description;

    post_verify_chat_request_local_var->_library_owned = 1;
    return post_verify_chat_request_local_var;
}

__attribute__((deprecated)) post_verify_chat_request_t *post_verify_chat_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    return post_verify_chat_request_create_internal (
        chat_id,
        custom_description
        );
}

void post_verify_chat_request_free(post_verify_chat_request_t *post_verify_chat_request) {
    if(NULL == post_verify_chat_request){
        return ;
    }
    if(post_verify_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_verify_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_verify_chat_request->chat_id) {
        post_send_message_request_chat_id_free(post_verify_chat_request->chat_id);
        post_verify_chat_request->chat_id = NULL;
    }
    if (post_verify_chat_request->custom_description) {
        free(post_verify_chat_request->custom_description);
        post_verify_chat_request->custom_description = NULL;
    }
    free(post_verify_chat_request);
}

cJSON *post_verify_chat_request_convertToJSON(post_verify_chat_request_t *post_verify_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // post_verify_chat_request->chat_id
    if (!post_verify_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_verify_chat_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_verify_chat_request->custom_description
    if(post_verify_chat_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", post_verify_chat_request->custom_description) == NULL) {
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

post_verify_chat_request_t *post_verify_chat_request_parseFromJSON(cJSON *post_verify_chat_requestJSON){

    post_verify_chat_request_t *post_verify_chat_request_local_var = NULL;

    // define the local variable for post_verify_chat_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_verify_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_verify_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_verify_chat_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(post_verify_chat_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    post_verify_chat_request_local_var = post_verify_chat_request_create_internal (
        chat_id_local_nonprim,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return post_verify_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
