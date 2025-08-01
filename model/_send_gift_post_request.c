#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_gift_post_request.h"



static _send_gift_post_request_t *_send_gift_post_request_create_internal(
    char *gift_id,
    int user_id,
    _send_gift_post_request_chat_id_t *chat_id,
    int pay_for_upgrade,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    _send_gift_post_request_t *_send_gift_post_request_local_var = malloc(sizeof(_send_gift_post_request_t));
    if (!_send_gift_post_request_local_var) {
        return NULL;
    }
    _send_gift_post_request_local_var->gift_id = gift_id;
    _send_gift_post_request_local_var->user_id = user_id;
    _send_gift_post_request_local_var->chat_id = chat_id;
    _send_gift_post_request_local_var->pay_for_upgrade = pay_for_upgrade;
    _send_gift_post_request_local_var->text = text;
    _send_gift_post_request_local_var->text_parse_mode = text_parse_mode;
    _send_gift_post_request_local_var->text_entities = text_entities;

    _send_gift_post_request_local_var->_library_owned = 1;
    return _send_gift_post_request_local_var;
}

__attribute__((deprecated)) _send_gift_post_request_t *_send_gift_post_request_create(
    char *gift_id,
    int user_id,
    _send_gift_post_request_chat_id_t *chat_id,
    int pay_for_upgrade,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
    ) {
    return _send_gift_post_request_create_internal (
        gift_id,
        user_id,
        chat_id,
        pay_for_upgrade,
        text,
        text_parse_mode,
        text_entities
        );
}

void _send_gift_post_request_free(_send_gift_post_request_t *_send_gift_post_request) {
    if(NULL == _send_gift_post_request){
        return ;
    }
    if(_send_gift_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_gift_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_gift_post_request->gift_id) {
        free(_send_gift_post_request->gift_id);
        _send_gift_post_request->gift_id = NULL;
    }
    if (_send_gift_post_request->chat_id) {
        _send_gift_post_request_chat_id_free(_send_gift_post_request->chat_id);
        _send_gift_post_request->chat_id = NULL;
    }
    if (_send_gift_post_request->text) {
        free(_send_gift_post_request->text);
        _send_gift_post_request->text = NULL;
    }
    if (_send_gift_post_request->text_parse_mode) {
        free(_send_gift_post_request->text_parse_mode);
        _send_gift_post_request->text_parse_mode = NULL;
    }
    if (_send_gift_post_request->text_entities) {
        list_ForEach(listEntry, _send_gift_post_request->text_entities) {
            message_entity_free(listEntry->data);
        }
        list_freeList(_send_gift_post_request->text_entities);
        _send_gift_post_request->text_entities = NULL;
    }
    free(_send_gift_post_request);
}

