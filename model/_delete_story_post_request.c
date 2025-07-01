#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_story_post_request.h"



static _delete_story_post_request_t *_delete_story_post_request_create_internal(
    char *business_connection_id,
    int story_id
    ) {
    _delete_story_post_request_t *_delete_story_post_request_local_var = malloc(sizeof(_delete_story_post_request_t));
    if (!_delete_story_post_request_local_var) {
        return NULL;
    }
    _delete_story_post_request_local_var->business_connection_id = business_connection_id;
    _delete_story_post_request_local_var->story_id = story_id;

    _delete_story_post_request_local_var->_library_owned = 1;
    return _delete_story_post_request_local_var;
}

__attribute__((deprecated)) _delete_story_post_request_t *_delete_story_post_request_create(
    char *business_connection_id,
    int story_id
    ) {
    return _delete_story_post_request_create_internal (
        business_connection_id,
        story_id
        );
}

void _delete_story_post_request_free(_delete_story_post_request_t *_delete_story_post_request) {
    if(NULL == _delete_story_post_request){
        return ;
    }
    if(_delete_story_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_story_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_story_post_request->business_connection_id) {
        free(_delete_story_post_request->business_connection_id);
        _delete_story_post_request->business_connection_id = NULL;
    }
    free(_delete_story_post_request);
}

cJSON *_delete_story_post_request_convertToJSON(_delete_story_post_request_t *_delete_story_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_story_post_request->business_connection_id
    if (!_delete_story_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _delete_story_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _delete_story_post_request->story_id
    if (!_delete_story_post_request->story_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "story_id", _delete_story_post_request->story_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_delete_story_post_request_t *_delete_story_post_request_parseFromJSON(cJSON *_delete_story_post_requestJSON){

    _delete_story_post_request_t *_delete_story_post_request_local_var = NULL;

    // _delete_story_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_delete_story_post_requestJSON, "business_connection_id");
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

    // _delete_story_post_request->story_id
    cJSON *story_id = cJSON_GetObjectItemCaseSensitive(_delete_story_post_requestJSON, "story_id");
    if (cJSON_IsNull(story_id)) {
        story_id = NULL;
    }
    if (!story_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(story_id))
    {
    goto end; //Numeric
    }


    _delete_story_post_request_local_var = _delete_story_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        story_id->valuedouble
        );

    return _delete_story_post_request_local_var;
end:
    return NULL;

}
