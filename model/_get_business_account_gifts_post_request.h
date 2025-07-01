/*
 * _get_business_account_gifts_post_request.h
 *
 * 
 */

#ifndef __get_business_account_gifts_post_request_H_
#define __get_business_account_gifts_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_business_account_gifts_post_request_t _get_business_account_gifts_post_request_t;




typedef struct _get_business_account_gifts_post_request_t {
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
} _get_business_account_gifts_post_request_t;

__attribute__((deprecated)) _get_business_account_gifts_post_request_t *_get_business_account_gifts_post_request_create(
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

void _get_business_account_gifts_post_request_free(_get_business_account_gifts_post_request_t *_get_business_account_gifts_post_request);

_get_business_account_gifts_post_request_t *_get_business_account_gifts_post_request_parseFromJSON(cJSON *_get_business_account_gifts_post_requestJSON);

cJSON *_get_business_account_gifts_post_request_convertToJSON(_get_business_account_gifts_post_request_t *_get_business_account_gifts_post_request);

#endif /* __get_business_account_gifts_post_request_H_ */

