#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revoke_chat_invite_link_request.h"



static revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_create_internal(
    revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_local_var = malloc(sizeof(revoke_chat_invite_link_request_t));
    if (!revoke_chat_invite_link_request_local_var) {
        return NULL;
    }
    revoke_chat_invite_link_request_local_var->chat_id = chat_id;
    revoke_chat_invite_link_request_local_var->invite_link = invite_link;

    revoke_chat_invite_link_request_local_var->_library_owned = 1;
    return revoke_chat_invite_link_request_local_var;
}

__attribute__((deprecated)) revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_create(
    revoke_chat_invite_link_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    return revoke_chat_invite_link_request_create_internal (
        chat_id,
        invite_link
        );
}

void revoke_chat_invite_link_request_free(revoke_chat_invite_link_request_t *revoke_chat_invite_link_request) {
    if(NULL == revoke_chat_invite_link_request){
        return ;
    }
    if(revoke_chat_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_chat_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revoke_chat_invite_link_request->chat_id) {
        revoke_chat_invite_link_request_chat_id_free(revoke_chat_invite_link_request->chat_id);
        revoke_chat_invite_link_request->chat_id = NULL;
    }
    if (revoke_chat_invite_link_request->invite_link) {
        free(revoke_chat_invite_link_request->invite_link);
        revoke_chat_invite_link_request->invite_link = NULL;
    }
    free(revoke_chat_invite_link_request);
}

cJSON *revoke_chat_invite_link_request_convertToJSON(revoke_chat_invite_link_request_t *revoke_chat_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // revoke_chat_invite_link_request->chat_id
    if (!revoke_chat_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = revoke_chat_invite_link_request_chat_id_convertToJSON(revoke_chat_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // revoke_chat_invite_link_request->invite_link
    if (!revoke_chat_invite_link_request->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", revoke_chat_invite_link_request->invite_link) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_parseFromJSON(cJSON *revoke_chat_invite_link_requestJSON){

    revoke_chat_invite_link_request_t *revoke_chat_invite_link_request_local_var = NULL;

    // define the local variable for revoke_chat_invite_link_request->chat_id
    revoke_chat_invite_link_request_chat_id_t *chat_id_local_nonprim = NULL;

    // revoke_chat_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(revoke_chat_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = revoke_chat_invite_link_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // revoke_chat_invite_link_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(revoke_chat_invite_link_requestJSON, "invite_link");
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


    revoke_chat_invite_link_request_local_var = revoke_chat_invite_link_request_create_internal (
        chat_id_local_nonprim,
        strdup(invite_link->valuestring)
        );

    return revoke_chat_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        revoke_chat_invite_link_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
