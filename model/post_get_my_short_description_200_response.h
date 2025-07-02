/*
 * post_get_my_short_description_200_response.h
 *
 * 
 */

#ifndef _post_get_my_short_description_200_response_H_
#define _post_get_my_short_description_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_my_short_description_200_response_t post_get_my_short_description_200_response_t;

#include "bot_short_description.h"



typedef struct post_get_my_short_description_200_response_t {
    int ok; //boolean
    struct bot_short_description_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_my_short_description_200_response_t;

__attribute__((deprecated)) post_get_my_short_description_200_response_t *post_get_my_short_description_200_response_create(
    int ok,
    bot_short_description_t *result
);

void post_get_my_short_description_200_response_free(post_get_my_short_description_200_response_t *post_get_my_short_description_200_response);

post_get_my_short_description_200_response_t *post_get_my_short_description_200_response_parseFromJSON(cJSON *post_get_my_short_description_200_responseJSON);

cJSON *post_get_my_short_description_200_response_convertToJSON(post_get_my_short_description_200_response_t *post_get_my_short_description_200_response);

#endif /* _post_get_my_short_description_200_response_H_ */

