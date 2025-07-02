#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_edit_general_forum_topic_request.h"



static post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *name
    ) {
    post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request_local_var = malloc(sizeof(post_edit_general_forum_topic_request_t));
    if (!post_edit_general_forum_topic_request_local_var) {
        return NULL;
    }
    post_edit_general_forum_topic_request_local_var->chat_id = chat_id;
    post_edit_general_forum_topic_request_local_var->name = name;

    post_edit_general_forum_topic_request_local_var->_library_owned = 1;
    return post_edit_general_forum_topic_request_local_var;
}

__attribute__((deprecated)) post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    char *name
    ) {
    return post_edit_general_forum_topic_request_create_internal (
        chat_id,
        name
        );
}

void post_edit_general_forum_topic_request_free(post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request) {
    if(NULL == post_edit_general_forum_topic_request){
        return ;
    }
    if(post_edit_general_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_edit_general_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_edit_general_forum_topic_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_edit_general_forum_topic_request->chat_id);
        post_edit_general_forum_topic_request->chat_id = NULL;
    }
    if (post_edit_general_forum_topic_request->name) {
        free(post_edit_general_forum_topic_request->name);
        post_edit_general_forum_topic_request->name = NULL;
    }
    free(post_edit_general_forum_topic_request);
}

cJSON *post_edit_general_forum_topic_request_convertToJSON(post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // post_edit_general_forum_topic_request->chat_id
    if (!post_edit_general_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_edit_general_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_edit_general_forum_topic_request->name
    if (!post_edit_general_forum_topic_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", post_edit_general_forum_topic_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request_parseFromJSON(cJSON *post_edit_general_forum_topic_requestJSON){

    post_edit_general_forum_topic_request_t *post_edit_general_forum_topic_request_local_var = NULL;

    // define the local variable for post_edit_general_forum_topic_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_edit_general_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_edit_general_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_edit_general_forum_topic_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_edit_general_forum_topic_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    post_edit_general_forum_topic_request_local_var = post_edit_general_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        strdup(name->valuestring)
        );

    return post_edit_general_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
