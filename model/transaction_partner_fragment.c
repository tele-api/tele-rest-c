#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_fragment.h"



static transaction_partner_fragment_t *transaction_partner_fragment_create_internal(
    char *type,
    revenue_withdrawal_state_t *withdrawal_state
    ) {
    transaction_partner_fragment_t *transaction_partner_fragment_local_var = malloc(sizeof(transaction_partner_fragment_t));
    if (!transaction_partner_fragment_local_var) {
        return NULL;
    }
    transaction_partner_fragment_local_var->type = type;
    transaction_partner_fragment_local_var->withdrawal_state = withdrawal_state;

    transaction_partner_fragment_local_var->_library_owned = 1;
    return transaction_partner_fragment_local_var;
}

__attribute__((deprecated)) transaction_partner_fragment_t *transaction_partner_fragment_create(
    char *type,
    revenue_withdrawal_state_t *withdrawal_state
    ) {
    return transaction_partner_fragment_create_internal (
        type,
        withdrawal_state
        );
}

void transaction_partner_fragment_free(transaction_partner_fragment_t *transaction_partner_fragment) {
    if(NULL == transaction_partner_fragment){
        return ;
    }
    if(transaction_partner_fragment->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_fragment_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_fragment->type) {
        free(transaction_partner_fragment->type);
        transaction_partner_fragment->type = NULL;
    }
    if (transaction_partner_fragment->withdrawal_state) {
        revenue_withdrawal_state_free(transaction_partner_fragment->withdrawal_state);
        transaction_partner_fragment->withdrawal_state = NULL;
    }
    free(transaction_partner_fragment);
}

cJSON *transaction_partner_fragment_convertToJSON(transaction_partner_fragment_t *transaction_partner_fragment) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_fragment->type
    if (!transaction_partner_fragment->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_fragment->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner_fragment->withdrawal_state
    if(transaction_partner_fragment->withdrawal_state) {
    cJSON *withdrawal_state_local_JSON = revenue_withdrawal_state_convertToJSON(transaction_partner_fragment->withdrawal_state);
    if(withdrawal_state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "withdrawal_state", withdrawal_state_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_partner_fragment_t *transaction_partner_fragment_parseFromJSON(cJSON *transaction_partner_fragmentJSON){

    transaction_partner_fragment_t *transaction_partner_fragment_local_var = NULL;

    // define the local variable for transaction_partner_fragment->withdrawal_state
    revenue_withdrawal_state_t *withdrawal_state_local_nonprim = NULL;

    // transaction_partner_fragment->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_fragmentJSON, "type");
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

    // transaction_partner_fragment->withdrawal_state
    cJSON *withdrawal_state = cJSON_GetObjectItemCaseSensitive(transaction_partner_fragmentJSON, "withdrawal_state");
    if (cJSON_IsNull(withdrawal_state)) {
        withdrawal_state = NULL;
    }
    if (withdrawal_state) { 
    withdrawal_state_local_nonprim = revenue_withdrawal_state_parseFromJSON(withdrawal_state); //nonprimitive
    }


    transaction_partner_fragment_local_var = transaction_partner_fragment_create_internal (
        strdup(type->valuestring),
        withdrawal_state ? withdrawal_state_local_nonprim : NULL
        );

    return transaction_partner_fragment_local_var;
end:
    if (withdrawal_state_local_nonprim) {
        revenue_withdrawal_state_free(withdrawal_state_local_nonprim);
        withdrawal_state_local_nonprim = NULL;
    }
    return NULL;

}
