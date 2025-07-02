#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pin_chat_message_response.h"



static pin_chat_message_response_t *pin_chat_message_response_create_internal(
    int ok,
    int result
    ) {
    pin_chat_message_response_t *pin_chat_message_response_local_var = malloc(sizeof(pin_chat_message_response_t));
    if (!pin_chat_message_response_local_var) {
        return NULL;
    }
    pin_chat_message_response_local_var->ok = ok;
    pin_chat_message_response_local_var->result = result;

    pin_chat_message_response_local_var->_library_owned = 1;
    return pin_chat_message_response_local_var;
}

__attribute__((deprecated)) pin_chat_message_response_t *pin_chat_message_response_create(
    int ok,
    int result
    ) {
    return pin_chat_message_response_create_internal (
        ok,
        result
        );
}

void pin_chat_message_response_free(pin_chat_message_response_t *pin_chat_message_response) {
    if(NULL == pin_chat_message_response){
        return ;
    }
    if(pin_chat_message_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pin_chat_message_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(pin_chat_message_response);
}

cJSON *pin_chat_message_response_convertToJSON(pin_chat_message_response_t *pin_chat_message_response) {
    cJSON *item = cJSON_CreateObject();

    // pin_chat_message_response->ok
    if (!pin_chat_message_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", pin_chat_message_response->ok) == NULL) {
    goto fail; //Bool
    }


    // pin_chat_message_response->result
    if (!pin_chat_message_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", pin_chat_message_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pin_chat_message_response_t *pin_chat_message_response_parseFromJSON(cJSON *pin_chat_message_responseJSON){

    pin_chat_message_response_t *pin_chat_message_response_local_var = NULL;

    // pin_chat_message_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(pin_chat_message_responseJSON, "ok");
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

    // pin_chat_message_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(pin_chat_message_responseJSON, "result");
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


    pin_chat_message_response_local_var = pin_chat_message_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return pin_chat_message_response_local_var;
end:
    return NULL;

}
