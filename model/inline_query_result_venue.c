#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_venue.h"



static inline_query_result_venue_t *inline_query_result_venue_create_internal(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    inline_query_result_venue_t *inline_query_result_venue_local_var = malloc(sizeof(inline_query_result_venue_t));
    if (!inline_query_result_venue_local_var) {
        return NULL;
    }
    inline_query_result_venue_local_var->type = type;
    inline_query_result_venue_local_var->id = id;
    inline_query_result_venue_local_var->latitude = latitude;
    inline_query_result_venue_local_var->longitude = longitude;
    inline_query_result_venue_local_var->title = title;
    inline_query_result_venue_local_var->address = address;
    inline_query_result_venue_local_var->foursquare_id = foursquare_id;
    inline_query_result_venue_local_var->foursquare_type = foursquare_type;
    inline_query_result_venue_local_var->google_place_id = google_place_id;
    inline_query_result_venue_local_var->google_place_type = google_place_type;
    inline_query_result_venue_local_var->reply_markup = reply_markup;
    inline_query_result_venue_local_var->input_message_content = input_message_content;
    inline_query_result_venue_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_venue_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_venue_local_var->thumbnail_height = thumbnail_height;

    inline_query_result_venue_local_var->_library_owned = 1;
    return inline_query_result_venue_local_var;
}

__attribute__((deprecated)) inline_query_result_venue_t *inline_query_result_venue_create(
    char *type,
    char *id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    return inline_query_result_venue_create_internal (
        type,
        id,
        latitude,
        longitude,
        title,
        address,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type,
        reply_markup,
        input_message_content,
        thumbnail_url,
        thumbnail_width,
        thumbnail_height
        );
}

void inline_query_result_venue_free(inline_query_result_venue_t *inline_query_result_venue) {
    if(NULL == inline_query_result_venue){
        return ;
    }
    if(inline_query_result_venue->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_venue_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_venue->type) {
        free(inline_query_result_venue->type);
        inline_query_result_venue->type = NULL;
    }
    if (inline_query_result_venue->id) {
        free(inline_query_result_venue->id);
        inline_query_result_venue->id = NULL;
    }
    if (inline_query_result_venue->title) {
        free(inline_query_result_venue->title);
        inline_query_result_venue->title = NULL;
    }
    if (inline_query_result_venue->address) {
        free(inline_query_result_venue->address);
        inline_query_result_venue->address = NULL;
    }
    if (inline_query_result_venue->foursquare_id) {
        free(inline_query_result_venue->foursquare_id);
        inline_query_result_venue->foursquare_id = NULL;
    }
    if (inline_query_result_venue->foursquare_type) {
        free(inline_query_result_venue->foursquare_type);
        inline_query_result_venue->foursquare_type = NULL;
    }
    if (inline_query_result_venue->google_place_id) {
        free(inline_query_result_venue->google_place_id);
        inline_query_result_venue->google_place_id = NULL;
    }
    if (inline_query_result_venue->google_place_type) {
        free(inline_query_result_venue->google_place_type);
        inline_query_result_venue->google_place_type = NULL;
    }
    if (inline_query_result_venue->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_venue->reply_markup);
        inline_query_result_venue->reply_markup = NULL;
    }
    if (inline_query_result_venue->input_message_content) {
        input_message_content_free(inline_query_result_venue->input_message_content);
        inline_query_result_venue->input_message_content = NULL;
    }
    if (inline_query_result_venue->thumbnail_url) {
        free(inline_query_result_venue->thumbnail_url);
        inline_query_result_venue->thumbnail_url = NULL;
    }
    free(inline_query_result_venue);
}

cJSON *inline_query_result_venue_convertToJSON(inline_query_result_venue_t *inline_query_result_venue) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_venue->type
    if (!inline_query_result_venue->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_venue->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_venue->id
    if (!inline_query_result_venue->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_venue->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_venue->latitude
    if (!inline_query_result_venue->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", inline_query_result_venue->latitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result_venue->longitude
    if (!inline_query_result_venue->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", inline_query_result_venue->longitude) == NULL) {
    goto fail; //Numeric
    }


    // inline_query_result_venue->title
    if (!inline_query_result_venue->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", inline_query_result_venue->title) == NULL) {
    goto fail; //String
    }


    // inline_query_result_venue->address
    if (!inline_query_result_venue->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", inline_query_result_venue->address) == NULL) {
    goto fail; //String
    }


    // inline_query_result_venue->foursquare_id
    if(inline_query_result_venue->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", inline_query_result_venue->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_venue->foursquare_type
    if(inline_query_result_venue->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", inline_query_result_venue->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_venue->google_place_id
    if(inline_query_result_venue->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", inline_query_result_venue->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_venue->google_place_type
    if(inline_query_result_venue->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", inline_query_result_venue->google_place_type) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_venue->reply_markup
    if(inline_query_result_venue->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_venue->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_venue->input_message_content
    if(inline_query_result_venue->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_venue->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_venue->thumbnail_url
    if(inline_query_result_venue->thumbnail_url) {
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_venue->thumbnail_url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_venue->thumbnail_width
    if(inline_query_result_venue->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result_venue->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_venue->thumbnail_height
    if(inline_query_result_venue->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result_venue->thumbnail_height) == NULL) {
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

inline_query_result_venue_t *inline_query_result_venue_parseFromJSON(cJSON *inline_query_result_venueJSON){

    inline_query_result_venue_t *inline_query_result_venue_local_var = NULL;

    // define the local variable for inline_query_result_venue->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_venue->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_venue->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "type");
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

    // inline_query_result_venue->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "id");
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

    // inline_query_result_venue->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "latitude");
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

    // inline_query_result_venue->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "longitude");
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

    // inline_query_result_venue->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "title");
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

    // inline_query_result_venue->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "address");
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

    // inline_query_result_venue->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // inline_query_result_venue->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // inline_query_result_venue->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // inline_query_result_venue->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }

    // inline_query_result_venue->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_venue->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }

    // inline_query_result_venue->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (thumbnail_url) { 
    if(!cJSON_IsString(thumbnail_url) && !cJSON_IsNull(thumbnail_url))
    {
    goto end; //String
    }
    }

    // inline_query_result_venue->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_venue->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_venueJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_venue_local_var = inline_query_result_venue_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(title->valuestring),
        strdup(address->valuestring),
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL,
        thumbnail_url && !cJSON_IsNull(thumbnail_url) ? strdup(thumbnail_url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0
        );

    return inline_query_result_venue_local_var;
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
