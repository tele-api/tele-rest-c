/*
 * get_star_transactions_response.h
 *
 * 
 */

#ifndef _get_star_transactions_response_H_
#define _get_star_transactions_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_star_transactions_response_t get_star_transactions_response_t;

#include "star_transactions.h"



typedef struct get_star_transactions_response_t {
    int ok; //boolean
    struct star_transactions_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_star_transactions_response_t;

__attribute__((deprecated)) get_star_transactions_response_t *get_star_transactions_response_create(
    int ok,
    star_transactions_t *result
);

void get_star_transactions_response_free(get_star_transactions_response_t *get_star_transactions_response);

get_star_transactions_response_t *get_star_transactions_response_parseFromJSON(cJSON *get_star_transactions_responseJSON);

cJSON *get_star_transactions_response_convertToJSON(get_star_transactions_response_t *get_star_transactions_response);

#endif /* _get_star_transactions_response_H_ */

