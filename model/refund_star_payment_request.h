/*
 * refund_star_payment_request.h
 *
 * Request parameters for refundStarPayment
 */

#ifndef _refund_star_payment_request_H_
#define _refund_star_payment_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct refund_star_payment_request_t refund_star_payment_request_t;




typedef struct refund_star_payment_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} refund_star_payment_request_t;

__attribute__((deprecated)) refund_star_payment_request_t *refund_star_payment_request_create(
    int user_id,
    char *telegram_payment_charge_id
);

void refund_star_payment_request_free(refund_star_payment_request_t *refund_star_payment_request);

refund_star_payment_request_t *refund_star_payment_request_parseFromJSON(cJSON *refund_star_payment_requestJSON);

cJSON *refund_star_payment_request_convertToJSON(refund_star_payment_request_t *refund_star_payment_request);

#endif /* _refund_star_payment_request_H_ */

