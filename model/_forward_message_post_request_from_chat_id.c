#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_forward_message_post_request_from_chat_id.h"



static _forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id_create_internal(
    ) {
    _forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id_local_var = malloc(sizeof(_forward_message_post_request_from_chat_id_t));
    if (!_forward_message_post_request_from_chat_id_local_var) {
        return NULL;
    }

    _forward_message_post_request_from_chat_id_local_var->_library_owned = 1;
    return _forward_message_post_request_from_chat_id_local_var;
}

__attribute__((deprecated)) _forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id_create(
    ) {
    return _forward_message_post_request_from_chat_id_create_internal (
        );
}

void _forward_message_post_request_from_chat_id_free(_forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id) {
    if(NULL == _forward_message_post_request_from_chat_id){
        return ;
    }
    if(_forward_message_post_request_from_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_forward_message_post_request_from_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_forward_message_post_request_from_chat_id);
}

cJSON *_forward_message_post_request_from_chat_id_convertToJSON(_forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id_parseFromJSON(cJSON *_forward_message_post_request_from_chat_idJSON){

    _forward_message_post_request_from_chat_id_t *_forward_message_post_request_from_chat_id_local_var = NULL;


    _forward_message_post_request_from_chat_id_local_var = _forward_message_post_request_from_chat_id_create_internal (
        );

    return _forward_message_post_request_from_chat_id_local_var;
end:
    return NULL;

}
