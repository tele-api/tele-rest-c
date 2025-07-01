#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_read_business_message_post_request.h"



static _read_business_message_post_request_t *_read_business_message_post_request_create_internal(
    char *business_connection_id,
    int chat_id,
    int message_id
    ) {
    _read_business_message_post_request_t *_read_business_message_post_request_local_var = malloc(sizeof(_read_business_message_post_request_t));
    if (!_read_business_message_post_request_local_var) {
        return NULL;
    }
    _read_business_message_post_request_local_var->business_connection_id = business_connection_id;
    _read_business_message_post_request_local_var->chat_id = chat_id;
    _read_business_message_post_request_local_var->message_id = message_id;

    _read_business_message_post_request_local_var->_library_owned = 1;
    return _read_business_message_post_request_local_var;
}

__attribute__((deprecated)) _read_business_message_post_request_t *_read_business_message_post_request_create(
    char *business_connection_id,
    int chat_id,
    int message_id
    ) {
    return _read_business_message_post_request_create_internal (
        business_connection_id,
        chat_id,
        message_id
        );
}

void _read_business_message_post_request_free(_read_business_message_post_request_t *_read_business_message_post_request) {
    if(NULL == _read_business_message_post_request){
        return ;
    }
    if(_read_business_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_read_business_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_read_business_message_post_request->business_connection_id) {
        free(_read_business_message_post_request->business_connection_id);
        _read_business_message_post_request->business_connection_id = NULL;
    }
    free(_read_business_message_post_request);
}

cJSON *_read_business_message_post_request_convertToJSON(_read_business_message_post_request_t *_read_business_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _read_business_message_post_request->business_connection_id
    if (!_read_business_message_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _read_business_message_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _read_business_message_post_request->chat_id
    if (!_read_business_message_post_request->chat_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "chat_id", _read_business_message_post_request->chat_id) == NULL) {
    goto fail; //Numeric
    }


    // _read_business_message_post_request->message_id
    if (!_read_business_message_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _read_business_message_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_read_business_message_post_request_t *_read_business_message_post_request_parseFromJSON(cJSON *_read_business_message_post_requestJSON){

    _read_business_message_post_request_t *_read_business_message_post_request_local_var = NULL;

    // _read_business_message_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_read_business_message_post_requestJSON, "business_connection_id");
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

    // _read_business_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_read_business_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }

    // _read_business_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_read_business_message_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }


    _read_business_message_post_request_local_var = _read_business_message_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        chat_id->valuedouble,
        message_id->valuedouble
        );

    return _read_business_message_post_request_local_var;
end:
    return NULL;

}
