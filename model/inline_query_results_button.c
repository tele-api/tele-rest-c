#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_results_button.h"



static inline_query_results_button_t *inline_query_results_button_create_internal(
    char *text,
    web_app_info_t *web_app,
    char *start_parameter
    ) {
    inline_query_results_button_t *inline_query_results_button_local_var = malloc(sizeof(inline_query_results_button_t));
    if (!inline_query_results_button_local_var) {
        return NULL;
    }
    inline_query_results_button_local_var->text = text;
    inline_query_results_button_local_var->web_app = web_app;
    inline_query_results_button_local_var->start_parameter = start_parameter;

    inline_query_results_button_local_var->_library_owned = 1;
    return inline_query_results_button_local_var;
}

__attribute__((deprecated)) inline_query_results_button_t *inline_query_results_button_create(
    char *text,
    web_app_info_t *web_app,
    char *start_parameter
    ) {
    return inline_query_results_button_create_internal (
        text,
        web_app,
        start_parameter
        );
}

void inline_query_results_button_free(inline_query_results_button_t *inline_query_results_button) {
    if(NULL == inline_query_results_button){
        return ;
    }
    if(inline_query_results_button->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_results_button_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_results_button->text) {
        free(inline_query_results_button->text);
        inline_query_results_button->text = NULL;
    }
    if (inline_query_results_button->web_app) {
        web_app_info_free(inline_query_results_button->web_app);
        inline_query_results_button->web_app = NULL;
    }
    if (inline_query_results_button->start_parameter) {
        free(inline_query_results_button->start_parameter);
        inline_query_results_button->start_parameter = NULL;
    }
    free(inline_query_results_button);
}

cJSON *inline_query_results_button_convertToJSON(inline_query_results_button_t *inline_query_results_button) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_results_button->text
    if (!inline_query_results_button->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", inline_query_results_button->text) == NULL) {
    goto fail; //String
    }


    // inline_query_results_button->web_app
    if(inline_query_results_button->web_app) {
    cJSON *web_app_local_JSON = web_app_info_convertToJSON(inline_query_results_button->web_app);
    if(web_app_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app", web_app_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_results_button->start_parameter
    if(inline_query_results_button->start_parameter) {
    if(cJSON_AddStringToObject(item, "start_parameter", inline_query_results_button->start_parameter) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_query_results_button_t *inline_query_results_button_parseFromJSON(cJSON *inline_query_results_buttonJSON){

    inline_query_results_button_t *inline_query_results_button_local_var = NULL;

    // define the local variable for inline_query_results_button->web_app
    web_app_info_t *web_app_local_nonprim = NULL;

    // inline_query_results_button->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(inline_query_results_buttonJSON, "text");
    if (cJSON_IsNull(text)) {
        text = NULL;
    }
    if (!text) {
        goto end;
    }

    
    if(!cJSON_IsString(text))
    {
    goto end; //String
    }

    // inline_query_results_button->web_app
    cJSON *web_app = cJSON_GetObjectItemCaseSensitive(inline_query_results_buttonJSON, "web_app");
    if (cJSON_IsNull(web_app)) {
        web_app = NULL;
    }
    if (web_app) { 
    web_app_local_nonprim = web_app_info_parseFromJSON(web_app); //nonprimitive
    }

    // inline_query_results_button->start_parameter
    cJSON *start_parameter = cJSON_GetObjectItemCaseSensitive(inline_query_results_buttonJSON, "start_parameter");
    if (cJSON_IsNull(start_parameter)) {
        start_parameter = NULL;
    }
    if (start_parameter) { 
    if(!cJSON_IsString(start_parameter) && !cJSON_IsNull(start_parameter))
    {
    goto end; //String
    }
    }


    inline_query_results_button_local_var = inline_query_results_button_create_internal (
        strdup(text->valuestring),
        web_app ? web_app_local_nonprim : NULL,
        start_parameter && !cJSON_IsNull(start_parameter) ? strdup(start_parameter->valuestring) : NULL
        );

    return inline_query_results_button_local_var;
end:
    if (web_app_local_nonprim) {
        web_app_info_free(web_app_local_nonprim);
        web_app_local_nonprim = NULL;
    }
    return NULL;

}
