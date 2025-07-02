#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_business_account_gifts_request.h"



static get_business_account_gifts_request_t *get_business_account_gifts_request_create_internal(
    char *business_connection_id,
    int exclude_unsaved,
    int exclude_saved,
    int exclude_unlimited,
    int exclude_limited,
    int exclude_unique,
    int sort_by_price,
    char *offset,
    int limit
    ) {
    get_business_account_gifts_request_t *get_business_account_gifts_request_local_var = malloc(sizeof(get_business_account_gifts_request_t));
    if (!get_business_account_gifts_request_local_var) {
        return NULL;
    }
    get_business_account_gifts_request_local_var->business_connection_id = business_connection_id;
    get_business_account_gifts_request_local_var->exclude_unsaved = exclude_unsaved;
    get_business_account_gifts_request_local_var->exclude_saved = exclude_saved;
    get_business_account_gifts_request_local_var->exclude_unlimited = exclude_unlimited;
    get_business_account_gifts_request_local_var->exclude_limited = exclude_limited;
    get_business_account_gifts_request_local_var->exclude_unique = exclude_unique;
    get_business_account_gifts_request_local_var->sort_by_price = sort_by_price;
    get_business_account_gifts_request_local_var->offset = offset;
    get_business_account_gifts_request_local_var->limit = limit;

    get_business_account_gifts_request_local_var->_library_owned = 1;
    return get_business_account_gifts_request_local_var;
}

__attribute__((deprecated)) get_business_account_gifts_request_t *get_business_account_gifts_request_create(
    char *business_connection_id,
    int exclude_unsaved,
    int exclude_saved,
    int exclude_unlimited,
    int exclude_limited,
    int exclude_unique,
    int sort_by_price,
    char *offset,
    int limit
    ) {
    return get_business_account_gifts_request_create_internal (
        business_connection_id,
        exclude_unsaved,
        exclude_saved,
        exclude_unlimited,
        exclude_limited,
        exclude_unique,
        sort_by_price,
        offset,
        limit
        );
}

void get_business_account_gifts_request_free(get_business_account_gifts_request_t *get_business_account_gifts_request) {
    if(NULL == get_business_account_gifts_request){
        return ;
    }
    if(get_business_account_gifts_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_business_account_gifts_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_business_account_gifts_request->business_connection_id) {
        free(get_business_account_gifts_request->business_connection_id);
        get_business_account_gifts_request->business_connection_id = NULL;
    }
    if (get_business_account_gifts_request->offset) {
        free(get_business_account_gifts_request->offset);
        get_business_account_gifts_request->offset = NULL;
    }
    free(get_business_account_gifts_request);
}

cJSON *get_business_account_gifts_request_convertToJSON(get_business_account_gifts_request_t *get_business_account_gifts_request) {
    cJSON *item = cJSON_CreateObject();

    // get_business_account_gifts_request->business_connection_id
    if (!get_business_account_gifts_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", get_business_account_gifts_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // get_business_account_gifts_request->exclude_unsaved
    if(get_business_account_gifts_request->exclude_unsaved) {
    if(cJSON_AddBoolToObject(item, "exclude_unsaved", get_business_account_gifts_request->exclude_unsaved) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->exclude_saved
    if(get_business_account_gifts_request->exclude_saved) {
    if(cJSON_AddBoolToObject(item, "exclude_saved", get_business_account_gifts_request->exclude_saved) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->exclude_unlimited
    if(get_business_account_gifts_request->exclude_unlimited) {
    if(cJSON_AddBoolToObject(item, "exclude_unlimited", get_business_account_gifts_request->exclude_unlimited) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->exclude_limited
    if(get_business_account_gifts_request->exclude_limited) {
    if(cJSON_AddBoolToObject(item, "exclude_limited", get_business_account_gifts_request->exclude_limited) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->exclude_unique
    if(get_business_account_gifts_request->exclude_unique) {
    if(cJSON_AddBoolToObject(item, "exclude_unique", get_business_account_gifts_request->exclude_unique) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->sort_by_price
    if(get_business_account_gifts_request->sort_by_price) {
    if(cJSON_AddBoolToObject(item, "sort_by_price", get_business_account_gifts_request->sort_by_price) == NULL) {
    goto fail; //Bool
    }
    }


    // get_business_account_gifts_request->offset
    if(get_business_account_gifts_request->offset) {
    if(cJSON_AddStringToObject(item, "offset", get_business_account_gifts_request->offset) == NULL) {
    goto fail; //String
    }
    }


    // get_business_account_gifts_request->limit
    if(get_business_account_gifts_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", get_business_account_gifts_request->limit) == NULL) {
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

get_business_account_gifts_request_t *get_business_account_gifts_request_parseFromJSON(cJSON *get_business_account_gifts_requestJSON){

    get_business_account_gifts_request_t *get_business_account_gifts_request_local_var = NULL;

    // get_business_account_gifts_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "business_connection_id");
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

    // get_business_account_gifts_request->exclude_unsaved
    cJSON *exclude_unsaved = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "exclude_unsaved");
    if (cJSON_IsNull(exclude_unsaved)) {
        exclude_unsaved = NULL;
    }
    if (exclude_unsaved) { 
    if(!cJSON_IsBool(exclude_unsaved))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->exclude_saved
    cJSON *exclude_saved = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "exclude_saved");
    if (cJSON_IsNull(exclude_saved)) {
        exclude_saved = NULL;
    }
    if (exclude_saved) { 
    if(!cJSON_IsBool(exclude_saved))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->exclude_unlimited
    cJSON *exclude_unlimited = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "exclude_unlimited");
    if (cJSON_IsNull(exclude_unlimited)) {
        exclude_unlimited = NULL;
    }
    if (exclude_unlimited) { 
    if(!cJSON_IsBool(exclude_unlimited))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->exclude_limited
    cJSON *exclude_limited = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "exclude_limited");
    if (cJSON_IsNull(exclude_limited)) {
        exclude_limited = NULL;
    }
    if (exclude_limited) { 
    if(!cJSON_IsBool(exclude_limited))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->exclude_unique
    cJSON *exclude_unique = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "exclude_unique");
    if (cJSON_IsNull(exclude_unique)) {
        exclude_unique = NULL;
    }
    if (exclude_unique) { 
    if(!cJSON_IsBool(exclude_unique))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->sort_by_price
    cJSON *sort_by_price = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "sort_by_price");
    if (cJSON_IsNull(sort_by_price)) {
        sort_by_price = NULL;
    }
    if (sort_by_price) { 
    if(!cJSON_IsBool(sort_by_price))
    {
    goto end; //Bool
    }
    }

    // get_business_account_gifts_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsString(offset) && !cJSON_IsNull(offset))
    {
    goto end; //String
    }
    }

    // get_business_account_gifts_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_business_account_gifts_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    get_business_account_gifts_request_local_var = get_business_account_gifts_request_create_internal (
        strdup(business_connection_id->valuestring),
        exclude_unsaved ? exclude_unsaved->valueint : 0,
        exclude_saved ? exclude_saved->valueint : 0,
        exclude_unlimited ? exclude_unlimited->valueint : 0,
        exclude_limited ? exclude_limited->valueint : 0,
        exclude_unique ? exclude_unique->valueint : 0,
        sort_by_price ? sort_by_price->valueint : 0,
        offset && !cJSON_IsNull(offset) ? strdup(offset->valuestring) : NULL,
        limit ? limit->valuedouble : 0
        );

    return get_business_account_gifts_request_local_var;
end:
    return NULL;

}
