/*
 * edit_user_star_subscription_request.h
 *
 * Request parameters for editUserStarSubscription
 */

#ifndef _edit_user_star_subscription_request_H_
#define _edit_user_star_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct edit_user_star_subscription_request_t edit_user_star_subscription_request_t;




typedef struct edit_user_star_subscription_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string
    int is_canceled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} edit_user_star_subscription_request_t;

__attribute__((deprecated)) edit_user_star_subscription_request_t *edit_user_star_subscription_request_create(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
);

void edit_user_star_subscription_request_free(edit_user_star_subscription_request_t *edit_user_star_subscription_request);

edit_user_star_subscription_request_t *edit_user_star_subscription_request_parseFromJSON(cJSON *edit_user_star_subscription_requestJSON);

cJSON *edit_user_star_subscription_request_convertToJSON(edit_user_star_subscription_request_t *edit_user_star_subscription_request);

#endif /* _edit_user_star_subscription_request_H_ */

