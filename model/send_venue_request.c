#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_venue_request.h"



static send_venue_request_t *send_venue_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *business_connection_id,
    int message_thread_id,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    send_venue_request_t *send_venue_request_local_var = malloc(sizeof(send_venue_request_t));
    if (!send_venue_request_local_var) {
        return NULL;
    }
    send_venue_request_local_var->chat_id = chat_id;
    send_venue_request_local_var->latitude = latitude;
    send_venue_request_local_var->longitude = longitude;
    send_venue_request_local_var->title = title;
    send_venue_request_local_var->address = address;
    send_venue_request_local_var->business_connection_id = business_connection_id;
    send_venue_request_local_var->message_thread_id = message_thread_id;
    send_venue_request_local_var->foursquare_id = foursquare_id;
    send_venue_request_local_var->foursquare_type = foursquare_type;
    send_venue_request_local_var->google_place_id = google_place_id;
    send_venue_request_local_var->google_place_type = google_place_type;
    send_venue_request_local_var->disable_notification = disable_notification;
    send_venue_request_local_var->protect_content = protect_content;
    send_venue_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    send_venue_request_local_var->message_effect_id = message_effect_id;
    send_venue_request_local_var->reply_parameters = reply_parameters;
    send_venue_request_local_var->reply_markup = reply_markup;

    send_venue_request_local_var->_library_owned = 1;
    return send_venue_request_local_var;
}

