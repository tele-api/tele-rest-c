/*
 * order_info.h
 *
 * This object represents information about an order.
 */

#ifndef _order_info_H_
#define _order_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_info_t order_info_t;

#include "shipping_address.h"



typedef struct order_info_t {
    char *name; // string
    char *phone_number; // string
    char *email; // string
    struct shipping_address_t *shipping_address; //model

    int _library_owned; // Is the library responsible for freeing this object?
} order_info_t;

__attribute__((deprecated)) order_info_t *order_info_create(
    char *name,
    char *phone_number,
    char *email,
    shipping_address_t *shipping_address
);

void order_info_free(order_info_t *order_info);

order_info_t *order_info_parseFromJSON(cJSON *order_infoJSON);

cJSON *order_info_convertToJSON(order_info_t *order_info);

#endif /* _order_info_H_ */

