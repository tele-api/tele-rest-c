/*
 * set_business_account_bio_response.h
 *
 * 
 */

#ifndef _set_business_account_bio_response_H_
#define _set_business_account_bio_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_business_account_bio_response_t set_business_account_bio_response_t;




typedef struct set_business_account_bio_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_business_account_bio_response_t;

__attribute__((deprecated)) set_business_account_bio_response_t *set_business_account_bio_response_create(
    int ok,
    int result
);

void set_business_account_bio_response_free(set_business_account_bio_response_t *set_business_account_bio_response);

set_business_account_bio_response_t *set_business_account_bio_response_parseFromJSON(cJSON *set_business_account_bio_responseJSON);

cJSON *set_business_account_bio_response_convertToJSON(set_business_account_bio_response_t *set_business_account_bio_response);

#endif /* _set_business_account_bio_response_H_ */

