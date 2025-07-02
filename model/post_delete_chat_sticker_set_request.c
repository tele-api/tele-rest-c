#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_chat_sticker_set_request.h"



static post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id
    ) {
    post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_local_var = malloc(sizeof(post_delete_chat_sticker_set_request_t));
    if (!post_delete_chat_sticker_set_request_local_var) {
        return NULL;
    }
    post_delete_chat_sticker_set_request_local_var->chat_id = chat_id;

    post_delete_chat_sticker_set_request_local_var->_library_owned = 1;
    return post_delete_chat_sticker_set_request_local_var;
}

__attribute__((deprecated)) post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id
    ) {
    return post_delete_chat_sticker_set_request_create_internal (
        chat_id
        );
}

void post_delete_chat_sticker_set_request_free(post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request) {
    if(NULL == post_delete_chat_sticker_set_request){
        return ;
    }
    if(post_delete_chat_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_chat_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_chat_sticker_set_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_delete_chat_sticker_set_request->chat_id);
        post_delete_chat_sticker_set_request->chat_id = NULL;
    }
    free(post_delete_chat_sticker_set_request);
}

cJSON *post_delete_chat_sticker_set_request_convertToJSON(post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_chat_sticker_set_request->chat_id
    if (!post_delete_chat_sticker_set_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_delete_chat_sticker_set_request->chat_id);
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

post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_parseFromJSON(cJSON *post_delete_chat_sticker_set_requestJSON){

    post_delete_chat_sticker_set_request_t *post_delete_chat_sticker_set_request_local_var = NULL;

    // define the local variable for post_delete_chat_sticker_set_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_delete_chat_sticker_set_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_delete_chat_sticker_set_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    post_delete_chat_sticker_set_request_local_var = post_delete_chat_sticker_set_request_create_internal (
        chat_id_local_nonprim
        );

    return post_delete_chat_sticker_set_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
