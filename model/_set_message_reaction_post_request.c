#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_message_reaction_post_request.h"



static _set_message_reaction_post_request_t *_set_message_reaction_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    _set_message_reaction_post_request_t *_set_message_reaction_post_request_local_var = malloc(sizeof(_set_message_reaction_post_request_t));
    if (!_set_message_reaction_post_request_local_var) {
        return NULL;
    }
    _set_message_reaction_post_request_local_var->chat_id = chat_id;
    _set_message_reaction_post_request_local_var->message_id = message_id;
    _set_message_reaction_post_request_local_var->reaction = reaction;
    _set_message_reaction_post_request_local_var->is_big = is_big;

    _set_message_reaction_post_request_local_var->_library_owned = 1;
    return _set_message_reaction_post_request_local_var;
}

__attribute__((deprecated)) _set_message_reaction_post_request_t *_set_message_reaction_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    int message_id,
    list_t *reaction,
    int is_big
    ) {
    return _set_message_reaction_post_request_create_internal (
        chat_id,
        message_id,
        reaction,
        is_big
        );
}

void _set_message_reaction_post_request_free(_set_message_reaction_post_request_t *_set_message_reaction_post_request) {
    if(NULL == _set_message_reaction_post_request){
        return ;
    }
    if(_set_message_reaction_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_message_reaction_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_message_reaction_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_set_message_reaction_post_request->chat_id);
        _set_message_reaction_post_request->chat_id = NULL;
    }
    if (_set_message_reaction_post_request->reaction) {
        list_ForEach(listEntry, _set_message_reaction_post_request->reaction) {
            reaction_type_free(listEntry->data);
        }
        list_freeList(_set_message_reaction_post_request->reaction);
        _set_message_reaction_post_request->reaction = NULL;
    }
    free(_set_message_reaction_post_request);
}

cJSON *_set_message_reaction_post_request_convertToJSON(_set_message_reaction_post_request_t *_set_message_reaction_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_message_reaction_post_request->chat_id
    if (!_set_message_reaction_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_set_message_reaction_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _set_message_reaction_post_request->message_id
    if (!_set_message_reaction_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _set_message_reaction_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // _set_message_reaction_post_request->reaction
    if(_set_message_reaction_post_request->reaction) {
    cJSON *reaction = cJSON_AddArrayToObject(item, "reaction");
    if(reaction == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reactionListEntry;
    if (_set_message_reaction_post_request->reaction) {
    list_ForEach(reactionListEntry, _set_message_reaction_post_request->reaction) {
    cJSON *itemLocal = reaction_type_convertToJSON(reactionListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reaction, itemLocal);
    }
    }
    }


    // _set_message_reaction_post_request->is_big
    if(_set_message_reaction_post_request->is_big) {
    if(cJSON_AddBoolToObject(item, "is_big", _set_message_reaction_post_request->is_big) == NULL) {
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

_set_message_reaction_post_request_t *_set_message_reaction_post_request_parseFromJSON(cJSON *_set_message_reaction_post_requestJSON){

    _set_message_reaction_post_request_t *_set_message_reaction_post_request_local_var = NULL;

    // define the local variable for _set_message_reaction_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for _set_message_reaction_post_request->reaction
    list_t *reactionList = NULL;

    // _set_message_reaction_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_message_reaction_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _set_message_reaction_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_set_message_reaction_post_requestJSON, "message_id");
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

    // _set_message_reaction_post_request->reaction
    cJSON *reaction = cJSON_GetObjectItemCaseSensitive(_set_message_reaction_post_requestJSON, "reaction");
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

    // _set_message_reaction_post_request->is_big
    cJSON *is_big = cJSON_GetObjectItemCaseSensitive(_set_message_reaction_post_requestJSON, "is_big");
    if (cJSON_IsNull(is_big)) {
        is_big = NULL;
    }
    if (is_big) { 
    if(!cJSON_IsBool(is_big))
    {
    goto end; //Bool
    }
    }


    _set_message_reaction_post_request_local_var = _set_message_reaction_post_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        reaction ? reactionList : NULL,
        is_big ? is_big->valueint : 0
        );

    return _set_message_reaction_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
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
