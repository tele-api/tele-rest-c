#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_location_message_content.h"



static input_location_message_content_t *input_location_message_content_create_internal(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
    ) {
    input_location_message_content_t *input_location_message_content_local_var = malloc(sizeof(input_location_message_content_t));
    if (!input_location_message_content_local_var) {
        return NULL;
    }
    input_location_message_content_local_var->latitude = latitude;
    input_location_message_content_local_var->longitude = longitude;
    input_location_message_content_local_var->horizontal_accuracy = horizontal_accuracy;
    input_location_message_content_local_var->live_period = live_period;
    input_location_message_content_local_var->heading = heading;
    input_location_message_content_local_var->proximity_alert_radius = proximity_alert_radius;

    input_location_message_content_local_var->_library_owned = 1;
    return input_location_message_content_local_var;
}

__attribute__((deprecated)) input_location_message_content_t *input_location_message_content_create(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
    ) {
    return input_location_message_content_create_internal (
        latitude,
        longitude,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius
        );
}

void input_location_message_content_free(input_location_message_content_t *input_location_message_content) {
    if(NULL == input_location_message_content){
        return ;
    }
    if(input_location_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_location_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    free(input_location_message_content);
}

cJSON *input_location_message_content_convertToJSON(input_location_message_content_t *input_location_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_location_message_content->latitude
    if (!input_location_message_content->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", input_location_message_content->latitude) == NULL) {
    goto fail; //Numeric
    }


    // input_location_message_content->longitude
    if (!input_location_message_content->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", input_location_message_content->longitude) == NULL) {
    goto fail; //Numeric
    }


    // input_location_message_content->horizontal_accuracy
    if(input_location_message_content->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", input_location_message_content->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_location_message_content->live_period
    if(input_location_message_content->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", input_location_message_content->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_location_message_content->heading
    if(input_location_message_content->heading) {
    if(cJSON_AddNumberToObject(item, "heading", input_location_message_content->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // input_location_message_content->proximity_alert_radius
    if(input_location_message_content->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", input_location_message_content->proximity_alert_radius) == NULL) {
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

input_location_message_content_t *input_location_message_content_parseFromJSON(cJSON *input_location_message_contentJSON){

    input_location_message_content_t *input_location_message_content_local_var = NULL;

    // input_location_message_content->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "latitude");
    if (cJSON_IsNull(latitude)) {
        latitude = NULL;
    }
    if (!latitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(latitude))
    {
    goto end; //Numeric
    }

    // input_location_message_content->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "longitude");
    if (cJSON_IsNull(longitude)) {
        longitude = NULL;
    }
    if (!longitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(longitude))
    {
    goto end; //Numeric
    }

    // input_location_message_content->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // input_location_message_content->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // input_location_message_content->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // input_location_message_content->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(input_location_message_contentJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }


    input_location_message_content_local_var = input_location_message_content_create_internal (
        latitude->valuedouble,
        longitude->valuedouble,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0
        );

    return input_location_message_content_local_var;
end:
    return NULL;

}
