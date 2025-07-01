#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media_purchased.h"



static paid_media_purchased_t *paid_media_purchased_create_internal(
    user_t *from,
    char *paid_media_payload
    ) {
    paid_media_purchased_t *paid_media_purchased_local_var = malloc(sizeof(paid_media_purchased_t));
    if (!paid_media_purchased_local_var) {
        return NULL;
    }
    paid_media_purchased_local_var->from = from;
    paid_media_purchased_local_var->paid_media_payload = paid_media_payload;

    paid_media_purchased_local_var->_library_owned = 1;
    return paid_media_purchased_local_var;
}

__attribute__((deprecated)) paid_media_purchased_t *paid_media_purchased_create(
    user_t *from,
    char *paid_media_payload
    ) {
    return paid_media_purchased_create_internal (
        from,
        paid_media_payload
        );
}

void paid_media_purchased_free(paid_media_purchased_t *paid_media_purchased) {
    if(NULL == paid_media_purchased){
        return ;
    }
    if(paid_media_purchased->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_purchased_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media_purchased->from) {
        user_free(paid_media_purchased->from);
        paid_media_purchased->from = NULL;
    }
    if (paid_media_purchased->paid_media_payload) {
        free(paid_media_purchased->paid_media_payload);
        paid_media_purchased->paid_media_payload = NULL;
    }
    free(paid_media_purchased);
}

cJSON *paid_media_purchased_convertToJSON(paid_media_purchased_t *paid_media_purchased) {
    cJSON *item = cJSON_CreateObject();

    // paid_media_purchased->from
    if (!paid_media_purchased->from) {
        goto fail;
    }
    cJSON *from_local_JSON = user_convertToJSON(paid_media_purchased->from);
    if(from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from", from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // paid_media_purchased->paid_media_payload
    if (!paid_media_purchased->paid_media_payload) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "paid_media_payload", paid_media_purchased->paid_media_payload) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_purchased_t *paid_media_purchased_parseFromJSON(cJSON *paid_media_purchasedJSON){

    paid_media_purchased_t *paid_media_purchased_local_var = NULL;

    // define the local variable for paid_media_purchased->from
    user_t *from_local_nonprim = NULL;

    // paid_media_purchased->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(paid_media_purchasedJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (!from) {
        goto end;
    }

    
    from_local_nonprim = user_parseFromJSON(from); //nonprimitive

    // paid_media_purchased->paid_media_payload
    cJSON *paid_media_payload = cJSON_GetObjectItemCaseSensitive(paid_media_purchasedJSON, "paid_media_payload");
    if (cJSON_IsNull(paid_media_payload)) {
        paid_media_payload = NULL;
    }
    if (!paid_media_payload) {
        goto end;
    }

    
    if(!cJSON_IsString(paid_media_payload))
    {
    goto end; //String
    }


    paid_media_purchased_local_var = paid_media_purchased_create_internal (
        from_local_nonprim,
        strdup(paid_media_payload->valuestring)
        );

    return paid_media_purchased_local_var;
end:
    if (from_local_nonprim) {
        user_free(from_local_nonprim);
        from_local_nonprim = NULL;
    }
    return NULL;

}
