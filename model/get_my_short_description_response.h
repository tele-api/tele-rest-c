/*
 * get_my_short_description_response.h
 *
 * 
 */

#ifndef _get_my_short_description_response_H_
#define _get_my_short_description_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_my_short_description_response_t get_my_short_description_response_t;

#include "bot_short_description.h"



typedef struct get_my_short_description_response_t {
    int ok; //boolean
    struct bot_short_description_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_my_short_description_response_t;

__attribute__((deprecated)) get_my_short_description_response_t *get_my_short_description_response_create(
    int ok,
    bot_short_description_t *result
);

void get_my_short_description_response_free(get_my_short_description_response_t *get_my_short_description_response);

get_my_short_description_response_t *get_my_short_description_response_parseFromJSON(cJSON *get_my_short_description_responseJSON);

cJSON *get_my_short_description_response_convertToJSON(get_my_short_description_response_t *get_my_short_description_response);

#endif /* _get_my_short_description_response_H_ */

