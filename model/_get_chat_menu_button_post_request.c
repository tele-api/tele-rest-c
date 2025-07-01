#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_chat_menu_button_post_request.h"



static _get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_create_internal(
    int chat_id
    ) {
    _get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_local_var = malloc(sizeof(_get_chat_menu_button_post_request_t));
    if (!_get_chat_menu_button_post_request_local_var) {
        return NULL;
    }
    _get_chat_menu_button_post_request_local_var->chat_id = chat_id;

    _get_chat_menu_button_post_request_local_var->_library_owned = 1;
    return _get_chat_menu_button_post_request_local_var;
}

__attribute__((deprecated)) _get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_create(
    int chat_id
    ) {
    return _get_chat_menu_button_post_request_create_internal (
        chat_id
        );
}

void _get_chat_menu_button_post_request_free(_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request) {
    if(NULL == _get_chat_menu_button_post_request){
        return ;
    }
    if(_get_chat_menu_button_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_chat_menu_button_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_get_chat_menu_button_post_request);
}

cJSON *_get_chat_menu_button_post_request_convertToJSON(_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_chat_menu_button_post_request->chat_id
    if(_get_chat_menu_button_post_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", _get_chat_menu_button_post_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_parseFromJSON(cJSON *_get_chat_menu_button_post_requestJSON){

    _get_chat_menu_button_post_request_t *_get_chat_menu_button_post_request_local_var = NULL;

    // _get_chat_menu_button_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_get_chat_menu_button_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }


    _get_chat_menu_button_post_request_local_var = _get_chat_menu_button_post_request_create_internal (
        chat_id ? chat_id->valuedouble : 0
        );

    return _get_chat_menu_button_post_request_local_var;
end:
    return NULL;

}
