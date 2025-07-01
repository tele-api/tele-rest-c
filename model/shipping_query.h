/*
 * shipping_query.h
 *
 * This object contains information about an incoming shipping query.
 */

#ifndef _shipping_query_H_
#define _shipping_query_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_query_t shipping_query_t;

#include "shipping_address.h"
#include "user.h"



typedef struct shipping_query_t {
    char *id; // string
    struct user_t *from; //model
    char *invoice_payload; // string
    struct shipping_address_t *shipping_address; //model

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_query_t;

__attribute__((deprecated)) shipping_query_t *shipping_query_create(
    char *id,
    user_t *from,
    char *invoice_payload,
    shipping_address_t *shipping_address
);

void shipping_query_free(shipping_query_t *shipping_query);

shipping_query_t *shipping_query_parseFromJSON(cJSON *shipping_queryJSON);

cJSON *shipping_query_convertToJSON(shipping_query_t *shipping_query);

#endif /* _shipping_query_H_ */

