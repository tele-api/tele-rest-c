/*
 * _get_my_name_post_200_response.h
 *
 * 
 */

#ifndef __get_my_name_post_200_response_H_
#define __get_my_name_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_my_name_post_200_response_t _get_my_name_post_200_response_t;

#include "bot_name.h"



typedef struct _get_my_name_post_200_response_t {
    int ok; //boolean
    struct bot_name_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _get_my_name_post_200_response_t;

__attribute__((deprecated)) _get_my_name_post_200_response_t *_get_my_name_post_200_response_create(
    int ok,
    bot_name_t *result
);

void _get_my_name_post_200_response_free(_get_my_name_post_200_response_t *_get_my_name_post_200_response);

_get_my_name_post_200_response_t *_get_my_name_post_200_response_parseFromJSON(cJSON *_get_my_name_post_200_responseJSON);

cJSON *_get_my_name_post_200_response_convertToJSON(_get_my_name_post_200_response_t *_get_my_name_post_200_response);

#endif /* __get_my_name_post_200_response_H_ */

