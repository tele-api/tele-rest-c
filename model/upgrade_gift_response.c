#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "upgrade_gift_response.h"



static upgrade_gift_response_t *upgrade_gift_response_create_internal(
    int ok,
    int result
    ) {
    upgrade_gift_response_t *upgrade_gift_response_local_var = malloc(sizeof(upgrade_gift_response_t));
    if (!upgrade_gift_response_local_var) {
        return NULL;
    }
    upgrade_gift_response_local_var->ok = ok;
    upgrade_gift_response_local_var->result = result;

    upgrade_gift_response_local_var->_library_owned = 1;
    return upgrade_gift_response_local_var;
}

__attribute__((deprecated)) upgrade_gift_response_t *upgrade_gift_response_create(
    int ok,
    int result
    ) {
    return upgrade_gift_response_create_internal (
        ok,
        result
        );
}

void upgrade_gift_response_free(upgrade_gift_response_t *upgrade_gift_response) {
    if(NULL == upgrade_gift_response){
        return ;
    }
    if(upgrade_gift_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "upgrade_gift_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(upgrade_gift_response);
}

cJSON *upgrade_gift_response_convertToJSON(upgrade_gift_response_t *upgrade_gift_response) {
    cJSON *item = cJSON_CreateObject();

    // upgrade_gift_response->ok
    if (!upgrade_gift_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", upgrade_gift_response->ok) == NULL) {
    goto fail; //Bool
    }


    // upgrade_gift_response->result
    if (!upgrade_gift_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", upgrade_gift_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

upgrade_gift_response_t *upgrade_gift_response_parseFromJSON(cJSON *upgrade_gift_responseJSON){

    upgrade_gift_response_t *upgrade_gift_response_local_var = NULL;

    // upgrade_gift_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(upgrade_gift_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // upgrade_gift_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(upgrade_gift_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsBool(result))
    {
    goto end; //Bool
    }


    upgrade_gift_response_local_var = upgrade_gift_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return upgrade_gift_response_local_var;
end:
    return NULL;

}
