#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_ban_chat_member_post_request_chat_id.h"



static _ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_create_internal(
    ) {
    _ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_local_var = malloc(sizeof(_ban_chat_member_post_request_chat_id_t));
    if (!_ban_chat_member_post_request_chat_id_local_var) {
        return NULL;
    }

    _ban_chat_member_post_request_chat_id_local_var->_library_owned = 1;
    return _ban_chat_member_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_create(
    ) {
    return _ban_chat_member_post_request_chat_id_create_internal (
        );
}

void _ban_chat_member_post_request_chat_id_free(_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id) {
    if(NULL == _ban_chat_member_post_request_chat_id){
        return ;
    }
    if(_ban_chat_member_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_ban_chat_member_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_ban_chat_member_post_request_chat_id);
}

cJSON *_ban_chat_member_post_request_chat_id_convertToJSON(_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_parseFromJSON(cJSON *_ban_chat_member_post_request_chat_idJSON){

    _ban_chat_member_post_request_chat_id_t *_ban_chat_member_post_request_chat_id_local_var = NULL;


    _ban_chat_member_post_request_chat_id_local_var = _ban_chat_member_post_request_chat_id_create_internal (
        );

    return _ban_chat_member_post_request_chat_id_local_var;
end:
    return NULL;

}
