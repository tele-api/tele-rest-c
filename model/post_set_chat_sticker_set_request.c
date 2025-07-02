#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_chat_sticker_set_request.h"



static post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *sticker_set_name
    ) {
    post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request_local_var = malloc(sizeof(post_set_chat_sticker_set_request_t));
    if (!post_set_chat_sticker_set_request_local_var) {
        return NULL;
    }
    post_set_chat_sticker_set_request_local_var->chat_id = chat_id;
    post_set_chat_sticker_set_request_local_var->sticker_set_name = sticker_set_name;

    post_set_chat_sticker_set_request_local_var->_library_owned = 1;
    return post_set_chat_sticker_set_request_local_var;
}

__attribute__((deprecated)) post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *sticker_set_name
    ) {
    return post_set_chat_sticker_set_request_create_internal (
        chat_id,
        sticker_set_name
        );
}

void post_set_chat_sticker_set_request_free(post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request) {
    if(NULL == post_set_chat_sticker_set_request){
        return ;
    }
    if(post_set_chat_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_chat_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_chat_sticker_set_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_set_chat_sticker_set_request->chat_id);
        post_set_chat_sticker_set_request->chat_id = NULL;
    }
    if (post_set_chat_sticker_set_request->sticker_set_name) {
        free(post_set_chat_sticker_set_request->sticker_set_name);
        post_set_chat_sticker_set_request->sticker_set_name = NULL;
    }
    free(post_set_chat_sticker_set_request);
}

cJSON *post_set_chat_sticker_set_request_convertToJSON(post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_chat_sticker_set_request->chat_id
    if (!post_set_chat_sticker_set_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_set_chat_sticker_set_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_chat_sticker_set_request->sticker_set_name
    if (!post_set_chat_sticker_set_request->sticker_set_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker_set_name", post_set_chat_sticker_set_request->sticker_set_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request_parseFromJSON(cJSON *post_set_chat_sticker_set_requestJSON){

    post_set_chat_sticker_set_request_t *post_set_chat_sticker_set_request_local_var = NULL;

    // define the local variable for post_set_chat_sticker_set_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_set_chat_sticker_set_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_sticker_set_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_set_chat_sticker_set_request->sticker_set_name
    cJSON *sticker_set_name = cJSON_GetObjectItemCaseSensitive(post_set_chat_sticker_set_requestJSON, "sticker_set_name");
    if (cJSON_IsNull(sticker_set_name)) {
        sticker_set_name = NULL;
    }
    if (!sticker_set_name) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker_set_name))
    {
    goto end; //String
    }


    post_set_chat_sticker_set_request_local_var = post_set_chat_sticker_set_request_create_internal (
        chat_id_local_nonprim,
        strdup(sticker_set_name->valuestring)
        );

    return post_set_chat_sticker_set_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
