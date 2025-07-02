/*
 * set_game_score_request.h
 *
 * Request parameters for setGameScore
 */

#ifndef _set_game_score_request_H_
#define _set_game_score_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_game_score_request_t set_game_score_request_t;




typedef struct set_game_score_request_t {
    int user_id; //numeric
    int score; //numeric
    int force; //boolean
    int disable_edit_message; //boolean
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_game_score_request_t;

__attribute__((deprecated)) set_game_score_request_t *set_game_score_request_create(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void set_game_score_request_free(set_game_score_request_t *set_game_score_request);

set_game_score_request_t *set_game_score_request_parseFromJSON(cJSON *set_game_score_requestJSON);

cJSON *set_game_score_request_convertToJSON(set_game_score_request_t *set_game_score_request);

#endif /* _set_game_score_request_H_ */

