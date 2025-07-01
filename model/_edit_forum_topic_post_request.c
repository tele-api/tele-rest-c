#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_forum_topic_post_request.h"



static _edit_forum_topic_post_request_t *_edit_forum_topic_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int message_thread_id,
    char *name,
    char *icon_custom_emoji_id
    ) {
    _edit_forum_topic_post_request_t *_edit_forum_topic_post_request_local_var = malloc(sizeof(_edit_forum_topic_post_request_t));
    if (!_edit_forum_topic_post_request_local_var) {
        return NULL;
    }
    _edit_forum_topic_post_request_local_var->chat_id = chat_id;
    _edit_forum_topic_post_request_local_var->message_thread_id = message_thread_id;
    _edit_forum_topic_post_request_local_var->name = name;
    _edit_forum_topic_post_request_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    _edit_forum_topic_post_request_local_var->_library_owned = 1;
    return _edit_forum_topic_post_request_local_var;
}

__attribute__((deprecated)) _edit_forum_topic_post_request_t *_edit_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int message_thread_id,
    char *name,
    char *icon_custom_emoji_id
    ) {
    return _edit_forum_topic_post_request_create_internal (
        chat_id,
        message_thread_id,
        name,
        icon_custom_emoji_id
        );
}

void _edit_forum_topic_post_request_free(_edit_forum_topic_post_request_t *_edit_forum_topic_post_request) {
    if(NULL == _edit_forum_topic_post_request){
        return ;
    }
    if(_edit_forum_topic_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_forum_topic_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_forum_topic_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_edit_forum_topic_post_request->chat_id);
        _edit_forum_topic_post_request->chat_id = NULL;
    }
    if (_edit_forum_topic_post_request->name) {
        free(_edit_forum_topic_post_request->name);
        _edit_forum_topic_post_request->name = NULL;
    }
    if (_edit_forum_topic_post_request->icon_custom_emoji_id) {
        free(_edit_forum_topic_post_request->icon_custom_emoji_id);
        _edit_forum_topic_post_request->icon_custom_emoji_id = NULL;
    }
    free(_edit_forum_topic_post_request);
}

cJSON *_edit_forum_topic_post_request_convertToJSON(_edit_forum_topic_post_request_t *_edit_forum_topic_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _edit_forum_topic_post_request->chat_id
    if (!_edit_forum_topic_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_edit_forum_topic_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _edit_forum_topic_post_request->message_thread_id
    if (!_edit_forum_topic_post_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", _edit_forum_topic_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }


    // _edit_forum_topic_post_request->name
    if(_edit_forum_topic_post_request->name) {
    if(cJSON_AddStringToObject(item, "name", _edit_forum_topic_post_request->name) == NULL) {
    goto fail; //String
    }
    }


    // _edit_forum_topic_post_request->icon_custom_emoji_id
    if(_edit_forum_topic_post_request->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", _edit_forum_topic_post_request->icon_custom_emoji_id) == NULL) {
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

_edit_forum_topic_post_request_t *_edit_forum_topic_post_request_parseFromJSON(cJSON *_edit_forum_topic_post_requestJSON){

    _edit_forum_topic_post_request_t *_edit_forum_topic_post_request_local_var = NULL;

    // define the local variable for _edit_forum_topic_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _edit_forum_topic_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_edit_forum_topic_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _edit_forum_topic_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_edit_forum_topic_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (!message_thread_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }

    // _edit_forum_topic_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_edit_forum_topic_post_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // _edit_forum_topic_post_request->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(_edit_forum_topic_post_requestJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    _edit_forum_topic_post_request_local_var = _edit_forum_topic_post_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return _edit_forum_topic_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _restrict_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
