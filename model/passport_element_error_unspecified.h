/*
 * passport_element_error_unspecified.h
 *
 * Represents an issue in an unspecified place. The error is considered resolved when new data is added.
 */

#ifndef _passport_element_error_unspecified_H_
#define _passport_element_error_unspecified_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_unspecified_t passport_element_error_unspecified_t;




typedef struct passport_element_error_unspecified_t {
    char *source; // string
    char *type; // string
    char *element_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_unspecified_t;

__attribute__((deprecated)) passport_element_error_unspecified_t *passport_element_error_unspecified_create(
    char *source,
    char *type,
    char *element_hash,
    char *message
);

void passport_element_error_unspecified_free(passport_element_error_unspecified_t *passport_element_error_unspecified);

passport_element_error_unspecified_t *passport_element_error_unspecified_parseFromJSON(cJSON *passport_element_error_unspecifiedJSON);

cJSON *passport_element_error_unspecified_convertToJSON(passport_element_error_unspecified_t *passport_element_error_unspecified);

#endif /* _passport_element_error_unspecified_H_ */

