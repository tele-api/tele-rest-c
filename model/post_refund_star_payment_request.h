/*
 * post_refund_star_payment_request.h
 *
 * 
 */

#ifndef _post_refund_star_payment_request_H_
#define _post_refund_star_payment_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_refund_star_payment_request_t post_refund_star_payment_request_t;




typedef struct post_refund_star_payment_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_refund_star_payment_request_t;

__attribute__((deprecated)) post_refund_star_payment_request_t *post_refund_star_payment_request_create(
    int user_id,
    char *telegram_payment_charge_id
);

void post_refund_star_payment_request_free(post_refund_star_payment_request_t *post_refund_star_payment_request);

post_refund_star_payment_request_t *post_refund_star_payment_request_parseFromJSON(cJSON *post_refund_star_payment_requestJSON);

cJSON *post_refund_star_payment_request_convertToJSON(post_refund_star_payment_request_t *post_refund_star_payment_request);

#endif /* _post_refund_star_payment_request_H_ */

