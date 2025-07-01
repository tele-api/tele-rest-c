#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_join_request.h"



static chat_join_request_t *chat_join_request_create_internal(
    chat_t *chat,
    user_t *from,
    int user_chat_id,
    int date,
    char *bio,
    chat_invite_link_t *invite_link
    ) {
    chat_join_request_t *chat_join_request_local_var = malloc(sizeof(chat_join_request_t));
    if (!chat_join_request_local_var) {
        return NULL;
    }
    chat_join_request_local_var->chat = chat;
    chat_join_request_local_var->from = from;
    chat_join_request_local_var->user_chat_id = user_chat_id;
    chat_join_request_local_var->date = date;
    chat_join_request_local_var->bio = bio;
    chat_join_request_local_var->invite_link = invite_link;

    chat_join_request_local_var->_library_owned = 1;
    return chat_join_request_local_var;
}

__attribute__((deprecated)) chat_join_request_t *chat_join_request_create(
    chat_t *chat,
    user_t *from,
    int user_chat_id,
    int date,
    char *bio,
    chat_invite_link_t *invite_link
    ) {
    return chat_join_request_create_internal (
        chat,
        from,
        user_chat_id,
        date,
        bio,
        invite_link
        );
}

void chat_join_request_free(chat_join_request_t *chat_join_request) {
    if(NULL == chat_join_request){
        return ;
    }
    if(chat_join_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_join_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_join_request->chat) {
        chat_free(chat_join_request->chat);
        chat_join_request->chat = NULL;
    }
    if (chat_join_request->from) {
        user_free(chat_join_request->from);
        chat_join_request->from = NULL;
    }
    if (chat_join_request->bio) {
        free(chat_join_request->bio);
        chat_join_request->bio = NULL;
    }
    if (chat_join_request->invite_link) {
        chat_invite_link_free(chat_join_request->invite_link);
        chat_join_request->invite_link = NULL;
    }
    free(chat_join_request);
}

cJSON *chat_join_request_convertToJSON(chat_join_request_t *chat_join_request) {
    cJSON *item = cJSON_CreateObject();

    // chat_join_request->chat
    if (!chat_join_request->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(chat_join_request->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_join_request->from
    if (!chat_join_request->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(chat_join_request->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_join_request->user_chat_id
    if (!chat_join_request->user_chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_chat_id", chat_join_request->user_chat_id) == NULL) {
    goto fail; //Numeric
    }


    // chat_join_request->date
    if (!chat_join_request->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", chat_join_request->date) == NULL) {
    goto fail; //Numeric
    }


    // chat_join_request->bio
    if(chat_join_request->bio) {
    if(cJSON_AddStringToObject(item, "bio", chat_join_request->bio) == NULL) {
    goto fail; //String
    }
    }


    // chat_join_request->invite_link
    if(chat_join_request->invite_link) {
    cJSON *invite_link_local_JSON = chat_invite_link_convertToJSON(chat_join_request->invite_link);
    if(invite_link_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invite_link", invite_link_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_join_request_t *chat_join_request_parseFromJSON(cJSON *chat_join_requestJSON){

    chat_join_request_t *chat_join_request_local_var = NULL;

    // define the local variable for chat_join_request->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local variable for chat_join_request->from
    user_t *from_local_nonprim = NULL;

    // define the local variable for chat_join_request->invite_link
    chat_invite_link_t *invite_link_local_nonprim = NULL;

    // chat_join_request->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // chat_join_request->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // chat_join_request->user_chat_id
    cJSON *user_chat_id = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "user_chat_id");
    if (cJSON_IsNull(user_chat_id)) {
        user_chat_id = NULL;
    }
    if (!user_chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_chat_id))
    {
    goto end; //Numeric
    }

    // chat_join_request->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "date");
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

    // chat_join_request->bio
    cJSON *bio = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "bio");
    if (cJSON_IsNull(bio)) {
        bio = NULL;
    }
    if (bio) { 
    if(!cJSON_IsString(bio) && !cJSON_IsNull(bio))
    {
    goto end; //String
    }
    }

    // chat_join_request->invite_link
    cJSON *invite_link = cJSON_GetObjectItemCaseSensitive(chat_join_requestJSON, "invite_link");
    if (cJSON_IsNull(invite_link)) {
        invite_link = NULL;
    }
    if (invite_link) { 
    invite_link_local_nonprim = chat_invite_link_parseFromJSON(invite_link); //nonprimitive
    }


    chat_join_request_local_var = chat_join_request_create_internal (
        chat_local_nonprim,
        from_local_nonprim,
        user_chat_id->valuedouble,
        date->valuedouble,
        bio && !cJSON_IsNull(bio) ? strdup(bio->valuestring) : NULL,
        invite_link ? invite_link_local_nonprim : NULL
        );

    return chat_join_request_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    if (invite_link_local_nonprim) {
        chat_invite_link_free(invite_link_local_nonprim);
        invite_link_local_nonprim = NULL;
    }
    return NULL;

}
