/*
 * encrypted_credentials.h
 *
 * Describes data required for decrypting and authenticating [EncryptedPassportElement](https://core.telegram.org/bots/api/#encryptedpassportelement). See the [Telegram Passport Documentation](https://core.telegram.org/passport#receiving-information) for a complete description of the data decryption and authentication processes.
 */

#ifndef _encrypted_credentials_H_
#define _encrypted_credentials_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct encrypted_credentials_t encrypted_credentials_t;




typedef struct encrypted_credentials_t {
    char *data; // string
    char *hash; // string
    char *secret; // string

    int _library_owned; // Is the library responsible for freeing this object?
} encrypted_credentials_t;

__attribute__((deprecated)) encrypted_credentials_t *encrypted_credentials_create(
    char *data,
    char *hash,
    char *secret
);

void encrypted_credentials_free(encrypted_credentials_t *encrypted_credentials);

encrypted_credentials_t *encrypted_credentials_parseFromJSON(cJSON *encrypted_credentialsJSON);

cJSON *encrypted_credentials_convertToJSON(encrypted_credentials_t *encrypted_credentials);

#endif /* _encrypted_credentials_H_ */

