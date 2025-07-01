/*
 * labeled_price.h
 *
 * This object represents a portion of the price for goods or services.
 */

#ifndef _labeled_price_H_
#define _labeled_price_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct labeled_price_t labeled_price_t;




typedef struct labeled_price_t {
    char *label; // string
    int amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} labeled_price_t;

__attribute__((deprecated)) labeled_price_t *labeled_price_create(
    char *label,
    int amount
);

void labeled_price_free(labeled_price_t *labeled_price);

labeled_price_t *labeled_price_parseFromJSON(cJSON *labeled_priceJSON);

cJSON *labeled_price_convertToJSON(labeled_price_t *labeled_price);

#endif /* _labeled_price_H_ */

