/*
 * response_parameters.h
 *
 * Describes why a request was unsuccessful.
 */

#ifndef _response_parameters_H_
#define _response_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct response_parameters_t response_parameters_t;




typedef struct response_parameters_t {
    int migrate_to_chat_id; //numeric
    int retry_after; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} response_parameters_t;

__attribute__((deprecated)) response_parameters_t *response_parameters_create(
    int migrate_to_chat_id,
    int retry_after
);

void response_parameters_free(response_parameters_t *response_parameters);

response_parameters_t *response_parameters_parseFromJSON(cJSON *response_parametersJSON);

cJSON *response_parameters_convertToJSON(response_parameters_t *response_parameters);

#endif /* _response_parameters_H_ */

