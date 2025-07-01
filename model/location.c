#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location.h"



static location_t *location_create_internal(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
    ) {
    location_t *location_local_var = malloc(sizeof(location_t));
    if (!location_local_var) {
        return NULL;
    }
    location_local_var->latitude = latitude;
    location_local_var->longitude = longitude;
    location_local_var->horizontal_accuracy = horizontal_accuracy;
    location_local_var->live_period = live_period;
    location_local_var->heading = heading;
    location_local_var->proximity_alert_radius = proximity_alert_radius;

    location_local_var->_library_owned = 1;
    return location_local_var;
}

__attribute__((deprecated)) location_t *location_create(
    double latitude,
    double longitude,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius
    ) {
    return location_create_internal (
        latitude,
        longitude,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius
        );
}

void location_free(location_t *location) {
    if(NULL == location){
        return ;
    }
    if(location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "location_free");
        return ;
    }
    listEntry_t *listEntry;
    free(location);
}

cJSON *location_convertToJSON(location_t *location) {
    cJSON *item = cJSON_CreateObject();

    // location->latitude
    if (!location->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", location->latitude) == NULL) {
    goto fail; //Numeric
    }


    // location->longitude
    if (!location->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", location->longitude) == NULL) {
    goto fail; //Numeric
    }


    // location->horizontal_accuracy
    if(location->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", location->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // location->live_period
    if(location->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", location->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // location->heading
    if(location->heading) {
    if(cJSON_AddNumberToObject(item, "heading", location->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // location->proximity_alert_radius
    if(location->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", location->proximity_alert_radius) == NULL) {
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

location_t *location_parseFromJSON(cJSON *locationJSON){

    location_t *location_local_var = NULL;

    // location->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(locationJSON, "latitude");
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

    // location->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(locationJSON, "longitude");
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

    // location->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(locationJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // location->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(locationJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // location->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(locationJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // location->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(locationJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }


    location_local_var = location_create_internal (
        latitude->valuedouble,
        longitude->valuedouble,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0
        );

    return location_local_var;
end:
    return NULL;

}
