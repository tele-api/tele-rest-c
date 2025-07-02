#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revoke_chat_invite_link_request_chat_id.h"



static revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_create_internal(
    ) {
    revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_local_var = malloc(sizeof(revoke_chat_invite_link_request_chat_id_t));
    if (!revoke_chat_invite_link_request_chat_id_local_var) {
        return NULL;
    }

    revoke_chat_invite_link_request_chat_id_local_var->_library_owned = 1;
    return revoke_chat_invite_link_request_chat_id_local_var;
}

__attribute__((deprecated)) revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_create(
    ) {
    return revoke_chat_invite_link_request_chat_id_create_internal (
        );
}

void revoke_chat_invite_link_request_chat_id_free(revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id) {
    if(NULL == revoke_chat_invite_link_request_chat_id){
        return ;
    }
    if(revoke_chat_invite_link_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revoke_chat_invite_link_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(revoke_chat_invite_link_request_chat_id);
}

cJSON *revoke_chat_invite_link_request_chat_id_convertToJSON(revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_parseFromJSON(cJSON *revoke_chat_invite_link_request_chat_idJSON){

    revoke_chat_invite_link_request_chat_id_t *revoke_chat_invite_link_request_chat_id_local_var = NULL;


    revoke_chat_invite_link_request_chat_id_local_var = revoke_chat_invite_link_request_chat_id_create_internal (
        );

    return revoke_chat_invite_link_request_chat_id_local_var;
end:
    return NULL;

}
