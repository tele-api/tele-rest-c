#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_profile_photo_static.h"



static input_profile_photo_static_t *input_profile_photo_static_create_internal(
    char *type,
    char *photo
    ) {
    input_profile_photo_static_t *input_profile_photo_static_local_var = malloc(sizeof(input_profile_photo_static_t));
    if (!input_profile_photo_static_local_var) {
        return NULL;
    }
    input_profile_photo_static_local_var->type = type;
    input_profile_photo_static_local_var->photo = photo;

    input_profile_photo_static_local_var->_library_owned = 1;
    return input_profile_photo_static_local_var;
}

__attribute__((deprecated)) input_profile_photo_static_t *input_profile_photo_static_create(
    char *type,
    char *photo
    ) {
    return input_profile_photo_static_create_internal (
        type,
        photo
        );
}

void input_profile_photo_static_free(input_profile_photo_static_t *input_profile_photo_static) {
    if(NULL == input_profile_photo_static){
        return ;
    }
    if(input_profile_photo_static->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_profile_photo_static_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_profile_photo_static->type) {
        free(input_profile_photo_static->type);
        input_profile_photo_static->type = NULL;
    }
    if (input_profile_photo_static->photo) {
        free(input_profile_photo_static->photo);
        input_profile_photo_static->photo = NULL;
    }
    free(input_profile_photo_static);
}

cJSON *input_profile_photo_static_convertToJSON(input_profile_photo_static_t *input_profile_photo_static) {
    cJSON *item = cJSON_CreateObject();

    // input_profile_photo_static->type
    if (!input_profile_photo_static->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_profile_photo_static->type) == NULL) {
    goto fail; //String
    }


    // input_profile_photo_static->photo
    if (!input_profile_photo_static->photo) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "photo", input_profile_photo_static->photo) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_profile_photo_static_t *input_profile_photo_static_parseFromJSON(cJSON *input_profile_photo_staticJSON){

    input_profile_photo_static_t *input_profile_photo_static_local_var = NULL;

    // input_profile_photo_static->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_profile_photo_staticJSON, "type");
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

    // input_profile_photo_static->photo
    cJSON *photo = cJSON_GetObjectItemCaseSensitive(input_profile_photo_staticJSON, "photo");
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


    input_profile_photo_static_local_var = input_profile_photo_static_create_internal (
        strdup(type->valuestring),
        strdup(photo->valuestring)
        );

    return input_profile_photo_static_local_var;
end:
    return NULL;

}
