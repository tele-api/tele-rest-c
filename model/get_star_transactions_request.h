/*
 * get_star_transactions_request.h
 *
 * Request parameters for getStarTransactions
 */

#ifndef _get_star_transactions_request_H_
#define _get_star_transactions_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_star_transactions_request_t get_star_transactions_request_t;




typedef struct get_star_transactions_request_t {
    int offset; //numeric
    int limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_star_transactions_request_t;

__attribute__((deprecated)) get_star_transactions_request_t *get_star_transactions_request_create(
    int offset,
    int limit
);

void get_star_transactions_request_free(get_star_transactions_request_t *get_star_transactions_request);

get_star_transactions_request_t *get_star_transactions_request_parseFromJSON(cJSON *get_star_transactions_requestJSON);

cJSON *get_star_transactions_request_convertToJSON(get_star_transactions_request_t *get_star_transactions_request);

#endif /* _get_star_transactions_request_H_ */

