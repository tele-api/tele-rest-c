#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_telegram_ads.h"



static transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_create_internal(
    char *type
    ) {
    transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_local_var = malloc(sizeof(transaction_partner_telegram_ads_t));
    if (!transaction_partner_telegram_ads_local_var) {
        return NULL;
    }
    transaction_partner_telegram_ads_local_var->type = type;

    transaction_partner_telegram_ads_local_var->_library_owned = 1;
    return transaction_partner_telegram_ads_local_var;
}

__attribute__((deprecated)) transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_create(
    char *type
    ) {
    return transaction_partner_telegram_ads_create_internal (
        type
        );
}

void transaction_partner_telegram_ads_free(transaction_partner_telegram_ads_t *transaction_partner_telegram_ads) {
    if(NULL == transaction_partner_telegram_ads){
        return ;
    }
    if(transaction_partner_telegram_ads->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_telegram_ads_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_telegram_ads->type) {
        free(transaction_partner_telegram_ads->type);
        transaction_partner_telegram_ads->type = NULL;
    }
    free(transaction_partner_telegram_ads);
}

cJSON *transaction_partner_telegram_ads_convertToJSON(transaction_partner_telegram_ads_t *transaction_partner_telegram_ads) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_telegram_ads->type
    if (!transaction_partner_telegram_ads->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_telegram_ads->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_parseFromJSON(cJSON *transaction_partner_telegram_adsJSON){

    transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_local_var = NULL;

    // transaction_partner_telegram_ads->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_telegram_adsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    transaction_partner_telegram_ads_local_var = transaction_partner_telegram_ads_create_internal (
        strdup(type->valuestring)
        );

    return transaction_partner_telegram_ads_local_var;
end:
    return NULL;

}
