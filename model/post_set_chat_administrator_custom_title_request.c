#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_chat_administrator_custom_title_request.h"



static post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_local_var = malloc(sizeof(post_set_chat_administrator_custom_title_request_t));
    if (!post_set_chat_administrator_custom_title_request_local_var) {
        return NULL;
    }
    post_set_chat_administrator_custom_title_request_local_var->chat_id = chat_id;
    post_set_chat_administrator_custom_title_request_local_var->user_id = user_id;
    post_set_chat_administrator_custom_title_request_local_var->custom_title = custom_title;

    post_set_chat_administrator_custom_title_request_local_var->_library_owned = 1;
    return post_set_chat_administrator_custom_title_request_local_var;
}

__attribute__((deprecated)) post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int user_id,
    char *custom_title
    ) {
    return post_set_chat_administrator_custom_title_request_create_internal (
        chat_id,
        user_id,
        custom_title
        );
}

void post_set_chat_administrator_custom_title_request_free(post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request) {
    if(NULL == post_set_chat_administrator_custom_title_request){
        return ;
    }
    if(post_set_chat_administrator_custom_title_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_chat_administrator_custom_title_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_chat_administrator_custom_title_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_set_chat_administrator_custom_title_request->chat_id);
        post_set_chat_administrator_custom_title_request->chat_id = NULL;
    }
    if (post_set_chat_administrator_custom_title_request->custom_title) {
        free(post_set_chat_administrator_custom_title_request->custom_title);
        post_set_chat_administrator_custom_title_request->custom_title = NULL;
    }
    free(post_set_chat_administrator_custom_title_request);
}

cJSON *post_set_chat_administrator_custom_title_request_convertToJSON(post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_chat_administrator_custom_title_request->chat_id
    if (!post_set_chat_administrator_custom_title_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_set_chat_administrator_custom_title_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_chat_administrator_custom_title_request->user_id
    if (!post_set_chat_administrator_custom_title_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_set_chat_administrator_custom_title_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_set_chat_administrator_custom_title_request->custom_title
    if (!post_set_chat_administrator_custom_title_request->custom_title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "custom_title", post_set_chat_administrator_custom_title_request->custom_title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_parseFromJSON(cJSON *post_set_chat_administrator_custom_title_requestJSON){

    post_set_chat_administrator_custom_title_request_t *post_set_chat_administrator_custom_title_request_local_var = NULL;

    // define the local variable for post_set_chat_administrator_custom_title_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_set_chat_administrator_custom_title_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_administrator_custom_title_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_set_chat_administrator_custom_title_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_set_chat_administrator_custom_title_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // post_set_chat_administrator_custom_title_request->custom_title
    cJSON *custom_title = cJSON_GetObjectItemCaseSensitive(post_set_chat_administrator_custom_title_requestJSON, "custom_title");
    if (cJSON_IsNull(custom_title)) {
        custom_title = NULL;
    }
    if (!custom_title) {
        goto end;
    }

    
    if(!cJSON_IsString(custom_title))
    {
    goto end; //String
    }


    post_set_chat_administrator_custom_title_request_local_var = post_set_chat_administrator_custom_title_request_create_internal (
        chat_id_local_nonprim,
        user_id->valuedouble,
        strdup(custom_title->valuestring)
        );

    return post_set_chat_administrator_custom_title_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
