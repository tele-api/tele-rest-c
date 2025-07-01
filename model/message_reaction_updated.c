#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_reaction_updated.h"



static message_reaction_updated_t *message_reaction_updated_create_internal(
    chat_t *chat,
    int message_id,
    int date,
    list_t *old_reaction,
    list_t *new_reaction,
    user_t *user,
    chat_t *actor_chat
    ) {
    message_reaction_updated_t *message_reaction_updated_local_var = malloc(sizeof(message_reaction_updated_t));
    if (!message_reaction_updated_local_var) {
        return NULL;
    }
    message_reaction_updated_local_var->chat = chat;
    message_reaction_updated_local_var->message_id = message_id;
    message_reaction_updated_local_var->date = date;
    message_reaction_updated_local_var->old_reaction = old_reaction;
    message_reaction_updated_local_var->new_reaction = new_reaction;
    message_reaction_updated_local_var->user = user;
    message_reaction_updated_local_var->actor_chat = actor_chat;

    message_reaction_updated_local_var->_library_owned = 1;
    return message_reaction_updated_local_var;
}

__attribute__((deprecated)) message_reaction_updated_t *message_reaction_updated_create(
    chat_t *chat,
    int message_id,
    int date,
    list_t *old_reaction,
    list_t *new_reaction,
    user_t *user,
    chat_t *actor_chat
    ) {
    return message_reaction_updated_create_internal (
        chat,
        message_id,
        date,
        old_reaction,
        new_reaction,
        user,
        actor_chat
        );
}

void message_reaction_updated_free(message_reaction_updated_t *message_reaction_updated) {
    if(NULL == message_reaction_updated){
        return ;
    }
    if(message_reaction_updated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_reaction_updated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_reaction_updated->chat) {
        chat_free(message_reaction_updated->chat);
        message_reaction_updated->chat = NULL;
    }
    if (message_reaction_updated->old_reaction) {
        list_ForEach(listEntry, message_reaction_updated->old_reaction) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(message_reaction_updated->old_reaction);
        message_reaction_updated->old_reaction = NULL;
    }
    if (message_reaction_updated->new_reaction) {
        list_ForEach(listEntry, message_reaction_updated->new_reaction) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(message_reaction_updated->new_reaction);
        message_reaction_updated->new_reaction = NULL;
    }
    if (message_reaction_updated->user) {
        user_free(message_reaction_updated->user);
        message_reaction_updated->user = NULL;
    }
    if (message_reaction_updated->actor_chat) {
        chat_free(message_reaction_updated->actor_chat);
        message_reaction_updated->actor_chat = NULL;
    }
    free(message_reaction_updated);
}

