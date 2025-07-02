#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_game_high_scores_request.h"



static get_game_high_scores_request_t *get_game_high_scores_request_create_internal(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    get_game_high_scores_request_t *get_game_high_scores_request_local_var = malloc(sizeof(get_game_high_scores_request_t));
    if (!get_game_high_scores_request_local_var) {
        return NULL;
    }
    get_game_high_scores_request_local_var->user_id = user_id;
    get_game_high_scores_request_local_var->chat_id = chat_id;
    get_game_high_scores_request_local_var->message_id = message_id;
    get_game_high_scores_request_local_var->inline_message_id = inline_message_id;

    get_game_high_scores_request_local_var->_library_owned = 1;
    return get_game_high_scores_request_local_var;
}

__attribute__((deprecated)) get_game_high_scores_request_t *get_game_high_scores_request_create(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
    ) {
    return get_game_high_scores_request_create_internal (
        user_id,
        chat_id,
        message_id,
        inline_message_id
        );
}

void get_game_high_scores_request_free(get_game_high_scores_request_t *get_game_high_scores_request) {
    if(NULL == get_game_high_scores_request){
        return ;
    }
    if(get_game_high_scores_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_game_high_scores_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_game_high_scores_request->inline_message_id) {
        free(get_game_high_scores_request->inline_message_id);
        get_game_high_scores_request->inline_message_id = NULL;
    }
    free(get_game_high_scores_request);
}

cJSON *get_game_high_scores_request_convertToJSON(get_game_high_scores_request_t *get_game_high_scores_request) {
    cJSON *item = cJSON_CreateObject();

    // get_game_high_scores_request->user_id
    if (!get_game_high_scores_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", get_game_high_scores_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // get_game_high_scores_request->chat_id
    if(get_game_high_scores_request->chat_id) {
    if(cJSON_AddNumberToObject(item, "chat_id", get_game_high_scores_request->chat_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_game_high_scores_request->message_id
    if(get_game_high_scores_request->message_id) {
    if(cJSON_AddNumberToObject(item, "message_id", get_game_high_scores_request->message_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_game_high_scores_request->inline_message_id
    if(get_game_high_scores_request->inline_message_id) {
    if(cJSON_AddStringToObject(item, "inline_message_id", get_game_high_scores_request->inline_message_id) == NULL) {
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

get_game_high_scores_request_t *get_game_high_scores_request_parseFromJSON(cJSON *get_game_high_scores_requestJSON){

    get_game_high_scores_request_t *get_game_high_scores_request_local_var = NULL;

    // get_game_high_scores_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_requestJSON, "user_id");
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

    // get_game_high_scores_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (chat_id) { 
    if(!cJSON_IsNumber(chat_id))
    {
    goto end; //Numeric
    }
    }

    // get_game_high_scores_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (message_id) { 
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }
    }

    // get_game_high_scores_request->inline_message_id
    cJSON *inline_message_id = cJSON_GetObjectItemCaseSensitive(get_game_high_scores_requestJSON, "inline_message_id");
    if (cJSON_IsNull(inline_message_id)) {
        inline_message_id = NULL;
    }
    if (inline_message_id) { 
    if(!cJSON_IsString(inline_message_id) && !cJSON_IsNull(inline_message_id))
    {
    goto end; //String
    }
    }


    get_game_high_scores_request_local_var = get_game_high_scores_request_create_internal (
        user_id->valuedouble,
        chat_id ? chat_id->valuedouble : 0,
        message_id ? message_id->valuedouble : 0,
        inline_message_id && !cJSON_IsNull(inline_message_id) ? strdup(inline_message_id->valuestring) : NULL
        );

    return get_game_high_scores_request_local_var;
end:
    return NULL;

}
