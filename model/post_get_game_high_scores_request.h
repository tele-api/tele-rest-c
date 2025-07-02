/*
 * post_get_game_high_scores_request.h
 *
 * 
 */

#ifndef _post_get_game_high_scores_request_H_
#define _post_get_game_high_scores_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_game_high_scores_request_t post_get_game_high_scores_request_t;




typedef struct post_get_game_high_scores_request_t {
    int user_id; //numeric
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_game_high_scores_request_t;

__attribute__((deprecated)) post_get_game_high_scores_request_t *post_get_game_high_scores_request_create(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void post_get_game_high_scores_request_free(post_get_game_high_scores_request_t *post_get_game_high_scores_request);

post_get_game_high_scores_request_t *post_get_game_high_scores_request_parseFromJSON(cJSON *post_get_game_high_scores_requestJSON);

cJSON *post_get_game_high_scores_request_convertToJSON(post_get_game_high_scores_request_t *post_get_game_high_scores_request);

#endif /* _post_get_game_high_scores_request_H_ */

