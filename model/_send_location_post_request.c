#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_location_post_request.h"



static _send_location_post_request_t *_send_location_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *business_connection_id,
    int message_thread_id,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    _send_location_post_request_t *_send_location_post_request_local_var = malloc(sizeof(_send_location_post_request_t));
    if (!_send_location_post_request_local_var) {
        return NULL;
    }
    _send_location_post_request_local_var->chat_id = chat_id;
    _send_location_post_request_local_var->latitude = latitude;
    _send_location_post_request_local_var->longitude = longitude;
    _send_location_post_request_local_var->business_connection_id = business_connection_id;
    _send_location_post_request_local_var->message_thread_id = message_thread_id;
    _send_location_post_request_local_var->horizontal_accuracy = horizontal_accuracy;
    _send_location_post_request_local_var->live_period = live_period;
    _send_location_post_request_local_var->heading = heading;
    _send_location_post_request_local_var->proximity_alert_radius = proximity_alert_radius;
    _send_location_post_request_local_var->disable_notification = disable_notification;
    _send_location_post_request_local_var->protect_content = protect_content;
    _send_location_post_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    _send_location_post_request_local_var->message_effect_id = message_effect_id;
    _send_location_post_request_local_var->reply_parameters = reply_parameters;
    _send_location_post_request_local_var->reply_markup = reply_markup;

    _send_location_post_request_local_var->_library_owned = 1;
    return _send_location_post_request_local_var;
}

__attribute__((deprecated)) _send_location_post_request_t *_send_location_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *business_connection_id,
    int message_thread_id,
    double horizontal_accuracy,
    int live_period,
    int heading,
    int proximity_alert_radius,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    _send_message_post_request_reply_markup_t *reply_markup
    ) {
    return _send_location_post_request_create_internal (
        chat_id,
        latitude,
        longitude,
        business_connection_id,
        message_thread_id,
        horizontal_accuracy,
        live_period,
        heading,
        proximity_alert_radius,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void _send_location_post_request_free(_send_location_post_request_t *_send_location_post_request) {
    if(NULL == _send_location_post_request){
        return ;
    }
    if(_send_location_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_location_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_location_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_send_location_post_request->chat_id);
        _send_location_post_request->chat_id = NULL;
    }
    if (_send_location_post_request->business_connection_id) {
        free(_send_location_post_request->business_connection_id);
        _send_location_post_request->business_connection_id = NULL;
    }
    if (_send_location_post_request->message_effect_id) {
        free(_send_location_post_request->message_effect_id);
        _send_location_post_request->message_effect_id = NULL;
    }
    if (_send_location_post_request->reply_parameters) {
        reply_parameters_free(_send_location_post_request->reply_parameters);
        _send_location_post_request->reply_parameters = NULL;
    }
    if (_send_location_post_request->reply_markup) {
        _send_message_post_request_reply_markup_free(_send_location_post_request->reply_markup);
        _send_location_post_request->reply_markup = NULL;
    }
    free(_send_location_post_request);
}

cJSON *_send_location_post_request_convertToJSON(_send_location_post_request_t *_send_location_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _send_location_post_request->chat_id
    if (!_send_location_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_send_location_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _send_location_post_request->latitude
    if (!_send_location_post_request->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", _send_location_post_request->latitude) == NULL) {
    goto fail; //Numeric
    }


    // _send_location_post_request->longitude
    if (!_send_location_post_request->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", _send_location_post_request->longitude) == NULL) {
    goto fail; //Numeric
    }


    // _send_location_post_request->business_connection_id
    if(_send_location_post_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", _send_location_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_location_post_request->message_thread_id
    if(_send_location_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _send_location_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_location_post_request->horizontal_accuracy
    if(_send_location_post_request->horizontal_accuracy) {
    if(cJSON_AddNumberToObject(item, "horizontal_accuracy", _send_location_post_request->horizontal_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_location_post_request->live_period
    if(_send_location_post_request->live_period) {
    if(cJSON_AddNumberToObject(item, "live_period", _send_location_post_request->live_period) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_location_post_request->heading
    if(_send_location_post_request->heading) {
    if(cJSON_AddNumberToObject(item, "heading", _send_location_post_request->heading) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_location_post_request->proximity_alert_radius
    if(_send_location_post_request->proximity_alert_radius) {
    if(cJSON_AddNumberToObject(item, "proximity_alert_radius", _send_location_post_request->proximity_alert_radius) == NULL) {
    goto fail; //Numeric
    }
    }


    // _send_location_post_request->disable_notification
    if(_send_location_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _send_location_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_location_post_request->protect_content
    if(_send_location_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _send_location_post_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_location_post_request->allow_paid_broadcast
    if(_send_location_post_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", _send_location_post_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // _send_location_post_request->message_effect_id
    if(_send_location_post_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", _send_location_post_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // _send_location_post_request->reply_parameters
    if(_send_location_post_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(_send_location_post_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // _send_location_post_request->reply_markup
    if(_send_location_post_request->reply_markup) {
    cJSON *reply_markup_local_JSON = _send_message_post_request_reply_markup_convertToJSON(_send_location_post_request->reply_markup);
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

_send_location_post_request_t *_send_location_post_request_parseFromJSON(cJSON *_send_location_post_requestJSON){

    _send_location_post_request_t *_send_location_post_request_local_var = NULL;

    // define the local variable for _send_location_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _send_location_post_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for _send_location_post_request->reply_markup
    _send_message_post_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // _send_location_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _send_location_post_request->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "latitude");
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

    // _send_location_post_request->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "longitude");
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

    // _send_location_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // _send_location_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _send_location_post_request->horizontal_accuracy
    cJSON *horizontal_accuracy = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "horizontal_accuracy");
    if (cJSON_IsNull(horizontal_accuracy)) {
        horizontal_accuracy = NULL;
    }
    if (horizontal_accuracy) { 
    if(!cJSON_IsNumber(horizontal_accuracy))
    {
    goto end; //Numeric
    }
    }

    // _send_location_post_request->live_period
    cJSON *live_period = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "live_period");
    if (cJSON_IsNull(live_period)) {
        live_period = NULL;
    }
    if (live_period) { 
    if(!cJSON_IsNumber(live_period))
    {
    goto end; //Numeric
    }
    }

    // _send_location_post_request->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsNumber(heading))
    {
    goto end; //Numeric
    }
    }

    // _send_location_post_request->proximity_alert_radius
    cJSON *proximity_alert_radius = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "proximity_alert_radius");
    if (cJSON_IsNull(proximity_alert_radius)) {
        proximity_alert_radius = NULL;
    }
    if (proximity_alert_radius) { 
    if(!cJSON_IsNumber(proximity_alert_radius))
    {
    goto end; //Numeric
    }
    }

    // _send_location_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _send_location_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // _send_location_post_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // _send_location_post_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // _send_location_post_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // _send_location_post_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(_send_location_post_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = _send_message_post_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    _send_location_post_request_local_var = _send_location_post_request_create_internal (
        chat_id_local_nonprim,
        latitude->valuedouble,
        longitude->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        horizontal_accuracy ? horizontal_accuracy->valuedouble : 0,
        live_period ? live_period->valuedouble : 0,
        heading ? heading->valuedouble : 0,
        proximity_alert_radius ? proximity_alert_radius->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return _send_location_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        _send_message_post_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
