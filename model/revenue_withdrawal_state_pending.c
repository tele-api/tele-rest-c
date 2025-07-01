#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "revenue_withdrawal_state_pending.h"



static revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_create_internal(
    char *type
    ) {
    revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_local_var = malloc(sizeof(revenue_withdrawal_state_pending_t));
    if (!revenue_withdrawal_state_pending_local_var) {
        return NULL;
    }
    revenue_withdrawal_state_pending_local_var->type = type;

    revenue_withdrawal_state_pending_local_var->_library_owned = 1;
    return revenue_withdrawal_state_pending_local_var;
}

__attribute__((deprecated)) revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_create(
    char *type
    ) {
    return revenue_withdrawal_state_pending_create_internal (
        type
        );
}

void revenue_withdrawal_state_pending_free(revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending) {
    if(NULL == revenue_withdrawal_state_pending){
        return ;
    }
    if(revenue_withdrawal_state_pending->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "revenue_withdrawal_state_pending_free");
        return ;
    }
    listEntry_t *listEntry;
    if (revenue_withdrawal_state_pending->type) {
        free(revenue_withdrawal_state_pending->type);
        revenue_withdrawal_state_pending->type = NULL;
    }
    free(revenue_withdrawal_state_pending);
}

cJSON *revenue_withdrawal_state_pending_convertToJSON(revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending) {
    cJSON *item = cJSON_CreateObject();

    // revenue_withdrawal_state_pending->type
    if (!revenue_withdrawal_state_pending->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", revenue_withdrawal_state_pending->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_parseFromJSON(cJSON *revenue_withdrawal_state_pendingJSON){

    revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_local_var = NULL;

    // revenue_withdrawal_state_pending->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(revenue_withdrawal_state_pendingJSON, "type");
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


    revenue_withdrawal_state_pending_local_var = revenue_withdrawal_state_pending_create_internal (
        strdup(type->valuestring)
        );

    return revenue_withdrawal_state_pending_local_var;
end:
    return NULL;

}
