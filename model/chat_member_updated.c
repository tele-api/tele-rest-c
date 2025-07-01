#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_member_updated.h"



static chat_member_updated_t *chat_member_updated_create_internal(
    chat_t *chat,
    user_t *from,
    int date,
    chat_member_t *old_chat_member,
    chat_member_t *new_chat_member,
    chat_invite_link_t *invite_link,
    int via_join_request,
    int via_chat_folder_invite_link
    ) {
    chat_member_updated_t *chat_member_updated_local_var = malloc(sizeof(chat_member_updated_t));
    if (!chat_member_updated_local_var) {
        return NULL;
    }
    chat_member_updated_local_var->chat = chat;
    chat_member_updated_local_var->from = from;
    chat_member_updated_local_var->date = date;
    chat_member_updated_local_var->old_chat_member = old_chat_member;
    chat_member_updated_local_var->new_chat_member = new_chat_member;
    chat_member_updated_local_var->invite_link = invite_link;
    chat_member_updated_local_var->via_join_request = via_join_request;
    chat_member_updated_local_var->via_chat_folder_invite_link = via_chat_folder_invite_link;

    chat_member_updated_local_var->_library_owned = 1;
    return chat_member_updated_local_var;
}

__attribute__((deprecated)) chat_member_updated_t *chat_member_updated_create(
    chat_t *chat,
    user_t *from,
    int date,
    chat_member_t *old_chat_member,
    chat_member_t *new_chat_member,
    chat_invite_link_t *invite_link,
    int via_join_request,
    int via_chat_folder_invite_link
    ) {
    return chat_member_updated_create_internal (
        chat,
        from,
        date,
        old_chat_member,
        new_chat_member,
        invite_link,
        via_join_request,
        via_chat_folder_invite_link
        );
}

void chat_member_updated_free(chat_member_updated_t *chat_member_updated) {
    if(NULL == chat_member_updated){
        return ;
    }
    if(chat_member_updated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_member_updated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_member_updated->chat) {
        chat_free(chat_member_updated->chat);
        chat_member_updated->chat = NULL;
    }
    if (chat_member_updated->from) {
        user_free(chat_member_updated->from);
        chat_member_updated->from = NULL;
    }
    if (chat_member_updated->old_chat_member) {
        chat_member_free(chat_member_updated->old_chat_member);
        chat_member_updated->old_chat_member = NULL;
    }
    if (chat_member_updated->new_chat_member) {
        chat_member_free(chat_member_updated->new_chat_member);
        chat_member_updated->new_chat_member = NULL;
    }
    if (chat_member_updated->invite_link) {
        chat_invite_link_free(chat_member_updated->invite_link);
        chat_member_updated->invite_link = NULL;
    }
    free(chat_member_updated);
}

