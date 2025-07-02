#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_message_reaction_request.h"



static set_message_reaction_request_t *set_message_reaction_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    set_message_reaction_request_t *set_message_reaction_request_local_var = malloc(sizeof(set_message_reaction_request_t));
    if (!set_message_reaction_request_local_var) {
        return NULL;
    }
    set_message_reaction_request_local_var->chat_id = chat_id;
    set_message_reaction_request_local_var->message_id = message_id;
    set_message_reaction_request_local_var->reaction = reaction;
    set_message_reaction_request_local_var->is_big = is_big;

    set_message_reaction_request_local_var->_library_owned = 1;
    return set_message_reaction_request_local_var;
}

__attribute__((deprecated)) set_message_reaction_request_t *set_message_reaction_request_create(
    send_message_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    return set_message_reaction_request_create_internal (
        chat_id,
        message_id,
        reaction,
        is_big
        );
}

void set_message_reaction_request_free(set_message_reaction_request_t *set_message_reaction_request) {
    if(NULL == set_message_reaction_request){
        return ;
    }
    if(set_message_reaction_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_message_reaction_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_message_reaction_request->chat_id) {
        send_message_request_chat_id_free(set_message_reaction_request->chat_id);
        set_message_reaction_request->chat_id = NULL;
    }
    if (set_message_reaction_request->reaction) {
        list_ForEach(listEntry, set_message_reaction_request->reaction) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(set_message_reaction_request->reaction);
        set_message_reaction_request->reaction = NULL;
    }
    free(set_message_reaction_request);
}

cJSON *set_message_reaction_request_convertToJSON(set_message_reaction_request_t *set_message_reaction_request) {
    cJSON *item = cJSON_CreateObject();

    // set_message_reaction_request->chat_id
    if (!set_message_reaction_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(set_message_reaction_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // set_message_reaction_request->message_id
    if (!set_message_reaction_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", set_message_reaction_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // set_message_reaction_request->reaction
    if(set_message_reaction_request->reaction) {
    cJSON *reaction = cJSON_AddArrayToObject(item, "reaction");
    if(reaction == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reactionListEntry;
    if (set_message_reaction_request->reaction) {
    list_ForEach(reactionListEntry, set_message_reaction_request->reaction) {
    cJSON *itemLocal = reaction_type_convertToJSON(reactionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reaction, itemLocal);
    }
    }
    }


    // set_message_reaction_request->is_big
    if(set_message_reaction_request->is_big) {
    if(cJSON_AddBoolToObject(item, "is_big", set_message_reaction_request->is_big) == NULL) {
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

set_message_reaction_request_t *set_message_reaction_request_parseFromJSON(cJSON *set_message_reaction_requestJSON){

    set_message_reaction_request_t *set_message_reaction_request_local_var = NULL;

    // define the local variable for set_message_reaction_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for set_message_reaction_request->reaction
    list_t *reactionList = NULL;

    // set_message_reaction_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(set_message_reaction_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // set_message_reaction_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(set_message_reaction_requestJSON, "message_id");
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

    // set_message_reaction_request->reaction
    cJSON *reaction = cJSON_GetObjectItemCaseSensitive(set_message_reaction_requestJSON, "reaction");
    if (cJSON_IsNull(reaction)) {
        reaction = NULL;
    }
    if (reaction) { 
    cJSON *reaction_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reaction)){
        goto end; //nonprimitive container
    }

    reactionList = list_createList();

    cJSON_ArrayForEach(reaction_local_nonprimitive,reaction )
    {
        if(!cJSON_IsObject(reaction_local_nonprimitive)){
            goto end;
        }
        reaction_type_t *reactionItem = reaction_type_parseFromJSON(reaction_local_nonprimitive);

        list_addElement(reactionList, reactionItem);
    }
    }

    // set_message_reaction_request->is_big
    cJSON *is_big = cJSON_GetObjectItemCaseSensitive(set_message_reaction_requestJSON, "is_big");
    if (cJSON_IsNull(is_big)) {
        is_big = NULL;
    }
    if (is_big) { 
    if(!cJSON_IsBool(is_big))
    {
    goto end; //Bool
    }
    }


    set_message_reaction_request_local_var = set_message_reaction_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        reaction ? reactionList : NULL,
        is_big ? is_big->valueint : 0
        );

    return set_message_reaction_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reactionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reactionList) {
            reaction_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reactionList);
        reactionList = NULL;
    }
    return NULL;

}
