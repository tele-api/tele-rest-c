#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_chat_administrator_custom_title_post_request.h"



static _set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    _set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request_local_var = malloc(sizeof(_set_chat_administrator_custom_title_post_request_t));
    if (!_set_chat_administrator_custom_title_post_request_local_var) {
        return NULL;
    }
    _set_chat_administrator_custom_title_post_request_local_var->chat_id = chat_id;
    _set_chat_administrator_custom_title_post_request_local_var->user_id = user_id;
    _set_chat_administrator_custom_title_post_request_local_var->custom_title = custom_title;

    _set_chat_administrator_custom_title_post_request_local_var->_library_owned = 1;
    return _set_chat_administrator_custom_title_post_request_local_var;
}

__attribute__((deprecated)) _set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    return _set_chat_administrator_custom_title_post_request_create_internal (
        chat_id,
        user_id,
        custom_title
        );
}

void _set_chat_administrator_custom_title_post_request_free(_set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request) {
    if(NULL == _set_chat_administrator_custom_title_post_request){
        return ;
    }
    if(_set_chat_administrator_custom_title_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_chat_administrator_custom_title_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_chat_administrator_custom_title_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_set_chat_administrator_custom_title_post_request->chat_id);
        _set_chat_administrator_custom_title_post_request->chat_id = NULL;
    }
    if (_set_chat_administrator_custom_title_post_request->custom_title) {
        free(_set_chat_administrator_custom_title_post_request->custom_title);
        _set_chat_administrator_custom_title_post_request->custom_title = NULL;
    }
    free(_set_chat_administrator_custom_title_post_request);
}

cJSON *_set_chat_administrator_custom_title_post_request_convertToJSON(_set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_chat_administrator_custom_title_post_request->chat_id
    if (!_set_chat_administrator_custom_title_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_set_chat_administrator_custom_title_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _set_chat_administrator_custom_title_post_request->user_id
    if (!_set_chat_administrator_custom_title_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _set_chat_administrator_custom_title_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _set_chat_administrator_custom_title_post_request->custom_title
    if (!_set_chat_administrator_custom_title_post_request->custom_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "custom_title", _set_chat_administrator_custom_title_post_request->custom_title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request_parseFromJSON(cJSON *_set_chat_administrator_custom_title_post_requestJSON){

    _set_chat_administrator_custom_title_post_request_t *_set_chat_administrator_custom_title_post_request_local_var = NULL;

    // define the local variable for _set_chat_administrator_custom_title_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _set_chat_administrator_custom_title_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_chat_administrator_custom_title_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _set_chat_administrator_custom_title_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_set_chat_administrator_custom_title_post_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // _set_chat_administrator_custom_title_post_request->custom_title
    cJSON *custom_title = cJSON_GetObjectItemCaseSensitive(_set_chat_administrator_custom_title_post_requestJSON, "custom_title");
    if (cJSON_IsNull(custom_title)) {
        custom_title = NULL;
    }
    if (!custom_title) {
        goto end;
    }

    
    if(!cJSON_IsString(custom_title))
    {
    goto end; //String
    }


    _set_chat_administrator_custom_title_post_request_local_var = _set_chat_administrator_custom_title_post_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        strdup(custom_title->valuestring)
        );

    return _set_chat_administrator_custom_title_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _restrict_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
