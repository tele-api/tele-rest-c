/*
 * refunded_payment.h
 *
 * This object contains basic information about a refunded payment.
 */

#ifndef _refunded_payment_H_
#define _refunded_payment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct refunded_payment_t refunded_payment_t;




typedef struct refunded_payment_t {
    char *currency; // string
    int total_amount; //numeric
    char *invoice_payload; // string
    char *telegram_payment_charge_id; // string
    char *provider_payment_charge_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} refunded_payment_t;

__attribute__((deprecated)) refunded_payment_t *refunded_payment_create(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id
);

void refunded_payment_free(refunded_payment_t *refunded_payment);

refunded_payment_t *refunded_payment_parseFromJSON(cJSON *refunded_paymentJSON);

cJSON *refunded_payment_convertToJSON(refunded_payment_t *refunded_payment);

#endif /* _refunded_payment_H_ */

