#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_edit_message_live_location_post_request.h"



static _edit_message_live_location_post_request_t *_edit_message_live_location_post_request_create_internal(
    double latitude,
    double longitude,
    char *business_connection_id,
    _edit_message_text_post_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
    ) {
    _edit_message_live_location_post_request_t *_edit_message_live_location_post_request_local_var = malloc(sizeof(_edit_message_live_location_post_request_t));
    if (!_edit_message_live_location_post_request_local_var) {
        return NULL;
    }
    _edit_message_live_location_post_request_local_var->latitude = latitude;
    _edit_message_live_location_post_request_local_var->longitude = longitude;
    _edit_message_live_location_post_request_local_var->business_connection_id = business_connection_id;
    _edit_message_live_location_post_request_local_var->chat_id = chat_id;
    _edit_message_live_location_post_request_local_var->message_id = message_id;
    _edit_message_live_location_post_request_local_var->inline_message_id = inline_message_id;
    _edit_message_live_location_post_request_local_var->live_period = live_period;
    _edit_message_live_location_post_request_local_var->horizontal_accuracy = horizontal_accuracy;
    _edit_message_live_location_post_request_local_var->heading = heading;
    _edit_message_live_location_post_request_local_var->proximity_alert_radius = proximity_alert_radius;
    _edit_message_live_location_post_request_local_var->reply_markup = reply_markup;

    _edit_message_live_location_post_request_local_var->_library_owned = 1;
    return _edit_message_live_location_post_request_local_var;
}

__attribute__((deprecated)) _edit_message_live_location_post_request_t *_edit_message_live_location_post_request_create(
    double latitude,
    double longitude,
    char *business_connection_id,
    _edit_message_text_post_request_chat_id_t *chat_id,
    int message_id,
    char *inline_message_id,
    int live_period,
    double horizontal_accuracy,
    int heading,
    int proximity_alert_radius,
    inline_keyboard_markup_t *reply_markup
    ) {
    return _edit_message_live_location_post_request_create_internal (
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

void _edit_message_live_location_post_request_free(_edit_message_live_location_post_request_t *_edit_message_live_location_post_request) {
    if(NULL == _edit_message_live_location_post_request){
        return ;
    }
    if(_edit_message_live_location_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_edit_message_live_location_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_edit_message_live_location_post_request->business_connection_id) {
        free(_edit_message_live_location_post_request->business_connection_id);
        _edit_message_live_location_post_request->business_connection_id = NULL;
    }
    if (_edit_message_live_location_post_request->chat_id) {
        _edit_message_text_post_request_chat_id_free(_edit_message_live_location_post_request->chat_id);
        _edit_message_live_location_post_request->chat_id = NULL;
    }
    if (_edit_message_live_location_post_request->inline_message_id) {
        free(_edit_message_live_location_post_request->inline_message_id);
        _edit_message_live_location_post_request->inline_message_id = NULL;
    }
    if (_edit_message_live_location_post_request->reply_markup) {
        inline_keyboard_markup_free(_edit_message_live_location_post_request->reply_markup);
        _edit_message_live_location_post_request->reply_markup = NULL;
    }
    free(_edit_message_live_location_post_request);
}

cJSON *_edit_message_live_location_post_request_convertToJSON(_edit_message_live_location_post_request_t *_edit_message_live_location_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _edit_message_live_location_post_request->latitude
    if (!_edit_message_live_location_post_request->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", _edit_message_live_location_post_request->latitude) == NULL) {
    goto fail; //Numeric
    }


    // _edit_message_live_location_post_request->longitude
    if (!_edit_message_live_location_post_request->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", _edit_message_live_location_post_request->longitude) == NULL) {
    goto fail; //Numeric
    }


    // _edit_message_live_location_post_request->business_connection_id
    if(_edit_message_live_location_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _edit_message_live_location_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_live_location_post_request->chat_id
    if(_edit_message_live_location_post_request->chat_id) {
    cJSON *chat_id_local_JSON = _edit_message_text_post_request_chat_id_convertToJSON(_edit_message_live_location_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _edit_message_live_location_post_request->message_id
    if(_edit_message_live_location_post_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", _edit_message_live_location_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_live_location_post_request->inline_message_id
    if(_edit_message_live_location_post_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", _edit_message_live_location_post_request->inline_message_id) == NULL) {
    goto fail; //String
    }
    }


    // _edit_message_live_location_post_request->live_period
    if(_edit_message_live_location_post_request->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", _edit_message_live_location_post_request->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_live_location_post_request->horizontal_accuracy
    if(_edit_message_live_location_post_request->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", _edit_message_live_location_post_request->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_live_location_post_request->heading
    if(_edit_message_live_location_post_request->heading) {
    if(cJSON_AddNumberToObject(item, "heading", _edit_message_live_location_post_request->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_live_location_post_request->proximity_alert_radius
    if(_edit_message_live_location_post_request->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", _edit_message_live_location_post_request->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // _edit_message_live_location_post_request->reply_markup
    if(_edit_message_live_location_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(_edit_message_live_location_post_request->reply_markup);
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

_edit_message_live_location_post_request_t *_edit_message_live_location_post_request_parseFromJSON(cJSON *_edit_message_live_location_post_requestJSON){

    _edit_message_live_location_post_request_t *_edit_message_live_location_post_request_local_var = NULL;

    // define the local variable for _edit_message_live_location_post_request->chat_id
    _edit_message_text_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _edit_message_live_location_post_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // _edit_message_live_location_post_request->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "latitude");
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

    // _edit_message_live_location_post_request->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "longitude");
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

    // _edit_message_live_location_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _edit_message_live_location_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    chat_id_local_nonprim = _edit_message_text_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive
    }

    // _edit_message_live_location_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_live_location_post_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }

    // _edit_message_live_location_post_request->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_live_location_post_request->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_live_location_post_request->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_live_location_post_request->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // _edit_message_live_location_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_edit_message_live_location_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _edit_message_live_location_post_request_local_var = _edit_message_live_location_post_request_create_internal (
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

    return _edit_message_live_location_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _edit_message_text_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
