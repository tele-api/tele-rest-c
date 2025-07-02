/*
 * set_game_score_response.h
 *
 * 
 */

#ifndef _set_game_score_response_H_
#define _set_game_score_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_game_score_response_t set_game_score_response_t;

#include "edit_message_text_response_result.h"



typedef struct set_game_score_response_t {
    int ok; //boolean
    struct edit_message_text_response_result_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} set_game_score_response_t;

__attribute__((deprecated)) set_game_score_response_t *set_game_score_response_create(
    int ok,
    edit_message_text_response_result_t *result
);

void set_game_score_response_free(set_game_score_response_t *set_game_score_response);

set_game_score_response_t *set_game_score_response_parseFromJSON(cJSON *set_game_score_responseJSON);

cJSON *set_game_score_response_convertToJSON(set_game_score_response_t *set_game_score_response);

#endif /* _set_game_score_response_H_ */

