#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_leave_chat_post_request_chat_id.h"



static _leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_create_internal(
    ) {
    _leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_local_var = malloc(sizeof(_leave_chat_post_request_chat_id_t));
    if (!_leave_chat_post_request_chat_id_local_var) {
        return NULL;
    }

    _leave_chat_post_request_chat_id_local_var->_library_owned = 1;
    return _leave_chat_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_create(
    ) {
    return _leave_chat_post_request_chat_id_create_internal (
        );
}

void _leave_chat_post_request_chat_id_free(_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id) {
    if(NULL == _leave_chat_post_request_chat_id){
        return ;
    }
    if(_leave_chat_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_leave_chat_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_leave_chat_post_request_chat_id);
}

cJSON *_leave_chat_post_request_chat_id_convertToJSON(_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_parseFromJSON(cJSON *_leave_chat_post_request_chat_idJSON){

    _leave_chat_post_request_chat_id_t *_leave_chat_post_request_chat_id_local_var = NULL;


    _leave_chat_post_request_chat_id_local_var = _leave_chat_post_request_chat_id_create_internal (
        );

    return _leave_chat_post_request_chat_id_local_var;
end:
    return NULL;

}
