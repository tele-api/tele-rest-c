#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_create_chat_invite_link_request.h"



static post_create_chat_invite_link_request_t *post_create_chat_invite_link_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    post_create_chat_invite_link_request_t *post_create_chat_invite_link_request_local_var = malloc(sizeof(post_create_chat_invite_link_request_t));
    if (!post_create_chat_invite_link_request_local_var) {
        return NULL;
    }
    post_create_chat_invite_link_request_local_var->chat_id = chat_id;
    post_create_chat_invite_link_request_local_var->name = name;
    post_create_chat_invite_link_request_local_var->expire_date = expire_date;
    post_create_chat_invite_link_request_local_var->member_limit = member_limit;
    post_create_chat_invite_link_request_local_var->creates_join_request = creates_join_request;

    post_create_chat_invite_link_request_local_var->_library_owned = 1;
    return post_create_chat_invite_link_request_local_var;
}

__attribute__((deprecated)) post_create_chat_invite_link_request_t *post_create_chat_invite_link_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    return post_create_chat_invite_link_request_create_internal (
        chat_id,
        name,
        expire_date,
        member_limit,
        creates_join_request
        );
}

void post_create_chat_invite_link_request_free(post_create_chat_invite_link_request_t *post_create_chat_invite_link_request) {
    if(NULL == post_create_chat_invite_link_request){
        return ;
    }
    if(post_create_chat_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_create_chat_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_create_chat_invite_link_request->chat_id) {
        post_send_message_request_chat_id_free(post_create_chat_invite_link_request->chat_id);
        post_create_chat_invite_link_request->chat_id = NULL;
    }
    if (post_create_chat_invite_link_request->name) {
        free(post_create_chat_invite_link_request->name);
        post_create_chat_invite_link_request->name = NULL;
    }
    free(post_create_chat_invite_link_request);
}

cJSON *post_create_chat_invite_link_request_convertToJSON(post_create_chat_invite_link_request_t *post_create_chat_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // post_create_chat_invite_link_request->chat_id
    if (!post_create_chat_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_create_chat_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_create_chat_invite_link_request->name
    if(post_create_chat_invite_link_request->name) {
    if(cJSON_AddStringToObject(item, "name", post_create_chat_invite_link_request->name) == NULL) {
    goto fail; //String
    }
    }


    // post_create_chat_invite_link_request->expire_date
    if(post_create_chat_invite_link_request->expire_date) {
    if(cJSON_AddNumberToObject(item, "expire_date", post_create_chat_invite_link_request->expire_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_create_chat_invite_link_request->member_limit
    if(post_create_chat_invite_link_request->member_limit) {
    if(cJSON_AddNumberToObject(item, "member_limit", post_create_chat_invite_link_request->member_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_create_chat_invite_link_request->creates_join_request
    if(post_create_chat_invite_link_request->creates_join_request) {
    if(cJSON_AddBoolToObject(item, "creates_join_request", post_create_chat_invite_link_request->creates_join_request) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_create_chat_invite_link_request_t *post_create_chat_invite_link_request_parseFromJSON(cJSON *post_create_chat_invite_link_requestJSON){

    post_create_chat_invite_link_request_t *post_create_chat_invite_link_request_local_var = NULL;

    // define the local variable for post_create_chat_invite_link_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_create_chat_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_create_chat_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_create_chat_invite_link_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_create_chat_invite_link_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // post_create_chat_invite_link_request->expire_date
    cJSON *expire_date = cJSON_GetObjectItemCaseSensitive(post_create_chat_invite_link_requestJSON, "expire_date");
    if (cJSON_IsNull(expire_date)) {
        expire_date = NULL;
    }
    if (expire_date) { 
    if(!cJSON_IsNumber(expire_date))
    {
    goto end; //Numeric
    }
    }

    // post_create_chat_invite_link_request->member_limit
    cJSON *member_limit = cJSON_GetObjectItemCaseSensitive(post_create_chat_invite_link_requestJSON, "member_limit");
    if (cJSON_IsNull(member_limit)) {
        member_limit = NULL;
    }
    if (member_limit) { 
    if(!cJSON_IsNumber(member_limit))
    {
    goto end; //Numeric
    }
    }

    // post_create_chat_invite_link_request->creates_join_request
    cJSON *creates_join_request = cJSON_GetObjectItemCaseSensitive(post_create_chat_invite_link_requestJSON, "creates_join_request");
    if (cJSON_IsNull(creates_join_request)) {
        creates_join_request = NULL;
    }
    if (creates_join_request) { 
    if(!cJSON_IsBool(creates_join_request))
    {
    goto end; //Bool
    }
    }


    post_create_chat_invite_link_request_local_var = post_create_chat_invite_link_request_create_internal (
        chat_id_local_nonprim,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        expire_date ? expire_date->valuedouble : 0,
        member_limit ? member_limit->valuedouble : 0,
        creates_join_request ? creates_join_request->valueint : 0
        );

    return post_create_chat_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
