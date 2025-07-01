#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_position.h"



static story_area_position_t *story_area_position_create_internal(
    double x_percentage,
    double y_percentage,
    double width_percentage,
    double height_percentage,
    double rotation_angle,
    double corner_radius_percentage
    ) {
    story_area_position_t *story_area_position_local_var = malloc(sizeof(story_area_position_t));
    if (!story_area_position_local_var) {
        return NULL;
    }
    story_area_position_local_var->x_percentage = x_percentage;
    story_area_position_local_var->y_percentage = y_percentage;
    story_area_position_local_var->width_percentage = width_percentage;
    story_area_position_local_var->height_percentage = height_percentage;
    story_area_position_local_var->rotation_angle = rotation_angle;
    story_area_position_local_var->corner_radius_percentage = corner_radius_percentage;

    story_area_position_local_var->_library_owned = 1;
    return story_area_position_local_var;
}

__attribute__((deprecated)) story_area_position_t *story_area_position_create(
    double x_percentage,
    double y_percentage,
    double width_percentage,
    double height_percentage,
    double rotation_angle,
    double corner_radius_percentage
    ) {
    return story_area_position_create_internal (
        x_percentage,
        y_percentage,
        width_percentage,
        height_percentage,
        rotation_angle,
        corner_radius_percentage
        );
}

void story_area_position_free(story_area_position_t *story_area_position) {
    if(NULL == story_area_position){
        return ;
    }
    if(story_area_position->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_position_free");
        return ;
    }
    listEntry_t *listEntry;
    free(story_area_position);
}

cJSON *story_area_position_convertToJSON(story_area_position_t *story_area_position) {
    cJSON *item = cJSON_CreateObject();

    // story_area_position->x_percentage
    if (!story_area_position->x_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "x_percentage", story_area_position->x_percentage) == NULL) {
    goto fail; //Numeric
    }


    // story_area_position->y_percentage
    if (!story_area_position->y_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "y_percentage", story_area_position->y_percentage) == NULL) {
    goto fail; //Numeric
    }


    // story_area_position->width_percentage
    if (!story_area_position->width_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "width_percentage", story_area_position->width_percentage) == NULL) {
    goto fail; //Numeric
    }


    // story_area_position->height_percentage
    if (!story_area_position->height_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "height_percentage", story_area_position->height_percentage) == NULL) {
    goto fail; //Numeric
    }


    // story_area_position->rotation_angle
    if (!story_area_position->rotation_angle) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "rotation_angle", story_area_position->rotation_angle) == NULL) {
    goto fail; //Numeric
    }


    // story_area_position->corner_radius_percentage
    if (!story_area_position->corner_radius_percentage) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "corner_radius_percentage", story_area_position->corner_radius_percentage) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_position_t *story_area_position_parseFromJSON(cJSON *story_area_positionJSON){

    story_area_position_t *story_area_position_local_var = NULL;

    // story_area_position->x_percentage
    cJSON *x_percentage = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "x_percentage");
    if (cJSON_IsNull(x_percentage)) {
        x_percentage = NULL;
    }
    if (!x_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(x_percentage))
    {
    goto end; //Numeric
    }

    // story_area_position->y_percentage
    cJSON *y_percentage = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "y_percentage");
    if (cJSON_IsNull(y_percentage)) {
        y_percentage = NULL;
    }
    if (!y_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(y_percentage))
    {
    goto end; //Numeric
    }

    // story_area_position->width_percentage
    cJSON *width_percentage = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "width_percentage");
    if (cJSON_IsNull(width_percentage)) {
        width_percentage = NULL;
    }
    if (!width_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(width_percentage))
    {
    goto end; //Numeric
    }

    // story_area_position->height_percentage
    cJSON *height_percentage = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "height_percentage");
    if (cJSON_IsNull(height_percentage)) {
        height_percentage = NULL;
    }
    if (!height_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(height_percentage))
    {
    goto end; //Numeric
    }

    // story_area_position->rotation_angle
    cJSON *rotation_angle = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "rotation_angle");
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

    // story_area_position->corner_radius_percentage
    cJSON *corner_radius_percentage = cJSON_GetObjectItemCaseSensitive(story_area_positionJSON, "corner_radius_percentage");
    if (cJSON_IsNull(corner_radius_percentage)) {
        corner_radius_percentage = NULL;
    }
    if (!corner_radius_percentage) {
        goto end;
    }

    
    if(!cJSON_IsNumber(corner_radius_percentage))
    {
    goto end; //Numeric
    }


    story_area_position_local_var = story_area_position_create_internal (
        x_percentage->valuedouble,
        y_percentage->valuedouble,
        width_percentage->valuedouble,
        height_percentage->valuedouble,
        rotation_angle->valuedouble,
        corner_radius_percentage->valuedouble
        );

    return story_area_position_local_var;
end:
    return NULL;

}
