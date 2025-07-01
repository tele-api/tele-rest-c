#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_verify_chat_post_request.h"



static _verify_chat_post_request_t *_verify_chat_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    _verify_chat_post_request_t *_verify_chat_post_request_local_var = malloc(sizeof(_verify_chat_post_request_t));
    if (!_verify_chat_post_request_local_var) {
        return NULL;
    }
    _verify_chat_post_request_local_var->chat_id = chat_id;
    _verify_chat_post_request_local_var->custom_description = custom_description;

    _verify_chat_post_request_local_var->_library_owned = 1;
    return _verify_chat_post_request_local_var;
}

__attribute__((deprecated)) _verify_chat_post_request_t *_verify_chat_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *custom_description
    ) {
    return _verify_chat_post_request_create_internal (
        chat_id,
        custom_description
        );
}

void _verify_chat_post_request_free(_verify_chat_post_request_t *_verify_chat_post_request) {
    if(NULL == _verify_chat_post_request){
        return ;
    }
    if(_verify_chat_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_verify_chat_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_verify_chat_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_verify_chat_post_request->chat_id);
        _verify_chat_post_request->chat_id = NULL;
    }
    if (_verify_chat_post_request->custom_description) {
        free(_verify_chat_post_request->custom_description);
        _verify_chat_post_request->custom_description = NULL;
    }
    free(_verify_chat_post_request);
}

cJSON *_verify_chat_post_request_convertToJSON(_verify_chat_post_request_t *_verify_chat_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _verify_chat_post_request->chat_id
    if (!_verify_chat_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_verify_chat_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _verify_chat_post_request->custom_description
    if(_verify_chat_post_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", _verify_chat_post_request->custom_description) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_verify_chat_post_request_t *_verify_chat_post_request_parseFromJSON(cJSON *_verify_chat_post_requestJSON){

    _verify_chat_post_request_t *_verify_chat_post_request_local_var = NULL;

    // define the local variable for _verify_chat_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _verify_chat_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_verify_chat_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _verify_chat_post_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(_verify_chat_post_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    _verify_chat_post_request_local_var = _verify_chat_post_request_create_internal (
        chat_id_local_nonprim,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return _verify_chat_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
