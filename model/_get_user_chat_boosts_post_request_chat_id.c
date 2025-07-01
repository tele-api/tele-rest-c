#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_user_chat_boosts_post_request_chat_id.h"



static _get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_create_internal(
    ) {
    _get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_local_var = malloc(sizeof(_get_user_chat_boosts_post_request_chat_id_t));
    if (!_get_user_chat_boosts_post_request_chat_id_local_var) {
        return NULL;
    }

    _get_user_chat_boosts_post_request_chat_id_local_var->_library_owned = 1;
    return _get_user_chat_boosts_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_create(
    ) {
    return _get_user_chat_boosts_post_request_chat_id_create_internal (
        );
}

void _get_user_chat_boosts_post_request_chat_id_free(_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id) {
    if(NULL == _get_user_chat_boosts_post_request_chat_id){
        return ;
    }
    if(_get_user_chat_boosts_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_user_chat_boosts_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_get_user_chat_boosts_post_request_chat_id);
}

cJSON *_get_user_chat_boosts_post_request_chat_id_convertToJSON(_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_parseFromJSON(cJSON *_get_user_chat_boosts_post_request_chat_idJSON){

    _get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_local_var = NULL;


    _get_user_chat_boosts_post_request_chat_id_local_var = _get_user_chat_boosts_post_request_chat_id_create_internal (
        );

    return _get_user_chat_boosts_post_request_chat_id_local_var;
end:
    return NULL;

}
