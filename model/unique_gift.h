/*
 * unique_gift.h
 *
 * This object describes a unique gift that was upgraded from a regular gift.
 */

#ifndef _unique_gift_H_
#define _unique_gift_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_t unique_gift_t;

#include "unique_gift_backdrop.h"
#include "unique_gift_model.h"
#include "unique_gift_symbol.h"



typedef struct unique_gift_t {
    char *base_name; // string
    char *name; // string
    int number; //numeric
    struct unique_gift_model_t *model; //model
    struct unique_gift_symbol_t *symbol; //model
    struct unique_gift_backdrop_t *backdrop; //model

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_t;

__attribute__((deprecated)) unique_gift_t *unique_gift_create(
    char *base_name,
    char *name,
    int number,
    unique_gift_model_t *model,
    unique_gift_symbol_t *symbol,
    unique_gift_backdrop_t *backdrop
);

void unique_gift_free(unique_gift_t *unique_gift);

unique_gift_t *unique_gift_parseFromJSON(cJSON *unique_giftJSON);

cJSON *unique_gift_convertToJSON(unique_gift_t *unique_gift);

#endif /* _unique_gift_H_ */

