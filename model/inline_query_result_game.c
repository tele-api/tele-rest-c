#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_query_result_game.h"



static inline_query_result_game_t *inline_query_result_game_create_internal(
    char *type,
    char *id,
    char *game_short_name,
    inline_keyboard_markup_t *reply_markup
    ) {
    inline_query_result_game_t *inline_query_result_game_local_var = malloc(sizeof(inline_query_result_game_t));
    if (!inline_query_result_game_local_var) {
        return NULL;
    }
    inline_query_result_game_local_var->type = type;
    inline_query_result_game_local_var->id = id;
    inline_query_result_game_local_var->game_short_name = game_short_name;
    inline_query_result_game_local_var->reply_markup = reply_markup;

    inline_query_result_game_local_var->_library_owned = 1;
    return inline_query_result_game_local_var;
}

__attribute__((deprecated)) inline_query_result_game_t *inline_query_result_game_create(
    char *type,
    char *id,
    char *game_short_name,
    inline_keyboard_markup_t *reply_markup
    ) {
    return inline_query_result_game_create_internal (
        type,
        id,
        game_short_name,
        reply_markup
        );
}

void inline_query_result_game_free(inline_query_result_game_t *inline_query_result_game) {
    if(NULL == inline_query_result_game){
        return ;
    }
    if(inline_query_result_game->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "inline_query_result_game_free");
        return ;
    }
    listEntry_t *listEntry;
    if (inline_query_result_game->type) {
        free(inline_query_result_game->type);
        inline_query_result_game->type = NULL;
    }
    if (inline_query_result_game->id) {
        free(inline_query_result_game->id);
        inline_query_result_game->id = NULL;
    }
    if (inline_query_result_game->game_short_name) {
        free(inline_query_result_game->game_short_name);
        inline_query_result_game->game_short_name = NULL;
    }
    if (inline_query_result_game->reply_markup) {
        inline_keyboard_markup_free(inline_query_result_game->reply_markup);
        inline_query_result_game->reply_markup = NULL;
    }
    free(inline_query_result_game);
}

cJSON *inline_query_result_game_convertToJSON(inline_query_result_game_t *inline_query_result_game) {
    cJSON *item = cJSON_CreateObject();

    // inline_query_result_game->type
    if (!inline_query_result_game->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", inline_query_result_game->type) == NULL) {
    goto fail; //String
    }


    // inline_query_result_game->id
    if (!inline_query_result_game->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", inline_query_result_game->id) == NULL) {
    goto fail; //String
    }


    // inline_query_result_game->game_short_name
    if (!inline_query_result_game->game_short_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "game_short_name", inline_query_result_game->game_short_name) == NULL) {
    goto fail; //String
    }


    // inline_query_result_game->reply_markup
    if(inline_query_result_game->reply_markup) {
    cJSON *reply_markup_local_JSON = inline_keyboard_markup_convertToJSON(inline_query_result_game->reply_markup);
    if(reply_markup_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reply_markup", reply_markup_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

inline_query_result_game_t *inline_query_result_game_parseFromJSON(cJSON *inline_query_result_gameJSON){

    inline_query_result_game_t *inline_query_result_game_local_var = NULL;

    // define the local variable for inline_query_result_game->reply_markup
    inline_keyboard_markup_t *reply_markup_local_nonprim = NULL;

    // inline_query_result_game->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_query_result_gameJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // inline_query_result_game->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_query_result_gameJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // inline_query_result_game->game_short_name
    cJSON *game_short_name = cJSON_GetObjectItemCaseSensitive(inline_query_result_gameJSON, "game_short_name");
    if (cJSON_IsNull(game_short_name)) {
        game_short_name = NULL;
    }
    if (!game_short_name) {
        goto end;
    }

    
    if(!cJSON_IsString(game_short_name))
    {
    goto end; //String
    }

    // inline_query_result_game->reply_markup
    cJSON *reply_markup = cJSON_GetObjectItemCaseSensitive(inline_query_result_gameJSON, "reply_markup");
    if (cJSON_IsNull(reply_markup)) {
        reply_markup = NULL;
    }
    if (reply_markup) { 
    reply_markup_local_nonprim = inline_keyboard_markup_parseFromJSON(reply_markup); //nonprimitive
    }


    inline_query_result_game_local_var = inline_query_result_game_create_internal (
        strdup(type->valuestring),
        strdup(id->valuestring),
        strdup(game_short_name->valuestring),
        reply_markup ? reply_markup_local_nonprim : NULL
        );

    return inline_query_result_game_local_var;
end:
    if (reply_markup_local_nonprim) {
        inline_keyboard_markup_free(reply_markup_local_nonprim);
        reply_markup_local_nonprim = NULL;
    }
    return NULL;

}
