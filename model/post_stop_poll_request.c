#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_stop_poll_request.h"



static post_stop_poll_request_t *post_stop_poll_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    inline_keyboard_markup_t *reply_markup
    ) {
    post_stop_poll_request_t *post_stop_poll_request_local_var = malloc(sizeof(post_stop_poll_request_t));
    if (!post_stop_poll_request_local_var) {
        return NULL;
    }
    post_stop_poll_request_local_var->chat_id = chat_id;
    post_stop_poll_request_local_var->message_id = message_id;
    post_stop_poll_request_local_var->business_connection_id = business_connection_id;
    post_stop_poll_request_local_var->reply_markup = reply_markup;

    post_stop_poll_request_local_var->_library_owned = 1;
    return post_stop_poll_request_local_var;
}

__attribute__((deprecated)) post_stop_poll_request_t *post_stop_poll_request_create(
    post_send_message_request_chat_id_t *chat_id,
    int message_id,
    char *business_connection_id,
    inline_keyboard_markup_t *reply_markup
    ) {
    return post_stop_poll_request_create_internal (
        chat_id,
        message_id,
        business_connection_id,
        reply_markup
        );
}

void post_stop_poll_request_free(post_stop_poll_request_t *post_stop_poll_request) {
    if(NULL == post_stop_poll_request){
        return ;
    }
    if(post_stop_poll_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_stop_poll_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_stop_poll_request->chat_id) {
        post_send_message_request_chat_id_free(post_stop_poll_request->chat_id);
        post_stop_poll_request->chat_id = NULL;
    }
    if (post_stop_poll_request->business_connection_id) {
        free(post_stop_poll_request->business_connection_id);
        post_stop_poll_request->business_connection_id = NULL;
    }
    if (post_stop_poll_request->reply_markup) {
        inline_keyboard_markup_free(post_stop_poll_request->reply_markup);
        post_stop_poll_request->reply_markup = NULL;
    }
    free(post_stop_poll_request);
}

cJSON *post_stop_poll_request_convertToJSON(post_stop_poll_request_t *post_stop_poll_request) {
    cJSON *item = cJSON_CreateObject();

    // post_stop_poll_request->chat_id
    if (!post_stop_poll_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_stop_poll_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_stop_poll_request->message_id
    if (!post_stop_poll_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", post_stop_poll_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // post_stop_poll_request->business_connection_id
    if(post_stop_poll_request->business_connection_id) {
    if(cJSON_AddStringToObject(item, "business_connection_id", post_stop_poll_request->business_connection_id) == NULL) {
    goto fail; //String
    }
    }


    // post_stop_poll_request->reply_markup
    if(post_stop_poll_request->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(post_stop_poll_request->reply_markup);
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

post_stop_poll_request_t *post_stop_poll_request_parseFromJSON(cJSON *post_stop_poll_requestJSON){

    post_stop_poll_request_t *post_stop_poll_request_local_var = NULL;

    // define the local variable for post_stop_poll_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_stop_poll_request->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // post_stop_poll_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_stop_poll_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_stop_poll_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_stop_poll_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // post_stop_poll_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(post_stop_poll_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (business_connection_id) { 
    if(!cJSON_IsString(business_connection_id) && !cJSON_IsNull(business_connection_id))
    {
    goto end; //String
    }
    }

    // post_stop_poll_request->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(post_stop_poll_requestJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    post_stop_poll_request_local_var = post_stop_poll_request_create_internal (
        chat_id_local_nonprim,
        message_id->valuedouble,
        business_connection_id && !cJSON_IsNull(business_connection_id) ? strdup(business_connection_id->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return post_stop_poll_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
