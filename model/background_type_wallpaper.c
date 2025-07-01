#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "background_type_wallpaper.h"



static background_type_wallpaper_t *background_type_wallpaper_create_internal(
    char *type,
    document_t *document,
    int dark_theme_dimming,
    int is_blurred,
    int is_moving
    ) {
    background_type_wallpaper_t *background_type_wallpaper_local_var = malloc(sizeof(background_type_wallpaper_t));
    if (!background_type_wallpaper_local_var) {
        return NULL;
    }
    background_type_wallpaper_local_var->type = type;
    background_type_wallpaper_local_var->document = document;
    background_type_wallpaper_local_var->dark_theme_dimming = dark_theme_dimming;
    background_type_wallpaper_local_var->is_blurred = is_blurred;
    background_type_wallpaper_local_var->is_moving = is_moving;

    background_type_wallpaper_local_var->_library_owned = 1;
    return background_type_wallpaper_local_var;
}

__attribute__((deprecated)) background_type_wallpaper_t *background_type_wallpaper_create(
    char *type,
    document_t *document,
    int dark_theme_dimming,
    int is_blurred,
    int is_moving
    ) {
    return background_type_wallpaper_create_internal (
        type,
        document,
        dark_theme_dimming,
        is_blurred,
        is_moving
        );
}

void background_type_wallpaper_free(background_type_wallpaper_t *background_type_wallpaper) {
    if(NULL == background_type_wallpaper){
        return ;
    }
    if(background_type_wallpaper->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "background_type_wallpaper_free");
        return ;
    }
    listEntry_t *listEntry;
    if (background_type_wallpaper->type) {
        free(background_type_wallpaper->type);
        background_type_wallpaper->type = NULL;
    }
    if (background_type_wallpaper->document) {
        document_free(background_type_wallpaper->document);
        background_type_wallpaper->document = NULL;
    }
    free(background_type_wallpaper);
}

cJSON *background_type_wallpaper_convertToJSON(background_type_wallpaper_t *background_type_wallpaper) {
    cJSON *item = cJSON_CreateObject();

    // background_type_wallpaper->type
    if (!background_type_wallpaper->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", background_type_wallpaper->type) == NULL) {
    goto fail; //String
    }


    // background_type_wallpaper->document
    if (!background_type_wallpaper->document) {
        goto fail;
    }
    cJSON *document_local_JSON = document_convertToJSON(background_type_wallpaper->document);
    if(document_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "document", document_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // background_type_wallpaper->dark_theme_dimming
    if (!background_type_wallpaper->dark_theme_dimming) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "dark_theme_dimming", background_type_wallpaper->dark_theme_dimming) == NULL) {
    goto fail; //Numeric
    }


    // background_type_wallpaper->is_blurred
    if(background_type_wallpaper->is_blurred) {
    if(cJSON_AddBoolToObject(item, "is_blurred", background_type_wallpaper->is_blurred) == NULL) {
    goto fail; //Bool
    }
    }


    // background_type_wallpaper->is_moving
    if(background_type_wallpaper->is_moving) {
    if(cJSON_AddBoolToObject(item, "is_moving", background_type_wallpaper->is_moving) == NULL) {
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

background_type_wallpaper_t *background_type_wallpaper_parseFromJSON(cJSON *background_type_wallpaperJSON){

    background_type_wallpaper_t *background_type_wallpaper_local_var = NULL;

    // define the local variable for background_type_wallpaper->document
    document_t *document_local_nonprim = NULL;

    // background_type_wallpaper->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(background_type_wallpaperJSON, "type");
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

    // background_type_wallpaper->document
    cJSON *document = cJSON_GetObjectItemCaseSensitive(background_type_wallpaperJSON, "document");
    if (cJSON_IsNull(document)) {
        document = NULL;
    }
    if (!document) {
        goto end;
    }

    
    document_local_nonprim = document_parseFromJSON(document); //nonprimitive

    // background_type_wallpaper->dark_theme_dimming
    cJSON *dark_theme_dimming = cJSON_GetObjectItemCaseSensitive(background_type_wallpaperJSON, "dark_theme_dimming");
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

    // background_type_wallpaper->is_blurred
    cJSON *is_blurred = cJSON_GetObjectItemCaseSensitive(background_type_wallpaperJSON, "is_blurred");
    if (cJSON_IsNull(is_blurred)) {
        is_blurred = NULL;
    }
    if (is_blurred) { 
    if(!cJSON_IsBool(is_blurred))
    {
    goto end; //Bool
    }
    }

    // background_type_wallpaper->is_moving
    cJSON *is_moving = cJSON_GetObjectItemCaseSensitive(background_type_wallpaperJSON, "is_moving");
    if (cJSON_IsNull(is_moving)) {
        is_moving = NULL;
    }
    if (is_moving) { 
    if(!cJSON_IsBool(is_moving))
    {
    goto end; //Bool
    }
    }


    background_type_wallpaper_local_var = background_type_wallpaper_create_internal (
        strdup(type->valuestring),
        document_local_nonprim,
        dark_theme_dimming->valuedouble,
        is_blurred ? is_blurred->valueint : 0,
        is_moving ? is_moving->valueint : 0
        );

    return background_type_wallpaper_local_var;
end:
    if (document_local_nonprim) {
        document_free(document_local_nonprim);
        document_local_nonprim = NULL;
    }
    return NULL;

}
