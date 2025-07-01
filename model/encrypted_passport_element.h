/*
 * encrypted_passport_element.h
 *
 * Describes documents or other Telegram Passport elements shared with the bot by the user.
 */

#ifndef _encrypted_passport_element_H_
#define _encrypted_passport_element_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct encrypted_passport_element_t encrypted_passport_element_t;

#include "passport_file.h"

// Enum TYPE for encrypted_passport_element

typedef enum  { telegram_bot_api_encrypted_passport_element_TYPE_NULL = 0, telegram_bot_api_encrypted_passport_element_TYPE_personal_details, telegram_bot_api_encrypted_passport_element_TYPE_passport, telegram_bot_api_encrypted_passport_element_TYPE_driver_license, telegram_bot_api_encrypted_passport_element_TYPE_identity_card, telegram_bot_api_encrypted_passport_element_TYPE_internal_passport, telegram_bot_api_encrypted_passport_element_TYPE_address, telegram_bot_api_encrypted_passport_element_TYPE_utility_bill, telegram_bot_api_encrypted_passport_element_TYPE_bank_statement, telegram_bot_api_encrypted_passport_element_TYPE_rental_agreement, telegram_bot_api_encrypted_passport_element_TYPE_passport_registration, telegram_bot_api_encrypted_passport_element_TYPE_temporary_registration, telegram_bot_api_encrypted_passport_element_TYPE_phone_number, telegram_bot_api_encrypted_passport_element_TYPE_email } telegram_bot_api_encrypted_passport_element_TYPE_e;

char* encrypted_passport_element_type_ToString(telegram_bot_api_encrypted_passport_element_TYPE_e type);

telegram_bot_api_encrypted_passport_element_TYPE_e encrypted_passport_element_type_FromString(char* type);



typedef struct encrypted_passport_element_t {
    telegram_bot_api_encrypted_passport_element_TYPE_e type; //enum
    char *hash; // string
    char *data; // string
    char *phone_number; // string
    char *email; // string
    list_t *files; //nonprimitive container
    struct passport_file_t *front_side; //model
    struct passport_file_t *reverse_side; //model
    struct passport_file_t *selfie; //model
    list_t *translation; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} encrypted_passport_element_t;

__attribute__((deprecated)) encrypted_passport_element_t *encrypted_passport_element_create(
    telegram_bot_api_encrypted_passport_element_TYPE_e type,
    char *hash,
    char *data,
    char *phone_number,
    char *email,
    list_t *files,
    passport_file_t *front_side,
    passport_file_t *reverse_side,
    passport_file_t *selfie,
    list_t *translation
);

void encrypted_passport_element_free(encrypted_passport_element_t *encrypted_passport_element);

encrypted_passport_element_t *encrypted_passport_element_parseFromJSON(cJSON *encrypted_passport_elementJSON);

cJSON *encrypted_passport_element_convertToJSON(encrypted_passport_element_t *encrypted_passport_element);

#endif /* _encrypted_passport_element_H_ */

