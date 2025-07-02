#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_chat_action_request.h"


char* send_chat_action_request_action_ToString(telegram_bot_api_send_chat_action_request_ACTION_e action) {
    char* actionArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    return actionArray[action];
}

telegram_bot_api_send_chat_action_request_ACTION_e send_chat_action_request_action_FromString(char* action){
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

static send_chat_action_request_t *send_chat_action_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    telegram_bot_api_send_chat_action_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    send_chat_action_request_t *send_chat_action_request_local_var = malloc(sizeof(send_chat_action_request_t));
    if (!send_chat_action_request_local_var) {
        return NULL;
    }
    send_chat_action_request_local_var->chat_id = chat_id;
    send_chat_action_request_local_var->action = action;
    send_chat_action_request_local_var->business_connection_id = business_connection_id;
    send_chat_action_request_local_var->message_thread_id = message_thread_id;

    send_chat_action_request_local_var->_library_owned = 1;
    return send_chat_action_request_local_var;
}

__attribute__((deprecated)) send_chat_action_request_t *send_chat_action_request_create(
    send_message_request_chat_id_t *chat_id,
    telegram_bot_api_send_chat_action_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    return send_chat_action_request_create_internal (
        chat_id,
        action,
        business_connection_id,
        message_thread_id
        );
}

void send_chat_action_request_free(send_chat_action_request_t *send_chat_action_request) {
    if(NULL == send_chat_action_request){
        return ;
    }
    if(send_chat_action_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_chat_action_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_chat_action_request->chat_id) {
        send_message_request_chat_id_free(send_chat_action_request->chat_id);
        send_chat_action_request->chat_id = NULL;
    }
    if (send_chat_action_request->business_connection_id) {
        free(send_chat_action_request->business_connection_id);
        send_chat_action_request->business_connection_id = NULL;
    }
    free(send_chat_action_request);
}

cJSON *send_chat_action_request_convertToJSON(send_chat_action_request_t *send_chat_action_request) {
    cJSON *item = cJSON_CreateObject();

    // send_chat_action_request->chat_id
    if (!send_chat_action_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_chat_action_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_chat_action_request->action
    if (telegram_bot_api_send_chat_action_request_ACTION_NULL == send_chat_action_request->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", send_chat_action_request_action_ToString(send_chat_action_request->action)) == NULL)
    {
    goto fail; //Enum
    }


    // send_chat_action_request->business_connection_id
    if(send_chat_action_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_chat_action_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_chat_action_request->message_thread_id
    if(send_chat_action_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_chat_action_request->message_thread_id) == NULL) {
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

send_chat_action_request_t *send_chat_action_request_parseFromJSON(cJSON *send_chat_action_requestJSON){

    send_chat_action_request_t *send_chat_action_request_local_var = NULL;

    // define the local variable for send_chat_action_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // send_chat_action_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_chat_action_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_chat_action_request->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(send_chat_action_requestJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    telegram_bot_api_send_chat_action_request_ACTION_e actionVariable;
    
    if(!cJSON_IsString(action))
    {
    goto end; //Enum
    }
    actionVariable = send_chat_action_request_action_FromString(action->valuestring);

    // send_chat_action_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_chat_action_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_chat_action_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_chat_action_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }


    send_chat_action_request_local_var = send_chat_action_request_create_internal (
        chat_id_local_nonprim,
        actionVariable,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0
        );

    return send_chat_action_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
