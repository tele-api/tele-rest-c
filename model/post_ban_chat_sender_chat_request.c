#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_ban_chat_sender_chat_request.h"



static post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_local_var = malloc(sizeof(post_ban_chat_sender_chat_request_t));
    if (!post_ban_chat_sender_chat_request_local_var) {
        return NULL;
    }
    post_ban_chat_sender_chat_request_local_var->chat_id = chat_id;
    post_ban_chat_sender_chat_request_local_var->sender_chat_id = sender_chat_id;

    post_ban_chat_sender_chat_request_local_var->_library_owned = 1;
    return post_ban_chat_sender_chat_request_local_var;
}

__attribute__((deprecated)) post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int sender_chat_id
    ) {
    return post_ban_chat_sender_chat_request_create_internal (
        chat_id,
        sender_chat_id
        );
}

void post_ban_chat_sender_chat_request_free(post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request) {
    if(NULL == post_ban_chat_sender_chat_request){
        return ;
    }
    if(post_ban_chat_sender_chat_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_ban_chat_sender_chat_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_ban_chat_sender_chat_request->chat_id) {
        post_send_message_request_chat_id_free(post_ban_chat_sender_chat_request->chat_id);
        post_ban_chat_sender_chat_request->chat_id = NULL;
    }
    free(post_ban_chat_sender_chat_request);
}

cJSON *post_ban_chat_sender_chat_request_convertToJSON(post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request) {
    cJSON *item = cJSON_CreateObject();

    // post_ban_chat_sender_chat_request->chat_id
    if (!post_ban_chat_sender_chat_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_ban_chat_sender_chat_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_ban_chat_sender_chat_request->sender_chat_id
    if (!post_ban_chat_sender_chat_request->sender_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sender_chat_id", post_ban_chat_sender_chat_request->sender_chat_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_parseFromJSON(cJSON *post_ban_chat_sender_chat_requestJSON){

    post_ban_chat_sender_chat_request_t *post_ban_chat_sender_chat_request_local_var = NULL;

    // define the local variable for post_ban_chat_sender_chat_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_ban_chat_sender_chat_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_ban_chat_sender_chat_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_ban_chat_sender_chat_request->sender_chat_id
    cJSON *sender_chat_id = cJSON_GetObjectItemCaseSensitive(post_ban_chat_sender_chat_requestJSON, "sender_chat_id");
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


    post_ban_chat_sender_chat_request_local_var = post_ban_chat_sender_chat_request_create_internal (
        chat_id_local_nonprim,
        sender_chat_id->valuedouble
        );

    return post_ban_chat_sender_chat_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
