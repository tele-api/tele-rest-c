#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_message_text_post_request_chat_id.h"



static _edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_create_internal(
    ) {
    _edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_local_var = malloc(sizeof(_edit_message_text_post_request_chat_id_t));
    if (!_edit_message_text_post_request_chat_id_local_var) {
        return NULL;
    }

    _edit_message_text_post_request_chat_id_local_var->_library_owned = 1;
    return _edit_message_text_post_request_chat_id_local_var;
}

__attribute__((deprecated)) _edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_create(
    ) {
    return _edit_message_text_post_request_chat_id_create_internal (
        );
}

void _edit_message_text_post_request_chat_id_free(_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id) {
    if(NULL == _edit_message_text_post_request_chat_id){
        return ;
    }
    if(_edit_message_text_post_request_chat_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_message_text_post_request_chat_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_edit_message_text_post_request_chat_id);
}

cJSON *_edit_message_text_post_request_chat_id_convertToJSON(_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_parseFromJSON(cJSON *_edit_message_text_post_request_chat_idJSON){

    _edit_message_text_post_request_chat_id_t *_edit_message_text_post_request_chat_id_local_var = NULL;


    _edit_message_text_post_request_chat_id_local_var = _edit_message_text_post_request_chat_id_create_internal (
        );

    return _edit_message_text_post_request_chat_id_local_var;
end:
    return NULL;

}
