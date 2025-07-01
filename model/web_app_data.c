#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_app_data.h"



static web_app_data_t *web_app_data_create_internal(
    char *data,
    char *button_text
    ) {
    web_app_data_t *web_app_data_local_var = malloc(sizeof(web_app_data_t));
    if (!web_app_data_local_var) {
        return NULL;
    }
    web_app_data_local_var->data = data;
    web_app_data_local_var->button_text = button_text;

    web_app_data_local_var->_library_owned = 1;
    return web_app_data_local_var;
}

__attribute__((deprecated)) web_app_data_t *web_app_data_create(
    char *data,
    char *button_text
    ) {
    return web_app_data_create_internal (
        data,
        button_text
        );
}

void web_app_data_free(web_app_data_t *web_app_data) {
    if(NULL == web_app_data){
        return ;
    }
    if(web_app_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_app_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (web_app_data->data) {
        free(web_app_data->data);
        web_app_data->data = NULL;
    }
    if (web_app_data->button_text) {
        free(web_app_data->button_text);
        web_app_data->button_text = NULL;
    }
    free(web_app_data);
}

cJSON *web_app_data_convertToJSON(web_app_data_t *web_app_data) {
    cJSON *item = cJSON_CreateObject();

    // web_app_data->data
    if (!web_app_data->data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "data", web_app_data->data) == NULL) {
    goto fail; //String
    }


    // web_app_data->button_text
    if (!web_app_data->button_text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "button_text", web_app_data->button_text) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

web_app_data_t *web_app_data_parseFromJSON(cJSON *web_app_dataJSON){

    web_app_data_t *web_app_data_local_var = NULL;

    // web_app_data->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(web_app_dataJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (!data) {
        goto end;
    }

    
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }

    // web_app_data->button_text
    cJSON *button_text = cJSON_GetObjectItemCaseSensitive(web_app_dataJSON, "button_text");
    if (cJSON_IsNull(button_text)) {
        button_text = NULL;
    }
    if (!button_text) {
        goto end;
    }

    
    if(!cJSON_IsString(button_text))
    {
    goto end; //String
    }


    web_app_data_local_var = web_app_data_create_internal (
        strdup(data->valuestring),
        strdup(button_text->valuestring)
        );

    return web_app_data_local_var;
end:
    return NULL;

}
