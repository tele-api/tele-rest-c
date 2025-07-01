#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_answer_shipping_query_post_request.h"



static _answer_shipping_query_post_request_t *_answer_shipping_query_post_request_create_internal(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    _answer_shipping_query_post_request_t *_answer_shipping_query_post_request_local_var = malloc(sizeof(_answer_shipping_query_post_request_t));
    if (!_answer_shipping_query_post_request_local_var) {
        return NULL;
    }
    _answer_shipping_query_post_request_local_var->shipping_query_id = shipping_query_id;
    _answer_shipping_query_post_request_local_var->ok = ok;
    _answer_shipping_query_post_request_local_var->shipping_options = shipping_options;
    _answer_shipping_query_post_request_local_var->error_message = error_message;

    _answer_shipping_query_post_request_local_var->_library_owned = 1;
    return _answer_shipping_query_post_request_local_var;
}

__attribute__((deprecated)) _answer_shipping_query_post_request_t *_answer_shipping_query_post_request_create(
    char *shipping_query_id,
    int ok,
    list_t *shipping_options,
    char *error_message
    ) {
    return _answer_shipping_query_post_request_create_internal (
        shipping_query_id,
        ok,
        shipping_options,
        error_message
        );
}

void _answer_shipping_query_post_request_free(_answer_shipping_query_post_request_t *_answer_shipping_query_post_request) {
    if(NULL == _answer_shipping_query_post_request){
        return ;
    }
    if(_answer_shipping_query_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_answer_shipping_query_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_answer_shipping_query_post_request->shipping_query_id) {
        free(_answer_shipping_query_post_request->shipping_query_id);
        _answer_shipping_query_post_request->shipping_query_id = NULL;
    }
    if (_answer_shipping_query_post_request->shipping_options) {
        list_ForEach(listEntry, _answer_shipping_query_post_request->shipping_options) {
            shipping_option_free(listEntry->data);
        }
        list_freeList(_answer_shipping_query_post_request->shipping_options);
        _answer_shipping_query_post_request->shipping_options = NULL;
    }
    if (_answer_shipping_query_post_request->error_message) {
        free(_answer_shipping_query_post_request->error_message);
        _answer_shipping_query_post_request->error_message = NULL;
    }
    free(_answer_shipping_query_post_request);
}

cJSON *_answer_shipping_query_post_request_convertToJSON(_answer_shipping_query_post_request_t *_answer_shipping_query_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _answer_shipping_query_post_request->shipping_query_id
    if (!_answer_shipping_query_post_request->shipping_query_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "shipping_query_id", _answer_shipping_query_post_request->shipping_query_id) == NULL) {
    goto fail; //String
    }


    // _answer_shipping_query_post_request->ok
    if (!_answer_shipping_query_post_request->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _answer_shipping_query_post_request->ok) == NULL) {
    goto fail; //Bool
    }


    // _answer_shipping_query_post_request->shipping_options
    if(_answer_shipping_query_post_request->shipping_options) {
    cJSON *shipping_options = cJSON_AddArrayToObject(item, "shipping_options");
    if(shipping_options == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shipping_optionsListEntry;
    if (_answer_shipping_query_post_request->shipping_options) {
    list_ForEach(shipping_optionsListEntry, _answer_shipping_query_post_request->shipping_options) {
    cJSON *itemLocal = shipping_option_convertToJSON(shipping_optionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shipping_options, itemLocal);
    }
    }
    }


    // _answer_shipping_query_post_request->error_message
    if(_answer_shipping_query_post_request->error_message) {
    if(cJSON_AddStringToObject(item, "error_message", _answer_shipping_query_post_request->error_message) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_answer_shipping_query_post_request_t *_answer_shipping_query_post_request_parseFromJSON(cJSON *_answer_shipping_query_post_requestJSON){

    _answer_shipping_query_post_request_t *_answer_shipping_query_post_request_local_var = NULL;

    // define the local list for _answer_shipping_query_post_request->shipping_options
    list_t *shipping_optionsList = NULL;

    // _answer_shipping_query_post_request->shipping_query_id
    cJSON *shipping_query_id = cJSON_GetObjectItemCaseSensitive(_answer_shipping_query_post_requestJSON, "shipping_query_id");
    if (cJSON_IsNull(shipping_query_id)) {
        shipping_query_id = NULL;
    }
    if (!shipping_query_id) {
        goto end;
    }

    
    if(!cJSON_IsString(shipping_query_id))
    {
    goto end; //String
    }

    // _answer_shipping_query_post_request->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_answer_shipping_query_post_requestJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // _answer_shipping_query_post_request->shipping_options
    cJSON *shipping_options = cJSON_GetObjectItemCaseSensitive(_answer_shipping_query_post_requestJSON, "shipping_options");
    if (cJSON_IsNull(shipping_options)) {
        shipping_options = NULL;
    }
    if (shipping_options) { 
    cJSON *shipping_options_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shipping_options)){
        goto end; //nonprimitive container
    }

    shipping_optionsList = list_createList();

    cJSON_ArrayForEach(shipping_options_local_nonprimitive,shipping_options )
    {
        if(!cJSON_IsObject(shipping_options_local_nonprimitive)){
            goto end;
        }
        shipping_option_t *shipping_optionsItem = shipping_option_parseFromJSON(shipping_options_local_nonprimitive);

        list_addElement(shipping_optionsList, shipping_optionsItem);
    }
    }

    // _answer_shipping_query_post_request->error_message
    cJSON *error_message = cJSON_GetObjectItemCaseSensitive(_answer_shipping_query_post_requestJSON, "error_message");
    if (cJSON_IsNull(error_message)) {
        error_message = NULL;
    }
    if (error_message) { 
    if(!cJSON_IsString(error_message) && !cJSON_IsNull(error_message))
    {
    goto end; //String
    }
    }


    _answer_shipping_query_post_request_local_var = _answer_shipping_query_post_request_create_internal (
        strdup(shipping_query_id->valuestring),
        ok->valueint,
        shipping_options ? shipping_optionsList : NULL,
        error_message && !cJSON_IsNull(error_message) ? strdup(error_message->valuestring) : NULL
        );

    return _answer_shipping_query_post_request_local_var;
end:
    if (shipping_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shipping_optionsList) {
            shipping_option_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shipping_optionsList);
        shipping_optionsList = NULL;
    }
    return NULL;

}
