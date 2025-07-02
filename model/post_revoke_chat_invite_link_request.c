#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_revoke_chat_invite_link_request.h"



static post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_create_internal(
    post_revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_local_var = malloc(sizeof(post_revoke_chat_invite_link_request_t));
    if (!post_revoke_chat_invite_link_request_local_var) {
        return NULL;
    }
    post_revoke_chat_invite_link_request_local_var->chat_id = chat_id;
    post_revoke_chat_invite_link_request_local_var->invite_link = invite_link;

    post_revoke_chat_invite_link_request_local_var->_library_owned = 1;
    return post_revoke_chat_invite_link_request_local_var;
}

__attribute__((deprecated)) post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_create(
    post_revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    return post_revoke_chat_invite_link_request_create_internal (
        chat_id,
        invite_link
        );
}

void post_revoke_chat_invite_link_request_free(post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request) {
    if(NULL == post_revoke_chat_invite_link_request){
        return ;
    }
    if(post_revoke_chat_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_revoke_chat_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_revoke_chat_invite_link_request->chat_id) {
        post_revoke_chat_invite_link_request_chat_id_free(post_revoke_chat_invite_link_request->chat_id);
        post_revoke_chat_invite_link_request->chat_id = NULL;
    }
    if (post_revoke_chat_invite_link_request->invite_link) {
        free(post_revoke_chat_invite_link_request->invite_link);
        post_revoke_chat_invite_link_request->invite_link = NULL;
    }
    free(post_revoke_chat_invite_link_request);
}

cJSON *post_revoke_chat_invite_link_request_convertToJSON(post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // post_revoke_chat_invite_link_request->chat_id
    if (!post_revoke_chat_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_revoke_chat_invite_link_request_chat_id_convertToJSON(post_revoke_chat_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_revoke_chat_invite_link_request->invite_link
    if (!post_revoke_chat_invite_link_request->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", post_revoke_chat_invite_link_request->invite_link) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_parseFromJSON(cJSON *post_revoke_chat_invite_link_requestJSON){

    post_revoke_chat_invite_link_request_t *post_revoke_chat_invite_link_request_local_var = NULL;

    // define the local variable for post_revoke_chat_invite_link_request->chat_id
    post_revoke_chat_invite_link_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_revoke_chat_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_revoke_chat_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_revoke_chat_invite_link_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_revoke_chat_invite_link_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(post_revoke_chat_invite_link_requestJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (!invite_link) {
        goto end;
    }

    
    if(!cJSON_IsString(invite_link))
    {
    goto end; //String
    }


    post_revoke_chat_invite_link_request_local_var = post_revoke_chat_invite_link_request_create_internal (
        chat_id_local_nonprim,
        strdup(invite_link->valuestring)
        );

    return post_revoke_chat_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_revoke_chat_invite_link_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
