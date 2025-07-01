/*
 * input_poll_option.h
 *
 * This object contains information about one answer option in a poll to be sent.
 */

#ifndef _input_poll_option_H_
#define _input_poll_option_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_poll_option_t input_poll_option_t;

#include "message_entity.h"



typedef struct input_poll_option_t {
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} input_poll_option_t;

__attribute__((deprecated)) input_poll_option_t *input_poll_option_create(
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void input_poll_option_free(input_poll_option_t *input_poll_option);

input_poll_option_t *input_poll_option_parseFromJSON(cJSON *input_poll_optionJSON);

cJSON *input_poll_option_convertToJSON(input_poll_option_t *input_poll_option);

#endif /* _input_poll_option_H_ */

