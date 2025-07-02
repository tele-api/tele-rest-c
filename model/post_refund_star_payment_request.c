#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_refund_star_payment_request.h"



static post_refund_star_payment_request_t *post_refund_star_payment_request_create_internal(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    post_refund_star_payment_request_t *post_refund_star_payment_request_local_var = malloc(sizeof(post_refund_star_payment_request_t));
    if (!post_refund_star_payment_request_local_var) {
        return NULL;
    }
    post_refund_star_payment_request_local_var->user_id = user_id;
    post_refund_star_payment_request_local_var->telegram_payment_charge_id = telegram_payment_charge_id;

    post_refund_star_payment_request_local_var->_library_owned = 1;
    return post_refund_star_payment_request_local_var;
}

__attribute__((deprecated)) post_refund_star_payment_request_t *post_refund_star_payment_request_create(
    int user_id,
    char *telegram_payment_charge_id
    ) {
    return post_refund_star_payment_request_create_internal (
        user_id,
        telegram_payment_charge_id
        );
}

void post_refund_star_payment_request_free(post_refund_star_payment_request_t *post_refund_star_payment_request) {
    if(NULL == post_refund_star_payment_request){
        return ;
    }
    if(post_refund_star_payment_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_refund_star_payment_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_refund_star_payment_request->telegram_payment_charge_id) {
        free(post_refund_star_payment_request->telegram_payment_charge_id);
        post_refund_star_payment_request->telegram_payment_charge_id = NULL;
    }
    free(post_refund_star_payment_request);
}

cJSON *post_refund_star_payment_request_convertToJSON(post_refund_star_payment_request_t *post_refund_star_payment_request) {
    cJSON *item = cJSON_CreateObject();

    // post_refund_star_payment_request->user_id
    if (!post_refund_star_payment_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_refund_star_payment_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_refund_star_payment_request->telegram_payment_charge_id
    if (!post_refund_star_payment_request->telegram_payment_charge_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "telegram_payment_charge_id", post_refund_star_payment_request->telegram_payment_charge_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_refund_star_payment_request_t *post_refund_star_payment_request_parseFromJSON(cJSON *post_refund_star_payment_requestJSON){

    post_refund_star_payment_request_t *post_refund_star_payment_request_local_var = NULL;

    // post_refund_star_payment_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_refund_star_payment_requestJSON, "user_id");
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

    // post_refund_star_payment_request->telegram_payment_charge_id
    cJSON *telegram_payment_charge_id = cJSON_GetObjectItemCaseSensitive(post_refund_star_payment_requestJSON, "telegram_payment_charge_id");
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


    post_refund_star_payment_request_local_var = post_refund_star_payment_request_create_internal (
        user_id->valuedouble,
        strdup(telegram_payment_charge_id->valuestring)
        );

    return post_refund_star_payment_request_local_var;
end:
    return NULL;

}
