/*
 * passport_element_error_files.h
 *
 * Represents an issue with a list of scans. The error is considered resolved when the list of files containing the scans changes.
 */

#ifndef _passport_element_error_files_H_
#define _passport_element_error_files_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_files_t passport_element_error_files_t;


// Enum TYPE for passport_element_error_files

typedef enum  { telegram_bot_api_passport_element_error_files_TYPE_NULL = 0, telegram_bot_api_passport_element_error_files_TYPE_utility_bill, telegram_bot_api_passport_element_error_files_TYPE_bank_statement, telegram_bot_api_passport_element_error_files_TYPE_rental_agreement, telegram_bot_api_passport_element_error_files_TYPE_passport_registration, telegram_bot_api_passport_element_error_files_TYPE_temporary_registration } telegram_bot_api_passport_element_error_files_TYPE_e;

char* passport_element_error_files_type_ToString(telegram_bot_api_passport_element_error_files_TYPE_e type);

telegram_bot_api_passport_element_error_files_TYPE_e passport_element_error_files_type_FromString(char* type);



typedef struct passport_element_error_files_t {
    char *source; // string
    telegram_bot_api_passport_element_error_files_TYPE_e type; //enum
    list_t *file_hashes; //primitive container
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_files_t;

__attribute__((deprecated)) passport_element_error_files_t *passport_element_error_files_create(
    char *source,
    telegram_bot_api_passport_element_error_files_TYPE_e type,
    list_t *file_hashes,
    char *message
);

void passport_element_error_files_free(passport_element_error_files_t *passport_element_error_files);

passport_element_error_files_t *passport_element_error_files_parseFromJSON(cJSON *passport_element_error_filesJSON);

cJSON *passport_element_error_files_convertToJSON(passport_element_error_files_t *passport_element_error_files);

#endif /* _passport_element_error_files_H_ */

