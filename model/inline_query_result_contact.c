#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_contact.h"



static inline_query_result_contact_t *inline_query_result_contact_create_internal(
    char *type,
    char *id,
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    inline_query_result_contact_t *inline_query_result_contact_local_var = malloc(sizeof(inline_query_result_contact_t));
    if (!inline_query_result_contact_local_var) {
        return NULL;
    }
    inline_query_result_contact_local_var->type = type;
    inline_query_result_contact_local_var->id = id;
    inline_query_result_contact_local_var->phone_number = phone_number;
    inline_query_result_contact_local_var->first_name = first_name;
    inline_query_result_contact_local_var->last_name = last_name;
    inline_query_result_contact_local_var->vcard = vcard;
    inline_query_result_contact_local_var->reply_markup = reply_markup;
    inline_query_result_contact_local_var->input_message_content = input_message_content;
    inline_query_result_contact_local_var->thumbnail_url = thumbnail_url;
    inline_query_result_contact_local_var->thumbnail_width = thumbnail_width;
    inline_query_result_contact_local_var->thumbnail_height = thumbnail_height;

    inline_query_result_contact_local_var->_library_owned = 1;
    return inline_query_result_contact_local_var;
}

__attribute__((deprecated)) inline_query_result_contact_t *inline_query_result_contact_create(
    char *type,
    char *id,
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard,
    inline_keyboard_markup_t *reply_markup,
    input_message_content_t *input_message_content,
    char *thumbnail_url,
    int thumbnail_width,
    int thumbnail_height
    ) {
    return inline_query_result_contact_create_internal (
        type,
        id,
        phone_number,
        first_name,
        last_name,
        vcard,
        reply_markup,
        input_message_content,
        thumbnail_url,
        thumbnail_width,
        thumbnail_height
        );
}

void inline_query_result_contact_free(inline_query_result_contact_t *inline_query_result_contact) {
    if(NULL == inline_query_result_contact){
        return ;
    }
    if(inline_query_result_contact->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_contact_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_contact->type) {
        free(inline_query_result_contact->type);
        inline_query_result_contact->type = NULL;
    }
    if (inline_query_result_contact->id) {
        free(inline_query_result_contact->id);
        inline_query_result_contact->id = NULL;
    }
    if (inline_query_result_contact->phone_number) {
        free(inline_query_result_contact->phone_number);
        inline_query_result_contact->phone_number = NULL;
    }
    if (inline_query_result_contact->first_name) {
        free(inline_query_result_contact->first_name);
        inline_query_result_contact->first_name = NULL;
    }
    if (inline_query_result_contact->last_name) {
        free(inline_query_result_contact->last_name);
        inline_query_result_contact->last_name = NULL;
    }
    if (inline_query_result_contact->vcard) {
        free(inline_query_result_contact->vcard);
        inline_query_result_contact->vcard = NULL;
    }
    if (inline_query_result_contact->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_contact->reply_markup);
        inline_query_result_contact->reply_markup = NULL;
    }
    if (inline_query_result_contact->input_message_content) {
        input_message_content_free(inline_query_result_contact->input_message_content);
        inline_query_result_contact->input_message_content = NULL;
    }
    if (inline_query_result_contact->thumbnail_url) {
        free(inline_query_result_contact->thumbnail_url);
        inline_query_result_contact->thumbnail_url = NULL;
    }
    free(inline_query_result_contact);
}

