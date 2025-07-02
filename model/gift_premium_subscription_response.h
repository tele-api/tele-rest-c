/*
 * gift_premium_subscription_response.h
 *
 * 
 */

#ifndef _gift_premium_subscription_response_H_
#define _gift_premium_subscription_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gift_premium_subscription_response_t gift_premium_subscription_response_t;




typedef struct gift_premium_subscription_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} gift_premium_subscription_response_t;

__attribute__((deprecated)) gift_premium_subscription_response_t *gift_premium_subscription_response_create(
    int ok,
    int result
);

void gift_premium_subscription_response_free(gift_premium_subscription_response_t *gift_premium_subscription_response);

gift_premium_subscription_response_t *gift_premium_subscription_response_parseFromJSON(cJSON *gift_premium_subscription_responseJSON);

cJSON *gift_premium_subscription_response_convertToJSON(gift_premium_subscription_response_t *gift_premium_subscription_response);

#endif /* _gift_premium_subscription_response_H_ */

