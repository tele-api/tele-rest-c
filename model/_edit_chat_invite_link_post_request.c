#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_chat_invite_link_post_request.h"



static _edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    _edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_local_var = malloc(sizeof(_edit_chat_invite_link_post_request_t));
    if (!_edit_chat_invite_link_post_request_local_var) {
        return NULL;
    }
    _edit_chat_invite_link_post_request_local_var->chat_id = chat_id;
    _edit_chat_invite_link_post_request_local_var->invite_link = invite_link;
    _edit_chat_invite_link_post_request_local_var->name = name;
    _edit_chat_invite_link_post_request_local_var->expire_date = expire_date;
    _edit_chat_invite_link_post_request_local_var->member_limit = member_limit;
    _edit_chat_invite_link_post_request_local_var->creates_join_request = creates_join_request;

    _edit_chat_invite_link_post_request_local_var->_library_owned = 1;
    return _edit_chat_invite_link_post_request_local_var;
}

__attribute__((deprecated)) _edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    return _edit_chat_invite_link_post_request_create_internal (
        chat_id,
        invite_link,
        name,
        expire_date,
        member_limit,
        creates_join_request
        );
}

void _edit_chat_invite_link_post_request_free(_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request) {
    if(NULL == _edit_chat_invite_link_post_request){
        return ;
    }
    if(_edit_chat_invite_link_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_chat_invite_link_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_chat_invite_link_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_edit_chat_invite_link_post_request->chat_id);
        _edit_chat_invite_link_post_request->chat_id = NULL;
    }
    if (_edit_chat_invite_link_post_request->invite_link) {
        free(_edit_chat_invite_link_post_request->invite_link);
        _edit_chat_invite_link_post_request->invite_link = NULL;
    }
    if (_edit_chat_invite_link_post_request->name) {
        free(_edit_chat_invite_link_post_request->name);
        _edit_chat_invite_link_post_request->name = NULL;
    }
    free(_edit_chat_invite_link_post_request);
}

cJSON *_edit_chat_invite_link_post_request_convertToJSON(_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _edit_chat_invite_link_post_request->chat_id
    if (!_edit_chat_invite_link_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_edit_chat_invite_link_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _edit_chat_invite_link_post_request->invite_link
    if (!_edit_chat_invite_link_post_request->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", _edit_chat_invite_link_post_request->invite_link) == NULL) {
    goto fail; //String
    }


    // _edit_chat_invite_link_post_request->name
    if(_edit_chat_invite_link_post_request->name) {
    if(cJSON_AddStringToObject(item, "name", _edit_chat_invite_link_post_request->name) == NULL) {
    goto fail; //String
    }
    }


    // _edit_chat_invite_link_post_request->expire_date
    if(_edit_chat_invite_link_post_request->expire_date) {
    if(cJSON_AddNumberToObject(item, "expire_date", _edit_chat_invite_link_post_request->expire_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_chat_invite_link_post_request->member_limit
    if(_edit_chat_invite_link_post_request->member_limit) {
    if(cJSON_AddNumberToObject(item, "member_limit", _edit_chat_invite_link_post_request->member_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_chat_invite_link_post_request->creates_join_request
    if(_edit_chat_invite_link_post_request->creates_join_request) {
    if(cJSON_AddBoolToObject(item, "creates_join_request", _edit_chat_invite_link_post_request->creates_join_request) == NULL) {
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

_edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_parseFromJSON(cJSON *_edit_chat_invite_link_post_requestJSON){

    _edit_chat_invite_link_post_request_t *_edit_chat_invite_link_post_request_local_var = NULL;

    // define the local variable for _edit_chat_invite_link_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _edit_chat_invite_link_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _edit_chat_invite_link_post_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (!invite_link) {
        goto end;
    }

    
    if(!cJSON_IsString(invite_link))
    {
    goto end; //String
    }

    // _edit_chat_invite_link_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // _edit_chat_invite_link_post_request->expire_date
    cJSON *expire_date = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "expire_date");
    if (cJSON_IsNull(expire_date)) {
        expire_date = NULL;
    }
    if (expire_date) { 
    if(!cJSON_IsNumber(expire_date))
    {
    goto end; //Numeric
    }
    }

    // _edit_chat_invite_link_post_request->member_limit
    cJSON *member_limit = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "member_limit");
    if (cJSON_IsNull(member_limit)) {
        member_limit = NULL;
    }
    if (member_limit) { 
    if(!cJSON_IsNumber(member_limit))
    {
    goto end; //Numeric
    }
    }

    // _edit_chat_invite_link_post_request->creates_join_request
    cJSON *creates_join_request = cJSON_GetObjectItemCaseSensitive(_edit_chat_invite_link_post_requestJSON, "creates_join_request");
    if (cJSON_IsNull(creates_join_request)) {
        creates_join_request = NULL;
    }
    if (creates_join_request) { 
    if(!cJSON_IsBool(creates_join_request))
    {
    goto end; //Bool
    }
    }


    _edit_chat_invite_link_post_request_local_var = _edit_chat_invite_link_post_request_create_internal (
        chat_id_local_nonprim,
        strdup(invite_link->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        expire_date ? expire_date->valuedouble : 0,
        member_limit ? member_limit->valuedouble : 0,
        creates_join_request ? creates_join_request->valueint : 0
        );

    return _edit_chat_invite_link_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
