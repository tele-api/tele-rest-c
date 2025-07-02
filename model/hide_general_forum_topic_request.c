#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hide_general_forum_topic_request.h"



static hide_general_forum_topic_request_t *hide_general_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    hide_general_forum_topic_request_t *hide_general_forum_topic_request_local_var = malloc(sizeof(hide_general_forum_topic_request_t));
    if (!hide_general_forum_topic_request_local_var) {
        return NULL;
    }
    hide_general_forum_topic_request_local_var->chat_id = chat_id;

    hide_general_forum_topic_request_local_var->_library_owned = 1;
    return hide_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) hide_general_forum_topic_request_t *hide_general_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id
    ) {
    return hide_general_forum_topic_request_create_internal (
        chat_id
        );
}

void hide_general_forum_topic_request_free(hide_general_forum_topic_request_t *hide_general_forum_topic_request) {
    if(NULL == hide_general_forum_topic_request){
        return ;
    }
    if(hide_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hide_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hide_general_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(hide_general_forum_topic_request->chat_id);
        hide_general_forum_topic_request->chat_id = NULL;
    }
    free(hide_general_forum_topic_request);
}

cJSON *hide_general_forum_topic_request_convertToJSON(hide_general_forum_topic_request_t *hide_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // hide_general_forum_topic_request->chat_id
    if (!hide_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(hide_general_forum_topic_request->chat_id);
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

hide_general_forum_topic_request_t *hide_general_forum_topic_request_parseFromJSON(cJSON *hide_general_forum_topic_requestJSON){

    hide_general_forum_topic_request_t *hide_general_forum_topic_request_local_var = NULL;

    // define the local variable for hide_general_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // hide_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(hide_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive


    hide_general_forum_topic_request_local_var = hide_general_forum_topic_request_create_internal (
        chat_id_local_nonprim
        );

    return hide_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
