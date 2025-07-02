#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_edit_message_live_location_request.h"



static post_edit_message_live_location_request_t *post_edit_message_live_location_request_create_internal(
    double latitude,
    double longitude,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
    ) {
    post_edit_message_live_location_request_t *post_edit_message_live_location_request_local_var = malloc(sizeof(post_edit_message_live_location_request_t));
    if (!post_edit_message_live_location_request_local_var) {
        return NULL;
    }
    post_edit_message_live_location_request_local_var->latitude = latitude;
    post_edit_message_live_location_request_local_var->longitude = longitude;
    post_edit_message_live_location_request_local_var->business_connection_id = business_connection_id;
    post_edit_message_live_location_request_local_var->chat_id = chat_id;
    post_edit_message_live_location_request_local_var->message_id = message_id;
    post_edit_message_live_location_request_local_var->inline_message_id = inline_message_id;
    post_edit_message_live_location_request_local_var->live_period = live_period;
    post_edit_message_live_location_request_local_var->horizontal_accuracy = horizontal_accuracy;
    post_edit_message_live_location_request_local_var->heading = heading;
    post_edit_message_live_location_request_local_var->proximity_alert_radius = proximity_alert_radius;
    post_edit_message_live_location_request_local_var->reply_markup = reply_markup;

    post_edit_message_live_location_request_local_var->_library_owned = 1;
    return post_edit_message_live_location_request_local_var;
}

__attribute__((deprecated)) post_edit_message_live_location_request_t *post_edit_message_live_location_request_create(
    double latitude,
    double longitude,
    char *business_connection_id,
    post_edit_message_text_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
    ) {
    return post_edit_message_live_location_request_create_internal (
        latitude,
        longitude,
        business_connection_id,
        chat_id,
        message_id,
        inline_message_id,
        live_period,
        horizontal_accuracy,
        heading,
        proximity_alert_radius,
        reply_markup
        );
}

void post_edit_message_live_location_request_free(post_edit_message_live_location_request_t *post_edit_message_live_location_request) {
    if(NULL == post_edit_message_live_location_request){
        return ;
    }
    if(post_edit_message_live_location_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_edit_message_live_location_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_edit_message_live_location_request->business_connection_id) {
        free(post_edit_message_live_location_request->business_connection_id);
        post_edit_message_live_location_request->business_connection_id = NULL;
    }
    if (post_edit_message_live_location_request->chat_id) {
        post_edit_message_text_request_chat_id_free(post_edit_message_live_location_request->chat_id);
        post_edit_message_live_location_request->chat_id = NULL;
    }
    if (post_edit_message_live_location_request->inline_message_id) {
        free(post_edit_message_live_location_request->inline_message_id);
        post_edit_message_live_location_request->inline_message_id = NULL;
    }
    if (post_edit_message_live_location_request->reply_markup) {
        inline_keyboard_markup_free(post_edit_message_live_location_request->reply_markup);
        post_edit_message_live_location_request->reply_markup = NULL;
    }
    free(post_edit_message_live_location_request);
}

cJSON *post_edit_message_live_location_request_convertToJSON(post_edit_message_live_location_request_t *post_edit_message_live_location_request) {
    cJSON *item = cJSON_CreateObject();

    // post_edit_message_live_location_request->latitude
    if (!post_edit_message_live_location_request->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", post_edit_message_live_location_request->latitude) == NULL) {
    goto fail; //Numeric
    }


    // post_edit_message_live_location_request->longitude
    if (!post_edit_message_live_location_request->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", post_edit_message_live_location_request->longitude) == NULL) {
    goto fail; //Numeric
    }


    // post_edit_message_live_location_request->business_connection_id
    if(post_edit_message_live_location_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_edit_message_live_location_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_live_location_request->chat_id
    if(post_edit_message_live_location_request->chat_id) {
    cJSON *chat_id_local_JSON = post_edit_message_text_request_chat_id_convertToJSON(post_edit_message_live_location_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_edit_message_live_location_request->message_id
    if(post_edit_message_live_location_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", post_edit_message_live_location_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_live_location_request->inline_message_id
    if(post_edit_message_live_location_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", post_edit_message_live_location_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // post_edit_message_live_location_request->live_period
    if(post_edit_message_live_location_request->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", post_edit_message_live_location_request->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_live_location_request->horizontal_accuracy
    if(post_edit_message_live_location_request->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", post_edit_message_live_location_request->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_live_location_request->heading
    if(post_edit_message_live_location_request->heading) {
    if(cJSON_AddNumberToObject(item, "heading", post_edit_message_live_location_request->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_live_location_request->proximity_alert_radius
    if(post_edit_message_live_location_request->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", post_edit_message_live_location_request->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_edit_message_live_location_request->reply_markup
    if(post_edit_message_live_location_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(post_edit_message_live_location_request->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_edit_message_live_location_request_t *post_edit_message_live_location_request_parseFromJSON(cJSON *post_edit_message_live_location_requestJSON){

    post_edit_message_live_location_request_t *post_edit_message_live_location_request_local_var = NULL;

    // define the local variable for post_edit_message_live_location_request->chat_id
    post_edit_message_text_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_edit_message_live_location_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // post_edit_message_live_location_request->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "latitude");
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

    // post_edit_message_live_location_request->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "longitude");
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

    // post_edit_message_live_location_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_live_location_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = post_edit_message_text_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // post_edit_message_live_location_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_live_location_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // post_edit_message_live_location_request->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_live_location_request->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_live_location_request->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_live_location_request->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // post_edit_message_live_location_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_edit_message_live_location_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_edit_message_live_location_request_local_var = post_edit_message_live_location_request_create_internal (
        latitude->valuedouble,
        longitude->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        chat_id ? chat_id_local_nonprim : NULL,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL,
        live_period ? live_period->valuedouble : 0,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return post_edit_message_live_location_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_edit_message_text_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
