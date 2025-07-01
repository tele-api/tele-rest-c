#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_user_star_subscription_post_request.h"



static _edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_create_internal(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
    ) {
    _edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_local_var = malloc(sizeof(_edit_user_star_subscription_post_request_t));
    if (!_edit_user_star_subscription_post_request_local_var) {
        return NULL;
    }
    _edit_user_star_subscription_post_request_local_var->user_id = user_id;
    _edit_user_star_subscription_post_request_local_var->telegram_payment_charge_id = telegram_payment_charge_id;
    _edit_user_star_subscription_post_request_local_var->is_canceled = is_canceled;

    _edit_user_star_subscription_post_request_local_var->_library_owned = 1;
    return _edit_user_star_subscription_post_request_local_var;
}

__attribute__((deprecated)) _edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_create(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
    ) {
    return _edit_user_star_subscription_post_request_create_internal (
        user_id,
        telegram_payment_charge_id,
        is_canceled
        );
}

void _edit_user_star_subscription_post_request_free(_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request) {
    if(NULL == _edit_user_star_subscription_post_request){
        return ;
    }
    if(_edit_user_star_subscription_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_user_star_subscription_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_user_star_subscription_post_request->telegram_payment_charge_id) {
        free(_edit_user_star_subscription_post_request->telegram_payment_charge_id);
        _edit_user_star_subscription_post_request->telegram_payment_charge_id = NULL;
    }
    free(_edit_user_star_subscription_post_request);
}

cJSON *_edit_user_star_subscription_post_request_convertToJSON(_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _edit_user_star_subscription_post_request->user_id
    if (!_edit_user_star_subscription_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _edit_user_star_subscription_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _edit_user_star_subscription_post_request->telegram_payment_charge_id
    if (!_edit_user_star_subscription_post_request->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", _edit_user_star_subscription_post_request->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }


    // _edit_user_star_subscription_post_request->is_canceled
    if (!_edit_user_star_subscription_post_request->is_canceled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_canceled", _edit_user_star_subscription_post_request->is_canceled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_parseFromJSON(cJSON *_edit_user_star_subscription_post_requestJSON){

    _edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_local_var = NULL;

    // _edit_user_star_subscription_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_edit_user_star_subscription_post_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // _edit_user_star_subscription_post_request->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(_edit_user_star_subscription_post_requestJSON, "telegram_payment_charge_id");
    if (cJSON_IsNull(telegram_payment_charge_id)) {
        telegram_payment_charge_id = NULL;
    }
    if (!telegram_payment_charge_id) {
        goto end;
    }

    
    if(!cJSON_IsString(telegram_payment_charge_id))
    {
    goto end; //String
    }

    // _edit_user_star_subscription_post_request->is_canceled
    cJSON *is_canceled = cJSON_GetObjectItemCaseSensitive(_edit_user_star_subscription_post_requestJSON, "is_canceled");
    if (cJSON_IsNull(is_canceled)) {
        is_canceled = NULL;
    }
    if (!is_canceled) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_canceled))
    {
    goto end; //Bool
    }


    _edit_user_star_subscription_post_request_local_var = _edit_user_star_subscription_post_request_create_internal (
        user_id->valuedouble,
        strdup(telegram_payment_charge_id->valuestring),
        is_canceled->valueint
        );

    return _edit_user_star_subscription_post_request_local_var;
end:
    return NULL;

}
