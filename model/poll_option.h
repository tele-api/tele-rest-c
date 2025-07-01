/*
 * poll_option.h
 *
 * This object contains information about one answer option in a poll.
 */

#ifndef _poll_option_H_
#define _poll_option_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct poll_option_t poll_option_t;

#include "message_entity.h"



typedef struct poll_option_t {
    char *text; // string
    int voter_count; //numeric
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} poll_option_t;

__attribute__((deprecated)) poll_option_t *poll_option_create(
    char *text,
    int voter_count,
    list_t *text_entities
);

void poll_option_free(poll_option_t *poll_option);

poll_option_t *poll_option_parseFromJSON(cJSON *poll_optionJSON);

cJSON *poll_option_convertToJSON(poll_option_t *poll_option);

#endif /* _poll_option_H_ */

