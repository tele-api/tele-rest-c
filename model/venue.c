#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "venue.h"



static venue_t *venue_create_internal(
    location_t *location,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
    ) {
    venue_t *venue_local_var = malloc(sizeof(venue_t));
    if (!venue_local_var) {
        return NULL;
    }
    venue_local_var->location = location;
    venue_local_var->title = title;
    venue_local_var->address = address;
    venue_local_var->foursquare_id = foursquare_id;
    venue_local_var->foursquare_type = foursquare_type;
    venue_local_var->google_place_id = google_place_id;
    venue_local_var->google_place_type = google_place_type;

    venue_local_var->_library_owned = 1;
    return venue_local_var;
}

__attribute__((deprecated)) venue_t *venue_create(
    location_t *location,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type
    ) {
    return venue_create_internal (
        location,
        title,
        address,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type
        );
}

void venue_free(venue_t *venue) {
    if(NULL == venue){
        return ;
    }
    if(venue->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "venue_free");
        return ;
    }
    listEntry_t *listEntry;
    if (venue->location) {
        location_free(venue->location);
        venue->location = NULL;
    }
    if (venue->title) {
        free(venue->title);
        venue->title = NULL;
    }
    if (venue->address) {
        free(venue->address);
        venue->address = NULL;
    }
    if (venue->foursquare_id) {
        free(venue->foursquare_id);
        venue->foursquare_id = NULL;
    }
    if (venue->foursquare_type) {
        free(venue->foursquare_type);
        venue->foursquare_type = NULL;
    }
    if (venue->google_place_id) {
        free(venue->google_place_id);
        venue->google_place_id = NULL;
    }
    if (venue->google_place_type) {
        free(venue->google_place_type);
        venue->google_place_type = NULL;
    }
    free(venue);
}

cJSON *venue_convertToJSON(venue_t *venue) {
    cJSON *item = cJSON_CreateObject();

    // venue->location
    if (!venue->location) {
        goto fail;
    }
    cJSON *location_local_JSON = location_convertToJSON(venue->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // venue->title
    if (!venue->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", venue->title) == NULL) {
    goto fail; //String
    }


    // venue->address
    if (!venue->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", venue->address) == NULL) {
    goto fail; //String
    }


    // venue->foursquare_id
    if(venue->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", venue->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // venue->foursquare_type
    if(venue->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", venue->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // venue->google_place_id
    if(venue->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", venue->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // venue->google_place_type
    if(venue->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", venue->google_place_type) == NULL) {
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

venue_t *venue_parseFromJSON(cJSON *venueJSON){

    venue_t *venue_local_var = NULL;

    // define the local variable for venue->location
    location_t *location_local_nonprim = NULL;

    // venue->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(venueJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (!location) {
        goto end;
    }

    
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive

    // venue->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(venueJSON, "title");
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

    // venue->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(venueJSON, "address");
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

    // venue->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(venueJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // venue->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(venueJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // venue->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(venueJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // venue->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(venueJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }


    venue_local_var = venue_create_internal (
        location_local_nonprim,
        strdup(title->valuestring),
        strdup(address->valuestring),
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL
        );

    return venue_local_var;
end:
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
