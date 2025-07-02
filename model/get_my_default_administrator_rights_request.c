#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_my_default_administrator_rights_request.h"



static get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_create_internal(
    int for_channels
    ) {
    get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_local_var = malloc(sizeof(get_my_default_administrator_rights_request_t));
    if (!get_my_default_administrator_rights_request_local_var) {
        return NULL;
    }
    get_my_default_administrator_rights_request_local_var->for_channels = for_channels;

    get_my_default_administrator_rights_request_local_var->_library_owned = 1;
    return get_my_default_administrator_rights_request_local_var;
}

__attribute__((deprecated)) get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_create(
    int for_channels
    ) {
    return get_my_default_administrator_rights_request_create_internal (
        for_channels
        );
}

void get_my_default_administrator_rights_request_free(get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request) {
    if(NULL == get_my_default_administrator_rights_request){
        return ;
    }
    if(get_my_default_administrator_rights_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_my_default_administrator_rights_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_my_default_administrator_rights_request);
}

cJSON *get_my_default_administrator_rights_request_convertToJSON(get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request) {
    cJSON *item = cJSON_CreateObject();

    // get_my_default_administrator_rights_request->for_channels
    if(get_my_default_administrator_rights_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", get_my_default_administrator_rights_request->for_channels) == NULL) {
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

get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_parseFromJSON(cJSON *get_my_default_administrator_rights_requestJSON){

    get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_local_var = NULL;

    // get_my_default_administrator_rights_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(get_my_default_administrator_rights_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    get_my_default_administrator_rights_request_local_var = get_my_default_administrator_rights_request_create_internal (
        for_channels ? for_channels->valueint : 0
        );

    return get_my_default_administrator_rights_request_local_var;
end:
    return NULL;

}
