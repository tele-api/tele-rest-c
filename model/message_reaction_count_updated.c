#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "message_reaction_count_updated.h"



static message_reaction_count_updated_t *message_reaction_count_updated_create_internal(
    chat_t *chat,
    int message_id,
    int date,
    list_t *reactions
    ) {
    message_reaction_count_updated_t *message_reaction_count_updated_local_var = malloc(sizeof(message_reaction_count_updated_t));
    if (!message_reaction_count_updated_local_var) {
        return NULL;
    }
    message_reaction_count_updated_local_var->chat = chat;
    message_reaction_count_updated_local_var->message_id = message_id;
    message_reaction_count_updated_local_var->date = date;
    message_reaction_count_updated_local_var->reactions = reactions;

    message_reaction_count_updated_local_var->_library_owned = 1;
    return message_reaction_count_updated_local_var;
}

__attribute__((deprecated)) message_reaction_count_updated_t *message_reaction_count_updated_create(
    chat_t *chat,
    int message_id,
    int date,
    list_t *reactions
    ) {
    return message_reaction_count_updated_create_internal (
        chat,
        message_id,
        date,
        reactions
        );
}

void message_reaction_count_updated_free(message_reaction_count_updated_t *message_reaction_count_updated) {
    if(NULL == message_reaction_count_updated){
        return ;
    }
    if(message_reaction_count_updated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "message_reaction_count_updated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (message_reaction_count_updated->chat) {
        chat_free(message_reaction_count_updated->chat);
        message_reaction_count_updated->chat = NULL;
    }
    if (message_reaction_count_updated->reactions) {
        list_ForEach(listEntry, message_reaction_count_updated->reactions) {
            reaction_count_free(listEntry->data);
        }
        list_freeList(message_reaction_count_updated->reactions);
        message_reaction_count_updated->reactions = NULL;
    }
    free(message_reaction_count_updated);
}

cJSON *message_reaction_count_updated_convertToJSON(message_reaction_count_updated_t *message_reaction_count_updated) {
    cJSON *item = cJSON_CreateObject();

    // message_reaction_count_updated->chat
    if (!message_reaction_count_updated->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(message_reaction_count_updated->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // message_reaction_count_updated->message_id
    if (!message_reaction_count_updated->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", message_reaction_count_updated->message_id) == NULL) {
    goto fail; //Numeric
    }


    // message_reaction_count_updated->date
    if (!message_reaction_count_updated->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", message_reaction_count_updated->date) == NULL) {
    goto fail; //Numeric
    }


    // message_reaction_count_updated->reactions
    if (!message_reaction_count_updated->reactions) {
        goto fail;
    }
    cJSON *reactions = cJSON_AddArrayToObject(item, "reactions");
    if(reactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reactionsListEntry;
    if (message_reaction_count_updated->reactions) {
    list_ForEach(reactionsListEntry, message_reaction_count_updated->reactions) {
    cJSON *itemLocal = reaction_count_convertToJSON(reactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reactions, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

message_reaction_count_updated_t *message_reaction_count_updated_parseFromJSON(cJSON *message_reaction_count_updatedJSON){

    message_reaction_count_updated_t *message_reaction_count_updated_local_var = NULL;

    // define the local variable for message_reaction_count_updated->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local list for message_reaction_count_updated->reactions
    list_t *reactionsList = NULL;

    // message_reaction_count_updated->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(message_reaction_count_updatedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // message_reaction_count_updated->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(message_reaction_count_updatedJSON, "message_id");
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

    // message_reaction_count_updated->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(message_reaction_count_updatedJSON, "date");
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

    // message_reaction_count_updated->reactions
    cJSON *reactions = cJSON_GetObjectItemCaseSensitive(message_reaction_count_updatedJSON, "reactions");
    if (cJSON_IsNull(reactions)) {
        reactions = NULL;
    }
    if (!reactions) {
        goto end;
    }

    
    cJSON *reactions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reactions)){
        goto end; //nonprimitive container
    }

    reactionsList = list_createList();

    cJSON_ArrayForEach(reactions_local_nonprimitive,reactions )
    {
        if(!cJSON_IsObject(reactions_local_nonprimitive)){
            goto end;
        }
        reaction_count_t *reactionsItem = reaction_count_parseFromJSON(reactions_local_nonprimitive);

        list_addElement(reactionsList, reactionsItem);
    }


    message_reaction_count_updated_local_var = message_reaction_count_updated_create_internal (
        chat_local_nonprim,
        message_id->valuedouble,
        date->valuedouble,
        reactionsList
        );

    return message_reaction_count_updated_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
    }
    if (reactionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reactionsList) {
            reaction_count_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reactionsList);
        reactionsList = NULL;
    }
    return NULL;

}
