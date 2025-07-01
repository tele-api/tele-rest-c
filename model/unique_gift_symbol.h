/*
 * unique_gift_symbol.h
 *
 * This object describes the symbol shown on the pattern of a unique gift.
 */

#ifndef _unique_gift_symbol_H_
#define _unique_gift_symbol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_symbol_t unique_gift_symbol_t;

#include "sticker.h"



typedef struct unique_gift_symbol_t {
    char *name; // string
    struct sticker_t *sticker; //model
    int rarity_per_mille; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_symbol_t;

__attribute__((deprecated)) unique_gift_symbol_t *unique_gift_symbol_create(
    char *name,
    sticker_t *sticker,
    int rarity_per_mille
);

void unique_gift_symbol_free(unique_gift_symbol_t *unique_gift_symbol);

unique_gift_symbol_t *unique_gift_symbol_parseFromJSON(cJSON *unique_gift_symbolJSON);

cJSON *unique_gift_symbol_convertToJSON(unique_gift_symbol_t *unique_gift_symbol);

#endif /* _unique_gift_symbol_H_ */

