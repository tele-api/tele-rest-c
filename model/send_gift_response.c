#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_gift_response.h"



static send_gift_response_t *send_gift_response_create_internal(
    int ok,
    int result
    ) {
    send_gift_response_t *send_gift_response_local_var = malloc(sizeof(send_gift_response_t));
    if (!send_gift_response_local_var) {
        return NULL;
    }
    send_gift_response_local_var->ok = ok;
    send_gift_response_local_var->result = result;

    send_gift_response_local_var->_library_owned = 1;
    return send_gift_response_local_var;
}

__attribute__((deprecated)) send_gift_response_t *send_gift_response_create(
    int ok,
    int result
    ) {
    return send_gift_response_create_internal (
        ok,
        result
        );
}

void send_gift_response_free(send_gift_response_t *send_gift_response) {
    if(NULL == send_gift_response){
        return ;
    }
    if(send_gift_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_gift_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(send_gift_response);
}

cJSON *send_gift_response_convertToJSON(send_gift_response_t *send_gift_response) {
    cJSON *item = cJSON_CreateObject();

    // send_gift_response->ok
    if (!send_gift_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_gift_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_gift_response->result
    if (!send_gift_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", send_gift_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_gift_response_t *send_gift_response_parseFromJSON(cJSON *send_gift_responseJSON){

    send_gift_response_t *send_gift_response_local_var = NULL;

    // send_gift_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_gift_responseJSON, "ok");
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

    // send_gift_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_gift_responseJSON, "result");
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


    send_gift_response_local_var = send_gift_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return send_gift_response_local_var;
end:
    return NULL;

}
