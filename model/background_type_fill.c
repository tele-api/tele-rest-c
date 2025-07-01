#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_type_fill.h"



static background_type_fill_t *background_type_fill_create_internal(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming
    ) {
    background_type_fill_t *background_type_fill_local_var = malloc(sizeof(background_type_fill_t));
    if (!background_type_fill_local_var) {
        return NULL;
    }
    background_type_fill_local_var->type = type;
    background_type_fill_local_var->fill = fill;
    background_type_fill_local_var->dark_theme_dimming = dark_theme_dimming;

    background_type_fill_local_var->_library_owned = 1;
    return background_type_fill_local_var;
}

__attribute__((deprecated)) background_type_fill_t *background_type_fill_create(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming
    ) {
    return background_type_fill_create_internal (
        type,
        fill,
        dark_theme_dimming
        );
}

void background_type_fill_free(background_type_fill_t *background_type_fill) {
    if(NULL == background_type_fill){
        return ;
    }
    if(background_type_fill->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_type_fill_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_type_fill->type) {
        free(background_type_fill->type);
        background_type_fill->type = NULL;
    }
    if (background_type_fill->fill) {
        background_fill_free(background_type_fill->fill);
        background_type_fill->fill = NULL;
    }
    free(background_type_fill);
}

cJSON *background_type_fill_convertToJSON(background_type_fill_t *background_type_fill) {
    cJSON *item = cJSON_CreateObject();

    // background_type_fill->type
    if (!background_type_fill->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_type_fill->type) == NULL) {
    goto fail; //String
    }


    // background_type_fill->fill
    if (!background_type_fill->fill) {
        goto fail;
    }
    cJSON *fill_local_JSON = background_fill_convertToJSON(background_type_fill->fill);
    if(fill_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill", fill_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type_fill->dark_theme_dimming
    if (!background_type_fill->dark_theme_dimming) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "dark_theme_dimming", background_type_fill->dark_theme_dimming) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_type_fill_t *background_type_fill_parseFromJSON(cJSON *background_type_fillJSON){

    background_type_fill_t *background_type_fill_local_var = NULL;

    // define the local variable for background_type_fill->fill
    background_fill_t *fill_local_nonprim = NULL;

    // background_type_fill->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_type_fillJSON, "type");
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

    // background_type_fill->fill
    cJSON *fill = cJSON_GetObjectItemCaseSensitive(background_type_fillJSON, "fill");
    if (cJSON_IsNull(fill)) {
        fill = NULL;
    }
    if (!fill) {
        goto end;
    }

    
    fill_local_nonprim = background_fill_parseFromJSON(fill); //nonprimitive

    // background_type_fill->dark_theme_dimming
    cJSON *dark_theme_dimming = cJSON_GetObjectItemCaseSensitive(background_type_fillJSON, "dark_theme_dimming");
    if (cJSON_IsNull(dark_theme_dimming)) {
        dark_theme_dimming = NULL;
    }
    if (!dark_theme_dimming) {
        goto end;
    }

    
    if(!cJSON_IsNumber(dark_theme_dimming))
    {
    goto end; //Numeric
    }


    background_type_fill_local_var = background_type_fill_create_internal (
        strdup(type->valuestring),
        fill_local_nonprim,
        dark_theme_dimming->valuedouble
        );

    return background_type_fill_local_var;
end:
    if (fill_local_nonprim) {
        background_fill_free(fill_local_nonprim);
        fill_local_nonprim = NULL;
    }
    return NULL;

}
