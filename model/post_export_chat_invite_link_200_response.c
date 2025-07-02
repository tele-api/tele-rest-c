#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_export_chat_invite_link_200_response.h"



static post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_create_internal(
    int ok,
    char *result
    ) {
    post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_local_var = malloc(sizeof(post_export_chat_invite_link_200_response_t));
    if (!post_export_chat_invite_link_200_response_local_var) {
        return NULL;
    }
    post_export_chat_invite_link_200_response_local_var->ok = ok;
    post_export_chat_invite_link_200_response_local_var->result = result;

    post_export_chat_invite_link_200_response_local_var->_library_owned = 1;
    return post_export_chat_invite_link_200_response_local_var;
}

__attribute__((deprecated)) post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_create(
    int ok,
    char *result
    ) {
    return post_export_chat_invite_link_200_response_create_internal (
        ok,
        result
        );
}

void post_export_chat_invite_link_200_response_free(post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response) {
    if(NULL == post_export_chat_invite_link_200_response){
        return ;
    }
    if(post_export_chat_invite_link_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_export_chat_invite_link_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_export_chat_invite_link_200_response->result) {
        free(post_export_chat_invite_link_200_response->result);
        post_export_chat_invite_link_200_response->result = NULL;
    }
    free(post_export_chat_invite_link_200_response);
}

cJSON *post_export_chat_invite_link_200_response_convertToJSON(post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response) {
    cJSON *item = cJSON_CreateObject();

    // post_export_chat_invite_link_200_response->ok
    if (!post_export_chat_invite_link_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", post_export_chat_invite_link_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // post_export_chat_invite_link_200_response->result
    if (!post_export_chat_invite_link_200_response->result) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "result", post_export_chat_invite_link_200_response->result) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_parseFromJSON(cJSON *post_export_chat_invite_link_200_responseJSON){

    post_export_chat_invite_link_200_response_t *post_export_chat_invite_link_200_response_local_var = NULL;

    // post_export_chat_invite_link_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(post_export_chat_invite_link_200_responseJSON, "ok");
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

    // post_export_chat_invite_link_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(post_export_chat_invite_link_200_responseJSON, "result");
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


    post_export_chat_invite_link_200_response_local_var = post_export_chat_invite_link_200_response_create_internal (
        ok->valueint,
        strdup(result->valuestring)
        );

    return post_export_chat_invite_link_200_response_local_var;
end:
    return NULL;

}
