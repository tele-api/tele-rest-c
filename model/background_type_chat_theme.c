#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_type_chat_theme.h"



static background_type_chat_theme_t *background_type_chat_theme_create_internal(
    char *type,
    char *theme_name
    ) {
    background_type_chat_theme_t *background_type_chat_theme_local_var = malloc(sizeof(background_type_chat_theme_t));
    if (!background_type_chat_theme_local_var) {
        return NULL;
    }
    background_type_chat_theme_local_var->type = type;
    background_type_chat_theme_local_var->theme_name = theme_name;

    background_type_chat_theme_local_var->_library_owned = 1;
    return background_type_chat_theme_local_var;
}

__attribute__((deprecated)) background_type_chat_theme_t *background_type_chat_theme_create(
    char *type,
    char *theme_name
    ) {
    return background_type_chat_theme_create_internal (
        type,
        theme_name
        );
}

void background_type_chat_theme_free(background_type_chat_theme_t *background_type_chat_theme) {
    if(NULL == background_type_chat_theme){
        return ;
    }
    if(background_type_chat_theme->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_type_chat_theme_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_type_chat_theme->type) {
        free(background_type_chat_theme->type);
        background_type_chat_theme->type = NULL;
    }
    if (background_type_chat_theme->theme_name) {
        free(background_type_chat_theme->theme_name);
        background_type_chat_theme->theme_name = NULL;
    }
    free(background_type_chat_theme);
}

cJSON *background_type_chat_theme_convertToJSON(background_type_chat_theme_t *background_type_chat_theme) {
    cJSON *item = cJSON_CreateObject();

    // background_type_chat_theme->type
    if (!background_type_chat_theme->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_type_chat_theme->type) == NULL) {
    goto fail; //String
    }


    // background_type_chat_theme->theme_name
    if (!background_type_chat_theme->theme_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "theme_name", background_type_chat_theme->theme_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_type_chat_theme_t *background_type_chat_theme_parseFromJSON(cJSON *background_type_chat_themeJSON){

    background_type_chat_theme_t *background_type_chat_theme_local_var = NULL;

    // background_type_chat_theme->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_type_chat_themeJSON, "type");
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

    // background_type_chat_theme->theme_name
    cJSON *theme_name = cJSON_GetObjectItemCaseSensitive(background_type_chat_themeJSON, "theme_name");
    if (cJSON_IsNull(theme_name)) {
        theme_name = NULL;
    }
    if (!theme_name) {
        goto end;
    }

    
    if(!cJSON_IsString(theme_name))
    {
    goto end; //String
    }


    background_type_chat_theme_local_var = background_type_chat_theme_create_internal (
        strdup(type->valuestring),
        strdup(theme_name->valuestring)
        );

    return background_type_chat_theme_local_var;
end:
    return NULL;

}
