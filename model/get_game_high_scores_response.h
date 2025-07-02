/*
 * get_game_high_scores_response.h
 *
 * 
 */

#ifndef _get_game_high_scores_response_H_
#define _get_game_high_scores_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_game_high_scores_response_t get_game_high_scores_response_t;

#include "game_high_score.h"



typedef struct get_game_high_scores_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_game_high_scores_response_t;

__attribute__((deprecated)) get_game_high_scores_response_t *get_game_high_scores_response_create(
    int ok,
    list_t *result
);

void get_game_high_scores_response_free(get_game_high_scores_response_t *get_game_high_scores_response);

get_game_high_scores_response_t *get_game_high_scores_response_parseFromJSON(cJSON *get_game_high_scores_responseJSON);

cJSON *get_game_high_scores_response_convertToJSON(get_game_high_scores_response_t *get_game_high_scores_response);

#endif /* _get_game_high_scores_response_H_ */

