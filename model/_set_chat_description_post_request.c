#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_chat_description_post_request.h"



static _set_chat_description_post_request_t *_set_chat_description_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *description
    ) {
    _set_chat_description_post_request_t *_set_chat_description_post_request_local_var = malloc(sizeof(_set_chat_description_post_request_t));
    if (!_set_chat_description_post_request_local_var) {
        return NULL;
    }
    _set_chat_description_post_request_local_var->chat_id = chat_id;
    _set_chat_description_post_request_local_var->description = description;

    _set_chat_description_post_request_local_var->_library_owned = 1;
    return _set_chat_description_post_request_local_var;
}

__attribute__((deprecated)) _set_chat_description_post_request_t *_set_chat_description_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *description
    ) {
    return _set_chat_description_post_request_create_internal (
        chat_id,
        description
        );
}

void _set_chat_description_post_request_free(_set_chat_description_post_request_t *_set_chat_description_post_request) {
    if(NULL == _set_chat_description_post_request){
        return ;
    }
    if(_set_chat_description_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_chat_description_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_chat_description_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_set_chat_description_post_request->chat_id);
        _set_chat_description_post_request->chat_id = NULL;
    }
    if (_set_chat_description_post_request->description) {
        free(_set_chat_description_post_request->description);
        _set_chat_description_post_request->description = NULL;
    }
    free(_set_chat_description_post_request);
}

cJSON *_set_chat_description_post_request_convertToJSON(_set_chat_description_post_request_t *_set_chat_description_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_chat_description_post_request->chat_id
    if (!_set_chat_description_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_set_chat_description_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _set_chat_description_post_request->description
    if(_set_chat_description_post_request->description) {
    if(cJSON_AddStringToObject(item, "description", _set_chat_description_post_request->description) == NULL) {
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

_set_chat_description_post_request_t *_set_chat_description_post_request_parseFromJSON(cJSON *_set_chat_description_post_requestJSON){

    _set_chat_description_post_request_t *_set_chat_description_post_request_local_var = NULL;

    // define the local variable for _set_chat_description_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _set_chat_description_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_chat_description_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _set_chat_description_post_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(_set_chat_description_post_requestJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }


    _set_chat_description_post_request_local_var = _set_chat_description_post_request_create_internal (
        chat_id_local_nonprim,
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL
        );

    return _set_chat_description_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
