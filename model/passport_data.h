/*
 * passport_data.h
 *
 * Describes Telegram Passport data shared with the bot by the user.
 */

#ifndef _passport_data_H_
#define _passport_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct passport_data_t passport_data_t;

#include "encrypted_credentials.h"
#include "encrypted_passport_element.h"



typedef struct passport_data_t {
    list_t *data; //nonprimitive container
    struct encrypted_credentials_t *credentials; //model

    int _library_owned; // Is the library responsible for freeing this object?
} passport_data_t;

__attribute__((deprecated)) passport_data_t *passport_data_create(
    list_t *data,
    encrypted_credentials_t *credentials
);

void passport_data_free(passport_data_t *passport_data);

passport_data_t *passport_data_parseFromJSON(cJSON *passport_dataJSON);

cJSON *passport_data_convertToJSON(passport_data_t *passport_data);

#endif /* _passport_data_H_ */

