#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_location.h"



static inline_query_result_location_t *inline_query_result_location_create_internal(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    inline_query_result_location_t *inline_query_result_location_local_var = malloc(sizeof(inline_query_result_location_t));
    if (!inline_query_result_location_local_var) {
        return NULL;
    }
    inline_query_result_location_local_var->type = type;
    inline_query_result_location_local_var->id = id;
    inline_query_result_location_local_var->latitude = latitude;
    inline_query_result_location_local_var->longitude = longitude;
    inline_query_result_location_local_var->title = title;
    inline_query_result_location_local_var->horizontal_accuracy = horizontal_accuracy;
    inline_query_result_location_local_var->live_period = live_period;
    inline_query_result_location_local_var->heading = heading;
    inline_query_result_location_local_var->proximity_alert_radius = proximity_alert_radius;
    inline_query_result_location_local_var->reply_markup = reply_markup;
    inline_query_result_location_local_var->input_message_content = input_message_content;
    inline_query_result_location_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_location_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_location_local_var->thumbnail_height = thumbnail_height;

    inline_query_result_location_local_var->_library_owned = 1;
    return inline_query_result_location_local_var;
}

__attribute__((deprecated)) inline_query_result_location_t *inline_query_result_location_create(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    return inline_query_result_location_create_internal (
        type,
        id,
        latitude,
        longitude,
        title,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius,
        reply_markup,
        input_message_content,
        thumbnail_url,
        thumbnail_width,
        thumbnail_height
        );
}

void inline_query_result_location_free(inline_query_result_location_t *inline_query_result_location) {
    if(NULL == inline_query_result_location){
        return ;
    }
    if(inline_query_result_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_location->type) {
        free(inline_query_result_location->type);
        inline_query_result_location->type = NULL;
    }
    if (inline_query_result_location->id) {
        free(inline_query_result_location->id);
        inline_query_result_location->id = NULL;
    }
    if (inline_query_result_location->title) {
        free(inline_query_result_location->title);
        inline_query_result_location->title = NULL;
    }
    if (inline_query_result_location->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_location->reply_markup);
        inline_query_result_location->reply_markup = NULL;
    }
    if (inline_query_result_location->input_message_content) {
        input_message_content_free(inline_query_result_location->input_message_content);
        inline_query_result_location->input_message_content = NULL;
    }
    if (inline_query_result_location->thumbnail_url) {
        free(inline_query_result_location->thumbnail_url);
        inline_query_result_location->thumbnail_url = NULL;
    }
    free(inline_query_result_location);
}

cJSON *inline_query_result_location_convertToJSON(inline_query_result_location_t *inline_query_result_location) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_location->type
    if (!inline_query_result_location->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_location->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_location->id
    if (!inline_query_result_location->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_location->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_location->latitude
    if (!inline_query_result_location->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", inline_query_result_location->latitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result_location->longitude
    if (!inline_query_result_location->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", inline_query_result_location->longitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result_location->title
    if (!inline_query_result_location->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_location->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_location->horizontal_accuracy
    if(inline_query_result_location->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", inline_query_result_location->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_location->live_period
    if(inline_query_result_location->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", inline_query_result_location->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_location->heading
    if(inline_query_result_location->heading) {
    if(cJSON_AddNumberToObject(item, "heading", inline_query_result_location->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_location->proximity_alert_radius
    if(inline_query_result_location->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", inline_query_result_location->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_location->reply_markup
    if(inline_query_result_location->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_location->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_location->input_message_content
    if(inline_query_result_location->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_location->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_location->thumbnail_url
    if(inline_query_result_location->thumbnail_url) {
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_location->thumbnail_url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_location->thumbnail_width
    if(inline_query_result_location->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result_location->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_location->thumbnail_height
    if(inline_query_result_location->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result_location->thumbnail_height) == NULL) {
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

inline_query_result_location_t *inline_query_result_location_parseFromJSON(cJSON *inline_query_result_locationJSON){

    inline_query_result_location_t *inline_query_result_location_local_var = NULL;

    // define the local variable for inline_query_result_location->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_location->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_location->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "type");
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

    // inline_query_result_location->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // inline_query_result_location->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "latitude");
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

    // inline_query_result_location->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "longitude");
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

    // inline_query_result_location->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }

    // inline_query_result_location->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_location->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_location->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_location->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_location->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_location->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }

    // inline_query_result_location->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (thumbnail_url) { 
    if(!cJSON_IsString(thumbnail_url) && !cJSON_IsNull(thumbnail_url))
    {
    goto end; //String
    }
    }

    // inline_query_result_location->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_location->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_locationJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_location_local_var = inline_query_result_location_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(title->valuestring),
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL,
        thumbnail_url && !cJSON_IsNull(thumbnail_url) ? strdup(thumbnail_url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0
        );

    return inline_query_result_location_local_var;
end:
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    if (input_message_content_local_nonprim) {
        input_message_content_free(input_message_content_local_nonprim);
        input_message_content_local_nonprim = NULL;
    }
    return NULL;

}
