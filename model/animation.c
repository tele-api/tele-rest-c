#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "animation.h"



static animation_t *animation_create_internal(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    animation_t *animation_local_var = malloc(sizeof(animation_t));
    if (!animation_local_var) {
        return NULL;
    }
    animation_local_var->file_id = file_id;
    animation_local_var->file_unique_id = file_unique_id;
    animation_local_var->width = width;
    animation_local_var->height = height;
    animation_local_var->duration = duration;
    animation_local_var->thumbnail = thumbnail;
    animation_local_var->file_name = file_name;
    animation_local_var->mime_type = mime_type;
    animation_local_var->file_size = file_size;

    animation_local_var->_library_owned = 1;
    return animation_local_var;
}

__attribute__((deprecated)) animation_t *animation_create(
    char *file_id,
    char *file_unique_id,
    int width,
    int height,
    int duration,
    photo_size_t *thumbnail,
    char *file_name,
    char *mime_type,
    int file_size
    ) {
    return animation_create_internal (
        file_id,
        file_unique_id,
        width,
        height,
        duration,
        thumbnail,
        file_name,
        mime_type,
        file_size
        );
}

void animation_free(animation_t *animation) {
    if(NULL == animation){
        return ;
    }
    if(animation->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "animation_free");
        return ;
    }
    listEntry_t *listEntry;
    if (animation->file_id) {
        free(animation->file_id);
        animation->file_id = NULL;
    }
    if (animation->file_unique_id) {
        free(animation->file_unique_id);
        animation->file_unique_id = NULL;
    }
    if (animation->thumbnail) {
        photo_size_free(animation->thumbnail);
        animation->thumbnail = NULL;
    }
    if (animation->file_name) {
        free(animation->file_name);
        animation->file_name = NULL;
    }
    if (animation->mime_type) {
        free(animation->mime_type);
        animation->mime_type = NULL;
    }
    free(animation);
}

cJSON *animation_convertToJSON(animation_t *animation) {
    cJSON *item = cJSON_CreateObject();

    // animation->file_id
    if (!animation->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", animation->file_id) == NULL) {
    goto fail; //String
    }


    // animation->file_unique_id
    if (!animation->file_unique_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_unique_id", animation->file_unique_id) == NULL) {
    goto fail; //String
    }


    // animation->width
    if (!animation->width) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width", animation->width) == NULL) {
    goto fail; //Numeric
    }


    // animation->height
    if (!animation->height) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height", animation->height) == NULL) {
    goto fail; //Numeric
    }


    // animation->duration
    if (!animation->duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "duration", animation->duration) == NULL) {
    goto fail; //Numeric
    }


    // animation->thumbnail
    if(animation->thumbnail) {
    cJSON *thumbnail_local_JSON = photo_size_convertToJSON(animation->thumbnail);
    if(thumbnail_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "thumbnail", thumbnail_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // animation->file_name
    if(animation->file_name) {
    if(cJSON_AddStringToObject(item, "file_name", animation->file_name) == NULL) {
    goto fail; //String
    }
    }


    // animation->mime_type
    if(animation->mime_type) {
    if(cJSON_AddStringToObject(item, "mime_type", animation->mime_type) == NULL) {
    goto fail; //String
    }
    }


    // animation->file_size
    if(animation->file_size) {
    if(cJSON_AddNumberToObject(item, "file_size", animation->file_size) == NULL) {
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

animation_t *animation_parseFromJSON(cJSON *animationJSON){

    animation_t *animation_local_var = NULL;

    // define the local variable for animation->thumbnail
    photo_size_t *thumbnail_local_nonprim = NULL;

    // animation->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(animationJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }

    // animation->file_unique_id
    cJSON *file_unique_id = cJSON_GetObjectItemCaseSensitive(animationJSON, "file_unique_id");
    if (cJSON_IsNull(file_unique_id)) {
        file_unique_id = NULL;
    }
    if (!file_unique_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_unique_id))
    {
    goto end; //String
    }

    // animation->width
    cJSON *width = cJSON_GetObjectItemCaseSensitive(animationJSON, "width");
    if (cJSON_IsNull(width)) {
        width = NULL;
    }
    if (!width) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width))
    {
    goto end; //Numeric
    }

    // animation->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(animationJSON, "height");
    if (cJSON_IsNull(height)) {
        height = NULL;
    }
    if (!height) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }

    // animation->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(animationJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (!duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }

    // animation->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(animationJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    thumbnail_local_nonprim = photo_size_parseFromJSON(thumbnail); //nonprimitive
    }

    // animation->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(animationJSON, "file_name");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (file_name) { 
    if(!cJSON_IsString(file_name) && !cJSON_IsNull(file_name))
    {
    goto end; //String
    }
    }

    // animation->mime_type
    cJSON *mime_type = cJSON_GetObjectItemCaseSensitive(animationJSON, "mime_type");
    if (cJSON_IsNull(mime_type)) {
        mime_type = NULL;
    }
    if (mime_type) { 
    if(!cJSON_IsString(mime_type) && !cJSON_IsNull(mime_type))
    {
    goto end; //String
    }
    }

    // animation->file_size
    cJSON *file_size = cJSON_GetObjectItemCaseSensitive(animationJSON, "file_size");
    if (cJSON_IsNull(file_size)) {
        file_size = NULL;
    }
    if (file_size) { 
    if(!cJSON_IsNumber(file_size))
    {
    goto end; //Numeric
    }
    }


    animation_local_var = animation_create_internal (
        strdup(file_id->valuestring),
        strdup(file_unique_id->valuestring),
        width->valuedouble,
        height->valuedouble,
        duration->valuedouble,
        thumbnail ? thumbnail_local_nonprim : NULL,
        file_name && !cJSON_IsNull(file_name) ? strdup(file_name->valuestring) : NULL,
        mime_type && !cJSON_IsNull(mime_type) ? strdup(mime_type->valuestring) : NULL,
        file_size ? file_size->valuedouble : 0
        );

    return animation_local_var;
end:
    if (thumbnail_local_nonprim) {
        photo_size_free(thumbnail_local_nonprim);
        thumbnail_local_nonprim = NULL;
    }
    return NULL;

}
