#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_telegram_api.h"



static transaction_partner_telegram_api_t *transaction_partner_telegram_api_create_internal(
    char *type,
    int request_count
    ) {
    transaction_partner_telegram_api_t *transaction_partner_telegram_api_local_var = malloc(sizeof(transaction_partner_telegram_api_t));
    if (!transaction_partner_telegram_api_local_var) {
        return NULL;
    }
    transaction_partner_telegram_api_local_var->type = type;
    transaction_partner_telegram_api_local_var->request_count = request_count;

    transaction_partner_telegram_api_local_var->_library_owned = 1;
    return transaction_partner_telegram_api_local_var;
}

__attribute__((deprecated)) transaction_partner_telegram_api_t *transaction_partner_telegram_api_create(
    char *type,
    int request_count
    ) {
    return transaction_partner_telegram_api_create_internal (
        type,
        request_count
        );
}

void transaction_partner_telegram_api_free(transaction_partner_telegram_api_t *transaction_partner_telegram_api) {
    if(NULL == transaction_partner_telegram_api){
        return ;
    }
    if(transaction_partner_telegram_api->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_telegram_api_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_telegram_api->type) {
        free(transaction_partner_telegram_api->type);
        transaction_partner_telegram_api->type = NULL;
    }
    free(transaction_partner_telegram_api);
}

cJSON *transaction_partner_telegram_api_convertToJSON(transaction_partner_telegram_api_t *transaction_partner_telegram_api) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_telegram_api->type
    if (!transaction_partner_telegram_api->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_telegram_api->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner_telegram_api->request_count
    if (!transaction_partner_telegram_api->request_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "request_count", transaction_partner_telegram_api->request_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_partner_telegram_api_t *transaction_partner_telegram_api_parseFromJSON(cJSON *transaction_partner_telegram_apiJSON){

    transaction_partner_telegram_api_t *transaction_partner_telegram_api_local_var = NULL;

    // transaction_partner_telegram_api->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_telegram_apiJSON, "type");
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

    // transaction_partner_telegram_api->request_count
    cJSON *request_count = cJSON_GetObjectItemCaseSensitive(transaction_partner_telegram_apiJSON, "request_count");
    if (cJSON_IsNull(request_count)) {
        request_count = NULL;
    }
    if (!request_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(request_count))
    {
    goto end; //Numeric
    }


    transaction_partner_telegram_api_local_var = transaction_partner_telegram_api_create_internal (
        strdup(type->valuestring),
        request_count->valuedouble
        );

    return transaction_partner_telegram_api_local_var;
end:
    return NULL;

}
