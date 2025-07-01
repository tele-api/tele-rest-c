#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_game_score_post_request.h"



static _set_game_score_post_request_t *_set_game_score_post_request_create_internal(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    _set_game_score_post_request_t *_set_game_score_post_request_local_var = malloc(sizeof(_set_game_score_post_request_t));
    if (!_set_game_score_post_request_local_var) {
        return NULL;
    }
    _set_game_score_post_request_local_var->user_id = user_id;
    _set_game_score_post_request_local_var->score = score;
    _set_game_score_post_request_local_var->force = force;
    _set_game_score_post_request_local_var->disable_edit_message = disable_edit_message;
    _set_game_score_post_request_local_var->chat_id = chat_id;
    _set_game_score_post_request_local_var->message_id = message_id;
    _set_game_score_post_request_local_var->inline_message_id = inline_message_id;

    _set_game_score_post_request_local_var->_library_owned = 1;
    return _set_game_score_post_request_local_var;
}

__attribute__((deprecated)) _set_game_score_post_request_t *_set_game_score_post_request_create(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    return _set_game_score_post_request_create_internal (
        user_id,
        score,
        force,
        disable_edit_message,
        chat_id,
        message_id,
        inline_message_id
        );
}

void _set_game_score_post_request_free(_set_game_score_post_request_t *_set_game_score_post_request) {
    if(NULL == _set_game_score_post_request){
        return ;
    }
    if(_set_game_score_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_game_score_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_game_score_post_request->inline_message_id) {
        free(_set_game_score_post_request->inline_message_id);
        _set_game_score_post_request->inline_message_id = NULL;
    }
    free(_set_game_score_post_request);
}

cJSON *_set_game_score_post_request_convertToJSON(_set_game_score_post_request_t *_set_game_score_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_game_score_post_request->user_id
    if (!_set_game_score_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _set_game_score_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _set_game_score_post_request->score
    if (!_set_game_score_post_request->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", _set_game_score_post_request->score) == NULL) {
    goto fail; //Numeric
    }


    // _set_game_score_post_request->force
    if(_set_game_score_post_request->force) {
    if(cJSON_AddBoolToObject(item, "force", _set_game_score_post_request->force) == NULL) {
    goto fail; //Bool
    }
    }


    // _set_game_score_post_request->disable_edit_message
    if(_set_game_score_post_request->disable_edit_message) {
    if(cJSON_AddBoolToObject(item, "disable_edit_message", _set_game_score_post_request->disable_edit_message) == NULL) {
    goto fail; //Bool
    }
    }


    // _set_game_score_post_request->chat_id
    if(_set_game_score_post_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", _set_game_score_post_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _set_game_score_post_request->message_id
    if(_set_game_score_post_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", _set_game_score_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _set_game_score_post_request->inline_message_id
    if(_set_game_score_post_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", _set_game_score_post_request->inline_message_id) == NULL) {
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

_set_game_score_post_request_t *_set_game_score_post_request_parseFromJSON(cJSON *_set_game_score_post_requestJSON){

    _set_game_score_post_request_t *_set_game_score_post_request_local_var = NULL;

    // _set_game_score_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "user_id");
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

    // _set_game_score_post_request->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "score");
    if (cJSON_IsNull(score)) {
        score = NULL;
    }
    if (!score) {
        goto end;
    }

    
    if(!cJSON_IsNumber(score))
    {
    goto end; //Numeric
    }

    // _set_game_score_post_request->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }

    // _set_game_score_post_request->disable_edit_message
    cJSON *disable_edit_message = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "disable_edit_message");
    if (cJSON_IsNull(disable_edit_message)) {
        disable_edit_message = NULL;
    }
    if (disable_edit_message) { 
    if(!cJSON_IsBool(disable_edit_message))
    {
    goto end; //Bool
    }
    }

    // _set_game_score_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // _set_game_score_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // _set_game_score_post_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(_set_game_score_post_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    _set_game_score_post_request_local_var = _set_game_score_post_request_create_internal (
        user_id->valuedouble,
        score->valuedouble,
        force ? force->valueint : 0,
        disable_edit_message ? disable_edit_message->valueint : 0,
        chat_id ? chat_id->valuedouble : 0,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return _set_game_score_post_request_local_var;
end:
    return NULL;

}
