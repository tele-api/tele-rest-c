/*
 * _get_file_post_200_response.h
 *
 * 
 */

#ifndef __get_file_post_200_response_H_
#define __get_file_post_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_file_post_200_response_t _get_file_post_200_response_t;

#include "file.h"



typedef struct _get_file_post_200_response_t {
    int ok; //boolean
    struct binary_t*_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _get_file_post_200_response_t;

__attribute__((deprecated)) _get_file_post_200_response_t *_get_file_post_200_response_create(
    int ok,
    binary_t*_t *result
);

void _get_file_post_200_response_free(_get_file_post_200_response_t *_get_file_post_200_response);

_get_file_post_200_response_t *_get_file_post_200_response_parseFromJSON(cJSON *_get_file_post_200_responseJSON);

cJSON *_get_file_post_200_response_convertToJSON(_get_file_post_200_response_t *_get_file_post_200_response);

#endif /* __get_file_post_200_response_H_ */

