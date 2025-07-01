#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_chat_invite_link_post_request.h"



static _create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    _create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_local_var = malloc(sizeof(_create_chat_invite_link_post_request_t));
    if (!_create_chat_invite_link_post_request_local_var) {
        return NULL;
    }
    _create_chat_invite_link_post_request_local_var->chat_id = chat_id;
    _create_chat_invite_link_post_request_local_var->name = name;
    _create_chat_invite_link_post_request_local_var->expire_date = expire_date;
    _create_chat_invite_link_post_request_local_var->member_limit = member_limit;
    _create_chat_invite_link_post_request_local_var->creates_join_request = creates_join_request;

    _create_chat_invite_link_post_request_local_var->_library_owned = 1;
    return _create_chat_invite_link_post_request_local_var;
}

__attribute__((deprecated)) _create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    return _create_chat_invite_link_post_request_create_internal (
        chat_id,
        name,
        expire_date,
        member_limit,
        creates_join_request
        );
}

void _create_chat_invite_link_post_request_free(_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request) {
    if(NULL == _create_chat_invite_link_post_request){
        return ;
    }
    if(_create_chat_invite_link_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_chat_invite_link_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_create_chat_invite_link_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_create_chat_invite_link_post_request->chat_id);
        _create_chat_invite_link_post_request->chat_id = NULL;
    }
    if (_create_chat_invite_link_post_request->name) {
        free(_create_chat_invite_link_post_request->name);
        _create_chat_invite_link_post_request->name = NULL;
    }
    free(_create_chat_invite_link_post_request);
}

cJSON *_create_chat_invite_link_post_request_convertToJSON(_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _create_chat_invite_link_post_request->chat_id
    if (!_create_chat_invite_link_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_create_chat_invite_link_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _create_chat_invite_link_post_request->name
    if(_create_chat_invite_link_post_request->name) {
    if(cJSON_AddStringToObject(item, "name", _create_chat_invite_link_post_request->name) == NULL) {
    goto fail; //String
    }
    }


    // _create_chat_invite_link_post_request->expire_date
    if(_create_chat_invite_link_post_request->expire_date) {
    if(cJSON_AddNumberToObject(item, "expire_date", _create_chat_invite_link_post_request->expire_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_chat_invite_link_post_request->member_limit
    if(_create_chat_invite_link_post_request->member_limit) {
    if(cJSON_AddNumberToObject(item, "member_limit", _create_chat_invite_link_post_request->member_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // _create_chat_invite_link_post_request->creates_join_request
    if(_create_chat_invite_link_post_request->creates_join_request) {
    if(cJSON_AddBoolToObject(item, "creates_join_request", _create_chat_invite_link_post_request->creates_join_request) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_parseFromJSON(cJSON *_create_chat_invite_link_post_requestJSON){

    _create_chat_invite_link_post_request_t *_create_chat_invite_link_post_request_local_var = NULL;

    // define the local variable for _create_chat_invite_link_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _create_chat_invite_link_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _create_chat_invite_link_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // _create_chat_invite_link_post_request->expire_date
    cJSON *expire_date = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_requestJSON, "expire_date");
    if (cJSON_IsNull(expire_date)) {
        expire_date = NULL;
    }
    if (expire_date) { 
    if(!cJSON_IsNumber(expire_date))
    {
    goto end; //Numeric
    }
    }

    // _create_chat_invite_link_post_request->member_limit
    cJSON *member_limit = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_requestJSON, "member_limit");
    if (cJSON_IsNull(member_limit)) {
        member_limit = NULL;
    }
    if (member_limit) { 
    if(!cJSON_IsNumber(member_limit))
    {
    goto end; //Numeric
    }
    }

    // _create_chat_invite_link_post_request->creates_join_request
    cJSON *creates_join_request = cJSON_GetObjectItemCaseSensitive(_create_chat_invite_link_post_requestJSON, "creates_join_request");
    if (cJSON_IsNull(creates_join_request)) {
        creates_join_request = NULL;
    }
    if (creates_join_request) { 
    if(!cJSON_IsBool(creates_join_request))
    {
    goto end; //Bool
    }
    }


    _create_chat_invite_link_post_request_local_var = _create_chat_invite_link_post_request_create_internal (
        chat_id_local_nonprim,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        expire_date ? expire_date->valuedouble : 0,
        member_limit ? member_limit->valuedouble : 0,
        creates_join_request ? creates_join_request->valueint : 0
        );

    return _create_chat_invite_link_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
