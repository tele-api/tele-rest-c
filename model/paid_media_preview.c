#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "paid_media_preview.h"



static paid_media_preview_t *paid_media_preview_create_internal(
    char *type,
    int width,
    int height,
    int duration
    ) {
    paid_media_preview_t *paid_media_preview_local_var = malloc(sizeof(paid_media_preview_t));
    if (!paid_media_preview_local_var) {
        return NULL;
    }
    paid_media_preview_local_var->type = type;
    paid_media_preview_local_var->width = width;
    paid_media_preview_local_var->height = height;
    paid_media_preview_local_var->duration = duration;

    paid_media_preview_local_var->_library_owned = 1;
    return paid_media_preview_local_var;
}

__attribute__((deprecated)) paid_media_preview_t *paid_media_preview_create(
    char *type,
    int width,
    int height,
    int duration
    ) {
    return paid_media_preview_create_internal (
        type,
        width,
        height,
        duration
        );
}

void paid_media_preview_free(paid_media_preview_t *paid_media_preview) {
    if(NULL == paid_media_preview){
        return ;
    }
    if(paid_media_preview->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "paid_media_preview_free");
        return ;
    }
    listEntry_t *listEntry;
    if (paid_media_preview->type) {
        free(paid_media_preview->type);
        paid_media_preview->type = NULL;
    }
    free(paid_media_preview);
}

cJSON *paid_media_preview_convertToJSON(paid_media_preview_t *paid_media_preview) {
    cJSON *item = cJSON_CreateObject();

    // paid_media_preview->type
    if (!paid_media_preview->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", paid_media_preview->type) == NULL) {
    goto fail; //String
    }


    // paid_media_preview->width
    if(paid_media_preview->width) {
    if(cJSON_AddNumberToObject(item, "width", paid_media_preview->width) == NULL) {
    goto fail; //Numeric
    }
    }


    // paid_media_preview->height
    if(paid_media_preview->height) {
    if(cJSON_AddNumberToObject(item, "height", paid_media_preview->height) == NULL) {
    goto fail; //Numeric
    }
    }


    // paid_media_preview->duration
    if(paid_media_preview->duration) {
    if(cJSON_AddNumberToObject(item, "duration", paid_media_preview->duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

paid_media_preview_t *paid_media_preview_parseFromJSON(cJSON *paid_media_previewJSON){

    paid_media_preview_t *paid_media_preview_local_var = NULL;

    // paid_media_preview->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(paid_media_previewJSON, "type");
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

    // paid_media_preview->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(paid_media_previewJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (width) { 
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }
    }

    // paid_media_preview->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(paid_media_previewJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // paid_media_preview->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(paid_media_previewJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }


    paid_media_preview_local_var = paid_media_preview_create_internal (
        strdup(type->valuestring),
        width ? width->valuedouble : 0,
        height ? height->valuedouble : 0,
        duration ? duration->valuedouble : 0
        );

    return paid_media_preview_local_var;
end:
    return NULL;

}
