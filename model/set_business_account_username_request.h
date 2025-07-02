/*
 * set_business_account_username_request.h
 *
 * Request parameters for setBusinessAccountUsername
 */

#ifndef _set_business_account_username_request_H_
#define _set_business_account_username_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_business_account_username_request_t set_business_account_username_request_t;




typedef struct set_business_account_username_request_t {
    char *business_connection_id; // string
    char *username; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_business_account_username_request_t;

__attribute__((deprecated)) set_business_account_username_request_t *set_business_account_username_request_create(
    char *business_connection_id,
    char *username
);

void set_business_account_username_request_free(set_business_account_username_request_t *set_business_account_username_request);

set_business_account_username_request_t *set_business_account_username_request_parseFromJSON(cJSON *set_business_account_username_requestJSON);

cJSON *set_business_account_username_request_convertToJSON(set_business_account_username_request_t *set_business_account_username_request);

#endif /* _set_business_account_username_request_H_ */

