/*
 * passport_element_error_data_field.h
 *
 * Represents an issue in one of the data fields that was provided by the user. The error is considered resolved when the field&#39;s value changes.
 */

#ifndef _passport_element_error_data_field_H_
#define _passport_element_error_data_field_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_data_field_t passport_element_error_data_field_t;


// Enum TYPE for passport_element_error_data_field

typedef enum  { telegram_bot_api_passport_element_error_data_field_TYPE_NULL = 0, telegram_bot_api_passport_element_error_data_field_TYPE_personal_details, telegram_bot_api_passport_element_error_data_field_TYPE_passport, telegram_bot_api_passport_element_error_data_field_TYPE_driver_license, telegram_bot_api_passport_element_error_data_field_TYPE_identity_card, telegram_bot_api_passport_element_error_data_field_TYPE_internal_passport, telegram_bot_api_passport_element_error_data_field_TYPE_address } telegram_bot_api_passport_element_error_data_field_TYPE_e;

char* passport_element_error_data_field_type_ToString(telegram_bot_api_passport_element_error_data_field_TYPE_e type);

telegram_bot_api_passport_element_error_data_field_TYPE_e passport_element_error_data_field_type_FromString(char* type);



typedef struct passport_element_error_data_field_t {
    char *source; // string
    telegram_bot_api_passport_element_error_data_field_TYPE_e type; //enum
    char *field_name; // string
    char *data_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_data_field_t;

__attribute__((deprecated)) passport_element_error_data_field_t *passport_element_error_data_field_create(
    char *source,
    telegram_bot_api_passport_element_error_data_field_TYPE_e type,
    char *field_name,
    char *data_hash,
    char *message
);

void passport_element_error_data_field_free(passport_element_error_data_field_t *passport_element_error_data_field);

passport_element_error_data_field_t *passport_element_error_data_field_parseFromJSON(cJSON *passport_element_error_data_fieldJSON);

cJSON *passport_element_error_data_field_convertToJSON(passport_element_error_data_field_t *passport_element_error_data_field);

#endif /* _passport_element_error_data_field_H_ */

