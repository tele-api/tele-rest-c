#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "poll_answer.h"



static poll_answer_t *poll_answer_create_internal(
    char *poll_id,
    list_t *option_ids,
    chat_t *voter_chat,
    user_t *user
    ) {
    poll_answer_t *poll_answer_local_var = malloc(sizeof(poll_answer_t));
    if (!poll_answer_local_var) {
        return NULL;
    }
    poll_answer_local_var->poll_id = poll_id;
    poll_answer_local_var->option_ids = option_ids;
    poll_answer_local_var->voter_chat = voter_chat;
    poll_answer_local_var->user = user;

    poll_answer_local_var->_library_owned = 1;
    return poll_answer_local_var;
}

__attribute__((deprecated)) poll_answer_t *poll_answer_create(
    char *poll_id,
    list_t *option_ids,
    chat_t *voter_chat,
    user_t *user
    ) {
    return poll_answer_create_internal (
        poll_id,
        option_ids,
        voter_chat,
        user
        );
}

void poll_answer_free(poll_answer_t *poll_answer) {
    if(NULL == poll_answer){
        return ;
    }
    if(poll_answer->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "poll_answer_free");
        return ;
    }
    listEntry_t *listEntry;
    if (poll_answer->poll_id) {
        free(poll_answer->poll_id);
        poll_answer->poll_id = NULL;
    }
    if (poll_answer->option_ids) {
        list_ForEach(listEntry, poll_answer->option_ids) {
            free(listEntry->data);
        }
        list_freeList(poll_answer->option_ids);
        poll_answer->option_ids = NULL;
    }
    if (poll_answer->voter_chat) {
        chat_free(poll_answer->voter_chat);
        poll_answer->voter_chat = NULL;
    }
    if (poll_answer->user) {
        user_free(poll_answer->user);
        poll_answer->user = NULL;
    }
    free(poll_answer);
}

cJSON *poll_answer_convertToJSON(poll_answer_t *poll_answer) {
    cJSON *item = cJSON_CreateObject();

    // poll_answer->poll_id
    if (!poll_answer->poll_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "poll_id", poll_answer->poll_id) == NULL) {
    goto fail; //String
    }


    // poll_answer->option_ids
    if (!poll_answer->option_ids) {
        goto fail;
    }
    cJSON *option_ids = cJSON_AddArrayToObject(item, "option_ids");
    if(option_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *option_idsListEntry;
    list_ForEach(option_idsListEntry, poll_answer->option_ids) {
    if(cJSON_AddNumberToObject(option_ids, "", *(double *)option_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // poll_answer->voter_chat
    if(poll_answer->voter_chat) {
    cJSON *voter_chat_local_JSON = chat_convertToJSON(poll_answer->voter_chat);
    if(voter_chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "voter_chat", voter_chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // poll_answer->user
    if(poll_answer->user) {
    cJSON *user_local_JSON = user_convertToJSON(poll_answer->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
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

poll_answer_t *poll_answer_parseFromJSON(cJSON *poll_answerJSON){

    poll_answer_t *poll_answer_local_var = NULL;

    // define the local list for poll_answer->option_ids
    list_t *option_idsList = NULL;

    // define the local variable for poll_answer->voter_chat
    chat_t *voter_chat_local_nonprim = NULL;

    // define the local variable for poll_answer->user
    user_t *user_local_nonprim = NULL;

    // poll_answer->poll_id
    cJSON *poll_id = cJSON_GetObjectItemCaseSensitive(poll_answerJSON, "poll_id");
    if (cJSON_IsNull(poll_id)) {
        poll_id = NULL;
    }
    if (!poll_id) {
        goto end;
    }

    
    if(!cJSON_IsString(poll_id))
    {
    goto end; //String
    }

    // poll_answer->option_ids
    cJSON *option_ids = cJSON_GetObjectItemCaseSensitive(poll_answerJSON, "option_ids");
    if (cJSON_IsNull(option_ids)) {
        option_ids = NULL;
    }
    if (!option_ids) {
        goto end;
    }

    
    cJSON *option_ids_local = NULL;
    if(!cJSON_IsArray(option_ids)) {
        goto end;//primitive container
    }
    option_idsList = list_createList();

    cJSON_ArrayForEach(option_ids_local, option_ids)
    {
        if(!cJSON_IsNumber(option_ids_local))
        {
            goto end;
        }
        double *option_ids_local_value = calloc(1, sizeof(double));
        if(!option_ids_local_value)
        {
            goto end;
        }
        *option_ids_local_value = option_ids_local->valuedouble;
        list_addElement(option_idsList , option_ids_local_value);
    }

    // poll_answer->voter_chat
    cJSON *voter_chat = cJSON_GetObjectItemCaseSensitive(poll_answerJSON, "voter_chat");
    if (cJSON_IsNull(voter_chat)) {
        voter_chat = NULL;
    }
    if (voter_chat) { 
    voter_chat_local_nonprim = chat_parseFromJSON(voter_chat); //nonprimitive
    }

    // poll_answer->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(poll_answerJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive
    }


    poll_answer_local_var = poll_answer_create_internal (
        strdup(poll_id->valuestring),
        option_idsList,
        voter_chat ? voter_chat_local_nonprim : NULL,
        user ? user_local_nonprim : NULL
        );

    return poll_answer_local_var;
end:
    if (option_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, option_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(option_idsList);
        option_idsList = NULL;
    }
    if (voter_chat_local_nonprim) {
        chat_free(voter_chat_local_nonprim);
        voter_chat_local_nonprim = NULL;
    }
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
