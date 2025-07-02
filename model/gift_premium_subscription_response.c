#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gift_premium_subscription_response.h"



static gift_premium_subscription_response_t *gift_premium_subscription_response_create_internal(
    int ok,
    int result
    ) {
    gift_premium_subscription_response_t *gift_premium_subscription_response_local_var = malloc(sizeof(gift_premium_subscription_response_t));
    if (!gift_premium_subscription_response_local_var) {
        return NULL;
    }
    gift_premium_subscription_response_local_var->ok = ok;
    gift_premium_subscription_response_local_var->result = result;

    gift_premium_subscription_response_local_var->_library_owned = 1;
    return gift_premium_subscription_response_local_var;
}

__attribute__((deprecated)) gift_premium_subscription_response_t *gift_premium_subscription_response_create(
    int ok,
    int result
    ) {
    return gift_premium_subscription_response_create_internal (
        ok,
        result
        );
}

void gift_premium_subscription_response_free(gift_premium_subscription_response_t *gift_premium_subscription_response) {
    if(NULL == gift_premium_subscription_response){
        return ;
    }
    if(gift_premium_subscription_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gift_premium_subscription_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(gift_premium_subscription_response);
}

cJSON *gift_premium_subscription_response_convertToJSON(gift_premium_subscription_response_t *gift_premium_subscription_response) {
    cJSON *item = cJSON_CreateObject();

    // gift_premium_subscription_response->ok
    if (!gift_premium_subscription_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", gift_premium_subscription_response->ok) == NULL) {
    goto fail; //Bool
    }


    // gift_premium_subscription_response->result
    if (!gift_premium_subscription_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", gift_premium_subscription_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gift_premium_subscription_response_t *gift_premium_subscription_response_parseFromJSON(cJSON *gift_premium_subscription_responseJSON){

    gift_premium_subscription_response_t *gift_premium_subscription_response_local_var = NULL;

    // gift_premium_subscription_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_responseJSON, "ok");
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

    // gift_premium_subscription_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(gift_premium_subscription_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    gift_premium_subscription_response_local_var = gift_premium_subscription_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return gift_premium_subscription_response_local_var;
end:
    return NULL;

}
