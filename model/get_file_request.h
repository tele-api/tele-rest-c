/*
 * get_file_request.h
 *
 * Request parameters for getFile
 */

#ifndef _get_file_request_H_
#define _get_file_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_file_request_t get_file_request_t;




typedef struct get_file_request_t {
    char *file_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_file_request_t;

__attribute__((deprecated)) get_file_request_t *get_file_request_create(
    char *file_id
);

void get_file_request_free(get_file_request_t *get_file_request);

get_file_request_t *get_file_request_parseFromJSON(cJSON *get_file_requestJSON);

cJSON *get_file_request_convertToJSON(get_file_request_t *get_file_request);

#endif /* _get_file_request_H_ */

