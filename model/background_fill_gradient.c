#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_fill_gradient.h"



static background_fill_gradient_t *background_fill_gradient_create_internal(
    char *type,
    int top_color,
    int bottom_color,
    int rotation_angle
    ) {
    background_fill_gradient_t *background_fill_gradient_local_var = malloc(sizeof(background_fill_gradient_t));
    if (!background_fill_gradient_local_var) {
        return NULL;
    }
    background_fill_gradient_local_var->type = type;
    background_fill_gradient_local_var->top_color = top_color;
    background_fill_gradient_local_var->bottom_color = bottom_color;
    background_fill_gradient_local_var->rotation_angle = rotation_angle;

    background_fill_gradient_local_var->_library_owned = 1;
    return background_fill_gradient_local_var;
}

__attribute__((deprecated)) background_fill_gradient_t *background_fill_gradient_create(
    char *type,
    int top_color,
    int bottom_color,
    int rotation_angle
    ) {
    return background_fill_gradient_create_internal (
        type,
        top_color,
        bottom_color,
        rotation_angle
        );
}

void background_fill_gradient_free(background_fill_gradient_t *background_fill_gradient) {
    if(NULL == background_fill_gradient){
        return ;
    }
    if(background_fill_gradient->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_fill_gradient_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_fill_gradient->type) {
        free(background_fill_gradient->type);
        background_fill_gradient->type = NULL;
    }
    free(background_fill_gradient);
}

cJSON *background_fill_gradient_convertToJSON(background_fill_gradient_t *background_fill_gradient) {
    cJSON *item = cJSON_CreateObject();

    // background_fill_gradient->type
    if (!background_fill_gradient->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_fill_gradient->type) == NULL) {
    goto fail; //String
    }


    // background_fill_gradient->top_color
    if (!background_fill_gradient->top_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "top_color", background_fill_gradient->top_color) == NULL) {
    goto fail; //Numeric
    }


    // background_fill_gradient->bottom_color
    if (!background_fill_gradient->bottom_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "bottom_color", background_fill_gradient->bottom_color) == NULL) {
    goto fail; //Numeric
    }


    // background_fill_gradient->rotation_angle
    if (!background_fill_gradient->rotation_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rotation_angle", background_fill_gradient->rotation_angle) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_fill_gradient_t *background_fill_gradient_parseFromJSON(cJSON *background_fill_gradientJSON){

    background_fill_gradient_t *background_fill_gradient_local_var = NULL;

    // background_fill_gradient->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_fill_gradientJSON, "type");
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

    // background_fill_gradient->top_color
    cJSON *top_color = cJSON_GetObjectItemCaseSensitive(background_fill_gradientJSON, "top_color");
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

    // background_fill_gradient->bottom_color
    cJSON *bottom_color = cJSON_GetObjectItemCaseSensitive(background_fill_gradientJSON, "bottom_color");
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

    // background_fill_gradient->rotation_angle
    cJSON *rotation_angle = cJSON_GetObjectItemCaseSensitive(background_fill_gradientJSON, "rotation_angle");
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


    background_fill_gradient_local_var = background_fill_gradient_create_internal (
        strdup(type->valuestring),
        top_color->valuedouble,
        bottom_color->valuedouble,
        rotation_angle->valuedouble
        );

    return background_fill_gradient_local_var;
end:
    return NULL;

}
