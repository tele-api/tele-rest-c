#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_upgrade_gift_post_request.h"



static _upgrade_gift_post_request_t *_upgrade_gift_post_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    _upgrade_gift_post_request_t *_upgrade_gift_post_request_local_var = malloc(sizeof(_upgrade_gift_post_request_t));
    if (!_upgrade_gift_post_request_local_var) {
        return NULL;
    }
    _upgrade_gift_post_request_local_var->business_connection_id = business_connection_id;
    _upgrade_gift_post_request_local_var->owned_gift_id = owned_gift_id;
    _upgrade_gift_post_request_local_var->keep_original_details = keep_original_details;
    _upgrade_gift_post_request_local_var->star_count = star_count;

    _upgrade_gift_post_request_local_var->_library_owned = 1;
    return _upgrade_gift_post_request_local_var;
}

__attribute__((deprecated)) _upgrade_gift_post_request_t *_upgrade_gift_post_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
    ) {
    return _upgrade_gift_post_request_create_internal (
        business_connection_id,
        owned_gift_id,
        keep_original_details,
        star_count
        );
}

void _upgrade_gift_post_request_free(_upgrade_gift_post_request_t *_upgrade_gift_post_request) {
    if(NULL == _upgrade_gift_post_request){
        return ;
    }
    if(_upgrade_gift_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_upgrade_gift_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_upgrade_gift_post_request->business_connection_id) {
        free(_upgrade_gift_post_request->business_connection_id);
        _upgrade_gift_post_request->business_connection_id = NULL;
    }
    if (_upgrade_gift_post_request->owned_gift_id) {
        free(_upgrade_gift_post_request->owned_gift_id);
        _upgrade_gift_post_request->owned_gift_id = NULL;
    }
    free(_upgrade_gift_post_request);
}

cJSON *_upgrade_gift_post_request_convertToJSON(_upgrade_gift_post_request_t *_upgrade_gift_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _upgrade_gift_post_request->business_connection_id
    if (!_upgrade_gift_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _upgrade_gift_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _upgrade_gift_post_request->owned_gift_id
    if (!_upgrade_gift_post_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", _upgrade_gift_post_request->owned_gift_id) == NULL) {
    goto fail; //String
    }


    // _upgrade_gift_post_request->keep_original_details
    if(_upgrade_gift_post_request->keep_original_details) {
    if(cJSON_AddBoolToObject(item, "keep_original_details", _upgrade_gift_post_request->keep_original_details) == NULL) {
    goto fail; //Bool
    }
    }


    // _upgrade_gift_post_request->star_count
    if(_upgrade_gift_post_request->star_count) {
    if(cJSON_AddNumberToObject(item, "star_count", _upgrade_gift_post_request->star_count) == NULL) {
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

_upgrade_gift_post_request_t *_upgrade_gift_post_request_parseFromJSON(cJSON *_upgrade_gift_post_requestJSON){

    _upgrade_gift_post_request_t *_upgrade_gift_post_request_local_var = NULL;

    // _upgrade_gift_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_upgrade_gift_post_requestJSON, "business_connection_id");
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

    // _upgrade_gift_post_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(_upgrade_gift_post_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }

    // _upgrade_gift_post_request->keep_original_details
    cJSON *keep_original_details = cJSON_GetObjectItemCaseSensitive(_upgrade_gift_post_requestJSON, "keep_original_details");
    if (cJSON_IsNull(keep_original_details)) {
        keep_original_details = NULL;
    }
    if (keep_original_details) { 
    if(!cJSON_IsBool(keep_original_details))
    {
    goto end; //Bool
    }
    }

    // _upgrade_gift_post_request->star_count
    cJSON *star_count = cJSON_GetObjectItemCaseSensitive(_upgrade_gift_post_requestJSON, "star_count");
    if (cJSON_IsNull(star_count)) {
        star_count = NULL;
    }
    if (star_count) { 
    if(!cJSON_IsNumber(star_count))
    {
    goto end; //Numeric
    }
    }


    _upgrade_gift_post_request_local_var = _upgrade_gift_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring),
        keep_original_details ? keep_original_details->valueint : 0,
        star_count ? star_count->valuedouble : 0
        );

    return _upgrade_gift_post_request_local_var;
end:
    return NULL;

}
