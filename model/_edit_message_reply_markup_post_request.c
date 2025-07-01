#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_message_reply_markup_post_request.h"



static _edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request_create_internal(
    char *business_connection_id,
    _edit_message_text_post_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    inline_keyboard_markup_t *reply_markup
    ) {
    _edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request_local_var = malloc(sizeof(_edit_message_reply_markup_post_request_t));
    if (!_edit_message_reply_markup_post_request_local_var) {
        return NULL;
    }
    _edit_message_reply_markup_post_request_local_var->business_connection_id = business_connection_id;
    _edit_message_reply_markup_post_request_local_var->chat_id = chat_id;
    _edit_message_reply_markup_post_request_local_var->message_id = message_id;
    _edit_message_reply_markup_post_request_local_var->inline_message_id = inline_message_id;
    _edit_message_reply_markup_post_request_local_var->reply_markup = reply_markup;

    _edit_message_reply_markup_post_request_local_var->_library_owned = 1;
    return _edit_message_reply_markup_post_request_local_var;
}

__attribute__((deprecated)) _edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request_create(
    char *business_connection_id,
    _edit_message_text_post_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    inline_keyboard_markup_t *reply_markup
    ) {
    return _edit_message_reply_markup_post_request_create_internal (
        business_connection_id,
        chat_id,
        message_id,
        inline_message_id,
        reply_markup
        );
}

void _edit_message_reply_markup_post_request_free(_edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request) {
    if(NULL == _edit_message_reply_markup_post_request){
        return ;
    }
    if(_edit_message_reply_markup_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_message_reply_markup_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_message_reply_markup_post_request->business_connection_id) {
        free(_edit_message_reply_markup_post_request->business_connection_id);
        _edit_message_reply_markup_post_request->business_connection_id = NULL;
    }
    if (_edit_message_reply_markup_post_request->chat_id) {
        _edit_message_text_post_request_chat_id_free(_edit_message_reply_markup_post_request->chat_id);
        _edit_message_reply_markup_post_request->chat_id = NULL;
    }
    if (_edit_message_reply_markup_post_request->inline_message_id) {
        free(_edit_message_reply_markup_post_request->inline_message_id);
        _edit_message_reply_markup_post_request->inline_message_id = NULL;
    }
    if (_edit_message_reply_markup_post_request->reply_markup) {
        inline_keyboard_markup_free(_edit_message_reply_markup_post_request->reply_markup);
        _edit_message_reply_markup_post_request->reply_markup = NULL;
    }
    free(_edit_message_reply_markup_post_request);
}

cJSON *_edit_message_reply_markup_post_request_convertToJSON(_edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _edit_message_reply_markup_post_request->business_connection_id
    if(_edit_message_reply_markup_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _edit_message_reply_markup_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_reply_markup_post_request->chat_id
    if(_edit_message_reply_markup_post_request->chat_id) {
    cJSON *chat_id_local_JSON = _edit_message_text_post_request_chat_id_convertToJSON(_edit_message_reply_markup_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_reply_markup_post_request->message_id
    if(_edit_message_reply_markup_post_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", _edit_message_reply_markup_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_reply_markup_post_request->inline_message_id
    if(_edit_message_reply_markup_post_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", _edit_message_reply_markup_post_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_reply_markup_post_request->reply_markup
    if(_edit_message_reply_markup_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(_edit_message_reply_markup_post_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
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

_edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request_parseFromJSON(cJSON *_edit_message_reply_markup_post_requestJSON){

    _edit_message_reply_markup_post_request_t *_edit_message_reply_markup_post_request_local_var = NULL;

    // define the local variable for _edit_message_reply_markup_post_request->chat_id
    _edit_message_text_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _edit_message_reply_markup_post_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // _edit_message_reply_markup_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_edit_message_reply_markup_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _edit_message_reply_markup_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_edit_message_reply_markup_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = _edit_message_text_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // _edit_message_reply_markup_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_edit_message_reply_markup_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_reply_markup_post_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(_edit_message_reply_markup_post_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // _edit_message_reply_markup_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_edit_message_reply_markup_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _edit_message_reply_markup_post_request_local_var = _edit_message_reply_markup_post_request_create_internal (
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        chat_id ? chat_id_local_nonprim : NULL,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return _edit_message_reply_markup_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _edit_message_text_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
