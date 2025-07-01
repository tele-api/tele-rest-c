#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_revoke_chat_invite_link_post_request.h"



static _revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_create_internal(
    _revoke_chat_invite_link_post_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    _revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_local_var = malloc(sizeof(_revoke_chat_invite_link_post_request_t));
    if (!_revoke_chat_invite_link_post_request_local_var) {
        return NULL;
    }
    _revoke_chat_invite_link_post_request_local_var->chat_id = chat_id;
    _revoke_chat_invite_link_post_request_local_var->invite_link = invite_link;

    _revoke_chat_invite_link_post_request_local_var->_library_owned = 1;
    return _revoke_chat_invite_link_post_request_local_var;
}

__attribute__((deprecated)) _revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_create(
    _revoke_chat_invite_link_post_request_chat_id_t *chat_id,
    char *invite_link
    ) {
    return _revoke_chat_invite_link_post_request_create_internal (
        chat_id,
        invite_link
        );
}

void _revoke_chat_invite_link_post_request_free(_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request) {
    if(NULL == _revoke_chat_invite_link_post_request){
        return ;
    }
    if(_revoke_chat_invite_link_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_revoke_chat_invite_link_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_revoke_chat_invite_link_post_request->chat_id) {
        _revoke_chat_invite_link_post_request_chat_id_free(_revoke_chat_invite_link_post_request->chat_id);
        _revoke_chat_invite_link_post_request->chat_id = NULL;
    }
    if (_revoke_chat_invite_link_post_request->invite_link) {
        free(_revoke_chat_invite_link_post_request->invite_link);
        _revoke_chat_invite_link_post_request->invite_link = NULL;
    }
    free(_revoke_chat_invite_link_post_request);
}

cJSON *_revoke_chat_invite_link_post_request_convertToJSON(_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _revoke_chat_invite_link_post_request->chat_id
    if (!_revoke_chat_invite_link_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _revoke_chat_invite_link_post_request_chat_id_convertToJSON(_revoke_chat_invite_link_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _revoke_chat_invite_link_post_request->invite_link
    if (!_revoke_chat_invite_link_post_request->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", _revoke_chat_invite_link_post_request->invite_link) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_parseFromJSON(cJSON *_revoke_chat_invite_link_post_requestJSON){

    _revoke_chat_invite_link_post_request_t *_revoke_chat_invite_link_post_request_local_var = NULL;

    // define the local variable for _revoke_chat_invite_link_post_request->chat_id
    _revoke_chat_invite_link_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _revoke_chat_invite_link_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_revoke_chat_invite_link_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _revoke_chat_invite_link_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _revoke_chat_invite_link_post_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(_revoke_chat_invite_link_post_requestJSON, "invite_link");
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


    _revoke_chat_invite_link_post_request_local_var = _revoke_chat_invite_link_post_request_create_internal (
        chat_id_local_nonprim,
        strdup(invite_link->valuestring)
        );

    return _revoke_chat_invite_link_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _revoke_chat_invite_link_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
