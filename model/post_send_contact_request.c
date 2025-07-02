#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_send_contact_request.h"



static post_send_contact_request_t *post_send_contact_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    char *phone_number,
    char *first_name,
    char *business_connection_id,
    int message_thread_id,
    char *last_name,
    char *vcard,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    post_send_message_request_reply_markup_t *reply_markup
    ) {
    post_send_contact_request_t *post_send_contact_request_local_var = malloc(sizeof(post_send_contact_request_t));
    if (!post_send_contact_request_local_var) {
        return NULL;
    }
    post_send_contact_request_local_var->chat_id = chat_id;
    post_send_contact_request_local_var->phone_number = phone_number;
    post_send_contact_request_local_var->first_name = first_name;
    post_send_contact_request_local_var->business_connection_id = business_connection_id;
    post_send_contact_request_local_var->message_thread_id = message_thread_id;
    post_send_contact_request_local_var->last_name = last_name;
    post_send_contact_request_local_var->vcard = vcard;
    post_send_contact_request_local_var->disable_notification = disable_notification;
    post_send_contact_request_local_var->protect_content = protect_content;
    post_send_contact_request_local_var->allow_paid_broadcast = allow_paid_broadcast;
    post_send_contact_request_local_var->message_effect_id = message_effect_id;
    post_send_contact_request_local_var->reply_parameters = reply_parameters;
    post_send_contact_request_local_var->reply_markup = reply_markup;

    post_send_contact_request_local_var->_library_owned = 1;
    return post_send_contact_request_local_var;
}

__attribute__((deprecated)) post_send_contact_request_t *post_send_contact_request_create(
    post_send_message_request_chat_id_t *chat_id,
    char *phone_number,
    char *first_name,
    char *business_connection_id,
    int message_thread_id,
    char *last_name,
    char *vcard,
    int disable_notification,
    int protect_content,
    int allow_paid_broadcast,
    char *message_effect_id,
    reply_parameters_t *reply_parameters,
    post_send_message_request_reply_markup_t *reply_markup
    ) {
    return post_send_contact_request_create_internal (
        chat_id,
        phone_number,
        first_name,
        business_connection_id,
        message_thread_id,
        last_name,
        vcard,
        disable_notification,
        protect_content,
        allow_paid_broadcast,
        message_effect_id,
        reply_parameters,
        reply_markup
        );
}

void post_send_contact_request_free(post_send_contact_request_t *post_send_contact_request) {
    if(NULL == post_send_contact_request){
        return ;
    }
    if(post_send_contact_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_send_contact_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_send_contact_request->chat_id) {
        post_send_message_request_chat_id_free(post_send_contact_request->chat_id);
        post_send_contact_request->chat_id = NULL;
    }
    if (post_send_contact_request->phone_number) {
        free(post_send_contact_request->phone_number);
        post_send_contact_request->phone_number = NULL;
    }
    if (post_send_contact_request->first_name) {
        free(post_send_contact_request->first_name);
        post_send_contact_request->first_name = NULL;
    }
    if (post_send_contact_request->business_connection_id) {
        free(post_send_contact_request->business_connection_id);
        post_send_contact_request->business_connection_id = NULL;
    }
    if (post_send_contact_request->last_name) {
        free(post_send_contact_request->last_name);
        post_send_contact_request->last_name = NULL;
    }
    if (post_send_contact_request->vcard) {
        free(post_send_contact_request->vcard);
        post_send_contact_request->vcard = NULL;
    }
    if (post_send_contact_request->message_effect_id) {
        free(post_send_contact_request->message_effect_id);
        post_send_contact_request->message_effect_id = NULL;
    }
    if (post_send_contact_request->reply_parameters) {
        reply_parameters_free(post_send_contact_request->reply_parameters);
        post_send_contact_request->reply_parameters = NULL;
    }
    if (post_send_contact_request->reply_markup) {
        post_send_message_request_reply_markup_free(post_send_contact_request->reply_markup);
        post_send_contact_request->reply_markup = NULL;
    }
    free(post_send_contact_request);
}

