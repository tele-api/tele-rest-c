#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_contact_message_content.h"



static input_contact_message_content_t *input_contact_message_content_create_internal(
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard
    ) {
    input_contact_message_content_t *input_contact_message_content_local_var = malloc(sizeof(input_contact_message_content_t));
    if (!input_contact_message_content_local_var) {
        return NULL;
    }
    input_contact_message_content_local_var->phone_number = phone_number;
    input_contact_message_content_local_var->first_name = first_name;
    input_contact_message_content_local_var->last_name = last_name;
    input_contact_message_content_local_var->vcard = vcard;

    input_contact_message_content_local_var->_library_owned = 1;
    return input_contact_message_content_local_var;
}

__attribute__((deprecated)) input_contact_message_content_t *input_contact_message_content_create(
    char *phone_number,
    char *first_name,
    char *last_name,
    char *vcard
    ) {
    return input_contact_message_content_create_internal (
        phone_number,
        first_name,
        last_name,
        vcard
        );
}

void input_contact_message_content_free(input_contact_message_content_t *input_contact_message_content) {
    if(NULL == input_contact_message_content){
        return ;
    }
    if(input_contact_message_content->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "input_contact_message_content_free");
        return ;
    }
    listEntry_t *listEntry;
    if (input_contact_message_content->phone_number) {
        free(input_contact_message_content->phone_number);
        input_contact_message_content->phone_number = NULL;
    }
    if (input_contact_message_content->first_name) {
        free(input_contact_message_content->first_name);
        input_contact_message_content->first_name = NULL;
    }
    if (input_contact_message_content->last_name) {
        free(input_contact_message_content->last_name);
        input_contact_message_content->last_name = NULL;
    }
    if (input_contact_message_content->vcard) {
        free(input_contact_message_content->vcard);
        input_contact_message_content->vcard = NULL;
    }
    free(input_contact_message_content);
}

cJSON *input_contact_message_content_convertToJSON(input_contact_message_content_t *input_contact_message_content) {
    cJSON *item = cJSON_CreateObject();

    // input_contact_message_content->phone_number
    if (!input_contact_message_content->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", input_contact_message_content->phone_number) == NULL) {
    goto fail; //String
    }


    // input_contact_message_content->first_name
    if (!input_contact_message_content->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", input_contact_message_content->first_name) == NULL) {
    goto fail; //String
    }


    // input_contact_message_content->last_name
    if(input_contact_message_content->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", input_contact_message_content->last_name) == NULL) {
    goto fail; //String
    }
    }


    // input_contact_message_content->vcard
    if(input_contact_message_content->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", input_contact_message_content->vcard) == NULL) {
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

input_contact_message_content_t *input_contact_message_content_parseFromJSON(cJSON *input_contact_message_contentJSON){

    input_contact_message_content_t *input_contact_message_content_local_var = NULL;

    // input_contact_message_content->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(input_contact_message_contentJSON, "phone_number");
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

    // input_contact_message_content->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(input_contact_message_contentJSON, "first_name");
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

    // input_contact_message_content->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(input_contact_message_contentJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // input_contact_message_content->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(input_contact_message_contentJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }


    input_contact_message_content_local_var = input_contact_message_content_create_internal (
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL
        );

    return input_contact_message_content_local_var;
end:
    return NULL;

}
