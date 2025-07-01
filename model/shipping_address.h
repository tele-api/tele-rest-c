/*
 * shipping_address.h
 *
 * This object represents a shipping address.
 */

#ifndef _shipping_address_H_
#define _shipping_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_address_t shipping_address_t;




typedef struct shipping_address_t {
    char *country_code; // string
    char *state; // string
    char *city; // string
    char *street_line1; // string
    char *street_line2; // string
    char *post_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_address_t;

__attribute__((deprecated)) shipping_address_t *shipping_address_create(
    char *country_code,
    char *state,
    char *city,
    char *street_line1,
    char *street_line2,
    char *post_code
);

void shipping_address_free(shipping_address_t *shipping_address);

shipping_address_t *shipping_address_parseFromJSON(cJSON *shipping_addressJSON);

cJSON *shipping_address_convertToJSON(shipping_address_t *shipping_address);

#endif /* _shipping_address_H_ */

