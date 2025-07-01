/*
 * successful_payment.h
 *
 * This object contains basic information about a successful payment. Note that if the buyer initiates a chargeback with the relevant payment provider following this transaction, the funds may be debited from your balance. This is outside of Telegram&#39;s control.
 */

#ifndef _successful_payment_H_
#define _successful_payment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct successful_payment_t successful_payment_t;

#include "order_info.h"



typedef struct successful_payment_t {
    char *currency; // string
    int total_amount; //numeric
    char *invoice_payload; // string
    char *telegram_payment_charge_id; // string
    char *provider_payment_charge_id; // string
    int subscription_expiration_date; //numeric
    int is_recurring; //boolean
    int is_first_recurring; //boolean
    char *shipping_option_id; // string
    struct order_info_t *order_info; //model

    int _library_owned; // Is the library responsible for freeing this object?
} successful_payment_t;

__attribute__((deprecated)) successful_payment_t *successful_payment_create(
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *telegram_payment_charge_id,
    char *provider_payment_charge_id,
    int subscription_expiration_date,
    int is_recurring,
    int is_first_recurring,
    char *shipping_option_id,
    order_info_t *order_info
);

void successful_payment_free(successful_payment_t *successful_payment);

successful_payment_t *successful_payment_parseFromJSON(cJSON *successful_paymentJSON);

cJSON *successful_payment_convertToJSON(successful_payment_t *successful_payment);

#endif /* _successful_payment_H_ */

