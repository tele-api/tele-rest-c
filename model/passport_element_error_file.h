/*
 * passport_element_error_file.h
 *
 * Represents an issue with a document scan. The error is considered resolved when the file with the document scan changes.
 */

#ifndef _passport_element_error_file_H_
#define _passport_element_error_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_file_t passport_element_error_file_t;


// Enum TYPE for passport_element_error_file

typedef enum  { telegram_bot_api_passport_element_error_file_TYPE_NULL = 0, telegram_bot_api_passport_element_error_file_TYPE_utility_bill, telegram_bot_api_passport_element_error_file_TYPE_bank_statement, telegram_bot_api_passport_element_error_file_TYPE_rental_agreement, telegram_bot_api_passport_element_error_file_TYPE_passport_registration, telegram_bot_api_passport_element_error_file_TYPE_temporary_registration } telegram_bot_api_passport_element_error_file_TYPE_e;

char* passport_element_error_file_type_ToString(telegram_bot_api_passport_element_error_file_TYPE_e type);

telegram_bot_api_passport_element_error_file_TYPE_e passport_element_error_file_type_FromString(char* type);



typedef struct passport_element_error_file_t {
    char *source; // string
    telegram_bot_api_passport_element_error_file_TYPE_e type; //enum
    char *file_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_file_t;

__attribute__((deprecated)) passport_element_error_file_t *passport_element_error_file_create(
    char *source,
    telegram_bot_api_passport_element_error_file_TYPE_e type,
    char *file_hash,
    char *message
);

void passport_element_error_file_free(passport_element_error_file_t *passport_element_error_file);

passport_element_error_file_t *passport_element_error_file_parseFromJSON(cJSON *passport_element_error_fileJSON);

cJSON *passport_element_error_file_convertToJSON(passport_element_error_file_t *passport_element_error_file);

#endif /* _passport_element_error_file_H_ */

