/*
 * _edit_user_star_subscription_post_request.h
 *
 * 
 */

#ifndef __edit_user_star_subscription_post_request_H_
#define __edit_user_star_subscription_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _edit_user_star_subscription_post_request_t _edit_user_star_subscription_post_request_t;




typedef struct _edit_user_star_subscription_post_request_t {
    int user_id; //numeric
    char *telegram_payment_charge_id; // string
    int is_canceled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} _edit_user_star_subscription_post_request_t;

__attribute__((deprecated)) _edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_create(
    int user_id,
    char *telegram_payment_charge_id,
    int is_canceled
);

void _edit_user_star_subscription_post_request_free(_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request);

_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request_parseFromJSON(cJSON *_edit_user_star_subscription_post_requestJSON);

cJSON *_edit_user_star_subscription_post_request_convertToJSON(_edit_user_star_subscription_post_request_t *_edit_user_star_subscription_post_request);

#endif /* __edit_user_star_subscription_post_request_H_ */

