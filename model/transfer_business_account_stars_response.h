/*
 * transfer_business_account_stars_response.h
 *
 * 
 */

#ifndef _transfer_business_account_stars_response_H_
#define _transfer_business_account_stars_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transfer_business_account_stars_response_t transfer_business_account_stars_response_t;




typedef struct transfer_business_account_stars_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} transfer_business_account_stars_response_t;

__attribute__((deprecated)) transfer_business_account_stars_response_t *transfer_business_account_stars_response_create(
    int ok,
    int result
);

void transfer_business_account_stars_response_free(transfer_business_account_stars_response_t *transfer_business_account_stars_response);

transfer_business_account_stars_response_t *transfer_business_account_stars_response_parseFromJSON(cJSON *transfer_business_account_stars_responseJSON);

cJSON *transfer_business_account_stars_response_convertToJSON(transfer_business_account_stars_response_t *transfer_business_account_stars_response);

#endif /* _transfer_business_account_stars_response_H_ */

