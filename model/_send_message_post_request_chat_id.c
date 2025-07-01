#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_message_post_request_chat_id.h"



static _send_message_post_request_chat_id_t *_send_message_post_request_chat_id_create_internal(
    ) {
    _send_message_post_request_chat_id_t *_send_message_post_request_chat_id_local_var = malloc(sizeof(_send_message_post_request_chat_id_t));
    if (!_send_message_post_request_chat_id_local_var) {
        return NULL;
    }

    _send_message_post_request_chat_id_local_var->_library_owned = 1;
    return _send_message_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _send_message_post_request_chat_id_t *_send_message_post_request_chat_id_create(
    ) {
    return _send_message_post_request_chat_id_create_internal (
        );
}

void _send_message_post_request_chat_id_free(_send_message_post_request_chat_id_t *_send_message_post_request_chat_id) {
    if(NULL == _send_message_post_request_chat_id){
        return ;
    }
    if(_send_message_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_message_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_send_message_post_request_chat_id);
}

cJSON *_send_message_post_request_chat_id_convertToJSON(_send_message_post_request_chat_id_t *_send_message_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_message_post_request_chat_id_t *_send_message_post_request_chat_id_parseFromJSON(cJSON *_send_message_post_request_chat_idJSON){

    _send_message_post_request_chat_id_t *_send_message_post_request_chat_id_local_var = NULL;


    _send_message_post_request_chat_id_local_var = _send_message_post_request_chat_id_create_internal (
        );

    return _send_message_post_request_chat_id_local_var;
end:
    return NULL;

}
