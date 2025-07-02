/*
 * refund_star_payment_response.h
 *
 * 
 */

#ifndef _refund_star_payment_response_H_
#define _refund_star_payment_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct refund_star_payment_response_t refund_star_payment_response_t;




typedef struct refund_star_payment_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} refund_star_payment_response_t;

__attribute__((deprecated)) refund_star_payment_response_t *refund_star_payment_response_create(
    int ok,
    int result
);

void refund_star_payment_response_free(refund_star_payment_response_t *refund_star_payment_response);

refund_star_payment_response_t *refund_star_payment_response_parseFromJSON(cJSON *refund_star_payment_responseJSON);

cJSON *refund_star_payment_response_convertToJSON(refund_star_payment_response_t *refund_star_payment_response);

#endif /* _refund_star_payment_response_H_ */

