#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_transfer_business_account_stars_post_request.h"



static _transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_create_internal(
    char *business_connection_id,
    int star_count
    ) {
    _transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_local_var = malloc(sizeof(_transfer_business_account_stars_post_request_t));
    if (!_transfer_business_account_stars_post_request_local_var) {
        return NULL;
    }
    _transfer_business_account_stars_post_request_local_var->business_connection_id = business_connection_id;
    _transfer_business_account_stars_post_request_local_var->star_count = star_count;

    _transfer_business_account_stars_post_request_local_var->_library_owned = 1;
    return _transfer_business_account_stars_post_request_local_var;
}

__attribute__((deprecated)) _transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_create(
    char *business_connection_id,
    int star_count
    ) {
    return _transfer_business_account_stars_post_request_create_internal (
        business_connection_id,
        star_count
        );
}

void _transfer_business_account_stars_post_request_free(_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request) {
    if(NULL == _transfer_business_account_stars_post_request){
        return ;
    }
    if(_transfer_business_account_stars_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_transfer_business_account_stars_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_transfer_business_account_stars_post_request->business_connection_id) {
        free(_transfer_business_account_stars_post_request->business_connection_id);
        _transfer_business_account_stars_post_request->business_connection_id = NULL;
    }
    free(_transfer_business_account_stars_post_request);
}

cJSON *_transfer_business_account_stars_post_request_convertToJSON(_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _transfer_business_account_stars_post_request->business_connection_id
    if (!_transfer_business_account_stars_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _transfer_business_account_stars_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _transfer_business_account_stars_post_request->star_count
    if (!_transfer_business_account_stars_post_request->star_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "star_count", _transfer_business_account_stars_post_request->star_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_parseFromJSON(cJSON *_transfer_business_account_stars_post_requestJSON){

    _transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_local_var = NULL;

    // _transfer_business_account_stars_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_transfer_business_account_stars_post_requestJSON, "business_connection_id");
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

    // _transfer_business_account_stars_post_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(_transfer_business_account_stars_post_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (!star_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }


    _transfer_business_account_stars_post_request_local_var = _transfer_business_account_stars_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        star_count->valuedouble
        );

    return _transfer_business_account_stars_post_request_local_var;
end:
    return NULL;

}
