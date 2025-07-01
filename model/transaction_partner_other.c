#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_partner_other.h"



static transaction_partner_other_t *transaction_partner_other_create_internal(
    char *type
    ) {
    transaction_partner_other_t *transaction_partner_other_local_var = malloc(sizeof(transaction_partner_other_t));
    if (!transaction_partner_other_local_var) {
        return NULL;
    }
    transaction_partner_other_local_var->type = type;

    transaction_partner_other_local_var->_library_owned = 1;
    return transaction_partner_other_local_var;
}

__attribute__((deprecated)) transaction_partner_other_t *transaction_partner_other_create(
    char *type
    ) {
    return transaction_partner_other_create_internal (
        type
        );
}

void transaction_partner_other_free(transaction_partner_other_t *transaction_partner_other) {
    if(NULL == transaction_partner_other){
        return ;
    }
    if(transaction_partner_other->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transaction_partner_other_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transaction_partner_other->type) {
        free(transaction_partner_other->type);
        transaction_partner_other->type = NULL;
    }
    free(transaction_partner_other);
}

cJSON *transaction_partner_other_convertToJSON(transaction_partner_other_t *transaction_partner_other) {
    cJSON *item = cJSON_CreateObject();

    // transaction_partner_other->type
    if (!transaction_partner_other->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", transaction_partner_other->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transaction_partner_other_t *transaction_partner_other_parseFromJSON(cJSON *transaction_partner_otherJSON){

    transaction_partner_other_t *transaction_partner_other_local_var = NULL;

    // transaction_partner_other->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_partner_otherJSON, "type");
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


    transaction_partner_other_local_var = transaction_partner_other_create_internal (
        strdup(type->valuestring)
        );

    return transaction_partner_other_local_var;
end:
    return NULL;

}
