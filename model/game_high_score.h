/*
 * game_high_score.h
 *
 * This object represents one row of the high scores table for a game.
 */

#ifndef _game_high_score_H_
#define _game_high_score_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct game_high_score_t game_high_score_t;

#include "user.h"



typedef struct game_high_score_t {
    int position; //numeric
    struct user_t *user; //model
    int score; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} game_high_score_t;

__attribute__((deprecated)) game_high_score_t *game_high_score_create(
    int position,
    user_t *user,
    int score
);

void game_high_score_free(game_high_score_t *game_high_score);

game_high_score_t *game_high_score_parseFromJSON(cJSON *game_high_scoreJSON);

cJSON *game_high_score_convertToJSON(game_high_score_t *game_high_score);

#endif /* _game_high_score_H_ */

