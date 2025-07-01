#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_restrict_chat_member_post_request_chat_id.h"



static _restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_create_internal(
    ) {
    _restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_local_var = malloc(sizeof(_restrict_chat_member_post_request_chat_id_t));
    if (!_restrict_chat_member_post_request_chat_id_local_var) {
        return NULL;
    }

    _restrict_chat_member_post_request_chat_id_local_var->_library_owned = 1;
    return _restrict_chat_member_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_create(
    ) {
    return _restrict_chat_member_post_request_chat_id_create_internal (
        );
}

void _restrict_chat_member_post_request_chat_id_free(_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id) {
    if(NULL == _restrict_chat_member_post_request_chat_id){
        return ;
    }
    if(_restrict_chat_member_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_restrict_chat_member_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_restrict_chat_member_post_request_chat_id);
}

cJSON *_restrict_chat_member_post_request_chat_id_convertToJSON(_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_parseFromJSON(cJSON *_restrict_chat_member_post_request_chat_idJSON){

    _restrict_chat_member_post_request_chat_id_t *_restrict_chat_member_post_request_chat_id_local_var = NULL;


    _restrict_chat_member_post_request_chat_id_local_var = _restrict_chat_member_post_request_chat_id_create_internal (
        );

    return _restrict_chat_member_post_request_chat_id_local_var;
end:
    return NULL;

}
