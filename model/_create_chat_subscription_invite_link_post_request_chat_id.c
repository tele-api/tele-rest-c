#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_chat_subscription_invite_link_post_request_chat_id.h"



static _create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_create_internal(
    ) {
    _create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_local_var = malloc(sizeof(_create_chat_subscription_invite_link_post_request_chat_id_t));
    if (!_create_chat_subscription_invite_link_post_request_chat_id_local_var) {
        return NULL;
    }

    _create_chat_subscription_invite_link_post_request_chat_id_local_var->_library_owned = 1;
    return _create_chat_subscription_invite_link_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_create(
    ) {
    return _create_chat_subscription_invite_link_post_request_chat_id_create_internal (
        );
}

void _create_chat_subscription_invite_link_post_request_chat_id_free(_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id) {
    if(NULL == _create_chat_subscription_invite_link_post_request_chat_id){
        return ;
    }
    if(_create_chat_subscription_invite_link_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_chat_subscription_invite_link_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_create_chat_subscription_invite_link_post_request_chat_id);
}

cJSON *_create_chat_subscription_invite_link_post_request_chat_id_convertToJSON(_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_parseFromJSON(cJSON *_create_chat_subscription_invite_link_post_request_chat_idJSON){

    _create_chat_subscription_invite_link_post_request_chat_id_t *_create_chat_subscription_invite_link_post_request_chat_id_local_var = NULL;


    _create_chat_subscription_invite_link_post_request_chat_id_local_var = _create_chat_subscription_invite_link_post_request_chat_id_create_internal (
        );

    return _create_chat_subscription_invite_link_post_request_chat_id_local_var;
end:
    return NULL;

}
