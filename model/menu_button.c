#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu_button.h"



static menu_button_t *menu_button_create_internal(
    char *type,
    char *text,
    web_app_info_t *web_app
    ) {
    menu_button_t *menu_button_local_var = malloc(sizeof(menu_button_t));
    if (!menu_button_local_var) {
        return NULL;
    }
    menu_button_local_var->type = type;
    menu_button_local_var->text = text;
    menu_button_local_var->web_app = web_app;

    menu_button_local_var->_library_owned = 1;
    return menu_button_local_var;
}

__attribute__((deprecated)) menu_button_t *menu_button_create(
    char *type,
    char *text,
    web_app_info_t *web_app
    ) {
    return menu_button_create_internal (
        type,
        text,
        web_app
        );
}

void menu_button_free(menu_button_t *menu_button) {
    if(NULL == menu_button){
        return ;
    }
    if(menu_button->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "menu_button_free");
        return ;
    }
    listEntry_t *listEntry;
    if (menu_button->type) {
        free(menu_button->type);
        menu_button->type = NULL;
    }
    if (menu_button->text) {
        free(menu_button->text);
        menu_button->text = NULL;
    }
    if (menu_button->web_app) {
        web_app_info_free(menu_button->web_app);
        menu_button->web_app = NULL;
    }
    free(menu_button);
}

cJSON *menu_button_convertToJSON(menu_button_t *menu_button) {
    cJSON *item = cJSON_CreateObject();

    // menu_button->type
    if (!menu_button->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", menu_button->type) == NULL) {
    goto fail; //String
    }


    // menu_button->text
    if (!menu_button->text) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "text", menu_button->text) == NULL) {
    goto fail; //String
    }


    // menu_button->web_app
    if (!menu_button->web_app) {
        goto fail;
    }
    cJSON *web_app_local_JSON = web_app_info_convertToJSON(menu_button->web_app);
    if(web_app_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "web_app", web_app_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

menu_button_t *menu_button_parseFromJSON(cJSON *menu_buttonJSON){

    menu_button_t *menu_button_local_var = NULL;

    // define the local variable for menu_button->web_app
    web_app_info_t *web_app_local_nonprim = NULL;

    // menu_button->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(menu_buttonJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // menu_button->text
    cJSON *text = cJSON_GetObjectItemCaseSensitive(menu_buttonJSON, "text");
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

    // menu_button->web_app
    cJSON *web_app = cJSON_GetObjectItemCaseSensitive(menu_buttonJSON, "web_app");
    if (cJSON_IsNull(web_app)) {
        web_app = NULL;
    }
    if (!web_app) {
        goto end;
    }

    
    web_app_local_nonprim = web_app_info_parseFromJSON(web_app); //nonprimitive


    menu_button_local_var = menu_button_create_internal (
        strdup(type->valuestring),
        strdup(text->valuestring),
        web_app_local_nonprim
        );

    return menu_button_local_var;
end:
    if (web_app_local_nonprim) {
        web_app_info_free(web_app_local_nonprim);
        web_app_local_nonprim = NULL;
    }
    return NULL;

}