cJSON *post_send_contact_request_convertToJSON(post_send_contact_request_t *post_send_contact_request) {
    cJSON *item = cJSON_CreateObject();

    // post_send_contact_request->chat_id
    if (!post_send_contact_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_send_contact_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_send_contact_request->phone_number
    if (!post_send_contact_request->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", post_send_contact_request->phone_number) == NULL) {
    goto fail; //String
    }


    // post_send_contact_request->first_name
    if (!post_send_contact_request->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", post_send_contact_request->first_name) == NULL) {
    goto fail; //String
    }


    // post_send_contact_request->business_connection_id
    if(post_send_contact_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_send_contact_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_contact_request->message_thread_id
    if(post_send_contact_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_send_contact_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_send_contact_request->last_name
    if(post_send_contact_request->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", post_send_contact_request->last_name) == NULL) {
    goto fail; //String
    }
    }


    // post_send_contact_request->vcard
    if(post_send_contact_request->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", post_send_contact_request->vcard) == NULL) {
    goto fail; //String
    }
    }


    // post_send_contact_request->disable_notification
    if(post_send_contact_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", post_send_contact_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_contact_request->protect_content
    if(post_send_contact_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", post_send_contact_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_contact_request->allow_paid_broadcast
    if(post_send_contact_request->allow_paid_broadcast) {
    if(cJSON_AddBoolToObject(item, "allow_paid_broadcast", post_send_contact_request->allow_paid_broadcast) == NULL) {
    goto fail; //Bool
    }
    }


    // post_send_contact_request->message_effect_id
    if(post_send_contact_request->message_effect_id) {
    if(cJSON_AddStringToObject(item, "message_effect_id", post_send_contact_request->message_effect_id) == NULL) {
    goto fail; //String
    }
    }


    // post_send_contact_request->reply_parameters
    if(post_send_contact_request->reply_parameters) {
    cJSON *reply_parameters_local_JSON = reply_parameters_convertToJSON(post_send_contact_request->reply_parameters);
    if(reply_parameters_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_parameters", reply_parameters_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // post_send_contact_request->reply_markup
    if(post_send_contact_request->reply_markup) {
    cJSON *reply_markup_local_JSON = post_send_message_request_reply_markup_convertToJSON(post_send_contact_request->reply_markup);
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

post_send_contact_request_t *post_send_contact_request_parseFromJSON(cJSON *post_send_contact_requestJSON){

    post_send_contact_request_t *post_send_contact_request_local_var = NULL;

    // define the local variable for post_send_contact_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_send_contact_request->reply_parameters
    reply_parameters_t *reply_parameters_local_nonprim = NULL;

    // define the local variable for post_send_contact_request->reply_markup
    post_send_message_request_reply_markup_t *reply_markup_local_nonprim = NULL;

    // post_send_contact_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_send_contact_request->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "phone_number");
    if (cJSON_IsNull(phone_number)) {
        phone_number = NULL;
    }
    if (!phone_number) {
        goto end;
    }

    
    if(!cJSON_IsString(phone_number))
    {
    goto end; //String
    }

    // post_send_contact_request->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "first_name");
    if (cJSON_IsNull(first_name)) {
        first_name = NULL;
    }
    if (!first_name) {
        goto end;
    }

    
    if(!cJSON_IsString(first_name))
    {
    goto end; //String
    }

    // post_send_contact_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_send_contact_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // post_send_contact_request->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // post_send_contact_request->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }

    // post_send_contact_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // post_send_contact_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // post_send_contact_request->allow_paid_broadcast
    cJSON *allow_paid_broadcast = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "allow_paid_broadcast");
    if (cJSON_IsNull(allow_paid_broadcast)) {
        allow_paid_broadcast = NULL;
    }
    if (allow_paid_broadcast) { 
    if(!cJSON_IsBool(allow_paid_broadcast))
    {
    goto end; //Bool
    }
    }

    // post_send_contact_request->message_effect_id
    cJSON *message_effect_id = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "message_effect_id");
    if (cJSON_IsNull(message_effect_id)) {
        message_effect_id = NULL;
    }
    if (message_effect_id) { 
    if(!cJSON_IsString(message_effect_id) && !cJSON_IsNull(message_effect_id))
    {
    goto end; //String
    }
    }

    // post_send_contact_request->reply_parameters
    cJSON *reply_parameters = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "reply_parameters");
    if (cJSON_IsNull(reply_parameters)) {
        reply_parameters = NULL;
    }
    if (reply_parameters) { 
    reply_parameters_local_nonprim = reply_parameters_parseFromJSON(reply_parameters); //nonprimitive
    }

    // post_send_contact_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_send_contact_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = post_send_message_request_reply_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_send_contact_request_local_var = post_send_contact_request_create_internal (
        chat_id_local_nonprim,
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        message_thread_id ? message_thread_id->valuedouble : 0,
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        allow_paid_broadcast ? allow_paid_broadcast->valueint : 0,
        message_effect_id && !cJSON_IsNull(message_effect_id) ? strdup(message_effect_id->valuestring) : NULL,
        reply_parameters ? reply_parameters_local_nonprim : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return post_send_contact_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_parameters_local_nonprim) {
        reply_parameters_free(reply_parameters_local_nonprim);
        reply_parameters_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        post_send_message_request_reply_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
