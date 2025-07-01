#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "keyboard_button_poll_type.h"



static keyboard_button_poll_type_t *keyboard_button_poll_type_create_internal(
    char *type
    ) {
    keyboard_button_poll_type_t *keyboard_button_poll_type_local_var = malloc(sizeof(keyboard_button_poll_type_t));
    if (!keyboard_button_poll_type_local_var) {
        return NULL;
    }
    keyboard_button_poll_type_local_var->type = type;

    keyboard_button_poll_type_local_var->_library_owned = 1;
    return keyboard_button_poll_type_local_var;
}

__attribute__((deprecated)) keyboard_button_poll_type_t *keyboard_button_poll_type_create(
    char *type
    ) {
    return keyboard_button_poll_type_create_internal (
        type
        );
}

void keyboard_button_poll_type_free(keyboard_button_poll_type_t *keyboard_button_poll_type) {
    if(NULL == keyboard_button_poll_type){
        return ;
    }
    if(keyboard_button_poll_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "keyboard_button_poll_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (keyboard_button_poll_type->type) {
        free(keyboard_button_poll_type->type);
        keyboard_button_poll_type->type = NULL;
    }
    free(keyboard_button_poll_type);
}

cJSON *keyboard_button_poll_type_convertToJSON(keyboard_button_poll_type_t *keyboard_button_poll_type) {
    cJSON *item = cJSON_CreateObject();

    // keyboard_button_poll_type->type
    if(keyboard_button_poll_type->type) {
    if(cJSON_AddStringToObject(item, "type", keyboard_button_poll_type->type) == NULL) {
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

keyboard_button_poll_type_t *keyboard_button_poll_type_parseFromJSON(cJSON *keyboard_button_poll_typeJSON){

    keyboard_button_poll_type_t *keyboard_button_poll_type_local_var = NULL;

    // keyboard_button_poll_type->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(keyboard_button_poll_typeJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    keyboard_button_poll_type_local_var = keyboard_button_poll_type_create_internal (
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return keyboard_button_poll_type_local_var;
end:
    return NULL;

}
