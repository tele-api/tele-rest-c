/*
 * post_get_business_account_gifts_request.h
 *
 * 
 */

#ifndef _post_get_business_account_gifts_request_H_
#define _post_get_business_account_gifts_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_business_account_gifts_request_t post_get_business_account_gifts_request_t;




typedef struct post_get_business_account_gifts_request_t {
    char *business_connection_id; // string
    int exclude_unsaved; //boolean
    int exclude_saved; //boolean
    int exclude_unlimited; //boolean
    int exclude_limited; //boolean
    int exclude_unique; //boolean
    int sort_by_price; //boolean
    char *offset; // string
    int limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_business_account_gifts_request_t;

__attribute__((deprecated)) post_get_business_account_gifts_request_t *post_get_business_account_gifts_request_create(
    char *business_connection_id,
    int exclude_unsaved,
    int exclude_saved,
    int exclude_unlimited,
    int exclude_limited,
    int exclude_unique,
    int sort_by_price,
    char *offset,
    int limit
);

void post_get_business_account_gifts_request_free(post_get_business_account_gifts_request_t *post_get_business_account_gifts_request);

post_get_business_account_gifts_request_t *post_get_business_account_gifts_request_parseFromJSON(cJSON *post_get_business_account_gifts_requestJSON);

cJSON *post_get_business_account_gifts_request_convertToJSON(post_get_business_account_gifts_request_t *post_get_business_account_gifts_request);

#endif /* _post_get_business_account_gifts_request_H_ */

