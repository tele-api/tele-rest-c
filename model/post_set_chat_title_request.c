#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_chat_title_request.h"



static post_set_chat_title_request_t *post_set_chat_title_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *title
    ) {
    post_set_chat_title_request_t *post_set_chat_title_request_local_var = malloc(sizeof(post_set_chat_title_request_t));
    if (!post_set_chat_title_request_local_var) {
        return NULL;
    }
    post_set_chat_title_request_local_var->chat_id = chat_id;
    post_set_chat_title_request_local_var->title = title;

    post_set_chat_title_request_local_var->_library_owned = 1;
    return post_set_chat_title_request_local_var;
}

__attribute__((deprecated)) post_set_chat_title_request_t *post_set_chat_title_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *title
    ) {
    return post_set_chat_title_request_create_internal (
        chat_id,
        title
        );
}

void post_set_chat_title_request_free(post_set_chat_title_request_t *post_set_chat_title_request) {
    if(NULL == post_set_chat_title_request){
        return ;
    }
    if(post_set_chat_title_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_chat_title_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_chat_title_request->chat_id) {
        post_send_message_request_chat_id_free(post_set_chat_title_request->chat_id);
        post_set_chat_title_request->chat_id = NULL;
    }
    if (post_set_chat_title_request->title) {
        free(post_set_chat_title_request->title);
        post_set_chat_title_request->title = NULL;
    }
    free(post_set_chat_title_request);
}

cJSON *post_set_chat_title_request_convertToJSON(post_set_chat_title_request_t *post_set_chat_title_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_chat_title_request->chat_id
    if (!post_set_chat_title_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_set_chat_title_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_chat_title_request->title
    if (!post_set_chat_title_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", post_set_chat_title_request->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_chat_title_request_t *post_set_chat_title_request_parseFromJSON(cJSON *post_set_chat_title_requestJSON){

    post_set_chat_title_request_t *post_set_chat_title_request_local_var = NULL;

    // define the local variable for post_set_chat_title_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_set_chat_title_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_title_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_set_chat_title_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(post_set_chat_title_requestJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }


    post_set_chat_title_request_local_var = post_set_chat_title_request_create_internal (
        chat_id_local_nonprim,
        strdup(title->valuestring)
        );

    return post_set_chat_title_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
