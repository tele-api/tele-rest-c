/*
 * get_business_account_star_balance_response.h
 *
 * 
 */

#ifndef _get_business_account_star_balance_response_H_
#define _get_business_account_star_balance_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_business_account_star_balance_response_t get_business_account_star_balance_response_t;

#include "star_amount.h"



typedef struct get_business_account_star_balance_response_t {
    int ok; //boolean
    struct star_amount_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_business_account_star_balance_response_t;

__attribute__((deprecated)) get_business_account_star_balance_response_t *get_business_account_star_balance_response_create(
    int ok,
    star_amount_t *result
);

void get_business_account_star_balance_response_free(get_business_account_star_balance_response_t *get_business_account_star_balance_response);

get_business_account_star_balance_response_t *get_business_account_star_balance_response_parseFromJSON(cJSON *get_business_account_star_balance_responseJSON);

cJSON *get_business_account_star_balance_response_convertToJSON(get_business_account_star_balance_response_t *get_business_account_star_balance_response);

#endif /* _get_business_account_star_balance_response_H_ */

