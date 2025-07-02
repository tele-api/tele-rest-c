#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upgrade_gift_request.h"



static upgrade_gift_request_t *upgrade_gift_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    upgrade_gift_request_t *upgrade_gift_request_local_var = malloc(sizeof(upgrade_gift_request_t));
    if (!upgrade_gift_request_local_var) {
        return NULL;
    }
    upgrade_gift_request_local_var->business_connection_id = business_connection_id;
    upgrade_gift_request_local_var->owned_gift_id = owned_gift_id;
    upgrade_gift_request_local_var->keep_original_details = keep_original_details;
    upgrade_gift_request_local_var->star_count = star_count;

    upgrade_gift_request_local_var->_library_owned = 1;
    return upgrade_gift_request_local_var;
}

__attribute__((deprecated)) upgrade_gift_request_t *upgrade_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    return upgrade_gift_request_create_internal (
        business_connection_id,
        owned_gift_id,
        keep_original_details,
        star_count
        );
}

void upgrade_gift_request_free(upgrade_gift_request_t *upgrade_gift_request) {
    if(NULL == upgrade_gift_request){
        return ;
    }
    if(upgrade_gift_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "upgrade_gift_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (upgrade_gift_request->business_connection_id) {
        free(upgrade_gift_request->business_connection_id);
        upgrade_gift_request->business_connection_id = NULL;
    }
    if (upgrade_gift_request->owned_gift_id) {
        free(upgrade_gift_request->owned_gift_id);
        upgrade_gift_request->owned_gift_id = NULL;
    }
    free(upgrade_gift_request);
}

cJSON *upgrade_gift_request_convertToJSON(upgrade_gift_request_t *upgrade_gift_request) {
    cJSON *item = cJSON_CreateObject();

    // upgrade_gift_request->business_connection_id
    if (!upgrade_gift_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", upgrade_gift_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // upgrade_gift_request->owned_gift_id
    if (!upgrade_gift_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", upgrade_gift_request->owned_gift_id) == NULL) {
    goto fail; //String
    }


    // upgrade_gift_request->keep_original_details
    if(upgrade_gift_request->keep_original_details) {
    if(cJSON_AddBoolToObject(item, "keep_original_details", upgrade_gift_request->keep_original_details) == NULL) {
    goto fail; //Bool
    }
    }


    // upgrade_gift_request->star_count
    if(upgrade_gift_request->star_count) {
    if(cJSON_AddNumberToObject(item, "star_count", upgrade_gift_request->star_count) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

upgrade_gift_request_t *upgrade_gift_request_parseFromJSON(cJSON *upgrade_gift_requestJSON){

    upgrade_gift_request_t *upgrade_gift_request_local_var = NULL;

    // upgrade_gift_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(upgrade_gift_requestJSON, "business_connection_id");
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

    // upgrade_gift_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(upgrade_gift_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }

    // upgrade_gift_request->keep_original_details
    cJSON *keep_original_details = cJSON_GetObjectItemCaseSensitive(upgrade_gift_requestJSON, "keep_original_details");
    if (cJSON_IsNull(keep_original_details)) {
        keep_original_details = NULL;
    }
    if (keep_original_details) { 
    if(!cJSON_IsBool(keep_original_details))
    {
    goto end; //Bool
    }
    }

    // upgrade_gift_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(upgrade_gift_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (star_count) { 
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }
    }


    upgrade_gift_request_local_var = upgrade_gift_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring),
        keep_original_details ? keep_original_details->valueint : 0,
        star_count ? star_count->valuedouble : 0
        );

    return upgrade_gift_request_local_var;
end:
    return NULL;

}
