#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_chat_action_request.h"


char* post_send_chat_action_request_action_ToString(telegram_bot_api_post_send_chat_action_request_ACTION_e action) {
    char* actionArray[] =  { "NULL", "typing", "upload_photo", "record_video", "upload_video", "record_voice", "upload_voice", "upload_document", "choose_sticker", "find_location", "record_video_note", "upload_video_note" };
    return actionArray[action];
}

telegram_bot_api_post_send_chat_action_request_ACTION_e post_send_chat_action_request_action_FromString(char* action){
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

static post_send_chat_action_request_t *post_send_chat_action_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    telegram_bot_api_post_send_chat_action_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    post_send_chat_action_request_t *post_send_chat_action_request_local_var = malloc(sizeof(post_send_chat_action_request_t));
    if (!post_send_chat_action_request_local_var) {
        return NULL;
    }
    post_send_chat_action_request_local_var->chat_id = chat_id;
    post_send_chat_action_request_local_var->action = action;
    post_send_chat_action_request_local_var->business_connection_id = business_connection_id;
    post_send_chat_action_request_local_var->message_thread_id = message_thread_id;

    post_send_chat_action_request_local_var->_library_owned = 1;
    return post_send_chat_action_request_local_var;
}

__attribute__((deprecated)) post_send_chat_action_request_t *post_send_chat_action_request_create(
    post_send_message_request_chat_id_t *chat_id,
    telegram_bot_api_post_send_chat_action_request_ACTION_e action,
    char *business_connection_id,
    int message_thread_id
    ) {
    return post_send_chat_action_request_create_internal (
        chat_id,
        action,
        business_connection_id,
        message_thread_id
        );
}

void post_send_chat_action_request_free(post_send_chat_action_request_t *post_send_chat_action_request) {
    if(NULL == post_send_chat_action_request){
        return ;
    }
    if(post_send_chat_action_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_chat_action_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_send_chat_action_request->chat_id) {
        post_send_message_request_chat_id_free(post_send_chat_action_request->chat_id);
        post_send_chat_action_request->chat_id = NULL;
    }
    if (post_send_chat_action_request->business_connection_id) {
        free(post_send_chat_action_request->business_connection_id);
        post_send_chat_action_request->business_connection_id = NULL;
    }
    free(post_send_chat_action_request);
}

cJSON *post_send_chat_action_request_convertToJSON(post_send_chat_action_request_t *post_send_chat_action_request) {
    cJSON *item = cJSON_CreateObject();

    // post_send_chat_action_request->chat_id
    if (!post_send_chat_action_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_send_chat_action_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_send_chat_action_request->action
    if (telegram_bot_api_post_send_chat_action_request_ACTION_NULL == post_send_chat_action_request->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", post_send_chat_action_request_action_ToString(post_send_chat_action_request->action)) == NULL)
    {
    goto fail; //Enum
    }


    // post_send_chat_action_request->business_connection_id
    if(post_send_chat_action_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_send_chat_action_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_chat_action_request->message_thread_id
    if(post_send_chat_action_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_send_chat_action_request->message_thread_id) == NULL) {
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

post_send_chat_action_request_t *post_send_chat_action_request_parseFromJSON(cJSON *post_send_chat_action_requestJSON){

    post_send_chat_action_request_t *post_send_chat_action_request_local_var = NULL;

    // define the local variable for post_send_chat_action_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_send_chat_action_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_send_chat_action_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_send_chat_action_request->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(post_send_chat_action_requestJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    telegram_bot_api_post_send_chat_action_request_ACTION_e actionVariable;
    
    if(!cJSON_IsString(action))
    {
    goto end; //Enum
    }
    actionVariable = post_send_chat_action_request_action_FromString(action->valuestring);

    // post_send_chat_action_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_send_chat_action_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_send_chat_action_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_send_chat_action_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }


    post_send_chat_action_request_local_var = post_send_chat_action_request_create_internal (
        chat_id_local_nonprim,
        actionVariable,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0
        );

    return post_send_chat_action_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
