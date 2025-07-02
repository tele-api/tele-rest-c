#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "edit_user_star_subscription_request.h"



static edit_user_star_subscription_request_t *edit_user_star_subscription_request_create_internal(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
    ) {
    edit_user_star_subscription_request_t *edit_user_star_subscription_request_local_var = malloc(sizeof(edit_user_star_subscription_request_t));
    if (!edit_user_star_subscription_request_local_var) {
        return NULL;
    }
    edit_user_star_subscription_request_local_var->user_id = user_id;
    edit_user_star_subscription_request_local_var->telegram_payment_charge_id = telegram_payment_charge_id;
    edit_user_star_subscription_request_local_var->is_canceled = is_canceled;

    edit_user_star_subscription_request_local_var->_library_owned = 1;
    return edit_user_star_subscription_request_local_var;
}

__attribute__((deprecated)) edit_user_star_subscription_request_t *edit_user_star_subscription_request_create(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
    ) {
    return edit_user_star_subscription_request_create_internal (
        user_id,
        telegram_payment_charge_id,
        is_canceled
        );
}

void edit_user_star_subscription_request_free(edit_user_star_subscription_request_t *edit_user_star_subscription_request) {
    if(NULL == edit_user_star_subscription_request){
        return ;
    }
    if(edit_user_star_subscription_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "edit_user_star_subscription_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (edit_user_star_subscription_request->telegram_payment_charge_id) {
        free(edit_user_star_subscription_request->telegram_payment_charge_id);
        edit_user_star_subscription_request->telegram_payment_charge_id = NULL;
    }
    free(edit_user_star_subscription_request);
}

cJSON *edit_user_star_subscription_request_convertToJSON(edit_user_star_subscription_request_t *edit_user_star_subscription_request) {
    cJSON *item = cJSON_CreateObject();

    // edit_user_star_subscription_request->user_id
    if (!edit_user_star_subscription_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", edit_user_star_subscription_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // edit_user_star_subscription_request->telegram_payment_charge_id
    if (!edit_user_star_subscription_request->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", edit_user_star_subscription_request->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }


    // edit_user_star_subscription_request->is_canceled
    if (!edit_user_star_subscription_request->is_canceled) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_canceled", edit_user_star_subscription_request->is_canceled) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

edit_user_star_subscription_request_t *edit_user_star_subscription_request_parseFromJSON(cJSON *edit_user_star_subscription_requestJSON){

    edit_user_star_subscription_request_t *edit_user_star_subscription_request_local_var = NULL;

    // edit_user_star_subscription_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(edit_user_star_subscription_requestJSON, "user_id");
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

    // edit_user_star_subscription_request->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(edit_user_star_subscription_requestJSON, "telegram_payment_charge_id");
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

    // edit_user_star_subscription_request->is_canceled
    cJSON *is_canceled = cJSON_GetObjectItemCaseSensitive(edit_user_star_subscription_requestJSON, "is_canceled");
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


    edit_user_star_subscription_request_local_var = edit_user_star_subscription_request_create_internal (
        user_id->valuedouble,
        strdup(telegram_payment_charge_id->valuestring),
        is_canceled->valueint
        );

    return edit_user_star_subscription_request_local_var;
end:
    return NULL;

}
