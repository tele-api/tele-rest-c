#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_leave_chat_post_request.h"



static _leave_chat_post_request_t *_leave_chat_post_request_create_internal(
    _leave_chat_post_request_chat_id_t *chat_id
    ) {
    _leave_chat_post_request_t *_leave_chat_post_request_local_var = malloc(sizeof(_leave_chat_post_request_t));
    if (!_leave_chat_post_request_local_var) {
        return NULL;
    }
    _leave_chat_post_request_local_var->chat_id = chat_id;

    _leave_chat_post_request_local_var->_library_owned = 1;
    return _leave_chat_post_request_local_var;
}

__attribute__((deprecated)) _leave_chat_post_request_t *_leave_chat_post_request_create(
    _leave_chat_post_request_chat_id_t *chat_id
    ) {
    return _leave_chat_post_request_create_internal (
        chat_id
        );
}

void _leave_chat_post_request_free(_leave_chat_post_request_t *_leave_chat_post_request) {
    if(NULL == _leave_chat_post_request){
        return ;
    }
    if(_leave_chat_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_leave_chat_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_leave_chat_post_request->chat_id) {
        _leave_chat_post_request_chat_id_free(_leave_chat_post_request->chat_id);
        _leave_chat_post_request->chat_id = NULL;
    }
    free(_leave_chat_post_request);
}

cJSON *_leave_chat_post_request_convertToJSON(_leave_chat_post_request_t *_leave_chat_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _leave_chat_post_request->chat_id
    if (!_leave_chat_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _leave_chat_post_request_chat_id_convertToJSON(_leave_chat_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_leave_chat_post_request_t *_leave_chat_post_request_parseFromJSON(cJSON *_leave_chat_post_requestJSON){

    _leave_chat_post_request_t *_leave_chat_post_request_local_var = NULL;

    // define the local variable for _leave_chat_post_request->chat_id
    _leave_chat_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _leave_chat_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_leave_chat_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _leave_chat_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive


    _leave_chat_post_request_local_var = _leave_chat_post_request_create_internal (
        chat_id_local_nonprim
        );

    return _leave_chat_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _leave_chat_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
