/*
 * transfer_business_account_stars_request.h
 *
 * Request parameters for transferBusinessAccountStars
 */

#ifndef _transfer_business_account_stars_request_H_
#define _transfer_business_account_stars_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transfer_business_account_stars_request_t transfer_business_account_stars_request_t;




typedef struct transfer_business_account_stars_request_t {
    char *business_connection_id; // string
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} transfer_business_account_stars_request_t;

__attribute__((deprecated)) transfer_business_account_stars_request_t *transfer_business_account_stars_request_create(
    char *business_connection_id,
    int star_count
);

void transfer_business_account_stars_request_free(transfer_business_account_stars_request_t *transfer_business_account_stars_request);

transfer_business_account_stars_request_t *transfer_business_account_stars_request_parseFromJSON(cJSON *transfer_business_account_stars_requestJSON);

cJSON *transfer_business_account_stars_request_convertToJSON(transfer_business_account_stars_request_t *transfer_business_account_stars_request);

#endif /* _transfer_business_account_stars_request_H_ */

