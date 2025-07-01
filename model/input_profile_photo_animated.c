#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_profile_photo_animated.h"



static input_profile_photo_animated_t *input_profile_photo_animated_create_internal(
    char *type,
    char *animation,
    double main_frame_timestamp
    ) {
    input_profile_photo_animated_t *input_profile_photo_animated_local_var = malloc(sizeof(input_profile_photo_animated_t));
    if (!input_profile_photo_animated_local_var) {
        return NULL;
    }
    input_profile_photo_animated_local_var->type = type;
    input_profile_photo_animated_local_var->animation = animation;
    input_profile_photo_animated_local_var->main_frame_timestamp = main_frame_timestamp;

    input_profile_photo_animated_local_var->_library_owned = 1;
    return input_profile_photo_animated_local_var;
}

__attribute__((deprecated)) input_profile_photo_animated_t *input_profile_photo_animated_create(
    char *type,
    char *animation,
    double main_frame_timestamp
    ) {
    return input_profile_photo_animated_create_internal (
        type,
        animation,
        main_frame_timestamp
        );
}

void input_profile_photo_animated_free(input_profile_photo_animated_t *input_profile_photo_animated) {
    if(NULL == input_profile_photo_animated){
        return ;
    }
    if(input_profile_photo_animated->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_profile_photo_animated_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_profile_photo_animated->type) {
        free(input_profile_photo_animated->type);
        input_profile_photo_animated->type = NULL;
    }
    if (input_profile_photo_animated->animation) {
        free(input_profile_photo_animated->animation);
        input_profile_photo_animated->animation = NULL;
    }
    free(input_profile_photo_animated);
}

cJSON *input_profile_photo_animated_convertToJSON(input_profile_photo_animated_t *input_profile_photo_animated) {
    cJSON *item = cJSON_CreateObject();

    // input_profile_photo_animated->type
    if (!input_profile_photo_animated->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", input_profile_photo_animated->type) == NULL) {
    goto fail; //String
    }


    // input_profile_photo_animated->animation
    if (!input_profile_photo_animated->animation) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "animation", input_profile_photo_animated->animation) == NULL) {
    goto fail; //String
    }


    // input_profile_photo_animated->main_frame_timestamp
    if(input_profile_photo_animated->main_frame_timestamp) {
    if(cJSON_AddNumberToObject(item, "main_frame_timestamp", input_profile_photo_animated->main_frame_timestamp) == NULL) {
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

input_profile_photo_animated_t *input_profile_photo_animated_parseFromJSON(cJSON *input_profile_photo_animatedJSON){

    input_profile_photo_animated_t *input_profile_photo_animated_local_var = NULL;

    // input_profile_photo_animated->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(input_profile_photo_animatedJSON, "type");
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

    // input_profile_photo_animated->animation
    cJSON *animation = cJSON_GetObjectItemCaseSensitive(input_profile_photo_animatedJSON, "animation");
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

    // input_profile_photo_animated->main_frame_timestamp
    cJSON *main_frame_timestamp = cJSON_GetObjectItemCaseSensitive(input_profile_photo_animatedJSON, "main_frame_timestamp");
    if (cJSON_IsNull(main_frame_timestamp)) {
        main_frame_timestamp = NULL;
    }
    if (main_frame_timestamp) { 
    if(!cJSON_IsNumber(main_frame_timestamp))
    {
    goto end; //Numeric
    }
    }


    input_profile_photo_animated_local_var = input_profile_photo_animated_create_internal (
        strdup(type->valuestring),
        strdup(animation->valuestring),
        main_frame_timestamp ? main_frame_timestamp->valuedouble : 0
        );

    return input_profile_photo_animated_local_var;
end:
    return NULL;

}
