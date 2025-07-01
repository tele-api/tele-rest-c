#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_affiliate_program.h"



static transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_create_internal(
    char *type,
    int commission_per_mille,
    user_t *sponsor_user
    ) {
    transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_local_var = malloc(sizeof(transaction_partner_affiliate_program_t));
    if (!transaction_partner_affiliate_program_local_var) {
        return NULL;
    }
    transaction_partner_affiliate_program_local_var->type = type;
    transaction_partner_affiliate_program_local_var->commission_per_mille = commission_per_mille;
    transaction_partner_affiliate_program_local_var->sponsor_user = sponsor_user;

    transaction_partner_affiliate_program_local_var->_library_owned = 1;
    return transaction_partner_affiliate_program_local_var;
}

__attribute__((deprecated)) transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_create(
    char *type,
    int commission_per_mille,
    user_t *sponsor_user
    ) {
    return transaction_partner_affiliate_program_create_internal (
        type,
        commission_per_mille,
        sponsor_user
        );
}

void transaction_partner_affiliate_program_free(transaction_partner_affiliate_program_t *transaction_partner_affiliate_program) {
    if(NULL == transaction_partner_affiliate_program){
        return ;
    }
    if(transaction_partner_affiliate_program->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_affiliate_program_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_affiliate_program->type) {
        free(transaction_partner_affiliate_program->type);
        transaction_partner_affiliate_program->type = NULL;
    }
    if (transaction_partner_affiliate_program->sponsor_user) {
        user_free(transaction_partner_affiliate_program->sponsor_user);
        transaction_partner_affiliate_program->sponsor_user = NULL;
    }
    free(transaction_partner_affiliate_program);
}

cJSON *transaction_partner_affiliate_program_convertToJSON(transaction_partner_affiliate_program_t *transaction_partner_affiliate_program) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_affiliate_program->type
    if (!transaction_partner_affiliate_program->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_affiliate_program->type) == NULL) {
    goto fail; //String
    }


    // transaction_partner_affiliate_program->commission_per_mille
    if (!transaction_partner_affiliate_program->commission_per_mille) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "commission_per_mille", transaction_partner_affiliate_program->commission_per_mille) == NULL) {
    goto fail; //Numeric
    }


    // transaction_partner_affiliate_program->sponsor_user
    if(transaction_partner_affiliate_program->sponsor_user) {
    cJSON *sponsor_user_local_JSON = user_convertToJSON(transaction_partner_affiliate_program->sponsor_user);
    if(sponsor_user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sponsor_user", sponsor_user_local_JSON);
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

transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_parseFromJSON(cJSON *transaction_partner_affiliate_programJSON){

    transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_local_var = NULL;

    // define the local variable for transaction_partner_affiliate_program->sponsor_user
    user_t *sponsor_user_local_nonprim = NULL;

    // transaction_partner_affiliate_program->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_affiliate_programJSON, "type");
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

    // transaction_partner_affiliate_program->commission_per_mille
    cJSON *commission_per_mille = cJSON_GetObjectItemCaseSensitive(transaction_partner_affiliate_programJSON, "commission_per_mille");
    if (cJSON_IsNull(commission_per_mille)) {
        commission_per_mille = NULL;
    }
    if (!commission_per_mille) {
        goto end;
    }

    
    if(!cJSON_IsNumber(commission_per_mille))
    {
    goto end; //Numeric
    }

    // transaction_partner_affiliate_program->sponsor_user
    cJSON *sponsor_user = cJSON_GetObjectItemCaseSensitive(transaction_partner_affiliate_programJSON, "sponsor_user");
    if (cJSON_IsNull(sponsor_user)) {
        sponsor_user = NULL;
    }
    if (sponsor_user) { 
    sponsor_user_local_nonprim = user_parseFromJSON(sponsor_user); //nonprimitive
    }


    transaction_partner_affiliate_program_local_var = transaction_partner_affiliate_program_create_internal (
        strdup(type->valuestring),
        commission_per_mille->valuedouble,
        sponsor_user ? sponsor_user_local_nonprim : NULL
        );

    return transaction_partner_affiliate_program_local_var;
end:
    if (sponsor_user_local_nonprim) {
        user_free(sponsor_user_local_nonprim);
        sponsor_user_local_nonprim = NULL;
    }
    return NULL;

}
