#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_forum_topic_request.h"



static edit_forum_topic_request_t *edit_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id,
    char *name,
    char *icon_custom_emoji_id
    ) {
    edit_forum_topic_request_t *edit_forum_topic_request_local_var = malloc(sizeof(edit_forum_topic_request_t));
    if (!edit_forum_topic_request_local_var) {
        return NULL;
    }
    edit_forum_topic_request_local_var->chat_id = chat_id;
    edit_forum_topic_request_local_var->message_thread_id = message_thread_id;
    edit_forum_topic_request_local_var->name = name;
    edit_forum_topic_request_local_var->icon_custom_emoji_id = icon_custom_emoji_id;

    edit_forum_topic_request_local_var->_library_owned = 1;
    return edit_forum_topic_request_local_var;
}

__attribute__((deprecated)) edit_forum_topic_request_t *edit_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id,
    char *name,
    char *icon_custom_emoji_id
    ) {
    return edit_forum_topic_request_create_internal (
        chat_id,
        message_thread_id,
        name,
        icon_custom_emoji_id
        );
}

void edit_forum_topic_request_free(edit_forum_topic_request_t *edit_forum_topic_request) {
    if(NULL == edit_forum_topic_request){
        return ;
    }
    if(edit_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(edit_forum_topic_request->chat_id);
        edit_forum_topic_request->chat_id = NULL;
    }
    if (edit_forum_topic_request->name) {
        free(edit_forum_topic_request->name);
        edit_forum_topic_request->name = NULL;
    }
    if (edit_forum_topic_request->icon_custom_emoji_id) {
        free(edit_forum_topic_request->icon_custom_emoji_id);
        edit_forum_topic_request->icon_custom_emoji_id = NULL;
    }
    free(edit_forum_topic_request);
}

cJSON *edit_forum_topic_request_convertToJSON(edit_forum_topic_request_t *edit_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_forum_topic_request->chat_id
    if (!edit_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(edit_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // edit_forum_topic_request->message_thread_id
    if (!edit_forum_topic_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", edit_forum_topic_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }


    // edit_forum_topic_request->name
    if(edit_forum_topic_request->name) {
    if(cJSON_AddStringToObject(item, "name", edit_forum_topic_request->name) == NULL) {
    goto fail; //String
    }
    }


    // edit_forum_topic_request->icon_custom_emoji_id
    if(edit_forum_topic_request->icon_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "icon_custom_emoji_id", edit_forum_topic_request->icon_custom_emoji_id) == NULL) {
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

edit_forum_topic_request_t *edit_forum_topic_request_parseFromJSON(cJSON *edit_forum_topic_requestJSON){

    edit_forum_topic_request_t *edit_forum_topic_request_local_var = NULL;

    // define the local variable for edit_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // edit_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // edit_forum_topic_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_requestJSON, "message_thread_id");
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

    // edit_forum_topic_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // edit_forum_topic_request->icon_custom_emoji_id
    cJSON *icon_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(edit_forum_topic_requestJSON, "icon_custom_emoji_id");
    if (cJSON_IsNull(icon_custom_emoji_id)) {
        icon_custom_emoji_id = NULL;
    }
    if (icon_custom_emoji_id) { 
    if(!cJSON_IsString(icon_custom_emoji_id) && !cJSON_IsNull(icon_custom_emoji_id))
    {
    goto end; //String
    }
    }


    edit_forum_topic_request_local_var = edit_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        icon_custom_emoji_id && !cJSON_IsNull(icon_custom_emoji_id) ? strdup(icon_custom_emoji_id->valuestring) : NULL
        );

    return edit_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
