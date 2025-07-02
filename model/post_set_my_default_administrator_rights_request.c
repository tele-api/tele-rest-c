#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_my_default_administrator_rights_request.h"



static post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_create_internal(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_local_var = malloc(sizeof(post_set_my_default_administrator_rights_request_t));
    if (!post_set_my_default_administrator_rights_request_local_var) {
        return NULL;
    }
    post_set_my_default_administrator_rights_request_local_var->rights = rights;
    post_set_my_default_administrator_rights_request_local_var->for_channels = for_channels;

    post_set_my_default_administrator_rights_request_local_var->_library_owned = 1;
    return post_set_my_default_administrator_rights_request_local_var;
}

__attribute__((deprecated)) post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_create(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    return post_set_my_default_administrator_rights_request_create_internal (
        rights,
        for_channels
        );
}

void post_set_my_default_administrator_rights_request_free(post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request) {
    if(NULL == post_set_my_default_administrator_rights_request){
        return ;
    }
    if(post_set_my_default_administrator_rights_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_my_default_administrator_rights_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_my_default_administrator_rights_request->rights) {
        chat_administrator_rights_free(post_set_my_default_administrator_rights_request->rights);
        post_set_my_default_administrator_rights_request->rights = NULL;
    }
    free(post_set_my_default_administrator_rights_request);
}

cJSON *post_set_my_default_administrator_rights_request_convertToJSON(post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_my_default_administrator_rights_request->rights
    if(post_set_my_default_administrator_rights_request->rights) {
    cJSON *rights_local_JSON = chat_administrator_rights_convertToJSON(post_set_my_default_administrator_rights_request->rights);
    if(rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rights", rights_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_set_my_default_administrator_rights_request->for_channels
    if(post_set_my_default_administrator_rights_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", post_set_my_default_administrator_rights_request->for_channels) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_parseFromJSON(cJSON *post_set_my_default_administrator_rights_requestJSON){

    post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_local_var = NULL;

    // define the local variable for post_set_my_default_administrator_rights_request->rights
    chat_administrator_rights_t *rights_local_nonprim = NULL;

    // post_set_my_default_administrator_rights_request->rights
    cJSON *rights = cJSON_GetObjectItemCaseSensitive(post_set_my_default_administrator_rights_requestJSON, "rights");
    if (cJSON_IsNull(rights)) {
        rights = NULL;
    }
    if (rights) { 
    rights_local_nonprim = chat_administrator_rights_parseFromJSON(rights); //nonprimitive
    }

    // post_set_my_default_administrator_rights_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(post_set_my_default_administrator_rights_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    post_set_my_default_administrator_rights_request_local_var = post_set_my_default_administrator_rights_request_create_internal (
        rights ? rights_local_nonprim : NULL,
        for_channels ? for_channels->valueint : 0
        );

    return post_set_my_default_administrator_rights_request_local_var;
end:
    if (rights_local_nonprim) {
        chat_administrator_rights_free(rights_local_nonprim);
        rights_local_nonprim = NULL;
    }
    return NULL;

}
