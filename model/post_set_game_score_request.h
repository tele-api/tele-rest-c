/*
 * post_set_game_score_request.h
 *
 * 
 */

#ifndef _post_set_game_score_request_H_
#define _post_set_game_score_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_game_score_request_t post_set_game_score_request_t;




typedef struct post_set_game_score_request_t {
    int user_id; //numeric
    int score; //numeric
    int force; //boolean
    int disable_edit_message; //boolean
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_game_score_request_t;

__attribute__((deprecated)) post_set_game_score_request_t *post_set_game_score_request_create(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void post_set_game_score_request_free(post_set_game_score_request_t *post_set_game_score_request);

post_set_game_score_request_t *post_set_game_score_request_parseFromJSON(cJSON *post_set_game_score_requestJSON);

cJSON *post_set_game_score_request_convertToJSON(post_set_game_score_request_t *post_set_game_score_request);

#endif /* _post_set_game_score_request_H_ */

