#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_venue_message_content.h"



static input_venue_message_content_t *input_venue_message_content_create_internal(
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
    ) {
    input_venue_message_content_t *input_venue_message_content_local_var = malloc(sizeof(input_venue_message_content_t));
    if (!input_venue_message_content_local_var) {
        return NULL;
    }
    input_venue_message_content_local_var->latitude = latitude;
    input_venue_message_content_local_var->longitude = longitude;
    input_venue_message_content_local_var->title = title;
    input_venue_message_content_local_var->address = address;
    input_venue_message_content_local_var->foursquare_id = foursquare_id;
    input_venue_message_content_local_var->foursquare_type = foursquare_type;
    input_venue_message_content_local_var->google_place_id = google_place_id;
    input_venue_message_content_local_var->google_place_type = google_place_type;

    input_venue_message_content_local_var->_library_owned = 1;
    return input_venue_message_content_local_var;
}

__attribute__((deprecated)) input_venue_message_content_t *input_venue_message_content_create(
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
    ) {
    return input_venue_message_content_create_internal (
        latitude,
        longitude,
        title,
        address,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type
        );
}

void input_venue_message_content_free(input_venue_message_content_t *input_venue_message_content) {
    if(NULL == input_venue_message_content){
        return ;
    }
    if(input_venue_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_venue_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_venue_message_content->title) {
        free(input_venue_message_content->title);
        input_venue_message_content->title = NULL;
    }
    if (input_venue_message_content->address) {
        free(input_venue_message_content->address);
        input_venue_message_content->address = NULL;
    }
    if (input_venue_message_content->foursquare_id) {
        free(input_venue_message_content->foursquare_id);
        input_venue_message_content->foursquare_id = NULL;
    }
    if (input_venue_message_content->foursquare_type) {
        free(input_venue_message_content->foursquare_type);
        input_venue_message_content->foursquare_type = NULL;
    }
    if (input_venue_message_content->google_place_id) {
        free(input_venue_message_content->google_place_id);
        input_venue_message_content->google_place_id = NULL;
    }
    if (input_venue_message_content->google_place_type) {
        free(input_venue_message_content->google_place_type);
        input_venue_message_content->google_place_type = NULL;
    }
    free(input_venue_message_content);
}

cJSON *input_venue_message_content_convertToJSON(input_venue_message_content_t *input_venue_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_venue_message_content->latitude
    if (!input_venue_message_content->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", input_venue_message_content->latitude) == NULL) {
    goto fail; //Numeric
    }


    // input_venue_message_content->longitude
    if (!input_venue_message_content->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", input_venue_message_content->longitude) == NULL) {
    goto fail; //Numeric
    }


    // input_venue_message_content->title
    if (!input_venue_message_content->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", input_venue_message_content->title) == NULL) {
    goto fail; //String
    }


    // input_venue_message_content->address
    if (!input_venue_message_content->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", input_venue_message_content->address) == NULL) {
    goto fail; //String
    }


    // input_venue_message_content->foursquare_id
    if(input_venue_message_content->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", input_venue_message_content->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // input_venue_message_content->foursquare_type
    if(input_venue_message_content->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", input_venue_message_content->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // input_venue_message_content->google_place_id
    if(input_venue_message_content->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", input_venue_message_content->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // input_venue_message_content->google_place_type
    if(input_venue_message_content->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", input_venue_message_content->google_place_type) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

input_venue_message_content_t *input_venue_message_content_parseFromJSON(cJSON *input_venue_message_contentJSON){

    input_venue_message_content_t *input_venue_message_content_local_var = NULL;

    // input_venue_message_content->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "latitude");
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

    // input_venue_message_content->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "longitude");
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

    // input_venue_message_content->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "title");
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

    // input_venue_message_content->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // input_venue_message_content->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // input_venue_message_content->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // input_venue_message_content->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // input_venue_message_content->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(input_venue_message_contentJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }


    input_venue_message_content_local_var = input_venue_message_content_create_internal (
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(title->valuestring),
        strdup(address->valuestring),
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL
        );

    return input_venue_message_content_local_var;
end:
    return NULL;

}
