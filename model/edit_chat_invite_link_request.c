#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_chat_invite_link_request.h"



static edit_chat_invite_link_request_t *edit_chat_invite_link_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    edit_chat_invite_link_request_t *edit_chat_invite_link_request_local_var = malloc(sizeof(edit_chat_invite_link_request_t));
    if (!edit_chat_invite_link_request_local_var) {
        return NULL;
    }
    edit_chat_invite_link_request_local_var->chat_id = chat_id;
    edit_chat_invite_link_request_local_var->invite_link = invite_link;
    edit_chat_invite_link_request_local_var->name = name;
    edit_chat_invite_link_request_local_var->expire_date = expire_date;
    edit_chat_invite_link_request_local_var->member_limit = member_limit;
    edit_chat_invite_link_request_local_var->creates_join_request = creates_join_request;

    edit_chat_invite_link_request_local_var->_library_owned = 1;
    return edit_chat_invite_link_request_local_var;
}

__attribute__((deprecated)) edit_chat_invite_link_request_t *edit_chat_invite_link_request_create(
    send_message_request_chat_id_t *chat_id,
    char *invite_link,
    char *name,
    int expire_date,
    int member_limit,
    int creates_join_request
    ) {
    return edit_chat_invite_link_request_create_internal (
        chat_id,
        invite_link,
        name,
        expire_date,
        member_limit,
        creates_join_request
        );
}

void edit_chat_invite_link_request_free(edit_chat_invite_link_request_t *edit_chat_invite_link_request) {
    if(NULL == edit_chat_invite_link_request){
        return ;
    }
    if(edit_chat_invite_link_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_chat_invite_link_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_chat_invite_link_request->chat_id) {
        send_message_request_chat_id_free(edit_chat_invite_link_request->chat_id);
        edit_chat_invite_link_request->chat_id = NULL;
    }
    if (edit_chat_invite_link_request->invite_link) {
        free(edit_chat_invite_link_request->invite_link);
        edit_chat_invite_link_request->invite_link = NULL;
    }
    if (edit_chat_invite_link_request->name) {
        free(edit_chat_invite_link_request->name);
        edit_chat_invite_link_request->name = NULL;
    }
    free(edit_chat_invite_link_request);
}

cJSON *edit_chat_invite_link_request_convertToJSON(edit_chat_invite_link_request_t *edit_chat_invite_link_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_chat_invite_link_request->chat_id
    if (!edit_chat_invite_link_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(edit_chat_invite_link_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // edit_chat_invite_link_request->invite_link
    if (!edit_chat_invite_link_request->invite_link) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "invite_link", edit_chat_invite_link_request->invite_link) == NULL) {
    goto fail; //String
    }


    // edit_chat_invite_link_request->name
    if(edit_chat_invite_link_request->name) {
    if(cJSON_AddStringToObject(item, "name", edit_chat_invite_link_request->name) == NULL) {
    goto fail; //String
    }
    }


    // edit_chat_invite_link_request->expire_date
    if(edit_chat_invite_link_request->expire_date) {
    if(cJSON_AddNumberToObject(item, "expire_date", edit_chat_invite_link_request->expire_date) == NULL) {
    goto fail; //Numeric
    }
    }


    // edit_chat_invite_link_request->member_limit
    if(edit_chat_invite_link_request->member_limit) {
    if(cJSON_AddNumberToObject(item, "member_limit", edit_chat_invite_link_request->member_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // edit_chat_invite_link_request->creates_join_request
    if(edit_chat_invite_link_request->creates_join_request) {
    if(cJSON_AddBoolToObject(item, "creates_join_request", edit_chat_invite_link_request->creates_join_request) == NULL) {
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

edit_chat_invite_link_request_t *edit_chat_invite_link_request_parseFromJSON(cJSON *edit_chat_invite_link_requestJSON){

    edit_chat_invite_link_request_t *edit_chat_invite_link_request_local_var = NULL;

    // define the local variable for edit_chat_invite_link_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // edit_chat_invite_link_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // edit_chat_invite_link_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (!invite_link) {
        goto end;
    }

    
    if(!cJSON_IsString(invite_link))
    {
    goto end; //String
    }

    // edit_chat_invite_link_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // edit_chat_invite_link_request->expire_date
    cJSON *expire_date = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "expire_date");
    if (cJSON_IsNull(expire_date)) {
        expire_date = NULL;
    }
    if (expire_date) { 
    if(!cJSON_IsNumber(expire_date))
    {
    goto end; //Numeric
    }
    }

    // edit_chat_invite_link_request->member_limit
    cJSON *member_limit = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "member_limit");
    if (cJSON_IsNull(member_limit)) {
        member_limit = NULL;
    }
    if (member_limit) { 
    if(!cJSON_IsNumber(member_limit))
    {
    goto end; //Numeric
    }
    }

    // edit_chat_invite_link_request->creates_join_request
    cJSON *creates_join_request = cJSON_GetObjectItemCaseSensitive(edit_chat_invite_link_requestJSON, "creates_join_request");
    if (cJSON_IsNull(creates_join_request)) {
        creates_join_request = NULL;
    }
    if (creates_join_request) { 
    if(!cJSON_IsBool(creates_join_request))
    {
    goto end; //Bool
    }
    }


    edit_chat_invite_link_request_local_var = edit_chat_invite_link_request_create_internal (
        chat_id_local_nonprim,
        strdup(invite_link->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        expire_date ? expire_date->valuedouble : 0,
        member_limit ? member_limit->valuedouble : 0,
        creates_join_request ? creates_join_request->valueint : 0
        );

    return edit_chat_invite_link_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
