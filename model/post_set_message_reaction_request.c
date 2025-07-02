#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_message_reaction_request.h"



static post_set_message_reaction_request_t *post_set_message_reaction_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    post_set_message_reaction_request_t *post_set_message_reaction_request_local_var = malloc(sizeof(post_set_message_reaction_request_t));
    if (!post_set_message_reaction_request_local_var) {
        return NULL;
    }
    post_set_message_reaction_request_local_var->chat_id = chat_id;
    post_set_message_reaction_request_local_var->message_id = message_id;
    post_set_message_reaction_request_local_var->reaction = reaction;
    post_set_message_reaction_request_local_var->is_big = is_big;

    post_set_message_reaction_request_local_var->_library_owned = 1;
    return post_set_message_reaction_request_local_var;
}

__attribute__((deprecated)) post_set_message_reaction_request_t *post_set_message_reaction_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    return post_set_message_reaction_request_create_internal (
        chat_id,
        message_id,
        reaction,
        is_big
        );
}

void post_set_message_reaction_request_free(post_set_message_reaction_request_t *post_set_message_reaction_request) {
    if(NULL == post_set_message_reaction_request){
        return ;
    }
    if(post_set_message_reaction_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_message_reaction_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_message_reaction_request->chat_id) {
        post_send_message_request_chat_id_free(post_set_message_reaction_request->chat_id);
        post_set_message_reaction_request->chat_id = NULL;
    }
    if (post_set_message_reaction_request->reaction) {
        list_ForEach(listEntry, post_set_message_reaction_request->reaction) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(post_set_message_reaction_request->reaction);
        post_set_message_reaction_request->reaction = NULL;
    }
    free(post_set_message_reaction_request);
}

cJSON *post_set_message_reaction_request_convertToJSON(post_set_message_reaction_request_t *post_set_message_reaction_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_message_reaction_request->chat_id
    if (!post_set_message_reaction_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_set_message_reaction_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_set_message_reaction_request->message_id
    if (!post_set_message_reaction_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", post_set_message_reaction_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // post_set_message_reaction_request->reaction
    if(post_set_message_reaction_request->reaction) {
    cJSON *reaction = cJSON_AddArrayToObject(item, "reaction");
    if(reaction == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reactionListEntry;
    if (post_set_message_reaction_request->reaction) {
    list_ForEach(reactionListEntry, post_set_message_reaction_request->reaction) {
    cJSON *itemLocal = reaction_type_convertToJSON(reactionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reaction, itemLocal);
    }
    }
    }


    // post_set_message_reaction_request->is_big
    if(post_set_message_reaction_request->is_big) {
    if(cJSON_AddBoolToObject(item, "is_big", post_set_message_reaction_request->is_big) == NULL) {
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

post_set_message_reaction_request_t *post_set_message_reaction_request_parseFromJSON(cJSON *post_set_message_reaction_requestJSON){

    post_set_message_reaction_request_t *post_set_message_reaction_request_local_var = NULL;

    // define the local variable for post_set_message_reaction_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for post_set_message_reaction_request->reaction
    list_t *reactionList = NULL;

    // post_set_message_reaction_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_message_reaction_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_set_message_reaction_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_set_message_reaction_requestJSON, "message_id");
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

    // post_set_message_reaction_request->reaction
    cJSON *reaction = cJSON_GetObjectItemCaseSensitive(post_set_message_reaction_requestJSON, "reaction");
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

    // post_set_message_reaction_request->is_big
    cJSON *is_big = cJSON_GetObjectItemCaseSensitive(post_set_message_reaction_requestJSON, "is_big");
    if (cJSON_IsNull(is_big)) {
        is_big = NULL;
    }
    if (is_big) { 
    if(!cJSON_IsBool(is_big))
    {
    goto end; //Bool
    }
    }


    post_set_message_reaction_request_local_var = post_set_message_reaction_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        reaction ? reactionList : NULL,
        is_big ? is_big->valueint : 0
        );

    return post_set_message_reaction_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
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
