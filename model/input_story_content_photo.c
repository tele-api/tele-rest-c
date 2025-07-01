#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_story_content_photo.h"



static input_story_content_photo_t *input_story_content_photo_create_internal(
    char *type,
    char *photo
    ) {
    input_story_content_photo_t *input_story_content_photo_local_var = malloc(sizeof(input_story_content_photo_t));
    if (!input_story_content_photo_local_var) {
        return NULL;
    }
    input_story_content_photo_local_var->type = type;
    input_story_content_photo_local_var->photo = photo;

    input_story_content_photo_local_var->_library_owned = 1;
    return input_story_content_photo_local_var;
}

__attribute__((deprecated)) input_story_content_photo_t *input_story_content_photo_create(
    char *type,
    char *photo
    ) {
    return input_story_content_photo_create_internal (
        type,
        photo
        );
}

void input_story_content_photo_free(input_story_content_photo_t *input_story_content_photo) {
    if(NULL == input_story_content_photo){
        return ;
    }
    if(input_story_content_photo->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_story_content_photo_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_story_content_photo->type) {
        free(input_story_content_photo->type);
        input_story_content_photo->type = NULL;
    }
    if (input_story_content_photo->photo) {
        free(input_story_content_photo->photo);
        input_story_content_photo->photo = NULL;
    }
    free(input_story_content_photo);
}

cJSON *input_story_content_photo_convertToJSON(input_story_content_photo_t *input_story_content_photo) {
    cJSON *item = cJSON_CreateObject();

    // input_story_content_photo->type
    if (!input_story_content_photo->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_story_content_photo->type) == NULL) {
    goto fail; //String
    }


    // input_story_content_photo->photo
    if (!input_story_content_photo->photo) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo", input_story_content_photo->photo) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_story_content_photo_t *input_story_content_photo_parseFromJSON(cJSON *input_story_content_photoJSON){

    input_story_content_photo_t *input_story_content_photo_local_var = NULL;

    // input_story_content_photo->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_story_content_photoJSON, "type");
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

    // input_story_content_photo->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(input_story_content_photoJSON, "photo");
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


    input_story_content_photo_local_var = input_story_content_photo_create_internal (
        strdup(type->valuestring),
        strdup(photo->valuestring)
        );

    return input_story_content_photo_local_var;
end:
    return NULL;

}
