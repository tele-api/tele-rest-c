#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_chat_member_count_response.h"



static get_chat_member_count_response_t *get_chat_member_count_response_create_internal(
    int ok,
    int result
    ) {
    get_chat_member_count_response_t *get_chat_member_count_response_local_var = malloc(sizeof(get_chat_member_count_response_t));
    if (!get_chat_member_count_response_local_var) {
        return NULL;
    }
    get_chat_member_count_response_local_var->ok = ok;
    get_chat_member_count_response_local_var->result = result;

    get_chat_member_count_response_local_var->_library_owned = 1;
    return get_chat_member_count_response_local_var;
}

__attribute__((deprecated)) get_chat_member_count_response_t *get_chat_member_count_response_create(
    int ok,
    int result
    ) {
    return get_chat_member_count_response_create_internal (
        ok,
        result
        );
}

void get_chat_member_count_response_free(get_chat_member_count_response_t *get_chat_member_count_response) {
    if(NULL == get_chat_member_count_response){
        return ;
    }
    if(get_chat_member_count_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_chat_member_count_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_chat_member_count_response);
}

cJSON *get_chat_member_count_response_convertToJSON(get_chat_member_count_response_t *get_chat_member_count_response) {
    cJSON *item = cJSON_CreateObject();

    // get_chat_member_count_response->ok
    if (!get_chat_member_count_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_chat_member_count_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_chat_member_count_response->result
    if (!get_chat_member_count_response->result) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "result", get_chat_member_count_response->result) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_chat_member_count_response_t *get_chat_member_count_response_parseFromJSON(cJSON *get_chat_member_count_responseJSON){

    get_chat_member_count_response_t *get_chat_member_count_response_local_var = NULL;

    // get_chat_member_count_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_chat_member_count_responseJSON, "ok");
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

    // get_chat_member_count_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_chat_member_count_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsNumber(result))
    {
    goto end; //Numeric
    }


    get_chat_member_count_response_local_var = get_chat_member_count_response_create_internal (
        ok->valueint,
        result->valuedouble
        );

    return get_chat_member_count_response_local_var;
end:
    return NULL;

}
