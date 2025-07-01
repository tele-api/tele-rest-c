#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_create_chat_subscription_invite_link_post_request.h"



static _create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_create_internal(
    _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    _create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_local_var = malloc(sizeof(_create_chat_subscription_invite_link_post_request_t));
    if (!_create_chat_subscription_invite_link_post_request_local_var) {
        return NULL;
    }
    _create_chat_subscription_invite_link_post_request_local_var->chat_id = chat_id;
    _create_chat_subscription_invite_link_post_request_local_var->subscription_period = subscription_period;
    _create_chat_subscription_invite_link_post_request_local_var->subscription_price = subscription_price;
    _create_chat_subscription_invite_link_post_request_local_var->name = name;

    _create_chat_subscription_invite_link_post_request_local_var->_library_owned = 1;
    return _create_chat_subscription_invite_link_post_request_local_var;
}

__attribute__((deprecated)) _create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_create(
    _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id,
    int subscription_period,
    int subscription_price,
    char *name
    ) {
    return _create_chat_subscription_invite_link_post_request_create_internal (
        chat_id,
        subscription_period,
        subscription_price,
        name
        );
}

void _create_chat_subscription_invite_link_post_request_free(_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request) {
    if(NULL == _create_chat_subscription_invite_link_post_request){
        return ;
    }
    if(_create_chat_subscription_invite_link_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_create_chat_subscription_invite_link_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_create_chat_subscription_invite_link_post_request->chat_id) {
        _create_chat_subscription_invite_link_post_request_chat_id_free(_create_chat_subscription_invite_link_post_request->chat_id);
        _create_chat_subscription_invite_link_post_request->chat_id = NULL;
    }
    if (_create_chat_subscription_invite_link_post_request->name) {
        free(_create_chat_subscription_invite_link_post_request->name);
        _create_chat_subscription_invite_link_post_request->name = NULL;
    }
    free(_create_chat_subscription_invite_link_post_request);
}

cJSON *_create_chat_subscription_invite_link_post_request_convertToJSON(_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _create_chat_subscription_invite_link_post_request->chat_id
    if (!_create_chat_subscription_invite_link_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _create_chat_subscription_invite_link_post_request_chat_id_convertToJSON(_create_chat_subscription_invite_link_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _create_chat_subscription_invite_link_post_request->subscription_period
    if (!_create_chat_subscription_invite_link_post_request->subscription_period) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_period", _create_chat_subscription_invite_link_post_request->subscription_period) == NULL) {
    goto fail; //Numeric
    }


    // _create_chat_subscription_invite_link_post_request->subscription_price
    if (!_create_chat_subscription_invite_link_post_request->subscription_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "subscription_price", _create_chat_subscription_invite_link_post_request->subscription_price) == NULL) {
    goto fail; //Numeric
    }


    // _create_chat_subscription_invite_link_post_request->name
    if(_create_chat_subscription_invite_link_post_request->name) {
    if(cJSON_AddStringToObject(item, "name", _create_chat_subscription_invite_link_post_request->name) == NULL) {
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

_create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_parseFromJSON(cJSON *_create_chat_subscription_invite_link_post_requestJSON){

    _create_chat_subscription_invite_link_post_request_t *_create_chat_subscription_invite_link_post_request_local_var = NULL;

    // define the local variable for _create_chat_subscription_invite_link_post_request->chat_id
    _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // _create_chat_subscription_invite_link_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_create_chat_subscription_invite_link_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _create_chat_subscription_invite_link_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _create_chat_subscription_invite_link_post_request->subscription_period
    cJSON *subscription_period = cJSON_GetObjectItemCaseSensitive(_create_chat_subscription_invite_link_post_requestJSON, "subscription_period");
    if (cJSON_IsNull(subscription_period)) {
        subscription_period = NULL;
    }
    if (!subscription_period) {
        goto end;
    }

    
    if(!cJSON_IsNumber(subscription_period))
    {
    goto end; //Numeric
    }

    // _create_chat_subscription_invite_link_post_request->subscription_price
    cJSON *subscription_price = cJSON_GetObjectItemCaseSensitive(_create_chat_subscription_invite_link_post_requestJSON, "subscription_price");
    if (cJSON_IsNull(subscription_price)) {
        subscription_price = NULL;
    }
    if (!subscription_price) {
        goto end;
    }

    
    if(!cJSON_IsNumber(subscription_price))
    {
    goto end; //Numeric
    }

    // _create_chat_subscription_invite_link_post_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(_create_chat_subscription_invite_link_post_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    _create_chat_subscription_invite_link_post_request_local_var = _create_chat_subscription_invite_link_post_request_create_internal (
        chat_id_local_nonprim,
        subscription_period->valuedouble,
        subscription_price->valuedouble,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return _create_chat_subscription_invite_link_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _create_chat_subscription_invite_link_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
