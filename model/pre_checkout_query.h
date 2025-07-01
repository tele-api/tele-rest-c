/*
 * pre_checkout_query.h
 *
 * This object contains information about an incoming pre-checkout query.
 */

#ifndef _pre_checkout_query_H_
#define _pre_checkout_query_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pre_checkout_query_t pre_checkout_query_t;

#include "order_info.h"
#include "user.h"



typedef struct pre_checkout_query_t {
    char *id; // string
    struct user_t *from; //model
    char *currency; // string
    int total_amount; //numeric
    char *invoice_payload; // string
    char *shipping_option_id; // string
    struct order_info_t *order_info; //model

    int _library_owned; // Is the library responsible for freeing this object?
} pre_checkout_query_t;

__attribute__((deprecated)) pre_checkout_query_t *pre_checkout_query_create(
    char *id,
    user_t *from,
    char *currency,
    int total_amount,
    char *invoice_payload,
    char *shipping_option_id,
    order_info_t *order_info
);

void pre_checkout_query_free(pre_checkout_query_t *pre_checkout_query);

pre_checkout_query_t *pre_checkout_query_parseFromJSON(cJSON *pre_checkout_queryJSON);

cJSON *pre_checkout_query_convertToJSON(pre_checkout_query_t *pre_checkout_query);

#endif /* _pre_checkout_query_H_ */

