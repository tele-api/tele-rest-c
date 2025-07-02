/*
 * post_get_file_request.h
 *
 * 
 */

#ifndef _post_get_file_request_H_
#define _post_get_file_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_file_request_t post_get_file_request_t;




typedef struct post_get_file_request_t {
    char *file_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_file_request_t;

__attribute__((deprecated)) post_get_file_request_t *post_get_file_request_create(
    char *file_id
);

void post_get_file_request_free(post_get_file_request_t *post_get_file_request);

post_get_file_request_t *post_get_file_request_parseFromJSON(cJSON *post_get_file_requestJSON);

cJSON *post_get_file_request_convertToJSON(post_get_file_request_t *post_get_file_request);

#endif /* _post_get_file_request_H_ */

