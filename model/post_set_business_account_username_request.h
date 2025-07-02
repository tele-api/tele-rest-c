/*
 * post_set_business_account_username_request.h
 *
 * 
 */

#ifndef _post_set_business_account_username_request_H_
#define _post_set_business_account_username_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_business_account_username_request_t post_set_business_account_username_request_t;




typedef struct post_set_business_account_username_request_t {
    char *business_connection_id; // string
    char *username; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_business_account_username_request_t;

__attribute__((deprecated)) post_set_business_account_username_request_t *post_set_business_account_username_request_create(
    char *business_connection_id,
    char *username
);

void post_set_business_account_username_request_free(post_set_business_account_username_request_t *post_set_business_account_username_request);

post_set_business_account_username_request_t *post_set_business_account_username_request_parseFromJSON(cJSON *post_set_business_account_username_requestJSON);

cJSON *post_set_business_account_username_request_convertToJSON(post_set_business_account_username_request_t *post_set_business_account_username_request);

#endif /* _post_set_business_account_username_request_H_ */

