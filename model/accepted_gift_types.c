#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accepted_gift_types.h"



static accepted_gift_types_t *accepted_gift_types_create_internal(
    int unlimited_gifts,
    int limited_gifts,
    int unique_gifts,
    int premium_subscription
    ) {
    accepted_gift_types_t *accepted_gift_types_local_var = malloc(sizeof(accepted_gift_types_t));
    if (!accepted_gift_types_local_var) {
        return NULL;
    }
    accepted_gift_types_local_var->unlimited_gifts = unlimited_gifts;
    accepted_gift_types_local_var->limited_gifts = limited_gifts;
    accepted_gift_types_local_var->unique_gifts = unique_gifts;
    accepted_gift_types_local_var->premium_subscription = premium_subscription;

    accepted_gift_types_local_var->_library_owned = 1;
    return accepted_gift_types_local_var;
}

__attribute__((deprecated)) accepted_gift_types_t *accepted_gift_types_create(
    int unlimited_gifts,
    int limited_gifts,
    int unique_gifts,
    int premium_subscription
    ) {
    return accepted_gift_types_create_internal (
        unlimited_gifts,
        limited_gifts,
        unique_gifts,
        premium_subscription
        );
}

void accepted_gift_types_free(accepted_gift_types_t *accepted_gift_types) {
    if(NULL == accepted_gift_types){
        return ;
    }
    if(accepted_gift_types->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "accepted_gift_types_free");
        return ;
    }
    listEntry_t *listEntry;
    free(accepted_gift_types);
}

cJSON *accepted_gift_types_convertToJSON(accepted_gift_types_t *accepted_gift_types) {
    cJSON *item = cJSON_CreateObject();

    // accepted_gift_types->unlimited_gifts
    if (!accepted_gift_types->unlimited_gifts) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "unlimited_gifts", accepted_gift_types->unlimited_gifts) == NULL) {
    goto fail; //Bool
    }


    // accepted_gift_types->limited_gifts
    if (!accepted_gift_types->limited_gifts) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "limited_gifts", accepted_gift_types->limited_gifts) == NULL) {
    goto fail; //Bool
    }


    // accepted_gift_types->unique_gifts
    if (!accepted_gift_types->unique_gifts) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "unique_gifts", accepted_gift_types->unique_gifts) == NULL) {
    goto fail; //Bool
    }


    // accepted_gift_types->premium_subscription
    if (!accepted_gift_types->premium_subscription) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "premium_subscription", accepted_gift_types->premium_subscription) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

accepted_gift_types_t *accepted_gift_types_parseFromJSON(cJSON *accepted_gift_typesJSON){

    accepted_gift_types_t *accepted_gift_types_local_var = NULL;

    // accepted_gift_types->unlimited_gifts
    cJSON *unlimited_gifts = cJSON_GetObjectItemCaseSensitive(accepted_gift_typesJSON, "unlimited_gifts");
    if (cJSON_IsNull(unlimited_gifts)) {
        unlimited_gifts = NULL;
    }
    if (!unlimited_gifts) {
        goto end;
    }

    
    if(!cJSON_IsBool(unlimited_gifts))
    {
    goto end; //Bool
    }

    // accepted_gift_types->limited_gifts
    cJSON *limited_gifts = cJSON_GetObjectItemCaseSensitive(accepted_gift_typesJSON, "limited_gifts");
    if (cJSON_IsNull(limited_gifts)) {
        limited_gifts = NULL;
    }
    if (!limited_gifts) {
        goto end;
    }

    
    if(!cJSON_IsBool(limited_gifts))
    {
    goto end; //Bool
    }

    // accepted_gift_types->unique_gifts
    cJSON *unique_gifts = cJSON_GetObjectItemCaseSensitive(accepted_gift_typesJSON, "unique_gifts");
    if (cJSON_IsNull(unique_gifts)) {
        unique_gifts = NULL;
    }
    if (!unique_gifts) {
        goto end;
    }

    
    if(!cJSON_IsBool(unique_gifts))
    {
    goto end; //Bool
    }

    // accepted_gift_types->premium_subscription
    cJSON *premium_subscription = cJSON_GetObjectItemCaseSensitive(accepted_gift_typesJSON, "premium_subscription");
    if (cJSON_IsNull(premium_subscription)) {
        premium_subscription = NULL;
    }
    if (!premium_subscription) {
        goto end;
    }

    
    if(!cJSON_IsBool(premium_subscription))
    {
    goto end; //Bool
    }


    accepted_gift_types_local_var = accepted_gift_types_create_internal (
        unlimited_gifts->valueint,
        limited_gifts->valueint,
        unique_gifts->valueint,
        premium_subscription->valueint
        );

    return accepted_gift_types_local_var;
end:
    return NULL;

}
