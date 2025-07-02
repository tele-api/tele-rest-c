#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_forum_topic_request.h"



static delete_forum_topic_request_t *delete_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    delete_forum_topic_request_t *delete_forum_topic_request_local_var = malloc(sizeof(delete_forum_topic_request_t));
    if (!delete_forum_topic_request_local_var) {
        return NULL;
    }
    delete_forum_topic_request_local_var->chat_id = chat_id;
    delete_forum_topic_request_local_var->message_thread_id = message_thread_id;

    delete_forum_topic_request_local_var->_library_owned = 1;
    return delete_forum_topic_request_local_var;
}

__attribute__((deprecated)) delete_forum_topic_request_t *delete_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    return delete_forum_topic_request_create_internal (
        chat_id,
        message_thread_id
        );
}

void delete_forum_topic_request_free(delete_forum_topic_request_t *delete_forum_topic_request) {
    if(NULL == delete_forum_topic_request){
        return ;
    }
    if(delete_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(delete_forum_topic_request->chat_id);
        delete_forum_topic_request->chat_id = NULL;
    }
    free(delete_forum_topic_request);
}

cJSON *delete_forum_topic_request_convertToJSON(delete_forum_topic_request_t *delete_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_forum_topic_request->chat_id
    if (!delete_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(delete_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // delete_forum_topic_request->message_thread_id
    if (!delete_forum_topic_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", delete_forum_topic_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_forum_topic_request_t *delete_forum_topic_request_parseFromJSON(cJSON *delete_forum_topic_requestJSON){

    delete_forum_topic_request_t *delete_forum_topic_request_local_var = NULL;

    // define the local variable for delete_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // delete_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(delete_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // delete_forum_topic_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(delete_forum_topic_requestJSON, "message_thread_id");
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


    delete_forum_topic_request_local_var = delete_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble
        );

    return delete_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
