#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_fill.h"



static background_fill_t *background_fill_create_internal(
    char *type,
    int color,
    int top_color,
    int bottom_color,
    int rotation_angle,
    list_t *colors
    ) {
    background_fill_t *background_fill_local_var = malloc(sizeof(background_fill_t));
    if (!background_fill_local_var) {
        return NULL;
    }
    background_fill_local_var->type = type;
    background_fill_local_var->color = color;
    background_fill_local_var->top_color = top_color;
    background_fill_local_var->bottom_color = bottom_color;
    background_fill_local_var->rotation_angle = rotation_angle;
    background_fill_local_var->colors = colors;

    background_fill_local_var->_library_owned = 1;
    return background_fill_local_var;
}

__attribute__((deprecated)) background_fill_t *background_fill_create(
    char *type,
    int color,
    int top_color,
    int bottom_color,
    int rotation_angle,
    list_t *colors
    ) {
    return background_fill_create_internal (
        type,
        color,
        top_color,
        bottom_color,
        rotation_angle,
        colors
        );
}

void background_fill_free(background_fill_t *background_fill) {
    if(NULL == background_fill){
        return ;
    }
    if(background_fill->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_fill_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_fill->type) {
        free(background_fill->type);
        background_fill->type = NULL;
    }
    if (background_fill->colors) {
        list_ForEach(listEntry, background_fill->colors) {
            free(listEntry->data);
        }
        list_freeList(background_fill->colors);
        background_fill->colors = NULL;
    }
    free(background_fill);
}

cJSON *background_fill_convertToJSON(background_fill_t *background_fill) {
    cJSON *item = cJSON_CreateObject();

    // background_fill->type
    if (!background_fill->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_fill->type) == NULL) {
    goto fail; //String
    }


    // background_fill->color
    if (!background_fill->color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "color", background_fill->color) == NULL) {
    goto fail; //Numeric
    }


    // background_fill->top_color
    if (!background_fill->top_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top_color", background_fill->top_color) == NULL) {
    goto fail; //Numeric
    }


    // background_fill->bottom_color
    if (!background_fill->bottom_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bottom_color", background_fill->bottom_color) == NULL) {
    goto fail; //Numeric
    }


    // background_fill->rotation_angle
    if (!background_fill->rotation_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rotation_angle", background_fill->rotation_angle) == NULL) {
    goto fail; //Numeric
    }


    // background_fill->colors
    if (!background_fill->colors) {
        goto fail;
    }
    cJSON *colors = cJSON_AddArrayToObject(item, "colors");
    if(colors == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *colorsListEntry;
    list_ForEach(colorsListEntry, background_fill->colors) {
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

background_fill_t *background_fill_parseFromJSON(cJSON *background_fillJSON){

    background_fill_t *background_fill_local_var = NULL;

    // define the local list for background_fill->colors
    list_t *colorsList = NULL;

    // background_fill->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "type");
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

    // background_fill->color
    cJSON *color = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "color");
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

    // background_fill->top_color
    cJSON *top_color = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "top_color");
    if (cJSON_IsNull(top_color)) {
        top_color = NULL;
    }
    if (!top_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(top_color))
    {
    goto end; //Numeric
    }

    // background_fill->bottom_color
    cJSON *bottom_color = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "bottom_color");
    if (cJSON_IsNull(bottom_color)) {
        bottom_color = NULL;
    }
    if (!bottom_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(bottom_color))
    {
    goto end; //Numeric
    }

    // background_fill->rotation_angle
    cJSON *rotation_angle = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "rotation_angle");
    if (cJSON_IsNull(rotation_angle)) {
        rotation_angle = NULL;
    }
    if (!rotation_angle) {
        goto end;
    }

    
    if(!cJSON_IsNumber(rotation_angle))
    {
    goto end; //Numeric
    }

    // background_fill->colors
    cJSON *colors = cJSON_GetObjectItemCaseSensitive(background_fillJSON, "colors");
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


    background_fill_local_var = background_fill_create_internal (
        strdup(type->valuestring),
        color->valuedouble,
        top_color->valuedouble,
        bottom_color->valuedouble,
        rotation_angle->valuedouble,
        colorsList
        );

    return background_fill_local_var;
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
