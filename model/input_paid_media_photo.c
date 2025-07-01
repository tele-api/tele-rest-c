#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_paid_media_photo.h"



static input_paid_media_photo_t *input_paid_media_photo_create_internal(
    char *type,
    char *media
    ) {
    input_paid_media_photo_t *input_paid_media_photo_local_var = malloc(sizeof(input_paid_media_photo_t));
    if (!input_paid_media_photo_local_var) {
        return NULL;
    }
    input_paid_media_photo_local_var->type = type;
    input_paid_media_photo_local_var->media = media;

    input_paid_media_photo_local_var->_library_owned = 1;
    return input_paid_media_photo_local_var;
}

__attribute__((deprecated)) input_paid_media_photo_t *input_paid_media_photo_create(
    char *type,
    char *media
    ) {
    return input_paid_media_photo_create_internal (
        type,
        media
        );
}

void input_paid_media_photo_free(input_paid_media_photo_t *input_paid_media_photo) {
    if(NULL == input_paid_media_photo){
        return ;
    }
    if(input_paid_media_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_paid_media_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_paid_media_photo->type) {
        free(input_paid_media_photo->type);
        input_paid_media_photo->type = NULL;
    }
    if (input_paid_media_photo->media) {
        free(input_paid_media_photo->media);
        input_paid_media_photo->media = NULL;
    }
    free(input_paid_media_photo);
}

cJSON *input_paid_media_photo_convertToJSON(input_paid_media_photo_t *input_paid_media_photo) {
    cJSON *item = cJSON_CreateObject();

    // input_paid_media_photo->type
    if (!input_paid_media_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_paid_media_photo->type) == NULL) {
    goto fail; //String
    }


    // input_paid_media_photo->media
    if (!input_paid_media_photo->media) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "media", input_paid_media_photo->media) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_paid_media_photo_t *input_paid_media_photo_parseFromJSON(cJSON *input_paid_media_photoJSON){

    input_paid_media_photo_t *input_paid_media_photo_local_var = NULL;

    // input_paid_media_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_paid_media_photoJSON, "type");
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

    // input_paid_media_photo->media
    cJSON *media = cJSON_GetObjectItemCaseSensitive(input_paid_media_photoJSON, "media");
    if (cJSON_IsNull(media)) {
        media = NULL;
    }
    if (!media) {
        goto end;
    }

    
    if(!cJSON_IsString(media))
    {
    goto end; //String
    }


    input_paid_media_photo_local_var = input_paid_media_photo_create_internal (
        strdup(type->valuestring),
        strdup(media->valuestring)
        );

    return input_paid_media_photo_local_var;
end:
    return NULL;

}
