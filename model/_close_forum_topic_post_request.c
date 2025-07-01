#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_close_forum_topic_post_request.h"



static _close_forum_topic_post_request_t *_close_forum_topic_post_request_create_internal(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int message_thread_id
    ) {
    _close_forum_topic_post_request_t *_close_forum_topic_post_request_local_var = malloc(sizeof(_close_forum_topic_post_request_t));
    if (!_close_forum_topic_post_request_local_var) {
        return NULL;
    }
    _close_forum_topic_post_request_local_var->chat_id = chat_id;
    _close_forum_topic_post_request_local_var->message_thread_id = message_thread_id;

    _close_forum_topic_post_request_local_var->_library_owned = 1;
    return _close_forum_topic_post_request_local_var;
}

__attribute__((deprecated)) _close_forum_topic_post_request_t *_close_forum_topic_post_request_create(
    _restrict_chat_member_post_request_chat_id_t *chat_id,
    int message_thread_id
    ) {
    return _close_forum_topic_post_request_create_internal (
        chat_id,
        message_thread_id
        );
}

void _close_forum_topic_post_request_free(_close_forum_topic_post_request_t *_close_forum_topic_post_request) {
    if(NULL == _close_forum_topic_post_request){
        return ;
    }
    if(_close_forum_topic_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_close_forum_topic_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_close_forum_topic_post_request->chat_id) {
        _restrict_chat_member_post_request_chat_id_free(_close_forum_topic_post_request->chat_id);
        _close_forum_topic_post_request->chat_id = NULL;
    }
    free(_close_forum_topic_post_request);
}

cJSON *_close_forum_topic_post_request_convertToJSON(_close_forum_topic_post_request_t *_close_forum_topic_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _close_forum_topic_post_request->chat_id
    if (!_close_forum_topic_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _restrict_chat_member_post_request_chat_id_convertToJSON(_close_forum_topic_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _close_forum_topic_post_request->message_thread_id
    if (!_close_forum_topic_post_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", _close_forum_topic_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_close_forum_topic_post_request_t *_close_forum_topic_post_request_parseFromJSON(cJSON *_close_forum_topic_post_requestJSON){

    _close_forum_topic_post_request_t *_close_forum_topic_post_request_local_var = NULL;

    // define the local variable for _close_forum_topic_post_request->chat_id
    _restrict_chat_member_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _close_forum_topic_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_close_forum_topic_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _restrict_chat_member_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _close_forum_topic_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_close_forum_topic_post_requestJSON, "message_thread_id");
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


    _close_forum_topic_post_request_local_var = _close_forum_topic_post_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble
        );

    return _close_forum_topic_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _restrict_chat_member_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
