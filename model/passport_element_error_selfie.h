/*
 * passport_element_error_selfie.h
 *
 * Represents an issue with the selfie with a document. The error is considered resolved when the file with the selfie changes.
 */

#ifndef _passport_element_error_selfie_H_
#define _passport_element_error_selfie_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_element_error_selfie_t passport_element_error_selfie_t;


// Enum TYPE for passport_element_error_selfie

typedef enum  { telegram_bot_api_passport_element_error_selfie_TYPE_NULL = 0, telegram_bot_api_passport_element_error_selfie_TYPE_passport, telegram_bot_api_passport_element_error_selfie_TYPE_driver_license, telegram_bot_api_passport_element_error_selfie_TYPE_identity_card, telegram_bot_api_passport_element_error_selfie_TYPE_internal_passport } telegram_bot_api_passport_element_error_selfie_TYPE_e;

char* passport_element_error_selfie_type_ToString(telegram_bot_api_passport_element_error_selfie_TYPE_e type);

telegram_bot_api_passport_element_error_selfie_TYPE_e passport_element_error_selfie_type_FromString(char* type);



typedef struct passport_element_error_selfie_t {
    char *source; // string
    telegram_bot_api_passport_element_error_selfie_TYPE_e type; //enum
    char *file_hash; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} passport_element_error_selfie_t;

__attribute__((deprecated)) passport_element_error_selfie_t *passport_element_error_selfie_create(
    char *source,
    telegram_bot_api_passport_element_error_selfie_TYPE_e type,
    char *file_hash,
    char *message
);

void passport_element_error_selfie_free(passport_element_error_selfie_t *passport_element_error_selfie);

passport_element_error_selfie_t *passport_element_error_selfie_parseFromJSON(cJSON *passport_element_error_selfieJSON);

cJSON *passport_element_error_selfie_convertToJSON(passport_element_error_selfie_t *passport_element_error_selfie);

#endif /* _passport_element_error_selfie_H_ */

