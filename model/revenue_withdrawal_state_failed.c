#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revenue_withdrawal_state_failed.h"



static revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_create_internal(
    char *type
    ) {
    revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_local_var = malloc(sizeof(revenue_withdrawal_state_failed_t));
    if (!revenue_withdrawal_state_failed_local_var) {
        return NULL;
    }
    revenue_withdrawal_state_failed_local_var->type = type;

    revenue_withdrawal_state_failed_local_var->_library_owned = 1;
    return revenue_withdrawal_state_failed_local_var;
}

__attribute__((deprecated)) revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_create(
    char *type
    ) {
    return revenue_withdrawal_state_failed_create_internal (
        type
        );
}

void revenue_withdrawal_state_failed_free(revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed) {
    if(NULL == revenue_withdrawal_state_failed){
        return ;
    }
    if(revenue_withdrawal_state_failed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revenue_withdrawal_state_failed_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revenue_withdrawal_state_failed->type) {
        free(revenue_withdrawal_state_failed->type);
        revenue_withdrawal_state_failed->type = NULL;
    }
    free(revenue_withdrawal_state_failed);
}

cJSON *revenue_withdrawal_state_failed_convertToJSON(revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed) {
    cJSON *item = cJSON_CreateObject();

    // revenue_withdrawal_state_failed->type
    if (!revenue_withdrawal_state_failed->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", revenue_withdrawal_state_failed->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_parseFromJSON(cJSON *revenue_withdrawal_state_failedJSON){

    revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_local_var = NULL;

    // revenue_withdrawal_state_failed->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_state_failedJSON, "type");
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


    revenue_withdrawal_state_failed_local_var = revenue_withdrawal_state_failed_create_internal (
        strdup(type->valuestring)
        );

    return revenue_withdrawal_state_failed_local_var;
end:
    return NULL;

}
