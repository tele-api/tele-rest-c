/*
 * transaction_partner_telegram_ads.h
 *
 * Describes a withdrawal transaction to the Telegram Ads platform.
 */

#ifndef _transaction_partner_telegram_ads_H_
#define _transaction_partner_telegram_ads_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_telegram_ads_t transaction_partner_telegram_ads_t;




typedef struct transaction_partner_telegram_ads_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_telegram_ads_t;

__attribute__((deprecated)) transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_create(
    char *type
);

void transaction_partner_telegram_ads_free(transaction_partner_telegram_ads_t *transaction_partner_telegram_ads);

transaction_partner_telegram_ads_t *transaction_partner_telegram_ads_parseFromJSON(cJSON *transaction_partner_telegram_adsJSON);

cJSON *transaction_partner_telegram_ads_convertToJSON(transaction_partner_telegram_ads_t *transaction_partner_telegram_ads);

#endif /* _transaction_partner_telegram_ads_H_ */

