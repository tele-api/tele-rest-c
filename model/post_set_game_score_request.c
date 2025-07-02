#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_game_score_request.h"



static post_set_game_score_request_t *post_set_game_score_request_create_internal(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    post_set_game_score_request_t *post_set_game_score_request_local_var = malloc(sizeof(post_set_game_score_request_t));
    if (!post_set_game_score_request_local_var) {
        return NULL;
    }
    post_set_game_score_request_local_var->user_id = user_id;
    post_set_game_score_request_local_var->score = score;
    post_set_game_score_request_local_var->force = force;
    post_set_game_score_request_local_var->disable_edit_message = disable_edit_message;
    post_set_game_score_request_local_var->chat_id = chat_id;
    post_set_game_score_request_local_var->message_id = message_id;
    post_set_game_score_request_local_var->inline_message_id = inline_message_id;

    post_set_game_score_request_local_var->_library_owned = 1;
    return post_set_game_score_request_local_var;
}

__attribute__((deprecated)) post_set_game_score_request_t *post_set_game_score_request_create(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    return post_set_game_score_request_create_internal (
        user_id,
        score,
        force,
        disable_edit_message,
        chat_id,
        message_id,
        inline_message_id
        );
}

void post_set_game_score_request_free(post_set_game_score_request_t *post_set_game_score_request) {
    if(NULL == post_set_game_score_request){
        return ;
    }
    if(post_set_game_score_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_game_score_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_game_score_request->inline_message_id) {
        free(post_set_game_score_request->inline_message_id);
        post_set_game_score_request->inline_message_id = NULL;
    }
    free(post_set_game_score_request);
}

cJSON *post_set_game_score_request_convertToJSON(post_set_game_score_request_t *post_set_game_score_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_game_score_request->user_id
    if (!post_set_game_score_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", post_set_game_score_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // post_set_game_score_request->score
    if (!post_set_game_score_request->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", post_set_game_score_request->score) == NULL) {
    goto fail; //Numeric
    }


    // post_set_game_score_request->force
    if(post_set_game_score_request->force) {
    if(cJSON_AddBoolToObject(item, "force", post_set_game_score_request->force) == NULL) {
    goto fail; //Bool
    }
    }


    // post_set_game_score_request->disable_edit_message
    if(post_set_game_score_request->disable_edit_message) {
    if(cJSON_AddBoolToObject(item, "disable_edit_message", post_set_game_score_request->disable_edit_message) == NULL) {
    goto fail; //Bool
    }
    }


    // post_set_game_score_request->chat_id
    if(post_set_game_score_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", post_set_game_score_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_set_game_score_request->message_id
    if(post_set_game_score_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", post_set_game_score_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_set_game_score_request->inline_message_id
    if(post_set_game_score_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", post_set_game_score_request->inline_message_id) == NULL) {
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

post_set_game_score_request_t *post_set_game_score_request_parseFromJSON(cJSON *post_set_game_score_requestJSON){

    post_set_game_score_request_t *post_set_game_score_request_local_var = NULL;

    // post_set_game_score_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "user_id");
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

    // post_set_game_score_request->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "score");
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

    // post_set_game_score_request->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }

    // post_set_game_score_request->disable_edit_message
    cJSON *disable_edit_message = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "disable_edit_message");
    if (cJSON_IsNull(disable_edit_message)) {
        disable_edit_message = NULL;
    }
    if (disable_edit_message) { 
    if(!cJSON_IsBool(disable_edit_message))
    {
    goto end; //Bool
    }
    }

    // post_set_game_score_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // post_set_game_score_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // post_set_game_score_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(post_set_game_score_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    post_set_game_score_request_local_var = post_set_game_score_request_create_internal (
        user_id->valuedouble,
        score->valuedouble,
        force ? force->valueint : 0,
        disable_edit_message ? disable_edit_message->valueint : 0,
        chat_id ? chat_id->valuedouble : 0,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return post_set_game_score_request_local_var;
end:
    return NULL;

}