cJSON *inline_query_result_contact_convertToJSON(inline_query_result_contact_t *inline_query_result_contact) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_contact->type
    if (!inline_query_result_contact->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_contact->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_contact->id
    if (!inline_query_result_contact->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_contact->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_contact->phone_number
    if (!inline_query_result_contact->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", inline_query_result_contact->phone_number) == NULL) {
    goto fail; //String
    }


    // inline_query_result_contact->first_name
    if (!inline_query_result_contact->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", inline_query_result_contact->first_name) == NULL) {
    goto fail; //String
    }


    // inline_query_result_contact->last_name
    if(inline_query_result_contact->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", inline_query_result_contact->last_name) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_contact->vcard
    if(inline_query_result_contact->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", inline_query_result_contact->vcard) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_contact->reply_markup
    if(inline_query_result_contact->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_contact->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_contact->input_message_content
    if(inline_query_result_contact->input_message_content) {
    cJSON *input_message_content_local_JSON = input_message_content_convertToJSON(inline_query_result_contact->input_message_content);
    if(input_message_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "input_message_content", input_message_content_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // inline_query_result_contact->thumbnail_url
    if(inline_query_result_contact->thumbnail_url) {
    if(cJSON_AddStringToObject(item, "thumbnail_url", inline_query_result_contact->thumbnail_url) == NULL) {
    goto fail; //String
    }
    }


    // inline_query_result_contact->thumbnail_width
    if(inline_query_result_contact->thumbnail_width) {
    if(cJSON_AddNumberToObject(item, "thumbnail_width", inline_query_result_contact->thumbnail_width) == NULL) {
    goto fail; //Numeric
    }
    }


    // inline_query_result_contact->thumbnail_height
    if(inline_query_result_contact->thumbnail_height) {
    if(cJSON_AddNumberToObject(item, "thumbnail_height", inline_query_result_contact->thumbnail_height) == NULL) {
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

inline_query_result_contact_t *inline_query_result_contact_parseFromJSON(cJSON *inline_query_result_contactJSON){

    inline_query_result_contact_t *inline_query_result_contact_local_var = NULL;

    // define the local variable for inline_query_result_contact->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // define the local variable for inline_query_result_contact->input_message_content
    input_message_content_t *input_message_content_local_nonprim = NULL;

    // inline_query_result_contact->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "type");
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

    // inline_query_result_contact->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "id");
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

    // inline_query_result_contact->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "phone_number");
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

    // inline_query_result_contact->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "first_name");
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

    // inline_query_result_contact->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // inline_query_result_contact->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }

    // inline_query_result_contact->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }

    // inline_query_result_contact->input_message_content
    cJSON *input_message_content = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "input_message_content");
    if (cJSON_IsNull(input_message_content)) {
        input_message_content = NULL;
    }
    if (input_message_content) { 
    input_message_content_local_nonprim = input_message_content_parseFromJSON(input_message_content); //nonprimitive
    }

    // inline_query_result_contact->thumbnail_url
    cJSON *thumbnail_url = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "thumbnail_url");
    if (cJSON_IsNull(thumbnail_url)) {
        thumbnail_url = NULL;
    }
    if (thumbnail_url) { 
    if(!cJSON_IsString(thumbnail_url) && !cJSON_IsNull(thumbnail_url))
    {
    goto end; //String
    }
    }

    // inline_query_result_contact->thumbnail_width
    cJSON *thumbnail_width = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "thumbnail_width");
    if (cJSON_IsNull(thumbnail_width)) {
        thumbnail_width = NULL;
    }
    if (thumbnail_width) { 
    if(!cJSON_IsNumber(thumbnail_width))
    {
    goto end; //Numeric
    }
    }

    // inline_query_result_contact->thumbnail_height
    cJSON *thumbnail_height = cJSON_GetObjectItemCaseSensitive(inline_query_result_contactJSON, "thumbnail_height");
    if (cJSON_IsNull(thumbnail_height)) {
        thumbnail_height = NULL;
    }
    if (thumbnail_height) { 
    if(!cJSON_IsNumber(thumbnail_height))
    {
    goto end; //Numeric
    }
    }


    inline_query_result_contact_local_var = inline_query_result_contact_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL,
        reply_markup ? reply_markup_local_nonprim : NULL,
        input_message_content ? input_message_content_local_nonprim : NULL,
        thumbnail_url && !cJSON_IsNull(thumbnail_url) ? strdup(thumbnail_url->valuestring) : NULL,
        thumbnail_width ? thumbnail_width->valuedouble : 0,
        thumbnail_height ? thumbnail_height->valuedouble : 0
        );

    return inline_query_result_contact_local_var;
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
