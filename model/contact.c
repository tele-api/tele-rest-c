#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact.h"



static contact_t *contact_create_internal(
    char *phone_number,
    char *first_name,
    char *last_name,
    int user_id,
    char *vcard
    ) {
    contact_t *contact_local_var = malloc(sizeof(contact_t));
    if (!contact_local_var) {
        return NULL;
    }
    contact_local_var->phone_number = phone_number;
    contact_local_var->first_name = first_name;
    contact_local_var->last_name = last_name;
    contact_local_var->user_id = user_id;
    contact_local_var->vcard = vcard;

    contact_local_var->_library_owned = 1;
    return contact_local_var;
}

__attribute__((deprecated)) contact_t *contact_create(
    char *phone_number,
    char *first_name,
    char *last_name,
    int user_id,
    char *vcard
    ) {
    return contact_create_internal (
        phone_number,
        first_name,
        last_name,
        user_id,
        vcard
        );
}

void contact_free(contact_t *contact) {
    if(NULL == contact){
        return ;
    }
    if(contact->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "contact_free");
        return ;
    }
    listEntry_t *listEntry;
    if (contact->phone_number) {
        free(contact->phone_number);
        contact->phone_number = NULL;
    }
    if (contact->first_name) {
        free(contact->first_name);
        contact->first_name = NULL;
    }
    if (contact->last_name) {
        free(contact->last_name);
        contact->last_name = NULL;
    }
    if (contact->vcard) {
        free(contact->vcard);
        contact->vcard = NULL;
    }
    free(contact);
}

cJSON *contact_convertToJSON(contact_t *contact) {
    cJSON *item = cJSON_CreateObject();

    // contact->phone_number
    if (!contact->phone_number) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone_number", contact->phone_number) == NULL) {
    goto fail; //String
    }


    // contact->first_name
    if (!contact->first_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "first_name", contact->first_name) == NULL) {
    goto fail; //String
    }


    // contact->last_name
    if(contact->last_name) {
    if(cJSON_AddStringToObject(item, "last_name", contact->last_name) == NULL) {
    goto fail; //String
    }
    }


    // contact->user_id
    if(contact->user_id) {
    if(cJSON_AddNumberToObject(item, "user_id", contact->user_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // contact->vcard
    if(contact->vcard) {
    if(cJSON_AddStringToObject(item, "vcard", contact->vcard) == NULL) {
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

contact_t *contact_parseFromJSON(cJSON *contactJSON){

    contact_t *contact_local_var = NULL;

    // contact->phone_number
    cJSON *phone_number = cJSON_GetObjectItemCaseSensitive(contactJSON, "phone_number");
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

    // contact->first_name
    cJSON *first_name = cJSON_GetObjectItemCaseSensitive(contactJSON, "first_name");
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

    // contact->last_name
    cJSON *last_name = cJSON_GetObjectItemCaseSensitive(contactJSON, "last_name");
    if (cJSON_IsNull(last_name)) {
        last_name = NULL;
    }
    if (last_name) { 
    if(!cJSON_IsString(last_name) && !cJSON_IsNull(last_name))
    {
    goto end; //String
    }
    }

    // contact->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(contactJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }
    }

    // contact->vcard
    cJSON *vcard = cJSON_GetObjectItemCaseSensitive(contactJSON, "vcard");
    if (cJSON_IsNull(vcard)) {
        vcard = NULL;
    }
    if (vcard) { 
    if(!cJSON_IsString(vcard) && !cJSON_IsNull(vcard))
    {
    goto end; //String
    }
    }


    contact_local_var = contact_create_internal (
        strdup(phone_number->valuestring),
        strdup(first_name->valuestring),
        last_name && !cJSON_IsNull(last_name) ? strdup(last_name->valuestring) : NULL,
        user_id ? user_id->valuedouble : 0,
        vcard && !cJSON_IsNull(vcard) ? strdup(vcard->valuestring) : NULL
        );

    return contact_local_var;
end:
    return NULL;

}
