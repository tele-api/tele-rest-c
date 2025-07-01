/*
 * star_transaction.h
 *
 * Describes a Telegram Star transaction. Note that if the buyer initiates a chargeback with the payment provider from whom they acquired Stars (e.g., Apple, Google) following this transaction, the refunded Stars will be deducted from the bot&#39;s balance. This is outside of Telegram&#39;s control.
 */

#ifndef _star_transaction_H_
#define _star_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct star_transaction_t star_transaction_t;

#include "transaction_partner.h"



typedef struct star_transaction_t {
    char *id; // string
    int amount; //numeric
    int date; //numeric
    int nanostar_amount; //numeric
    struct transaction_partner_t *source; //model
    struct transaction_partner_t *receiver; //model

    int _library_owned; // Is the library responsible for freeing this object?
} star_transaction_t;

__attribute__((deprecated)) star_transaction_t *star_transaction_create(
    char *id,
    int amount,
    int date,
    int nanostar_amount,
    transaction_partner_t *source,
    transaction_partner_t *receiver
);

void star_transaction_free(star_transaction_t *star_transaction);

star_transaction_t *star_transaction_parseFromJSON(cJSON *star_transactionJSON);

cJSON *star_transaction_convertToJSON(star_transaction_t *star_transaction);

#endif /* _star_transaction_H_ */

