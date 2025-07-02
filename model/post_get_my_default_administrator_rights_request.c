#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_my_default_administrator_rights_request.h"



static post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_create_internal(
    int for_channels
    ) {
    post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_local_var = malloc(sizeof(post_get_my_default_administrator_rights_request_t));
    if (!post_get_my_default_administrator_rights_request_local_var) {
        return NULL;
    }
    post_get_my_default_administrator_rights_request_local_var->for_channels = for_channels;

    post_get_my_default_administrator_rights_request_local_var->_library_owned = 1;
    return post_get_my_default_administrator_rights_request_local_var;
}

__attribute__((deprecated)) post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_create(
    int for_channels
    ) {
    return post_get_my_default_administrator_rights_request_create_internal (
        for_channels
        );
}

void post_get_my_default_administrator_rights_request_free(post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request) {
    if(NULL == post_get_my_default_administrator_rights_request){
        return ;
    }
    if(post_get_my_default_administrator_rights_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_my_default_administrator_rights_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(post_get_my_default_administrator_rights_request);
}

cJSON *post_get_my_default_administrator_rights_request_convertToJSON(post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_my_default_administrator_rights_request->for_channels
    if(post_get_my_default_administrator_rights_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", post_get_my_default_administrator_rights_request->for_channels) == NULL) {
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

post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_parseFromJSON(cJSON *post_get_my_default_administrator_rights_requestJSON){

    post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_local_var = NULL;

    // post_get_my_default_administrator_rights_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(post_get_my_default_administrator_rights_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    post_get_my_default_administrator_rights_request_local_var = post_get_my_default_administrator_rights_request_create_internal (
        for_channels ? for_channels->valueint : 0
        );

    return post_get_my_default_administrator_rights_request_local_var;
end:
    return NULL;

}
