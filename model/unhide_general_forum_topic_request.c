#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unhide_general_forum_topic_request.h"



static unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_local_var = malloc(sizeof(unhide_general_forum_topic_request_t));
    if (!unhide_general_forum_topic_request_local_var) {
        return NULL;
    }
    unhide_general_forum_topic_request_local_var->chat_id = chat_id;

    unhide_general_forum_topic_request_local_var->_library_owned = 1;
    return unhide_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return unhide_general_forum_topic_request_create_internal (
        chat_id
        );
}

void unhide_general_forum_topic_request_free(unhide_general_forum_topic_request_t *unhide_general_forum_topic_request) {
    if(NULL == unhide_general_forum_topic_request){
        return ;
    }
    if(unhide_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unhide_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unhide_general_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(unhide_general_forum_topic_request->chat_id);
        unhide_general_forum_topic_request->chat_id = NULL;
    }
    free(unhide_general_forum_topic_request);
}

cJSON *unhide_general_forum_topic_request_convertToJSON(unhide_general_forum_topic_request_t *unhide_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // unhide_general_forum_topic_request->chat_id
    if (!unhide_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(unhide_general_forum_topic_request->chat_id);
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

unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_parseFromJSON(cJSON *unhide_general_forum_topic_requestJSON){

    unhide_general_forum_topic_request_t *unhide_general_forum_topic_request_local_var = NULL;

    // define the local variable for unhide_general_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // unhide_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unhide_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    unhide_general_forum_topic_request_local_var = unhide_general_forum_topic_request_create_internal (
        chat_id_local_nonprim
        );

    return unhide_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
