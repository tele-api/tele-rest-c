/*
 * _get_game_high_scores_post_request.h
 *
 * 
 */

#ifndef __get_game_high_scores_post_request_H_
#define __get_game_high_scores_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_game_high_scores_post_request_t _get_game_high_scores_post_request_t;




typedef struct _get_game_high_scores_post_request_t {
    int user_id; //numeric
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _get_game_high_scores_post_request_t;

__attribute__((deprecated)) _get_game_high_scores_post_request_t *_get_game_high_scores_post_request_create(
    int user_id,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void _get_game_high_scores_post_request_free(_get_game_high_scores_post_request_t *_get_game_high_scores_post_request);

_get_game_high_scores_post_request_t *_get_game_high_scores_post_request_parseFromJSON(cJSON *_get_game_high_scores_post_requestJSON);

cJSON *_get_game_high_scores_post_request_convertToJSON(_get_game_high_scores_post_request_t *_get_game_high_scores_post_request);

#endif /* __get_game_high_scores_post_request_H_ */

