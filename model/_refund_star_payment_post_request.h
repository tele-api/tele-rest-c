/*
 * _refund_star_payment_post_request.h
 *
 * 
 */

#ifndef __refund_star_payment_post_request_H_
#define __refund_star_payment_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _refund_star_payment_post_request_t _refund_star_payment_post_request_t;




typedef struct _refund_star_payment_post_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _refund_star_payment_post_request_t;

__attribute__((deprecated)) _refund_star_payment_post_request_t *_refund_star_payment_post_request_create(
    int user_id,
    char *telegram_payment_charge_id
);

void _refund_star_payment_post_request_free(_refund_star_payment_post_request_t *_refund_star_payment_post_request);

_refund_star_payment_post_request_t *_refund_star_payment_post_request_parseFromJSON(cJSON *_refund_star_payment_post_requestJSON);

cJSON *_refund_star_payment_post_request_convertToJSON(_refund_star_payment_post_request_t *_refund_star_payment_post_request);

#endif /* __refund_star_payment_post_request_H_ */

