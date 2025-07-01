/*
 * _transfer_business_account_stars_post_request.h
 *
 * 
 */

#ifndef __transfer_business_account_stars_post_request_H_
#define __transfer_business_account_stars_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _transfer_business_account_stars_post_request_t _transfer_business_account_stars_post_request_t;




typedef struct _transfer_business_account_stars_post_request_t {
    char *business_connection_id; // string
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _transfer_business_account_stars_post_request_t;

__attribute__((deprecated)) _transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_create(
    char *business_connection_id,
    int star_count
);

void _transfer_business_account_stars_post_request_free(_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request);

_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request_parseFromJSON(cJSON *_transfer_business_account_stars_post_requestJSON);

cJSON *_transfer_business_account_stars_post_request_convertToJSON(_transfer_business_account_stars_post_request_t *_transfer_business_account_stars_post_request);

#endif /* __transfer_business_account_stars_post_request_H_ */

