#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_game_high_scores_post_request.h"



static _get_game_high_scores_post_request_t *_get_game_high_scores_post_request_create_internal(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    _get_game_high_scores_post_request_t *_get_game_high_scores_post_request_local_var = malloc(sizeof(_get_game_high_scores_post_request_t));
    if (!_get_game_high_scores_post_request_local_var) {
        return NULL;
    }
    _get_game_high_scores_post_request_local_var->user_id = user_id;
    _get_game_high_scores_post_request_local_var->chat_id = chat_id;
    _get_game_high_scores_post_request_local_var->message_id = message_id;
    _get_game_high_scores_post_request_local_var->inline_message_id = inline_message_id;

    _get_game_high_scores_post_request_local_var->_library_owned = 1;
    return _get_game_high_scores_post_request_local_var;
}

__attribute__((deprecated)) _get_game_high_scores_post_request_t *_get_game_high_scores_post_request_create(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    return _get_game_high_scores_post_request_create_internal (
        user_id,
        chat_id,
        message_id,
        inline_message_id
        );
}

void _get_game_high_scores_post_request_free(_get_game_high_scores_post_request_t *_get_game_high_scores_post_request) {
    if(NULL == _get_game_high_scores_post_request){
        return ;
    }
    if(_get_game_high_scores_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_game_high_scores_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_game_high_scores_post_request->inline_message_id) {
        free(_get_game_high_scores_post_request->inline_message_id);
        _get_game_high_scores_post_request->inline_message_id = NULL;
    }
    free(_get_game_high_scores_post_request);
}

cJSON *_get_game_high_scores_post_request_convertToJSON(_get_game_high_scores_post_request_t *_get_game_high_scores_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_game_high_scores_post_request->user_id
    if (!_get_game_high_scores_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _get_game_high_scores_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _get_game_high_scores_post_request->chat_id
    if(_get_game_high_scores_post_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", _get_game_high_scores_post_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_game_high_scores_post_request->message_id
    if(_get_game_high_scores_post_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", _get_game_high_scores_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_game_high_scores_post_request->inline_message_id
    if(_get_game_high_scores_post_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", _get_game_high_scores_post_request->inline_message_id) == NULL) {
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

_get_game_high_scores_post_request_t *_get_game_high_scores_post_request_parseFromJSON(cJSON *_get_game_high_scores_post_requestJSON){

    _get_game_high_scores_post_request_t *_get_game_high_scores_post_request_local_var = NULL;

    // _get_game_high_scores_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_requestJSON, "user_id");
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

    // _get_game_high_scores_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // _get_game_high_scores_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // _get_game_high_scores_post_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(_get_game_high_scores_post_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    _get_game_high_scores_post_request_local_var = _get_game_high_scores_post_request_create_internal (
        user_id->valuedouble,
        chat_id ? chat_id->valuedouble : 0,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return _get_game_high_scores_post_request_local_var;
end:
    return NULL;

}
