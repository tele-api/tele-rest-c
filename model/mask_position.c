#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mask_position.h"


char* mask_position_point_ToString(telegram_bot_api_mask_position_POINT_e point) {
    char* pointArray[] =  { "NULL", "forehead", "eyes", "mouth", "chin" };
    return pointArray[point];
}

telegram_bot_api_mask_position_POINT_e mask_position_point_FromString(char* point){
    int stringToReturn = 0;
    char *pointArray[] =  { "NULL", "forehead", "eyes", "mouth", "chin" };
    size_t sizeofArray = sizeof(pointArray) / sizeof(pointArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(point, pointArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static mask_position_t *mask_position_create_internal(
    telegram_bot_api_mask_position_POINT_e point,
    double x_shift,
    double y_shift,
    double scale
    ) {
    mask_position_t *mask_position_local_var = malloc(sizeof(mask_position_t));
    if (!mask_position_local_var) {
        return NULL;
    }
    mask_position_local_var->point = point;
    mask_position_local_var->x_shift = x_shift;
    mask_position_local_var->y_shift = y_shift;
    mask_position_local_var->scale = scale;

    mask_position_local_var->_library_owned = 1;
    return mask_position_local_var;
}

__attribute__((deprecated)) mask_position_t *mask_position_create(
    telegram_bot_api_mask_position_POINT_e point,
    double x_shift,
    double y_shift,
    double scale
    ) {
    return mask_position_create_internal (
        point,
        x_shift,
        y_shift,
        scale
        );
}

void mask_position_free(mask_position_t *mask_position) {
    if(NULL == mask_position){
        return ;
    }
    if(mask_position->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mask_position_free");
        return ;
    }
    listEntry_t *listEntry;
    free(mask_position);
}

cJSON *mask_position_convertToJSON(mask_position_t *mask_position) {
    cJSON *item = cJSON_CreateObject();

    // mask_position->point
    if (telegram_bot_api_mask_position_POINT_NULL == mask_position->point) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "point", mask_position_point_ToString(mask_position->point)) == NULL)
    {
    goto fail; //Enum
    }


    // mask_position->x_shift
    if (!mask_position->x_shift) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "x_shift", mask_position->x_shift) == NULL) {
    goto fail; //Numeric
    }


    // mask_position->y_shift
    if (!mask_position->y_shift) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "y_shift", mask_position->y_shift) == NULL) {
    goto fail; //Numeric
    }


    // mask_position->scale
    if (!mask_position->scale) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "scale", mask_position->scale) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

mask_position_t *mask_position_parseFromJSON(cJSON *mask_positionJSON){

    mask_position_t *mask_position_local_var = NULL;

    // mask_position->point
    cJSON *point = cJSON_GetObjectItemCaseSensitive(mask_positionJSON, "point");
    if (cJSON_IsNull(point)) {
        point = NULL;
    }
    if (!point) {
        goto end;
    }

    telegram_bot_api_mask_position_POINT_e pointVariable;
    
    if(!cJSON_IsString(point))
    {
    goto end; //Enum
    }
    pointVariable = mask_position_point_FromString(point->valuestring);

    // mask_position->x_shift
    cJSON *x_shift = cJSON_GetObjectItemCaseSensitive(mask_positionJSON, "x_shift");
    if (cJSON_IsNull(x_shift)) {
        x_shift = NULL;
    }
    if (!x_shift) {
        goto end;
    }

    
    if(!cJSON_IsNumber(x_shift))
    {
    goto end; //Numeric
    }

    // mask_position->y_shift
    cJSON *y_shift = cJSON_GetObjectItemCaseSensitive(mask_positionJSON, "y_shift");
    if (cJSON_IsNull(y_shift)) {
        y_shift = NULL;
    }
    if (!y_shift) {
        goto end;
    }

    
    if(!cJSON_IsNumber(y_shift))
    {
    goto end; //Numeric
    }

    // mask_position->scale
    cJSON *scale = cJSON_GetObjectItemCaseSensitive(mask_positionJSON, "scale");
    if (cJSON_IsNull(scale)) {
        scale = NULL;
    }
    if (!scale) {
        goto end;
    }

    
    if(!cJSON_IsNumber(scale))
    {
    goto end; //Numeric
    }


    mask_position_local_var = mask_position_create_internal (
        pointVariable,
        x_shift->valuedouble,
        y_shift->valuedouble,
        scale->valuedouble
        );

    return mask_position_local_var;
end:
    return NULL;

}
