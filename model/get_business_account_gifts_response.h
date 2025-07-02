/*
 * get_business_account_gifts_response.h
 *
 * 
 */

#ifndef _get_business_account_gifts_response_H_
#define _get_business_account_gifts_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_business_account_gifts_response_t get_business_account_gifts_response_t;

#include "owned_gifts.h"



typedef struct get_business_account_gifts_response_t {
    int ok; //boolean
    struct owned_gifts_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_business_account_gifts_response_t;

__attribute__((deprecated)) get_business_account_gifts_response_t *get_business_account_gifts_response_create(
    int ok,
    owned_gifts_t *result
);

void get_business_account_gifts_response_free(get_business_account_gifts_response_t *get_business_account_gifts_response);

get_business_account_gifts_response_t *get_business_account_gifts_response_parseFromJSON(cJSON *get_business_account_gifts_responseJSON);

cJSON *get_business_account_gifts_response_convertToJSON(get_business_account_gifts_response_t *get_business_account_gifts_response);

#endif /* _get_business_account_gifts_response_H_ */

