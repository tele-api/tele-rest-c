#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "game_high_score.h"



static game_high_score_t *game_high_score_create_internal(
    int position,
    user_t *user,
    int score
    ) {
    game_high_score_t *game_high_score_local_var = malloc(sizeof(game_high_score_t));
    if (!game_high_score_local_var) {
        return NULL;
    }
    game_high_score_local_var->position = position;
    game_high_score_local_var->user = user;
    game_high_score_local_var->score = score;

    game_high_score_local_var->_library_owned = 1;
    return game_high_score_local_var;
}

__attribute__((deprecated)) game_high_score_t *game_high_score_create(
    int position,
    user_t *user,
    int score
    ) {
    return game_high_score_create_internal (
        position,
        user,
        score
        );
}

void game_high_score_free(game_high_score_t *game_high_score) {
    if(NULL == game_high_score){
        return ;
    }
    if(game_high_score->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "game_high_score_free");
        return ;
    }
    listEntry_t *listEntry;
    if (game_high_score->user) {
        user_free(game_high_score->user);
        game_high_score->user = NULL;
    }
    free(game_high_score);
}

cJSON *game_high_score_convertToJSON(game_high_score_t *game_high_score) {
    cJSON *item = cJSON_CreateObject();

    // game_high_score->position
    if (!game_high_score->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", game_high_score->position) == NULL) {
    goto fail; //Numeric
    }


    // game_high_score->user
    if (!game_high_score->user) {
        goto fail;
    }
    cJSON *user_local_JSON = user_convertToJSON(game_high_score->user);
    if(user_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "user", user_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // game_high_score->score
    if (!game_high_score->score) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "score", game_high_score->score) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

game_high_score_t *game_high_score_parseFromJSON(cJSON *game_high_scoreJSON){

    game_high_score_t *game_high_score_local_var = NULL;

    // define the local variable for game_high_score->user
    user_t *user_local_nonprim = NULL;

    // game_high_score->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(game_high_scoreJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }

    // game_high_score->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(game_high_scoreJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (!user) {
        goto end;
    }

    
    user_local_nonprim = user_parseFromJSON(user); //nonprimitive

    // game_high_score->score
    cJSON *score = cJSON_GetObjectItemCaseSensitive(game_high_scoreJSON, "score");
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


    game_high_score_local_var = game_high_score_create_internal (
        position->valuedouble,
        user_local_nonprim,
        score->valuedouble
        );

    return game_high_score_local_var;
end:
    if (user_local_nonprim) {
        user_free(user_local_nonprim);
        user_local_nonprim = NULL;
    }
    return NULL;

}
