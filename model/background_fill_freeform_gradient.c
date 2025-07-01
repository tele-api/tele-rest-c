#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_fill_freeform_gradient.h"



static background_fill_freeform_gradient_t *background_fill_freeform_gradient_create_internal(
    char *type,
    list_t *colors
    ) {
    background_fill_freeform_gradient_t *background_fill_freeform_gradient_local_var = malloc(sizeof(background_fill_freeform_gradient_t));
    if (!background_fill_freeform_gradient_local_var) {
        return NULL;
    }
    background_fill_freeform_gradient_local_var->type = type;
    background_fill_freeform_gradient_local_var->colors = colors;

    background_fill_freeform_gradient_local_var->_library_owned = 1;
    return background_fill_freeform_gradient_local_var;
}

__attribute__((deprecated)) background_fill_freeform_gradient_t *background_fill_freeform_gradient_create(
    char *type,
    list_t *colors
    ) {
    return background_fill_freeform_gradient_create_internal (
        type,
        colors
        );
}

void background_fill_freeform_gradient_free(background_fill_freeform_gradient_t *background_fill_freeform_gradient) {
    if(NULL == background_fill_freeform_gradient){
        return ;
    }
    if(background_fill_freeform_gradient->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_fill_freeform_gradient_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_fill_freeform_gradient->type) {
        free(background_fill_freeform_gradient->type);
        background_fill_freeform_gradient->type = NULL;
    }
    if (background_fill_freeform_gradient->colors) {
        list_ForEach(listEntry, background_fill_freeform_gradient->colors) {
            free(listEntry->data);
        }
        list_freeList(background_fill_freeform_gradient->colors);
        background_fill_freeform_gradient->colors = NULL;
    }
    free(background_fill_freeform_gradient);
}

cJSON *background_fill_freeform_gradient_convertToJSON(background_fill_freeform_gradient_t *background_fill_freeform_gradient) {
    cJSON *item = cJSON_CreateObject();

    // background_fill_freeform_gradient->type
    if (!background_fill_freeform_gradient->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_fill_freeform_gradient->type) == NULL) {
    goto fail; //String
    }


    // background_fill_freeform_gradient->colors
    if (!background_fill_freeform_gradient->colors) {
        goto fail;
    }
    cJSON *colors = cJSON_AddArrayToObject(item, "colors");
    if(colors == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *colorsListEntry;
    list_ForEach(colorsListEntry, background_fill_freeform_gradient->colors) {
    if(cJSON_AddNumberToObject(colors, "", *(double *)colorsListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_fill_freeform_gradient_t *background_fill_freeform_gradient_parseFromJSON(cJSON *background_fill_freeform_gradientJSON){

    background_fill_freeform_gradient_t *background_fill_freeform_gradient_local_var = NULL;

    // define the local list for background_fill_freeform_gradient->colors
    list_t *colorsList = NULL;

    // background_fill_freeform_gradient->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_fill_freeform_gradientJSON, "type");
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

    // background_fill_freeform_gradient->colors
    cJSON *colors = cJSON_GetObjectItemCaseSensitive(background_fill_freeform_gradientJSON, "colors");
    if (cJSON_IsNull(colors)) {
        colors = NULL;
    }
    if (!colors) {
        goto end;
    }

    
    cJSON *colors_local = NULL;
    if(!cJSON_IsArray(colors)) {
        goto end;//primitive container
    }
    colorsList = list_createList();

    cJSON_ArrayForEach(colors_local, colors)
    {
        if(!cJSON_IsNumber(colors_local))
        {
            goto end;
        }
        double *colors_local_value = calloc(1, sizeof(double));
        if(!colors_local_value)
        {
            goto end;
        }
        *colors_local_value = colors_local->valuedouble;
        list_addElement(colorsList , colors_local_value);
    }


    background_fill_freeform_gradient_local_var = background_fill_freeform_gradient_create_internal (
        strdup(type->valuestring),
        colorsList
        );

    return background_fill_freeform_gradient_local_var;
end:
    if (colorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, colorsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(colorsList);
        colorsList = NULL;
    }
    return NULL;

}
