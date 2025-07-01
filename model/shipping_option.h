/*
 * shipping_option.h
 *
 * This object represents one shipping option.
 */

#ifndef _shipping_option_H_
#define _shipping_option_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shipping_option_t shipping_option_t;

#include "labeled_price.h"



typedef struct shipping_option_t {
    char *id; // string
    char *title; // string
    list_t *prices; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} shipping_option_t;

__attribute__((deprecated)) shipping_option_t *shipping_option_create(
    char *id,
    char *title,
    list_t *prices
);

void shipping_option_free(shipping_option_t *shipping_option);

shipping_option_t *shipping_option_parseFromJSON(cJSON *shipping_optionJSON);

cJSON *shipping_option_convertToJSON(shipping_option_t *shipping_option);

#endif /* _shipping_option_H_ */

