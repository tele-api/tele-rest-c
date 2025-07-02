#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "close_general_forum_topic_request.h"



static close_general_forum_topic_request_t *close_general_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    close_general_forum_topic_request_t *close_general_forum_topic_request_local_var = malloc(sizeof(close_general_forum_topic_request_t));
    if (!close_general_forum_topic_request_local_var) {
        return NULL;
    }
    close_general_forum_topic_request_local_var->chat_id = chat_id;

    close_general_forum_topic_request_local_var->_library_owned = 1;
    return close_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) close_general_forum_topic_request_t *close_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return close_general_forum_topic_request_create_internal (
        chat_id
        );
}

void close_general_forum_topic_request_free(close_general_forum_topic_request_t *close_general_forum_topic_request) {
    if(NULL == close_general_forum_topic_request){
        return ;
    }
    if(close_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "close_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (close_general_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(close_general_forum_topic_request->chat_id);
        close_general_forum_topic_request->chat_id = NULL;
    }
    free(close_general_forum_topic_request);
}

cJSON *close_general_forum_topic_request_convertToJSON(close_general_forum_topic_request_t *close_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // close_general_forum_topic_request->chat_id
    if (!close_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(close_general_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

close_general_forum_topic_request_t *close_general_forum_topic_request_parseFromJSON(cJSON *close_general_forum_topic_requestJSON){

    close_general_forum_topic_request_t *close_general_forum_topic_request_local_var = NULL;

    // define the local variable for close_general_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // close_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(close_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    close_general_forum_topic_request_local_var = close_general_forum_topic_request_create_internal (
        chat_id_local_nonprim
        );

    return close_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
