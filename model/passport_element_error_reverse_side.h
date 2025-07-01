/*
 * passport_element_error_reverse_side.h
 *
 * Represents an issue with the reverse side of a document. The error is considered resolved when the file with reverse side of the document changes.
 */

#ifndef _passport_element_error_reverse_side_H_
#define _passport_element_error_reverse_side_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_reverse_side_t passport_element_error_reverse_side_t;


// Enum TYPE for passport_element_error_reverse_side

typedef enum  { telegram_bot_api_passport_element_error_reverse_side_TYPE_NULL = 0, telegram_bot_api_passport_element_error_reverse_side_TYPE_driver_license, telegram_bot_api_passport_element_error_reverse_side_TYPE_identity_card } telegram_bot_api_passport_element_error_reverse_side_TYPE_e;

char* passport_element_error_reverse_side_type_ToString(telegram_bot_api_passport_element_error_reverse_side_TYPE_e type);

telegram_bot_api_passport_element_error_reverse_side_TYPE_e passport_element_error_reverse_side_type_FromString(char* type);



typedef struct passport_element_error_reverse_side_t {
    char *source; // string
    telegram_bot_api_passport_element_error_reverse_side_TYPE_e type; //enum
    char *file_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_reverse_side_t;

__attribute__((deprecated)) passport_element_error_reverse_side_t *passport_element_error_reverse_side_create(
    char *source,
    telegram_bot_api_passport_element_error_reverse_side_TYPE_e type,
    char *file_hash,
    char *message
);

void passport_element_error_reverse_side_free(passport_element_error_reverse_side_t *passport_element_error_reverse_side);

passport_element_error_reverse_side_t *passport_element_error_reverse_side_parseFromJSON(cJSON *passport_element_error_reverse_sideJSON);

cJSON *passport_element_error_reverse_side_convertToJSON(passport_element_error_reverse_side_t *passport_element_error_reverse_side);

#endif /* _passport_element_error_reverse_side_H_ */

