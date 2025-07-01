#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_refund_star_payment_post_request.h"



static _refund_star_payment_post_request_t *_refund_star_payment_post_request_create_internal(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    _refund_star_payment_post_request_t *_refund_star_payment_post_request_local_var = malloc(sizeof(_refund_star_payment_post_request_t));
    if (!_refund_star_payment_post_request_local_var) {
        return NULL;
    }
    _refund_star_payment_post_request_local_var->user_id = user_id;
    _refund_star_payment_post_request_local_var->telegram_payment_charge_id = telegram_payment_charge_id;

    _refund_star_payment_post_request_local_var->_library_owned = 1;
    return _refund_star_payment_post_request_local_var;
}

__attribute__((deprecated)) _refund_star_payment_post_request_t *_refund_star_payment_post_request_create(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    return _refund_star_payment_post_request_create_internal (
        user_id,
        telegram_payment_charge_id
        );
}

void _refund_star_payment_post_request_free(_refund_star_payment_post_request_t *_refund_star_payment_post_request) {
    if(NULL == _refund_star_payment_post_request){
        return ;
    }
    if(_refund_star_payment_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_refund_star_payment_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_refund_star_payment_post_request->telegram_payment_charge_id) {
        free(_refund_star_payment_post_request->telegram_payment_charge_id);
        _refund_star_payment_post_request->telegram_payment_charge_id = NULL;
    }
    free(_refund_star_payment_post_request);
}

cJSON *_refund_star_payment_post_request_convertToJSON(_refund_star_payment_post_request_t *_refund_star_payment_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _refund_star_payment_post_request->user_id
    if (!_refund_star_payment_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _refund_star_payment_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _refund_star_payment_post_request->telegram_payment_charge_id
    if (!_refund_star_payment_post_request->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", _refund_star_payment_post_request->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_refund_star_payment_post_request_t *_refund_star_payment_post_request_parseFromJSON(cJSON *_refund_star_payment_post_requestJSON){

    _refund_star_payment_post_request_t *_refund_star_payment_post_request_local_var = NULL;

    // _refund_star_payment_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_refund_star_payment_post_requestJSON, "user_id");
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

    // _refund_star_payment_post_request->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(_refund_star_payment_post_requestJSON, "telegram_payment_charge_id");
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


    _refund_star_payment_post_request_local_var = _refund_star_payment_post_request_create_internal (
        user_id->valuedouble,
        strdup(telegram_payment_charge_id->valuestring)
        );

    return _refund_star_payment_post_request_local_var;
end:
    return NULL;

}
