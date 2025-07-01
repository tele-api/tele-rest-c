/*
 * passport_element_error_translation_file.h
 *
 * Represents an issue with one of the files that constitute the translation of a document. The error is considered resolved when the file changes.
 */

#ifndef _passport_element_error_translation_file_H_
#define _passport_element_error_translation_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_translation_file_t passport_element_error_translation_file_t;


// Enum TYPE for passport_element_error_translation_file

typedef enum  { telegram_bot_api_passport_element_error_translation_file_TYPE_NULL = 0, telegram_bot_api_passport_element_error_translation_file_TYPE_passport, telegram_bot_api_passport_element_error_translation_file_TYPE_driver_license, telegram_bot_api_passport_element_error_translation_file_TYPE_identity_card, telegram_bot_api_passport_element_error_translation_file_TYPE_internal_passport, telegram_bot_api_passport_element_error_translation_file_TYPE_utility_bill, telegram_bot_api_passport_element_error_translation_file_TYPE_bank_statement, telegram_bot_api_passport_element_error_translation_file_TYPE_rental_agreement, telegram_bot_api_passport_element_error_translation_file_TYPE_passport_registration, telegram_bot_api_passport_element_error_translation_file_TYPE_temporary_registration } telegram_bot_api_passport_element_error_translation_file_TYPE_e;

char* passport_element_error_translation_file_type_ToString(telegram_bot_api_passport_element_error_translation_file_TYPE_e type);

telegram_bot_api_passport_element_error_translation_file_TYPE_e passport_element_error_translation_file_type_FromString(char* type);



typedef struct passport_element_error_translation_file_t {
    char *source; // string
    telegram_bot_api_passport_element_error_translation_file_TYPE_e type; //enum
    char *file_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_translation_file_t;

__attribute__((deprecated)) passport_element_error_translation_file_t *passport_element_error_translation_file_create(
    char *source,
    telegram_bot_api_passport_element_error_translation_file_TYPE_e type,
    char *file_hash,
    char *message
);

void passport_element_error_translation_file_free(passport_element_error_translation_file_t *passport_element_error_translation_file);

passport_element_error_translation_file_t *passport_element_error_translation_file_parseFromJSON(cJSON *passport_element_error_translation_fileJSON);

cJSON *passport_element_error_translation_file_convertToJSON(passport_element_error_translation_file_t *passport_element_error_translation_file);

#endif /* _passport_element_error_translation_file_H_ */

