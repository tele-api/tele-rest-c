#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu_button_default.h"



static menu_button_default_t *menu_button_default_create_internal(
    char *type
    ) {
    menu_button_default_t *menu_button_default_local_var = malloc(sizeof(menu_button_default_t));
    if (!menu_button_default_local_var) {
        return NULL;
    }
    menu_button_default_local_var->type = type;

    menu_button_default_local_var->_library_owned = 1;
    return menu_button_default_local_var;
}

__attribute__((deprecated)) menu_button_default_t *menu_button_default_create(
    char *type
    ) {
    return menu_button_default_create_internal (
        type
        );
}

void menu_button_default_free(menu_button_default_t *menu_button_default) {
    if(NULL == menu_button_default){
        return ;
    }
    if(menu_button_default->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "menu_button_default_free");
        return ;
    }
    listEntry_t *listEntry;
    if (menu_button_default->type) {
        free(menu_button_default->type);
        menu_button_default->type = NULL;
    }
    free(menu_button_default);
}

cJSON *menu_button_default_convertToJSON(menu_button_default_t *menu_button_default) {
    cJSON *item = cJSON_CreateObject();

    // menu_button_default->type
    if (!menu_button_default->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", menu_button_default->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

menu_button_default_t *menu_button_default_parseFromJSON(cJSON *menu_button_defaultJSON){

    menu_button_default_t *menu_button_default_local_var = NULL;

    // menu_button_default->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(menu_button_defaultJSON, "type");
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


    menu_button_default_local_var = menu_button_default_create_internal (
        strdup(type->valuestring)
        );

    return menu_button_default_local_var;
end:
    return NULL;

}
