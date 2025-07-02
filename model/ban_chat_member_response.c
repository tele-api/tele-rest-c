#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ban_chat_member_response.h"



static ban_chat_member_response_t *ban_chat_member_response_create_internal(
    int ok,
    int result
    ) {
    ban_chat_member_response_t *ban_chat_member_response_local_var = malloc(sizeof(ban_chat_member_response_t));
    if (!ban_chat_member_response_local_var) {
        return NULL;
    }
    ban_chat_member_response_local_var->ok = ok;
    ban_chat_member_response_local_var->result = result;

    ban_chat_member_response_local_var->_library_owned = 1;
    return ban_chat_member_response_local_var;
}

__attribute__((deprecated)) ban_chat_member_response_t *ban_chat_member_response_create(
    int ok,
    int result
    ) {
    return ban_chat_member_response_create_internal (
        ok,
        result
        );
}

void ban_chat_member_response_free(ban_chat_member_response_t *ban_chat_member_response) {
    if(NULL == ban_chat_member_response){
        return ;
    }
    if(ban_chat_member_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ban_chat_member_response_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ban_chat_member_response);
}

cJSON *ban_chat_member_response_convertToJSON(ban_chat_member_response_t *ban_chat_member_response) {
    cJSON *item = cJSON_CreateObject();

    // ban_chat_member_response->ok
    if (!ban_chat_member_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", ban_chat_member_response->ok) == NULL) {
    goto fail; //Bool
    }


    // ban_chat_member_response->result
    if (!ban_chat_member_response->result) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "result", ban_chat_member_response->result) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ban_chat_member_response_t *ban_chat_member_response_parseFromJSON(cJSON *ban_chat_member_responseJSON){

    ban_chat_member_response_t *ban_chat_member_response_local_var = NULL;

    // ban_chat_member_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(ban_chat_member_responseJSON, "ok");
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

    // ban_chat_member_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(ban_chat_member_responseJSON, "result");
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


    ban_chat_member_response_local_var = ban_chat_member_response_create_internal (
        ok->valueint,
        result->valueint
        );

    return ban_chat_member_response_local_var;
end:
    return NULL;

}
