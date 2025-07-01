#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_chat_action_post_request.h"


char* _send_chat_action_post_request_action_ToString(telegram_bot_api__send_chat_action_post_request_ACTION_e action) {
    char* actionArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    return actionArray[action];
}

telegram_bot_api__send_chat_action_post_request_ACTION_e _send_chat_action_post_request_action_FromString(char* action){
    int stringToReturn = 0;
    char *actionArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    size_t sizeofArray = sizeof(actionArray) / sizeof(actionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(action, actionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static _send_chat_action_post_request_t *_send_chat_action_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    telegram_bot_api__send_chat_action_post_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    _send_chat_action_post_request_t *_send_chat_action_post_request_local_var = malloc(sizeof(_send_chat_action_post_request_t));
    if (!_send_chat_action_post_request_local_var) {
        return NULL;
    }
    _send_chat_action_post_request_local_var->chat_id = chat_id;
    _send_chat_action_post_request_local_var->action = action;
    _send_chat_action_post_request_local_var->business_connection_id = business_connection_id;
    _send_chat_action_post_request_local_var->message_thread_id = message_thread_id;

    _send_chat_action_post_request_local_var->_library_owned = 1;
    return _send_chat_action_post_request_local_var;
}

__attribute__((deprecated)) _send_chat_action_post_request_t *_send_chat_action_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    telegram_bot_api__send_chat_action_post_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    return _send_chat_action_post_request_create_internal (
        chat_id,
        action,
        business_connection_id,
        message_thread_id
        );
}

void _send_chat_action_post_request_free(_send_chat_action_post_request_t *_send_chat_action_post_request) {
    if(NULL == _send_chat_action_post_request){
        return ;
    }
    if(_send_chat_action_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_chat_action_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_chat_action_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_send_chat_action_post_request->chat_id);
        _send_chat_action_post_request->chat_id = NULL;
    }
    if (_send_chat_action_post_request->business_connection_id) {
        free(_send_chat_action_post_request->business_connection_id);
        _send_chat_action_post_request->business_connection_id = NULL;
    }
    free(_send_chat_action_post_request);
}

cJSON *_send_chat_action_post_request_convertToJSON(_send_chat_action_post_request_t *_send_chat_action_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _send_chat_action_post_request->chat_id
    if (!_send_chat_action_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_send_chat_action_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _send_chat_action_post_request->action
    if (telegram_bot_api__send_chat_action_post_request_ACTION_NULL == _send_chat_action_post_request->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", _send_chat_action_post_request_action_ToString(_send_chat_action_post_request->action)) == NULL)
    {
    goto fail; //Enum
    }


    // _send_chat_action_post_request->business_connection_id
    if(_send_chat_action_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _send_chat_action_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_chat_action_post_request->message_thread_id
    if(_send_chat_action_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _send_chat_action_post_request->message_thread_id) == NULL) {
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

_send_chat_action_post_request_t *_send_chat_action_post_request_parseFromJSON(cJSON *_send_chat_action_post_requestJSON){

    _send_chat_action_post_request_t *_send_chat_action_post_request_local_var = NULL;

    // define the local variable for _send_chat_action_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _send_chat_action_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_send_chat_action_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _send_chat_action_post_request->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(_send_chat_action_post_requestJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    telegram_bot_api__send_chat_action_post_request_ACTION_e actionVariable;
    
    if(!cJSON_IsString(action))
    {
    goto end; //Enum
    }
    actionVariable = _send_chat_action_post_request_action_FromString(action->valuestring);

    // _send_chat_action_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_send_chat_action_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _send_chat_action_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_send_chat_action_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }


    _send_chat_action_post_request_local_var = _send_chat_action_post_request_create_internal (
        chat_id_local_nonprim,
        actionVariable,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0
        );

    return _send_chat_action_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
