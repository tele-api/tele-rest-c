#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "encrypted_credentials.h"



static encrypted_credentials_t *encrypted_credentials_create_internal(
    char *data,
    char *hash,
    char *secret
    ) {
    encrypted_credentials_t *encrypted_credentials_local_var = malloc(sizeof(encrypted_credentials_t));
    if (!encrypted_credentials_local_var) {
        return NULL;
    }
    encrypted_credentials_local_var->data = data;
    encrypted_credentials_local_var->hash = hash;
    encrypted_credentials_local_var->secret = secret;

    encrypted_credentials_local_var->_library_owned = 1;
    return encrypted_credentials_local_var;
}

__attribute__((deprecated)) encrypted_credentials_t *encrypted_credentials_create(
    char *data,
    char *hash,
    char *secret
    ) {
    return encrypted_credentials_create_internal (
        data,
        hash,
        secret
        );
}

void encrypted_credentials_free(encrypted_credentials_t *encrypted_credentials) {
    if(NULL == encrypted_credentials){
        return ;
    }
    if(encrypted_credentials->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "encrypted_credentials_free");
        return ;
    }
    listEntry_t *listEntry;
    if (encrypted_credentials->data) {
        free(encrypted_credentials->data);
        encrypted_credentials->data = NULL;
    }
    if (encrypted_credentials->hash) {
        free(encrypted_credentials->hash);
        encrypted_credentials->hash = NULL;
    }
    if (encrypted_credentials->secret) {
        free(encrypted_credentials->secret);
        encrypted_credentials->secret = NULL;
    }
    free(encrypted_credentials);
}

cJSON *encrypted_credentials_convertToJSON(encrypted_credentials_t *encrypted_credentials) {
    cJSON *item = cJSON_CreateObject();

    // encrypted_credentials->data
    if (!encrypted_credentials->data) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "data", encrypted_credentials->data) == NULL) {
    goto fail; //String
    }


    // encrypted_credentials->hash
    if (!encrypted_credentials->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hash", encrypted_credentials->hash) == NULL) {
    goto fail; //String
    }


    // encrypted_credentials->secret
    if (!encrypted_credentials->secret) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "secret", encrypted_credentials->secret) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

encrypted_credentials_t *encrypted_credentials_parseFromJSON(cJSON *encrypted_credentialsJSON){

    encrypted_credentials_t *encrypted_credentials_local_var = NULL;

    // encrypted_credentials->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(encrypted_credentialsJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (!data) {
        goto end;
    }

    
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }

    // encrypted_credentials->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(encrypted_credentialsJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }

    // encrypted_credentials->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(encrypted_credentialsJSON, "secret");
    if (cJSON_IsNull(secret)) {
        secret = NULL;
    }
    if (!secret) {
        goto end;
    }

    
    if(!cJSON_IsString(secret))
    {
    goto end; //String
    }


    encrypted_credentials_local_var = encrypted_credentials_create_internal (
        strdup(data->valuestring),
        strdup(hash->valuestring),
        strdup(secret->valuestring)
        );

    return encrypted_credentials_local_var;
end:
    return NULL;

}
