/*
 * _set_game_score_post_request.h
 *
 * 
 */

#ifndef __set_game_score_post_request_H_
#define __set_game_score_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_game_score_post_request_t _set_game_score_post_request_t;




typedef struct _set_game_score_post_request_t {
    int user_id; //numeric
    int score; //numeric
    int force; //boolean
    int disable_edit_message; //boolean
    int chat_id; //numeric
    int message_id; //numeric
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _set_game_score_post_request_t;

__attribute__((deprecated)) _set_game_score_post_request_t *_set_game_score_post_request_create(
    int user_id,
    int score,
    int force,
    int disable_edit_message,
    int chat_id,
    int message_id,
    char *inline_message_id
);

void _set_game_score_post_request_free(_set_game_score_post_request_t *_set_game_score_post_request);

_set_game_score_post_request_t *_set_game_score_post_request_parseFromJSON(cJSON *_set_game_score_post_requestJSON);

cJSON *_set_game_score_post_request_convertToJSON(_set_game_score_post_request_t *_set_game_score_post_request);

#endif /* __set_game_score_post_request_H_ */

