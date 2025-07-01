#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_user_emoji_status_post_request.h"



static _set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request_create_internal(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
    ) {
    _set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request_local_var = malloc(sizeof(_set_user_emoji_status_post_request_t));
    if (!_set_user_emoji_status_post_request_local_var) {
        return NULL;
    }
    _set_user_emoji_status_post_request_local_var->user_id = user_id;
    _set_user_emoji_status_post_request_local_var->emoji_status_custom_emoji_id = emoji_status_custom_emoji_id;
    _set_user_emoji_status_post_request_local_var->emoji_status_expiration_date = emoji_status_expiration_date;

    _set_user_emoji_status_post_request_local_var->_library_owned = 1;
    return _set_user_emoji_status_post_request_local_var;
}

__attribute__((deprecated)) _set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request_create(
    int user_id,
    char *emoji_status_custom_emoji_id,
    int emoji_status_expiration_date
    ) {
    return _set_user_emoji_status_post_request_create_internal (
        user_id,
        emoji_status_custom_emoji_id,
        emoji_status_expiration_date
        );
}

void _set_user_emoji_status_post_request_free(_set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request) {
    if(NULL == _set_user_emoji_status_post_request){
        return ;
    }
    if(_set_user_emoji_status_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_user_emoji_status_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_user_emoji_status_post_request->emoji_status_custom_emoji_id) {
        free(_set_user_emoji_status_post_request->emoji_status_custom_emoji_id);
        _set_user_emoji_status_post_request->emoji_status_custom_emoji_id = NULL;
    }
    free(_set_user_emoji_status_post_request);
}

cJSON *_set_user_emoji_status_post_request_convertToJSON(_set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_user_emoji_status_post_request->user_id
    if (!_set_user_emoji_status_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _set_user_emoji_status_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _set_user_emoji_status_post_request->emoji_status_custom_emoji_id
    if(_set_user_emoji_status_post_request->emoji_status_custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "emoji_status_custom_emoji_id", _set_user_emoji_status_post_request->emoji_status_custom_emoji_id) == NULL) {
    goto fail; //String
    }
    }


    // _set_user_emoji_status_post_request->emoji_status_expiration_date
    if(_set_user_emoji_status_post_request->emoji_status_expiration_date) {
    if(cJSON_AddNumberToObject(item, "emoji_status_expiration_date", _set_user_emoji_status_post_request->emoji_status_expiration_date) == NULL) {
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

_set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request_parseFromJSON(cJSON *_set_user_emoji_status_post_requestJSON){

    _set_user_emoji_status_post_request_t *_set_user_emoji_status_post_request_local_var = NULL;

    // _set_user_emoji_status_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_set_user_emoji_status_post_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // _set_user_emoji_status_post_request->emoji_status_custom_emoji_id
    cJSON *emoji_status_custom_emoji_id = cJSON_GetObjectItemCaseSensitive(_set_user_emoji_status_post_requestJSON, "emoji_status_custom_emoji_id");
    if (cJSON_IsNull(emoji_status_custom_emoji_id)) {
        emoji_status_custom_emoji_id = NULL;
    }
    if (emoji_status_custom_emoji_id) { 
    if(!cJSON_IsString(emoji_status_custom_emoji_id) && !cJSON_IsNull(emoji_status_custom_emoji_id))
    {
    goto end; //String
    }
    }

    // _set_user_emoji_status_post_request->emoji_status_expiration_date
    cJSON *emoji_status_expiration_date = cJSON_GetObjectItemCaseSensitive(_set_user_emoji_status_post_requestJSON, "emoji_status_expiration_date");
    if (cJSON_IsNull(emoji_status_expiration_date)) {
        emoji_status_expiration_date = NULL;
    }
    if (emoji_status_expiration_date) { 
    if(!cJSON_IsNumber(emoji_status_expiration_date))
    {
    goto end; //Numeric
    }
    }


    _set_user_emoji_status_post_request_local_var = _set_user_emoji_status_post_request_create_internal (
        user_id->valuedouble,
        emoji_status_custom_emoji_id && !cJSON_IsNull(emoji_status_custom_emoji_id) ? strdup(emoji_status_custom_emoji_id->valuestring) : NULL,
        emoji_status_expiration_date ? emoji_status_expiration_date->valuedouble : 0
        );

    return _set_user_emoji_status_post_request_local_var;
end:
    return NULL;

}