cJSON *_send_gift_post_request_convertToJSON(_send_gift_post_request_t *_send_gift_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _send_gift_post_request->gift_id
    if (!_send_gift_post_request->gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gift_id", _send_gift_post_request->gift_id) == NULL) {
    goto fail; //String
    }


    // _send_gift_post_request->user_id
    if(_send_gift_post_request->user_id) {
    if(cJSON_AddNumberToObject(item, "user_id", _send_gift_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_gift_post_request->chat_id
    if(_send_gift_post_request->chat_id) {
    cJSON *chat_id_local_JSON = _send_gift_post_request_chat_id_convertToJSON(_send_gift_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _send_gift_post_request->pay_for_upgrade
    if(_send_gift_post_request->pay_for_upgrade) {
    if(cJSON_AddBoolToObject(item, "pay_for_upgrade", _send_gift_post_request->pay_for_upgrade) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_gift_post_request->text
    if(_send_gift_post_request->text) {
    if(cJSON_AddStringToObject(item, "text", _send_gift_post_request->text) == NULL) {
    goto fail; //String
    }
    }


    // _send_gift_post_request->text_parse_mode
    if(_send_gift_post_request->text_parse_mode) {
    if(cJSON_AddStringToObject(item, "text_parse_mode", _send_gift_post_request->text_parse_mode) == NULL) {
    goto fail; //String
    }
    }


    // _send_gift_post_request->text_entities
    if(_send_gift_post_request->text_entities) {
    cJSON *text_entities = cJSON_AddArrayToObject(item, "text_entities");
    if(text_entities == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *text_entitiesListEntry;
    if (_send_gift_post_request->text_entities) {
    list_ForEach(text_entitiesListEntry, _send_gift_post_request->text_entities) {
    cJSON *itemLocal = message_entity_convertToJSON(text_entitiesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(text_entities, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_send_gift_post_request_t *_send_gift_post_request_parseFromJSON(cJSON *_send_gift_post_requestJSON){

    _send_gift_post_request_t *_send_gift_post_request_local_var = NULL;

    // define the local variable for _send_gift_post_request->chat_id
    _send_gift_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for _send_gift_post_request->text_entities
    list_t *text_entitiesList = NULL;

    // _send_gift_post_request->gift_id
    cJSON *gift_id = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "gift_id");
    if (cJSON_IsNull(gift_id)) {
        gift_id = NULL;
    }
    if (!gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(gift_id))
    {
    goto end; //String
    }

    // _send_gift_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }
    }

    // _send_gift_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = _send_gift_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // _send_gift_post_request->pay_for_upgrade
    cJSON *pay_for_upgrade = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "pay_for_upgrade");
    if (cJSON_IsNull(pay_for_upgrade)) {
        pay_for_upgrade = NULL;
    }
    if (pay_for_upgrade) { 
    if(!cJSON_IsBool(pay_for_upgrade))
    {
    goto end; //Bool
    }
    }

    // _send_gift_post_request->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (text) { 
    if(!cJSON_IsString(text) && !cJSON_IsNull(text))
    {
    goto end; //String
    }
    }

    // _send_gift_post_request->text_parse_mode
    cJSON *text_parse_mode = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "text_parse_mode");
    if (cJSON_IsNull(text_parse_mode)) {
        text_parse_mode = NULL;
    }
    if (text_parse_mode) { 
    if(!cJSON_IsString(text_parse_mode) && !cJSON_IsNull(text_parse_mode))
    {
    goto end; //String
    }
    }

    // _send_gift_post_request->text_entities
    cJSON *text_entities = cJSON_GetObjectItemCaseSensitive(_send_gift_post_requestJSON, "text_entities");
    if (cJSON_IsNull(text_entities)) {
        text_entities = NULL;
    }
    if (text_entities) { 
    cJSON *text_entities_local_nonprimitive = NULL;
    if(!cJSON_IsArray(text_entities)){
        goto end; //nonprimitive container
    }

    text_entitiesList = list_createList();

    cJSON_ArrayForEach(text_entities_local_nonprimitive,text_entities )
    {
        if(!cJSON_IsObject(text_entities_local_nonprimitive)){
            goto end;
        }
        message_entity_t *text_entitiesItem = message_entity_parseFromJSON(text_entities_local_nonprimitive);

        list_addElement(text_entitiesList, text_entitiesItem);
    }
    }


    _send_gift_post_request_local_var = _send_gift_post_request_create_internal (
        strdup(gift_id->valuestring),
        user_id ? user_id->valuedouble : 0,
        chat_id ? chat_id_local_nonprim : NULL,
        pay_for_upgrade ? pay_for_upgrade->valueint : 0,
        text && !cJSON_IsNull(text) ? strdup(text->valuestring) : NULL,
        text_parse_mode && !cJSON_IsNull(text_parse_mode) ? strdup(text_parse_mode->valuestring) : NULL,
        text_entities ? text_entitiesList : NULL
        );

    return _send_gift_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_gift_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (text_entitiesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, text_entitiesList) {
            message_entity_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(text_entitiesList);
        text_entitiesList = NULL;
    }
    return NULL;

}
