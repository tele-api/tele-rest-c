#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_fill_solid.h"



static background_fill_solid_t *background_fill_solid_create_internal(
    char *type,
    int color
    ) {
    background_fill_solid_t *background_fill_solid_local_var = malloc(sizeof(background_fill_solid_t));
    if (!background_fill_solid_local_var) {
        return NULL;
    }
    background_fill_solid_local_var->type = type;
    background_fill_solid_local_var->color = color;

    background_fill_solid_local_var->_library_owned = 1;
    return background_fill_solid_local_var;
}

__attribute__((deprecated)) background_fill_solid_t *background_fill_solid_create(
    char *type,
    int color
    ) {
    return background_fill_solid_create_internal (
        type,
        color
        );
}

void background_fill_solid_free(background_fill_solid_t *background_fill_solid) {
    if(NULL == background_fill_solid){
        return ;
    }
    if(background_fill_solid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_fill_solid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_fill_solid->type) {
        free(background_fill_solid->type);
        background_fill_solid->type = NULL;
    }
    free(background_fill_solid);
}

cJSON *background_fill_solid_convertToJSON(background_fill_solid_t *background_fill_solid) {
    cJSON *item = cJSON_CreateObject();

    // background_fill_solid->type
    if (!background_fill_solid->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_fill_solid->type) == NULL) {
    goto fail; //String
    }


    // background_fill_solid->color
    if (!background_fill_solid->color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "color", background_fill_solid->color) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_fill_solid_t *background_fill_solid_parseFromJSON(cJSON *background_fill_solidJSON){

    background_fill_solid_t *background_fill_solid_local_var = NULL;

    // background_fill_solid->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_fill_solidJSON, "type");
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

    // background_fill_solid->color
    cJSON *color = cJSON_GetObjectItemCaseSensitive(background_fill_solidJSON, "color");
    if (cJSON_IsNull(color)) {
        color = NULL;
    }
    if (!color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(color))
    {
    goto end; //Numeric
    }


    background_fill_solid_local_var = background_fill_solid_create_internal (
        strdup(type->valuestring),
        color->valuedouble
        );

    return background_fill_solid_local_var;
end:
    return NULL;

}
