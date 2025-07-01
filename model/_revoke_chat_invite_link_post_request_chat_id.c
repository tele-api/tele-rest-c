#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_revoke_chat_invite_link_post_request_chat_id.h"



static _revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_create_internal(
    ) {
    _revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_local_var = malloc(sizeof(_revoke_chat_invite_link_post_request_chat_id_t));
    if (!_revoke_chat_invite_link_post_request_chat_id_local_var) {
        return NULL;
    }

    _revoke_chat_invite_link_post_request_chat_id_local_var->_library_owned = 1;
    return _revoke_chat_invite_link_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_create(
    ) {
    return _revoke_chat_invite_link_post_request_chat_id_create_internal (
        );
}

void _revoke_chat_invite_link_post_request_chat_id_free(_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id) {
    if(NULL == _revoke_chat_invite_link_post_request_chat_id){
        return ;
    }
    if(_revoke_chat_invite_link_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_revoke_chat_invite_link_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_revoke_chat_invite_link_post_request_chat_id);
}

cJSON *_revoke_chat_invite_link_post_request_chat_id_convertToJSON(_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_parseFromJSON(cJSON *_revoke_chat_invite_link_post_request_chat_idJSON){

    _revoke_chat_invite_link_post_request_chat_id_t *_revoke_chat_invite_link_post_request_chat_id_local_var = NULL;


    _revoke_chat_invite_link_post_request_chat_id_local_var = _revoke_chat_invite_link_post_request_chat_id_create_internal (
        );

    return _revoke_chat_invite_link_post_request_chat_id_local_var;
end:
    return NULL;

}
