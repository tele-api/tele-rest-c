#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_app_info.h"



static web_app_info_t *web_app_info_create_internal(
    char *url
    ) {
    web_app_info_t *web_app_info_local_var = malloc(sizeof(web_app_info_t));
    if (!web_app_info_local_var) {
        return NULL;
    }
    web_app_info_local_var->url = url;

    web_app_info_local_var->_library_owned = 1;
    return web_app_info_local_var;
}

__attribute__((deprecated)) web_app_info_t *web_app_info_create(
    char *url
    ) {
    return web_app_info_create_internal (
        url
        );
}

void web_app_info_free(web_app_info_t *web_app_info) {
    if(NULL == web_app_info){
        return ;
    }
    if(web_app_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_app_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_app_info->url) {
        free(web_app_info->url);
        web_app_info->url = NULL;
    }
    free(web_app_info);
}

cJSON *web_app_info_convertToJSON(web_app_info_t *web_app_info) {
    cJSON *item = cJSON_CreateObject();

    // web_app_info->url
    if (!web_app_info->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", web_app_info->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

web_app_info_t *web_app_info_parseFromJSON(cJSON *web_app_infoJSON){

    web_app_info_t *web_app_info_local_var = NULL;

    // web_app_info->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(web_app_infoJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    web_app_info_local_var = web_app_info_create_internal (
        strdup(url->valuestring)
        );

    return web_app_info_local_var;
end:
    return NULL;

}
