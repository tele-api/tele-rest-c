#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "write_access_allowed.h"



static write_access_allowed_t *write_access_allowed_create_internal(
    int from_request,
    char *web_app_name,
    int from_attachment_menu
    ) {
    write_access_allowed_t *write_access_allowed_local_var = malloc(sizeof(write_access_allowed_t));
    if (!write_access_allowed_local_var) {
        return NULL;
    }
    write_access_allowed_local_var->from_request = from_request;
    write_access_allowed_local_var->web_app_name = web_app_name;
    write_access_allowed_local_var->from_attachment_menu = from_attachment_menu;

    write_access_allowed_local_var->_library_owned = 1;
    return write_access_allowed_local_var;
}

__attribute__((deprecated)) write_access_allowed_t *write_access_allowed_create(
    int from_request,
    char *web_app_name,
    int from_attachment_menu
    ) {
    return write_access_allowed_create_internal (
        from_request,
        web_app_name,
        from_attachment_menu
        );
}

void write_access_allowed_free(write_access_allowed_t *write_access_allowed) {
    if(NULL == write_access_allowed){
        return ;
    }
    if(write_access_allowed->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "write_access_allowed_free");
        return ;
    }
    listEntry_t *listEntry;
    if (write_access_allowed->web_app_name) {
        free(write_access_allowed->web_app_name);
        write_access_allowed->web_app_name = NULL;
    }
    free(write_access_allowed);
}

cJSON *write_access_allowed_convertToJSON(write_access_allowed_t *write_access_allowed) {
    cJSON *item = cJSON_CreateObject();

    // write_access_allowed->from_request
    if(write_access_allowed->from_request) {
    if(cJSON_AddBoolToObject(item, "from_request", write_access_allowed->from_request) == NULL) {
    goto fail; //Bool
    }
    }


    // write_access_allowed->web_app_name
    if(write_access_allowed->web_app_name) {
    if(cJSON_AddStringToObject(item, "web_app_name", write_access_allowed->web_app_name) == NULL) {
    goto fail; //String
    }
    }


    // write_access_allowed->from_attachment_menu
    if(write_access_allowed->from_attachment_menu) {
    if(cJSON_AddBoolToObject(item, "from_attachment_menu", write_access_allowed->from_attachment_menu) == NULL) {
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

write_access_allowed_t *write_access_allowed_parseFromJSON(cJSON *write_access_allowedJSON){

    write_access_allowed_t *write_access_allowed_local_var = NULL;

    // write_access_allowed->from_request
    cJSON *from_request = cJSON_GetObjectItemCaseSensitive(write_access_allowedJSON, "from_request");
    if (cJSON_IsNull(from_request)) {
        from_request = NULL;
    }
    if (from_request) { 
    if(!cJSON_IsBool(from_request))
    {
    goto end; //Bool
    }
    }

    // write_access_allowed->web_app_name
    cJSON *web_app_name = cJSON_GetObjectItemCaseSensitive(write_access_allowedJSON, "web_app_name");
    if (cJSON_IsNull(web_app_name)) {
        web_app_name = NULL;
    }
    if (web_app_name) { 
    if(!cJSON_IsString(web_app_name) && !cJSON_IsNull(web_app_name))
    {
    goto end; //String
    }
    }

    // write_access_allowed->from_attachment_menu
    cJSON *from_attachment_menu = cJSON_GetObjectItemCaseSensitive(write_access_allowedJSON, "from_attachment_menu");
    if (cJSON_IsNull(from_attachment_menu)) {
        from_attachment_menu = NULL;
    }
    if (from_attachment_menu) { 
    if(!cJSON_IsBool(from_attachment_menu))
    {
    goto end; //Bool
    }
    }


    write_access_allowed_local_var = write_access_allowed_create_internal (
        from_request ? from_request->valueint : 0,
        web_app_name && !cJSON_IsNull(web_app_name) ? strdup(web_app_name->valuestring) : NULL,
        from_attachment_menu ? from_attachment_menu->valueint : 0
        );

    return write_access_allowed_local_var;
end:
    return NULL;

}
