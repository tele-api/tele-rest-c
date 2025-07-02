#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "refund_star_payment_request.h"



static refund_star_payment_request_t *refund_star_payment_request_create_internal(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    refund_star_payment_request_t *refund_star_payment_request_local_var = malloc(sizeof(refund_star_payment_request_t));
    if (!refund_star_payment_request_local_var) {
        return NULL;
    }
    refund_star_payment_request_local_var->user_id = user_id;
    refund_star_payment_request_local_var->telegram_payment_charge_id = telegram_payment_charge_id;

    refund_star_payment_request_local_var->_library_owned = 1;
    return refund_star_payment_request_local_var;
}

__attribute__((deprecated)) refund_star_payment_request_t *refund_star_payment_request_create(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    return refund_star_payment_request_create_internal (
        user_id,
        telegram_payment_charge_id
        );
}

void refund_star_payment_request_free(refund_star_payment_request_t *refund_star_payment_request) {
    if(NULL == refund_star_payment_request){
        return ;
    }
    if(refund_star_payment_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "refund_star_payment_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (refund_star_payment_request->telegram_payment_charge_id) {
        free(refund_star_payment_request->telegram_payment_charge_id);
        refund_star_payment_request->telegram_payment_charge_id = NULL;
    }
    free(refund_star_payment_request);
}

cJSON *refund_star_payment_request_convertToJSON(refund_star_payment_request_t *refund_star_payment_request) {
    cJSON *item = cJSON_CreateObject();

    // refund_star_payment_request->user_id
    if (!refund_star_payment_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", refund_star_payment_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // refund_star_payment_request->telegram_payment_charge_id
    if (!refund_star_payment_request->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", refund_star_payment_request->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

refund_star_payment_request_t *refund_star_payment_request_parseFromJSON(cJSON *refund_star_payment_requestJSON){

    refund_star_payment_request_t *refund_star_payment_request_local_var = NULL;

    // refund_star_payment_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(refund_star_payment_requestJSON, "user_id");
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

    // refund_star_payment_request->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(refund_star_payment_requestJSON, "telegram_payment_charge_id");
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


    refund_star_payment_request_local_var = refund_star_payment_request_create_internal (
        user_id->valuedouble,
        strdup(telegram_payment_charge_id->valuestring)
        );

    return refund_star_payment_request_local_var;
end:
    return NULL;

}
