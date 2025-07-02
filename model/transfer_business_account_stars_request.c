#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transfer_business_account_stars_request.h"



static transfer_business_account_stars_request_t *transfer_business_account_stars_request_create_internal(
    char *business_connection_id,
    int star_count
    ) {
    transfer_business_account_stars_request_t *transfer_business_account_stars_request_local_var = malloc(sizeof(transfer_business_account_stars_request_t));
    if (!transfer_business_account_stars_request_local_var) {
        return NULL;
    }
    transfer_business_account_stars_request_local_var->business_connection_id = business_connection_id;
    transfer_business_account_stars_request_local_var->star_count = star_count;

    transfer_business_account_stars_request_local_var->_library_owned = 1;
    return transfer_business_account_stars_request_local_var;
}

__attribute__((deprecated)) transfer_business_account_stars_request_t *transfer_business_account_stars_request_create(
    char *business_connection_id,
    int star_count
    ) {
    return transfer_business_account_stars_request_create_internal (
        business_connection_id,
        star_count
        );
}

void transfer_business_account_stars_request_free(transfer_business_account_stars_request_t *transfer_business_account_stars_request) {
    if(NULL == transfer_business_account_stars_request){
        return ;
    }
    if(transfer_business_account_stars_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "transfer_business_account_stars_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (transfer_business_account_stars_request->business_connection_id) {
        free(transfer_business_account_stars_request->business_connection_id);
        transfer_business_account_stars_request->business_connection_id = NULL;
    }
    free(transfer_business_account_stars_request);
}

cJSON *transfer_business_account_stars_request_convertToJSON(transfer_business_account_stars_request_t *transfer_business_account_stars_request) {
    cJSON *item = cJSON_CreateObject();

    // transfer_business_account_stars_request->business_connection_id
    if (!transfer_business_account_stars_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", transfer_business_account_stars_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // transfer_business_account_stars_request->star_count
    if (!transfer_business_account_stars_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", transfer_business_account_stars_request->star_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

transfer_business_account_stars_request_t *transfer_business_account_stars_request_parseFromJSON(cJSON *transfer_business_account_stars_requestJSON){

    transfer_business_account_stars_request_t *transfer_business_account_stars_request_local_var = NULL;

    // transfer_business_account_stars_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(transfer_business_account_stars_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // transfer_business_account_stars_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(transfer_business_account_stars_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }


    transfer_business_account_stars_request_local_var = transfer_business_account_stars_request_create_internal (
        strdup(business_connection_id->valuestring),
        star_count->valuedouble
        );

    return transfer_business_account_stars_request_local_var;
end:
    return NULL;

}
