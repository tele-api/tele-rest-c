/*
 * chosen_inline_result.h
 *
 * Represents a [result](https://core.telegram.org/bots/api/#inlinequeryresult) of an inline query that was chosen by the user and sent to their chat partner.
 */

#ifndef _chosen_inline_result_H_
#define _chosen_inline_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct chosen_inline_result_t chosen_inline_result_t;

#include "location.h"
#include "user.h"



typedef struct chosen_inline_result_t {
    char *result_id; // string
    struct user_t *from; //model
    char *query; // string
    struct location_t *location; //model
    char *inline_message_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} chosen_inline_result_t;

__attribute__((deprecated)) chosen_inline_result_t *chosen_inline_result_create(
    char *result_id,
    user_t *from,
    char *query,
    location_t *location,
    char *inline_message_id
);

void chosen_inline_result_free(chosen_inline_result_t *chosen_inline_result);

chosen_inline_result_t *chosen_inline_result_parseFromJSON(cJSON *chosen_inline_resultJSON);

cJSON *chosen_inline_result_convertToJSON(chosen_inline_result_t *chosen_inline_result);

#endif /* _chosen_inline_result_H_ */