cJSON *chat_member_updated_convertToJSON(chat_member_updated_t *chat_member_updated) {
    cJSON *item = cJSON_CreateObject();

    // chat_member_updated->chat
    if (!chat_member_updated->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(chat_member_updated->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_updated->from
    if (!chat_member_updated->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(chat_member_updated->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_updated->date
    if (!chat_member_updated->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", chat_member_updated->date) == NULL) {
    goto fail; //Numeric
    }


    // chat_member_updated->old_chat_member
    if (!chat_member_updated->old_chat_member) {
        goto fail;
    }
    cJSON *old_chat_member_local_JSON = chat_member_convertToJSON(chat_member_updated->old_chat_member);
    if(old_chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "old_chat_member", old_chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_updated->new_chat_member
    if (!chat_member_updated->new_chat_member) {
        goto fail;
    }
    cJSON *new_chat_member_local_JSON = chat_member_convertToJSON(chat_member_updated->new_chat_member);
    if(new_chat_member_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "new_chat_member", new_chat_member_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_member_updated->invite_link
    if(chat_member_updated->invite_link) {
    cJSON *invite_link_local_JSON = chat_invite_link_convertToJSON(chat_member_updated->invite_link);
    if(invite_link_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invite_link", invite_link_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // chat_member_updated->via_join_request
    if(chat_member_updated->via_join_request) {
    if(cJSON_AddBoolToObject(item, "via_join_request", chat_member_updated->via_join_request) == NULL) {
    goto fail; //Bool
    }
    }


    // chat_member_updated->via_chat_folder_invite_link
    if(chat_member_updated->via_chat_folder_invite_link) {
    if(cJSON_AddBoolToObject(item, "via_chat_folder_invite_link", chat_member_updated->via_chat_folder_invite_link) == NULL) {
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

chat_member_updated_t *chat_member_updated_parseFromJSON(cJSON *chat_member_updatedJSON){

    chat_member_updated_t *chat_member_updated_local_var = NULL;

    // define the local variable for chat_member_updated->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for chat_member_updated->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for chat_member_updated->old_chat_member
    chat_member_t *old_chat_member_local_nonprim = NULL;

    // define the local variable for chat_member_updated->new_chat_member
    chat_member_t *new_chat_member_local_nonprim = NULL;

    // define the local variable for chat_member_updated->invite_link
    chat_invite_link_t *invite_link_local_nonprim = NULL;

    // chat_member_updated->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // chat_member_updated->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // chat_member_updated->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // chat_member_updated->old_chat_member
    cJSON *old_chat_member = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "old_chat_member");
    if (cJSON_IsNull(old_chat_member)) {
        old_chat_member = NULL;
    }
    if (!old_chat_member) {
        goto end;
    }

    
    old_chat_member_local_nonprim = chat_member_parseFromJSON(old_chat_member); //nonprimitive

    // chat_member_updated->new_chat_member
    cJSON *new_chat_member = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "new_chat_member");
    if (cJSON_IsNull(new_chat_member)) {
        new_chat_member = NULL;
    }
    if (!new_chat_member) {
        goto end;
    }

    
    new_chat_member_local_nonprim = chat_member_parseFromJSON(new_chat_member); //nonprimitive

    // chat_member_updated->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (invite_link) { 
    invite_link_local_nonprim = chat_invite_link_parseFromJSON(invite_link); //nonprimitive
    }

    // chat_member_updated->via_join_request
    cJSON *via_join_request = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "via_join_request");
    if (cJSON_IsNull(via_join_request)) {
        via_join_request = NULL;
    }
    if (via_join_request) { 
    if(!cJSON_IsBool(via_join_request))
    {
    goto end; //Bool
    }
    }

    // chat_member_updated->via_chat_folder_invite_link
    cJSON *via_chat_folder_invite_link = cJSON_GetObjectItemCaseSensitive(chat_member_updatedJSON, "via_chat_folder_invite_link");
    if (cJSON_IsNull(via_chat_folder_invite_link)) {
        via_chat_folder_invite_link = NULL;
    }
    if (via_chat_folder_invite_link) { 
    if(!cJSON_IsBool(via_chat_folder_invite_link))
    {
    goto end; //Bool
    }
    }


    chat_member_updated_local_var = chat_member_updated_create_internal (
        chat_local_nonprim,
        from_local_nonprim,
        date->valuedouble,
        old_chat_member_local_nonprim,
        new_chat_member_local_nonprim,
        invite_link ? invite_link_local_nonprim : NULL,
        via_join_request ? via_join_request->valueint : 0,
        via_chat_folder_invite_link ? via_chat_folder_invite_link->valueint : 0
        );

    return chat_member_updated_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (old_chat_member_local_nonprim) {
        chat_member_free(old_chat_member_local_nonprim);
        old_chat_member_local_nonprim = NULL;
    }
    if (new_chat_member_local_nonprim) {
        chat_member_free(new_chat_member_local_nonprim);
        new_chat_member_local_nonprim = NULL;
    }
    if (invite_link_local_nonprim) {
        chat_invite_link_free(invite_link_local_nonprim);
        invite_link_local_nonprim = NULL;
    }
    return NULL;

}
