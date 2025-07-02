#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_my_default_administrator_rights_request.h"



static set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_create_internal(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_local_var = malloc(sizeof(set_my_default_administrator_rights_request_t));
    if (!set_my_default_administrator_rights_request_local_var) {
        return NULL;
    }
    set_my_default_administrator_rights_request_local_var->rights = rights;
    set_my_default_administrator_rights_request_local_var->for_channels = for_channels;

    set_my_default_administrator_rights_request_local_var->_library_owned = 1;
    return set_my_default_administrator_rights_request_local_var;
}

__attribute__((deprecated)) set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_create(
    chat_administrator_rights_t *rights,
    int for_channels
    ) {
    return set_my_default_administrator_rights_request_create_internal (
        rights,
        for_channels
        );
}

void set_my_default_administrator_rights_request_free(set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request) {
    if(NULL == set_my_default_administrator_rights_request){
        return ;
    }
    if(set_my_default_administrator_rights_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_my_default_administrator_rights_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_my_default_administrator_rights_request->rights) {
        chat_administrator_rights_free(set_my_default_administrator_rights_request->rights);
        set_my_default_administrator_rights_request->rights = NULL;
    }
    free(set_my_default_administrator_rights_request);
}

cJSON *set_my_default_administrator_rights_request_convertToJSON(set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request) {
    cJSON *item = cJSON_CreateObject();

    // set_my_default_administrator_rights_request->rights
    if(set_my_default_administrator_rights_request->rights) {
    cJSON *rights_local_JSON = chat_administrator_rights_convertToJSON(set_my_default_administrator_rights_request->rights);
    if(rights_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rights", rights_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // set_my_default_administrator_rights_request->for_channels
    if(set_my_default_administrator_rights_request->for_channels) {
    if(cJSON_AddBoolToObject(item, "for_channels", set_my_default_administrator_rights_request->for_channels) == NULL) {
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

set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_parseFromJSON(cJSON *set_my_default_administrator_rights_requestJSON){

    set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_local_var = NULL;

    // define the local variable for set_my_default_administrator_rights_request->rights
    chat_administrator_rights_t *rights_local_nonprim = NULL;

    // set_my_default_administrator_rights_request->rights
    cJSON *rights = cJSON_GetObjectItemCaseSensitive(set_my_default_administrator_rights_requestJSON, "rights");
    if (cJSON_IsNull(rights)) {
        rights = NULL;
    }
    if (rights) { 
    rights_local_nonprim = chat_administrator_rights_parseFromJSON(rights); //nonprimitive
    }

    // set_my_default_administrator_rights_request->for_channels
    cJSON *for_channels = cJSON_GetObjectItemCaseSensitive(set_my_default_administrator_rights_requestJSON, "for_channels");
    if (cJSON_IsNull(for_channels)) {
        for_channels = NULL;
    }
    if (for_channels) { 
    if(!cJSON_IsBool(for_channels))
    {
    goto end; //Bool
    }
    }


    set_my_default_administrator_rights_request_local_var = set_my_default_administrator_rights_request_create_internal (
        rights ? rights_local_nonprim : NULL,
        for_channels ? for_channels->valueint : 0
        );

    return set_my_default_administrator_rights_request_local_var;
end:
    if (rights_local_nonprim) {
        chat_administrator_rights_free(rights_local_nonprim);
        rights_local_nonprim = NULL;
    }
    return NULL;

}
