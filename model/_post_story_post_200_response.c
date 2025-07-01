#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_post_story_post_200_response.h"



static _post_story_post_200_response_t *_post_story_post_200_response_create_internal(
    int ok,
    story_t *result
    ) {
    _post_story_post_200_response_t *_post_story_post_200_response_local_var = malloc(sizeof(_post_story_post_200_response_t));
    if (!_post_story_post_200_response_local_var) {
        return NULL;
    }
    _post_story_post_200_response_local_var->ok = ok;
    _post_story_post_200_response_local_var->result = result;

    _post_story_post_200_response_local_var->_library_owned = 1;
    return _post_story_post_200_response_local_var;
}

__attribute__((deprecated)) _post_story_post_200_response_t *_post_story_post_200_response_create(
    int ok,
    story_t *result
    ) {
    return _post_story_post_200_response_create_internal (
        ok,
        result
        );
}

void _post_story_post_200_response_free(_post_story_post_200_response_t *_post_story_post_200_response) {
    if(NULL == _post_story_post_200_response){
        return ;
    }
    if(_post_story_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_post_story_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_post_story_post_200_response->result) {
        story_free(_post_story_post_200_response->result);
        _post_story_post_200_response->result = NULL;
    }
    free(_post_story_post_200_response);
}

cJSON *_post_story_post_200_response_convertToJSON(_post_story_post_200_response_t *_post_story_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _post_story_post_200_response->ok
    if (!_post_story_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _post_story_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _post_story_post_200_response->result
    if (!_post_story_post_200_response->result) {
        goto fail;
    }
    cJSON *result_local_JSON = story_convertToJSON(_post_story_post_200_response->result);
    if(result_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "result", result_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_post_story_post_200_response_t *_post_story_post_200_response_parseFromJSON(cJSON *_post_story_post_200_responseJSON){

    _post_story_post_200_response_t *_post_story_post_200_response_local_var = NULL;

    // define the local variable for _post_story_post_200_response->result
    story_t *result_local_nonprim = NULL;

    // _post_story_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_post_story_post_200_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // _post_story_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_post_story_post_200_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    result_local_nonprim = story_parseFromJSON(result); //nonprimitive


    _post_story_post_200_response_local_var = _post_story_post_200_response_create_internal (
        ok->valueint,
        result_local_nonprim
        );

    return _post_story_post_200_response_local_var;
end:
    if (result_local_nonprim) {
        story_free(result_local_nonprim);
        result_local_nonprim = NULL;
    }
    return NULL;

}
