/*
 * poll.h
 *
 * This object contains information about a poll.
 */

#ifndef _poll_H_
#define _poll_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct poll_t poll_t;

#include "message_entity.h"
#include "poll_option.h"

// Enum TYPE for poll

typedef enum  { telegram_bot_api_poll_TYPE_NULL = 0, telegram_bot_api_poll_TYPE_regular, telegram_bot_api_poll_TYPE_quiz } telegram_bot_api_poll_TYPE_e;

char* poll_type_ToString(telegram_bot_api_poll_TYPE_e type);

telegram_bot_api_poll_TYPE_e poll_type_FromString(char* type);



typedef struct poll_t {
    char *id; // string
    char *question; // string
    list_t *options; //nonprimitive container
    int total_voter_count; //numeric
    int is_closed; //boolean
    int is_anonymous; //boolean
    telegram_bot_api_poll_TYPE_e type; //enum
    int allows_multiple_answers; //boolean
    list_t *question_entities; //nonprimitive container
    int correct_option_id; //numeric
    char *explanation; // string
    list_t *explanation_entities; //nonprimitive container
    int open_period; //numeric
    int close_date; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} poll_t;

__attribute__((deprecated)) poll_t *poll_create(
    char *id,
    char *question,
    list_t *options,
    int total_voter_count,
    int is_closed,
    int is_anonymous,
    telegram_bot_api_poll_TYPE_e type,
    int allows_multiple_answers,
    list_t *question_entities,
    int correct_option_id,
    char *explanation,
    list_t *explanation_entities,
    int open_period,
    int close_date
);

void poll_free(poll_t *poll);

poll_t *poll_parseFromJSON(cJSON *pollJSON);

cJSON *poll_convertToJSON(poll_t *poll);

#endif /* _poll_H_ */

