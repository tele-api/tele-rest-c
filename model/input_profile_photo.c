#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_profile_photo.h"



static input_profile_photo_t *input_profile_photo_create_internal(
    char *type,
    char *photo,
    char *animation,
    double main_frame_timestamp
    ) {
    input_profile_photo_t *input_profile_photo_local_var = malloc(sizeof(input_profile_photo_t));
    if (!input_profile_photo_local_var) {
        return NULL;
    }
    input_profile_photo_local_var->type = type;
    input_profile_photo_local_var->photo = photo;
    input_profile_photo_local_var->animation = animation;
    input_profile_photo_local_var->main_frame_timestamp = main_frame_timestamp;

    input_profile_photo_local_var->_library_owned = 1;
    return input_profile_photo_local_var;
}

__attribute__((deprecated)) input_profile_photo_t *input_profile_photo_create(
    char *type,
    char *photo,
    char *animation,
    double main_frame_timestamp
    ) {
    return input_profile_photo_create_internal (
        type,
        photo,
        animation,
        main_frame_timestamp
        );
}

void input_profile_photo_free(input_profile_photo_t *input_profile_photo) {
    if(NULL == input_profile_photo){
        return ;
    }
    if(input_profile_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_profile_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_profile_photo->type) {
        free(input_profile_photo->type);
        input_profile_photo->type = NULL;
    }
    if (input_profile_photo->photo) {
        free(input_profile_photo->photo);
        input_profile_photo->photo = NULL;
    }
    if (input_profile_photo->animation) {
        free(input_profile_photo->animation);
        input_profile_photo->animation = NULL;
    }
    free(input_profile_photo);
}

cJSON *input_profile_photo_convertToJSON(input_profile_photo_t *input_profile_photo) {
    cJSON *item = cJSON_CreateObject();

    // input_profile_photo->type
    if (!input_profile_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_profile_photo->type) == NULL) {
    goto fail; //String
    }


    // input_profile_photo->photo
    if (!input_profile_photo->photo) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo", input_profile_photo->photo) == NULL) {
    goto fail; //String
    }


    // input_profile_photo->animation
    if (!input_profile_photo->animation) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "animation", input_profile_photo->animation) == NULL) {
    goto fail; //String
    }


    // input_profile_photo->main_frame_timestamp
    if(input_profile_photo->main_frame_timestamp) {
    if(cJSON_AddNumberToObject(item, "main_frame_timestamp", input_profile_photo->main_frame_timestamp) == NULL) {
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

input_profile_photo_t *input_profile_photo_parseFromJSON(cJSON *input_profile_photoJSON){

    input_profile_photo_t *input_profile_photo_local_var = NULL;

    // input_profile_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_profile_photoJSON, "type");
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

    // input_profile_photo->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(input_profile_photoJSON, "photo");
    if (cJSON_IsNull(photo)) {
        photo = NULL;
    }
    if (!photo) {
        goto end;
    }

    
    if(!cJSON_IsString(photo))
    {
    goto end; //String
    }

    // input_profile_photo->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(input_profile_photoJSON, "animation");
    if (cJSON_IsNull(animation)) {
        animation = NULL;
    }
    if (!animation) {
        goto end;
    }

    
    if(!cJSON_IsString(animation))
    {
    goto end; //String
    }

    // input_profile_photo->main_frame_timestamp
    cJSON *main_frame_timestamp = cJSON_GetObjectItemCaseSensitive(input_profile_photoJSON, "main_frame_timestamp");
    if (cJSON_IsNull(main_frame_timestamp)) {
        main_frame_timestamp = NULL;
    }
    if (main_frame_timestamp) { 
    if(!cJSON_IsNumber(main_frame_timestamp))
    {
    goto end; //Numeric
    }
    }


    input_profile_photo_local_var = input_profile_photo_create_internal (
        strdup(type->valuestring),
        strdup(photo->valuestring),
        strdup(animation->valuestring),
        main_frame_timestamp ? main_frame_timestamp->valuedouble : 0
        );

    return input_profile_photo_local_var;
end:
    return NULL;

}
