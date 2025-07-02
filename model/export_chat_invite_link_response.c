#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "export_chat_invite_link_response.h"



static export_chat_invite_link_response_t *export_chat_invite_link_response_create_internal(
    int ok,
    char *result
    ) {
    export_chat_invite_link_response_t *export_chat_invite_link_response_local_var = malloc(sizeof(export_chat_invite_link_response_t));
    if (!export_chat_invite_link_response_local_var) {
        return NULL;
    }
    export_chat_invite_link_response_local_var->ok = ok;
    export_chat_invite_link_response_local_var->result = result;

    export_chat_invite_link_response_local_var->_library_owned = 1;
    return export_chat_invite_link_response_local_var;
}

__attribute__((deprecated)) export_chat_invite_link_response_t *export_chat_invite_link_response_create(
    int ok,
    char *result
    ) {
    return export_chat_invite_link_response_create_internal (
        ok,
        result
        );
}

void export_chat_invite_link_response_free(export_chat_invite_link_response_t *export_chat_invite_link_response) {
    if(NULL == export_chat_invite_link_response){
        return ;
    }
    if(export_chat_invite_link_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "export_chat_invite_link_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (export_chat_invite_link_response->result) {
        free(export_chat_invite_link_response->result);
        export_chat_invite_link_response->result = NULL;
    }
    free(export_chat_invite_link_response);
}

cJSON *export_chat_invite_link_response_convertToJSON(export_chat_invite_link_response_t *export_chat_invite_link_response) {
    cJSON *item = cJSON_CreateObject();

    // export_chat_invite_link_response->ok
    if (!export_chat_invite_link_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", export_chat_invite_link_response->ok) == NULL) {
    goto fail; //Bool
    }


    // export_chat_invite_link_response->result
    if (!export_chat_invite_link_response->result) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "result", export_chat_invite_link_response->result) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

export_chat_invite_link_response_t *export_chat_invite_link_response_parseFromJSON(cJSON *export_chat_invite_link_responseJSON){

    export_chat_invite_link_response_t *export_chat_invite_link_response_local_var = NULL;

    // export_chat_invite_link_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(export_chat_invite_link_responseJSON, "ok");
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

    // export_chat_invite_link_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(export_chat_invite_link_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    if(!cJSON_IsString(result))
    {
    goto end; //String
    }


    export_chat_invite_link_response_local_var = export_chat_invite_link_response_create_internal (
        ok->valueint,
        strdup(result->valuestring)
        );

    return export_chat_invite_link_response_local_var;
end:
    return NULL;

}
