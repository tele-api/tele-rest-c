#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_business_account_bio_request.h"



static set_business_account_bio_request_t *set_business_account_bio_request_create_internal(
    char *business_connection_id,
    char *bio
    ) {
    set_business_account_bio_request_t *set_business_account_bio_request_local_var = malloc(sizeof(set_business_account_bio_request_t));
    if (!set_business_account_bio_request_local_var) {
        return NULL;
    }
    set_business_account_bio_request_local_var->business_connection_id = business_connection_id;
    set_business_account_bio_request_local_var->bio = bio;

    set_business_account_bio_request_local_var->_library_owned = 1;
    return set_business_account_bio_request_local_var;
}

__attribute__((deprecated)) set_business_account_bio_request_t *set_business_account_bio_request_create(
    char *business_connection_id,
    char *bio
    ) {
    return set_business_account_bio_request_create_internal (
        business_connection_id,
        bio
        );
}

void set_business_account_bio_request_free(set_business_account_bio_request_t *set_business_account_bio_request) {
    if(NULL == set_business_account_bio_request){
        return ;
    }
    if(set_business_account_bio_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_business_account_bio_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_business_account_bio_request->business_connection_id) {
        free(set_business_account_bio_request->business_connection_id);
        set_business_account_bio_request->business_connection_id = NULL;
    }
    if (set_business_account_bio_request->bio) {
        free(set_business_account_bio_request->bio);
        set_business_account_bio_request->bio = NULL;
    }
    free(set_business_account_bio_request);
}

cJSON *set_business_account_bio_request_convertToJSON(set_business_account_bio_request_t *set_business_account_bio_request) {
    cJSON *item = cJSON_CreateObject();

    // set_business_account_bio_request->business_connection_id
    if (!set_business_account_bio_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", set_business_account_bio_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // set_business_account_bio_request->bio
    if(set_business_account_bio_request->bio) {
    if(cJSON_AddStringToObject(item, "bio", set_business_account_bio_request->bio) == NULL) {
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

set_business_account_bio_request_t *set_business_account_bio_request_parseFromJSON(cJSON *set_business_account_bio_requestJSON){

    set_business_account_bio_request_t *set_business_account_bio_request_local_var = NULL;

    // set_business_account_bio_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(set_business_account_bio_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // set_business_account_bio_request->bio
    cJSON *bio = cJSON_GetObjectItemCaseSensitive(set_business_account_bio_requestJSON, "bio");
    if (cJSON_IsNull(bio)) {
        bio = NULL;
    }
    if (bio) { 
    if(!cJSON_IsString(bio) && !cJSON_IsNull(bio))
    {
    goto end; //String
    }
    }


    set_business_account_bio_request_local_var = set_business_account_bio_request_create_internal (
        strdup(business_connection_id->valuestring),
        bio && !cJSON_IsNull(bio) ? strdup(bio->valuestring) : NULL
        );

    return set_business_account_bio_request_local_var;
end:
    return NULL;

}
