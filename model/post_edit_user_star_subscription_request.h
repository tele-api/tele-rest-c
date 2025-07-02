/*
 * post_edit_user_star_subscription_request.h
 *
 * 
 */

#ifndef _post_edit_user_star_subscription_request_H_
#define _post_edit_user_star_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_edit_user_star_subscription_request_t post_edit_user_star_subscription_request_t;




typedef struct post_edit_user_star_subscription_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string
    int is_canceled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_edit_user_star_subscription_request_t;

__attribute__((deprecated)) post_edit_user_star_subscription_request_t *post_edit_user_star_subscription_request_create(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
);

void post_edit_user_star_subscription_request_free(post_edit_user_star_subscription_request_t *post_edit_user_star_subscription_request);

post_edit_user_star_subscription_request_t *post_edit_user_star_subscription_request_parseFromJSON(cJSON *post_edit_user_star_subscription_requestJSON);

cJSON *post_edit_user_star_subscription_request_convertToJSON(post_edit_user_star_subscription_request_t *post_edit_user_star_subscription_request);

#endif /* _post_edit_user_star_subscription_request_H_ */