__attribute__((deprecated)) send_venue_request_t *send_venue_request_create(
    send_message_request_chat_id_t *chat_id,
    double latitude,
    double longitude,
    char *title,
    char *address,
    char *business_connection_id,
    int message_thread_id,
    char *foursquare_id,
    char *foursquare_type,
    char *google_place_id,
    char *google_place_type,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    send_message_request_reply_markup_t *reply_markup
    ) {
    return send_venue_request_create_internal (
        chat_id,
        latitude,
        longitude,
        title,
        address,
        business_connection_id,
        message_thread_id,
        foursquare_id,
        foursquare_type,
        google_place_id,
        google_place_type,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void send_venue_request_free(send_venue_request_t *send_venue_request) {
    if(NULL == send_venue_request){
        return ;
    }
    if(send_venue_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_venue_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_venue_request->chat_id) {
        send_message_request_chat_id_free(send_venue_request->chat_id);
        send_venue_request->chat_id = NULL;
    }
    if (send_venue_request->title) {
        free(send_venue_request->title);
        send_venue_request->title = NULL;
    }
    if (send_venue_request->address) {
        free(send_venue_request->address);
        send_venue_request->address = NULL;
    }
    if (send_venue_request->business_connection_id) {
        free(send_venue_request->business_connection_id);
        send_venue_request->business_connection_id = NULL;
    }
    if (send_venue_request->foursquare_id) {
        free(send_venue_request->foursquare_id);
        send_venue_request->foursquare_id = NULL;
    }
    if (send_venue_request->foursquare_type) {
        free(send_venue_request->foursquare_type);
        send_venue_request->foursquare_type = NULL;
    }
    if (send_venue_request->google_place_id) {
        free(send_venue_request->google_place_id);
        send_venue_request->google_place_id = NULL;
    }
    if (send_venue_request->google_place_type) {
        free(send_venue_request->google_place_type);
        send_venue_request->google_place_type = NULL;
    }
    if (send_venue_request->message_effect_id) {
        free(send_venue_request->message_effect_id);
        send_venue_request->message_effect_id = NULL;
    }
    if (send_venue_request->reply_parameters) {
        reply_parameters_free(send_venue_request->reply_parameters);
        send_venue_request->reply_parameters = NULL;
    }
    if (send_venue_request->reply_markup) {
        send_message_request_reply_markup_free(send_venue_request->reply_markup);
        send_venue_request->reply_markup = NULL;
    }
    free(send_venue_request);
}

cJSON *send_venue_request_convertToJSON(send_venue_request_t *send_venue_request) {
    cJSON *item = cJSON_CreateObject();

    // send_venue_request->chat_id
    if (!send_venue_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(send_venue_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // send_venue_request->latitude
    if (!send_venue_request->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", send_venue_request->latitude) == NULL) {
    goto fail; //Numeric
    }


    // send_venue_request->longitude
    if (!send_venue_request->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", send_venue_request->longitude) == NULL) {
    goto fail; //Numeric
    }


    // send_venue_request->title
    if (!send_venue_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", send_venue_request->title) == NULL) {
    goto fail; //String
    }


    // send_venue_request->address
    if (!send_venue_request->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", send_venue_request->address) == NULL) {
    goto fail; //String
    }


    // send_venue_request->business_connection_id
    if(send_venue_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", send_venue_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->message_thread_id
    if(send_venue_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", send_venue_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // send_venue_request->foursquare_id
    if(send_venue_request->foursquare_id) {
    if(cJSON_AddStringToObject(item, "foursquare_id", send_venue_request->foursquare_id) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->foursquare_type
    if(send_venue_request->foursquare_type) {
    if(cJSON_AddStringToObject(item, "foursquare_type", send_venue_request->foursquare_type) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->google_place_id
    if(send_venue_request->google_place_id) {
    if(cJSON_AddStringToObject(item, "google_place_id", send_venue_request->google_place_id) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->google_place_type
    if(send_venue_request->google_place_type) {
    if(cJSON_AddStringToObject(item, "google_place_type", send_venue_request->google_place_type) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->disable_notification
    if(send_venue_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", send_venue_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // send_venue_request->protect_content
    if(send_venue_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", send_venue_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // send_venue_request->allow_paid_broadcast
    if(send_venue_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", send_venue_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // send_venue_request->message_effect_id
    if(send_venue_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", send_venue_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // send_venue_request->reply_parameters
    if(send_venue_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(send_venue_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_venue_request->reply_markup
    if(send_venue_request->reply_markup) {
    cJSON *reply_markup_local_JSON = send_message_request_reply_markup_convertToJSON(send_venue_request->reply_markup);
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

send_venue_request_t *send_venue_request_parseFromJSON(cJSON *send_venue_requestJSON){

    send_venue_request_t *send_venue_request_local_var = NULL;

    // define the local variable for send_venue_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for send_venue_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for send_venue_request->reply_markup
    send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // send_venue_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // send_venue_request->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "latitude");
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

    // send_venue_request->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "longitude");
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

    // send_venue_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "title");
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

    // send_venue_request->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "address");
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

    // send_venue_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // send_venue_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // send_venue_request->foursquare_id
    cJSON *foursquare_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "foursquare_id");
    if (cJSON_IsNull(foursquare_id)) {
        foursquare_id = NULL;
    }
    if (foursquare_id) { 
    if(!cJSON_IsString(foursquare_id) && !cJSON_IsNull(foursquare_id))
    {
    goto end; //String
    }
    }

    // send_venue_request->foursquare_type
    cJSON *foursquare_type = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "foursquare_type");
    if (cJSON_IsNull(foursquare_type)) {
        foursquare_type = NULL;
    }
    if (foursquare_type) { 
    if(!cJSON_IsString(foursquare_type) && !cJSON_IsNull(foursquare_type))
    {
    goto end; //String
    }
    }

    // send_venue_request->google_place_id
    cJSON *google_place_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "google_place_id");
    if (cJSON_IsNull(google_place_id)) {
        google_place_id = NULL;
    }
    if (google_place_id) { 
    if(!cJSON_IsString(google_place_id) && !cJSON_IsNull(google_place_id))
    {
    goto end; //String
    }
    }

    // send_venue_request->google_place_type
    cJSON *google_place_type = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "google_place_type");
    if (cJSON_IsNull(google_place_type)) {
        google_place_type = NULL;
    }
    if (google_place_type) { 
    if(!cJSON_IsString(google_place_type) && !cJSON_IsNull(google_place_type))
    {
    goto end; //String
    }
    }

    // send_venue_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // send_venue_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // send_venue_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // send_venue_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // send_venue_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // send_venue_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(send_venue_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    send_venue_request_local_var = send_venue_request_create_internal (
        chat_id_local_nonprim,
        latitude->valuedouble,
        longitude->valuedouble,
        strdup(title->valuestring),
        strdup(address->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        foursquare_id && !cJSON_IsNull(foursquare_id) ? strdup(foursquare_id->valuestring) : NULL,
        foursquare_type && !cJSON_IsNull(foursquare_type) ? strdup(foursquare_type->valuestring) : NULL,
        google_place_id && !cJSON_IsNull(google_place_id) ? strdup(google_place_id->valuestring) : NULL,
        google_place_type && !cJSON_IsNull(google_place_type) ? strdup(google_place_type->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return send_venue_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        send_message_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