cJSON *message_reaction_updated_convertToJSON(message_reaction_updated_t *message_reaction_updated) {
    cJSON *item = cJSON_CreateObject();

    // message_reaction_updated->chat
    if (!message_reaction_updated->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(message_reaction_updated->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_reaction_updated->message_id
    if (!message_reaction_updated->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", message_reaction_updated->message_id) == NULL) {
    goto fail; //Numeric
    }


    // message_reaction_updated->date
    if (!message_reaction_updated->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_reaction_updated->date) == NULL) {
    goto fail; //Numeric
    }


    // message_reaction_updated->old_reaction
    if (!message_reaction_updated->old_reaction) {
        goto fail;
    }
    cJSON *old_reaction = cJSON_AddArrayToObject(item, "old_reaction");
    if(old_reaction == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *old_reactionListEntry;
    if (message_reaction_updated->old_reaction) {
    list_ForEach(old_reactionListEntry, message_reaction_updated->old_reaction) {
    cJSON *itemLocal = reaction_type_convertToJSON(old_reactionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(old_reaction, itemLocal);
    }
    }


    // message_reaction_updated->new_reaction
    if (!message_reaction_updated->new_reaction) {
        goto fail;
    }
    cJSON *new_reaction = cJSON_AddArrayToObject(item, "new_reaction");
    if(new_reaction == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *new_reactionListEntry;
    if (message_reaction_updated->new_reaction) {
    list_ForEach(new_reactionListEntry, message_reaction_updated->new_reaction) {
    cJSON *itemLocal = reaction_type_convertToJSON(new_reactionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(new_reaction, itemLocal);
    }
    }


    // message_reaction_updated->user
    if(message_reaction_updated->user) {
    cJSON *user_local_JSON = user_convertToJSON(message_reaction_updated->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // message_reaction_updated->actor_chat
    if(message_reaction_updated->actor_chat) {
    cJSON *actor_chat_local_JSON = chat_convertToJSON(message_reaction_updated->actor_chat);
    if(actor_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "actor_chat", actor_chat_local_JSON);
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

message_reaction_updated_t *message_reaction_updated_parseFromJSON(cJSON *message_reaction_updatedJSON){

    message_reaction_updated_t *message_reaction_updated_local_var = NULL;

    // define the local variable for message_reaction_updated->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local list for message_reaction_updated->old_reaction
    list_t *old_reactionList = NULL;

    // define the local list for message_reaction_updated->new_reaction
    list_t *new_reactionList = NULL;

    // define the local variable for message_reaction_updated->user
    user_t *user_local_nonprim = NULL;

    // define the local variable for message_reaction_updated->actor_chat
    chat_t *actor_chat_local_nonprim = NULL;

    // message_reaction_updated->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // message_reaction_updated->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // message_reaction_updated->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "date");
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

    // message_reaction_updated->old_reaction
    cJSON *old_reaction = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "old_reaction");
    if (cJSON_IsNull(old_reaction)) {
        old_reaction = NULL;
    }
    if (!old_reaction) {
        goto end;
    }

    
    cJSON *old_reaction_local_nonprimitive = NULL;
    if(!cJSON_IsArray(old_reaction)){
        goto end; //nonprimitive container
    }

    old_reactionList = list_createList();

    cJSON_ArrayForEach(old_reaction_local_nonprimitive,old_reaction )
    {
        if(!cJSON_IsObject(old_reaction_local_nonprimitive)){
            goto end;
        }
        reaction_type_t *old_reactionItem = reaction_type_parseFromJSON(old_reaction_local_nonprimitive);

        list_addElement(old_reactionList, old_reactionItem);
    }

    // message_reaction_updated->new_reaction
    cJSON *new_reaction = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "new_reaction");
    if (cJSON_IsNull(new_reaction)) {
        new_reaction = NULL;
    }
    if (!new_reaction) {
        goto end;
    }

    
    cJSON *new_reaction_local_nonprimitive = NULL;
    if(!cJSON_IsArray(new_reaction)){
        goto end; //nonprimitive container
    }

    new_reactionList = list_createList();

    cJSON_ArrayForEach(new_reaction_local_nonprimitive,new_reaction )
    {
        if(!cJSON_IsObject(new_reaction_local_nonprimitive)){
            goto end;
        }
        reaction_type_t *new_reactionItem = reaction_type_parseFromJSON(new_reaction_local_nonprimitive);

        list_addElement(new_reactionList, new_reactionItem);
    }

    // message_reaction_updated->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive
    }

    // message_reaction_updated->actor_chat
    cJSON *actor_chat = cJSON_GetObjectItemCaseSensitive(message_reaction_updatedJSON, "actor_chat");
    if (cJSON_IsNull(actor_chat)) {
        actor_chat = NULL;
    }
    if (actor_chat) { 
    actor_chat_local_nonprim = chat_parseFromJSON(actor_chat); //nonprimitive
    }


    message_reaction_updated_local_var = message_reaction_updated_create_internal (
        chat_local_nonprim,
        message_id->valuedouble,
        date->valuedouble,
        old_reactionList,
        new_reactionList,
        user ? user_local_nonprim : NULL,
        actor_chat ? actor_chat_local_nonprim : NULL
        );

    return message_reaction_updated_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (old_reactionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, old_reactionList) {
            reaction_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(old_reactionList);
        old_reactionList = NULL;
    }
    if (new_reactionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, new_reactionList) {
            reaction_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(new_reactionList);
        new_reactionList = NULL;
    }
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    if (actor_chat_local_nonprim) {
        chat_free(actor_chat_local_nonprim);
        actor_chat_local_nonprim = NULL;
    }
    return NULL;

}
