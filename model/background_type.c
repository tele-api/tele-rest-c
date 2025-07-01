#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_type.h"



static background_type_t *background_type_create_internal(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming,
    document_t *document,
    int intensity,
    char *theme_name,
    int is_blurred,
    int is_moving,
    int is_inverted
    ) {
    background_type_t *background_type_local_var = malloc(sizeof(background_type_t));
    if (!background_type_local_var) {
        return NULL;
    }
    background_type_local_var->type = type;
    background_type_local_var->fill = fill;
    background_type_local_var->dark_theme_dimming = dark_theme_dimming;
    background_type_local_var->document = document;
    background_type_local_var->intensity = intensity;
    background_type_local_var->theme_name = theme_name;
    background_type_local_var->is_blurred = is_blurred;
    background_type_local_var->is_moving = is_moving;
    background_type_local_var->is_inverted = is_inverted;

    background_type_local_var->_library_owned = 1;
    return background_type_local_var;
}

__attribute__((deprecated)) background_type_t *background_type_create(
    char *type,
    background_fill_t *fill,
    int dark_theme_dimming,
    document_t *document,
    int intensity,
    char *theme_name,
    int is_blurred,
    int is_moving,
    int is_inverted
    ) {
    return background_type_create_internal (
        type,
        fill,
        dark_theme_dimming,
        document,
        intensity,
        theme_name,
        is_blurred,
        is_moving,
        is_inverted
        );
}

void background_type_free(background_type_t *background_type) {
    if(NULL == background_type){
        return ;
    }
    if(background_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_type->type) {
        free(background_type->type);
        background_type->type = NULL;
    }
    if (background_type->fill) {
        background_fill_free(background_type->fill);
        background_type->fill = NULL;
    }
    if (background_type->document) {
        document_free(background_type->document);
        background_type->document = NULL;
    }
    if (background_type->theme_name) {
        free(background_type->theme_name);
        background_type->theme_name = NULL;
    }
    free(background_type);
}

cJSON *background_type_convertToJSON(background_type_t *background_type) {
    cJSON *item = cJSON_CreateObject();

    // background_type->type
    if (!background_type->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_type->type) == NULL) {
    goto fail; //String
    }


    // background_type->fill
    if (!background_type->fill) {
        goto fail;
    }
    cJSON *fill_local_JSON = background_fill_convertToJSON(background_type->fill);
    if(fill_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fill", fill_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type->dark_theme_dimming
    if (!background_type->dark_theme_dimming) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "dark_theme_dimming", background_type->dark_theme_dimming) == NULL) {
    goto fail; //Numeric
    }


    // background_type->document
    if (!background_type->document) {
        goto fail;
    }
    cJSON *document_local_JSON = document_convertToJSON(background_type->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type->intensity
    if (!background_type->intensity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "intensity", background_type->intensity) == NULL) {
    goto fail; //Numeric
    }


    // background_type->theme_name
    if (!background_type->theme_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "theme_name", background_type->theme_name) == NULL) {
    goto fail; //String
    }


    // background_type->is_blurred
    if(background_type->is_blurred) {
    if(cJSON_AddBoolToObject(item, "is_blurred", background_type->is_blurred) == NULL) {
    goto fail; //Bool
    }
    }


    // background_type->is_moving
    if(background_type->is_moving) {
    if(cJSON_AddBoolToObject(item, "is_moving", background_type->is_moving) == NULL) {
    goto fail; //Bool
    }
    }


    // background_type->is_inverted
    if(background_type->is_inverted) {
    if(cJSON_AddBoolToObject(item, "is_inverted", background_type->is_inverted) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

background_type_t *background_type_parseFromJSON(cJSON *background_typeJSON){

    background_type_t *background_type_local_var = NULL;

    // define the local variable for background_type->fill
    background_fill_t *fill_local_nonprim = NULL;

    // define the local variable for background_type->document
    document_t *document_local_nonprim = NULL;

    // background_type->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "type");
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

    // background_type->fill
    cJSON *fill = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "fill");
    if (cJSON_IsNull(fill)) {
        fill = NULL;
    }
    if (!fill) {
        goto end;
    }

    
    fill_local_nonprim = background_fill_parseFromJSON(fill); //nonprimitive

    // background_type->dark_theme_dimming
    cJSON *dark_theme_dimming = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "dark_theme_dimming");
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

    // background_type->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (!document) {
        goto end;
    }

    
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive

    // background_type->intensity
    cJSON *intensity = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "intensity");
    if (cJSON_IsNull(intensity)) {
        intensity = NULL;
    }
    if (!intensity) {
        goto end;
    }

    
    if(!cJSON_IsNumber(intensity))
    {
    goto end; //Numeric
    }

    // background_type->theme_name
    cJSON *theme_name = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "theme_name");
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

    // background_type->is_blurred
    cJSON *is_blurred = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "is_blurred");
    if (cJSON_IsNull(is_blurred)) {
        is_blurred = NULL;
    }
    if (is_blurred) { 
    if(!cJSON_IsBool(is_blurred))
    {
    goto end; //Bool
    }
    }

    // background_type->is_moving
    cJSON *is_moving = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "is_moving");
    if (cJSON_IsNull(is_moving)) {
        is_moving = NULL;
    }
    if (is_moving) { 
    if(!cJSON_IsBool(is_moving))
    {
    goto end; //Bool
    }
    }

    // background_type->is_inverted
    cJSON *is_inverted = cJSON_GetObjectItemCaseSensitive(background_typeJSON, "is_inverted");
    if (cJSON_IsNull(is_inverted)) {
        is_inverted = NULL;
    }
    if (is_inverted) { 
    if(!cJSON_IsBool(is_inverted))
    {
    goto end; //Bool
    }
    }


    background_type_local_var = background_type_create_internal (
        strdup(type->valuestring),
        fill_local_nonprim,
        dark_theme_dimming->valuedouble,
        document_local_nonprim,
        intensity->valuedouble,
        strdup(theme_name->valuestring),
        is_blurred ? is_blurred->valueint : 0,
        is_moving ? is_moving->valueint : 0,
        is_inverted ? is_inverted->valueint : 0
        );

    return background_type_local_var;
end:
    if (fill_local_nonprim) {
        background_fill_free(fill_local_nonprim);
        fill_local_nonprim = NULL;
    }
    if (document_local_nonprim) {
        document_free(document_local_nonprim);
        document_local_nonprim = NULL;
    }
    return NULL;

}
