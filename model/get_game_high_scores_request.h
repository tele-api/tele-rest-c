/*
 * get_game_high_scores_request.h
 *
 * Request parameters for getGameHighScores
 */

#ifndef _get_game_high_scores_request_H_
#define _get_game_high_scores_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_game_high_scores_request_t get_game_high_scores_request_t;




typedef struct get_game_high_scores_request_t {
    int user_id; //numeric
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_game_high_scores_request_t;

__attribute__((deprecated)) get_game_high_scores_request_t *get_game_high_scores_request_create(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void get_game_high_scores_request_free(get_game_high_scores_request_t *get_game_high_scores_request);

get_game_high_scores_request_t *get_game_high_scores_request_parseFromJSON(cJSON *get_game_high_scores_requestJSON);

cJSON *get_game_high_scores_request_convertToJSON(get_game_high_scores_request_t *get_game_high_scores_request);

#endif /* _get_game_high_scores_request_H_ */

