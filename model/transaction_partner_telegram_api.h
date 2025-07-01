/*
 * transaction_partner_telegram_api.h
 *
 * Describes a transaction with payment for [paid broadcasting](https://core.telegram.org/bots/api/#paid-broadcasts).
 */

#ifndef _transaction_partner_telegram_api_H_
#define _transaction_partner_telegram_api_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_telegram_api_t transaction_partner_telegram_api_t;




typedef struct transaction_partner_telegram_api_t {
    char *type; // string
    int request_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_telegram_api_t;

__attribute__((deprecated)) transaction_partner_telegram_api_t *transaction_partner_telegram_api_create(
    char *type,
    int request_count
);

void transaction_partner_telegram_api_free(transaction_partner_telegram_api_t *transaction_partner_telegram_api);

transaction_partner_telegram_api_t *transaction_partner_telegram_api_parseFromJSON(cJSON *transaction_partner_telegram_apiJSON);

cJSON *transaction_partner_telegram_api_convertToJSON(transaction_partner_telegram_api_t *transaction_partner_telegram_api);

#endif /* _transaction_partner_telegram_api_H_ */

