#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "passport_element_error_unspecified.h"



static passport_element_error_unspecified_t *passport_element_error_unspecified_create_internal(
    char *source,
    char *type,
    char *element_hash,
    char *message
    ) {
    passport_element_error_unspecified_t *passport_element_error_unspecified_local_var = malloc(sizeof(passport_element_error_unspecified_t));
    if (!passport_element_error_unspecified_local_var) {
        return NULL;
    }
    passport_element_error_unspecified_local_var->source = source;
    passport_element_error_unspecified_local_var->type = type;
    passport_element_error_unspecified_local_var->element_hash = element_hash;
    passport_element_error_unspecified_local_var->message = message;

    passport_element_error_unspecified_local_var->_library_owned = 1;
    return passport_element_error_unspecified_local_var;
}

__attribute__((deprecated)) passport_element_error_unspecified_t *passport_element_error_unspecified_create(
    char *source,
    char *type,
    char *element_hash,
    char *message
    ) {
    return passport_element_error_unspecified_create_internal (
        source,
        type,
        element_hash,
        message
        );
}

void passport_element_error_unspecified_free(passport_element_error_unspecified_t *passport_element_error_unspecified) {
    if(NULL == passport_element_error_unspecified){
        return ;
    }
    if(passport_element_error_unspecified->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "passport_element_error_unspecified_free");
        return ;
    }
    listEntry_t *listEntry;
    if (passport_element_error_unspecified->source) {
        free(passport_element_error_unspecified->source);
        passport_element_error_unspecified->source = NULL;
    }
    if (passport_element_error_unspecified->type) {
        free(passport_element_error_unspecified->type);
        passport_element_error_unspecified->type = NULL;
    }
    if (passport_element_error_unspecified->element_hash) {
        free(passport_element_error_unspecified->element_hash);
        passport_element_error_unspecified->element_hash = NULL;
    }
    if (passport_element_error_unspecified->message) {
        free(passport_element_error_unspecified->message);
        passport_element_error_unspecified->message = NULL;
    }
    free(passport_element_error_unspecified);
}

cJSON *passport_element_error_unspecified_convertToJSON(passport_element_error_unspecified_t *passport_element_error_unspecified) {
    cJSON *item = cJSON_CreateObject();

    // passport_element_error_unspecified->source
    if (!passport_element_error_unspecified->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", passport_element_error_unspecified->source) == NULL) {
    goto fail; //String
    }


    // passport_element_error_unspecified->type
    if (!passport_element_error_unspecified->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", passport_element_error_unspecified->type) == NULL) {
    goto fail; //String
    }


    // passport_element_error_unspecified->element_hash
    if (!passport_element_error_unspecified->element_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "element_hash", passport_element_error_unspecified->element_hash) == NULL) {
    goto fail; //String
    }


    // passport_element_error_unspecified->message
    if (!passport_element_error_unspecified->message) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "message", passport_element_error_unspecified->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

passport_element_error_unspecified_t *passport_element_error_unspecified_parseFromJSON(cJSON *passport_element_error_unspecifiedJSON){

    passport_element_error_unspecified_t *passport_element_error_unspecified_local_var = NULL;

    // passport_element_error_unspecified->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(passport_element_error_unspecifiedJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }

    // passport_element_error_unspecified->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(passport_element_error_unspecifiedJSON, "type");
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

    // passport_element_error_unspecified->element_hash
    cJSON *element_hash = cJSON_GetObjectItemCaseSensitive(passport_element_error_unspecifiedJSON, "element_hash");
    if (cJSON_IsNull(element_hash)) {
        element_hash = NULL;
    }
    if (!element_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(element_hash))
    {
    goto end; //String
    }

    // passport_element_error_unspecified->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(passport_element_error_unspecifiedJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    passport_element_error_unspecified_local_var = passport_element_error_unspecified_create_internal (
        strdup(source->valuestring),
        strdup(type->valuestring),
        strdup(element_hash->valuestring),
        strdup(message->valuestring)
        );

    return passport_element_error_unspecified_local_var;
end:
    return NULL;

}
