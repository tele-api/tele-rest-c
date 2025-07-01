#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_chat_menu_button_post_request.h"



static _set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_create_internal(
    int chat_id,
    menu_button_t *menu_button
    ) {
    _set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_local_var = malloc(sizeof(_set_chat_menu_button_post_request_t));
    if (!_set_chat_menu_button_post_request_local_var) {
        return NULL;
    }
    _set_chat_menu_button_post_request_local_var->chat_id = chat_id;
    _set_chat_menu_button_post_request_local_var->menu_button = menu_button;

    _set_chat_menu_button_post_request_local_var->_library_owned = 1;
    return _set_chat_menu_button_post_request_local_var;
}

__attribute__((deprecated)) _set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_create(
    int chat_id,
    menu_button_t *menu_button
    ) {
    return _set_chat_menu_button_post_request_create_internal (
        chat_id,
        menu_button
        );
}

void _set_chat_menu_button_post_request_free(_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request) {
    if(NULL == _set_chat_menu_button_post_request){
        return ;
    }
    if(_set_chat_menu_button_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_chat_menu_button_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_chat_menu_button_post_request->menu_button) {
        menu_button_free(_set_chat_menu_button_post_request->menu_button);
        _set_chat_menu_button_post_request->menu_button = NULL;
    }
    free(_set_chat_menu_button_post_request);
}

cJSON *_set_chat_menu_button_post_request_convertToJSON(_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_chat_menu_button_post_request->chat_id
    if(_set_chat_menu_button_post_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", _set_chat_menu_button_post_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _set_chat_menu_button_post_request->menu_button
    if(_set_chat_menu_button_post_request->menu_button) {
    cJSON *menu_button_local_JSON = menu_button_convertToJSON(_set_chat_menu_button_post_request->menu_button);
    if(menu_button_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "menu_button", menu_button_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_parseFromJSON(cJSON *_set_chat_menu_button_post_requestJSON){

    _set_chat_menu_button_post_request_t *_set_chat_menu_button_post_request_local_var = NULL;

    // define the local variable for _set_chat_menu_button_post_request->menu_button
    menu_button_t *menu_button_local_nonprim = NULL;

    // _set_chat_menu_button_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_chat_menu_button_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // _set_chat_menu_button_post_request->menu_button
    cJSON *menu_button = cJSON_GetObjectItemCaseSensitive(_set_chat_menu_button_post_requestJSON, "menu_button");
    if (cJSON_IsNull(menu_button)) {
        menu_button = NULL;
    }
    if (menu_button) { 
    menu_button_local_nonprim = menu_button_parseFromJSON(menu_button); //nonprimitive
    }


    _set_chat_menu_button_post_request_local_var = _set_chat_menu_button_post_request_create_internal (
        chat_id ? chat_id->valuedouble : 0,
        menu_button ? menu_button_local_nonprim : NULL
        );

    return _set_chat_menu_button_post_request_local_var;
end:
    if (menu_button_local_nonprim) {
        menu_button_free(menu_button_local_nonprim);
        menu_button_local_nonprim = NULL;
    }
    return NULL;

}
