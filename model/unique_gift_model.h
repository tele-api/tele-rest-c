/*
 * unique_gift_model.h
 *
 * This object describes the model of a unique gift.
 */

#ifndef _unique_gift_model_H_
#define _unique_gift_model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_model_t unique_gift_model_t;

#include "sticker.h"



typedef struct unique_gift_model_t {
    char *name; // string
    struct sticker_t *sticker; //model
    int rarity_per_mille; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_model_t;

__attribute__((deprecated)) unique_gift_model_t *unique_gift_model_create(
    char *name,
    sticker_t *sticker,
    int rarity_per_mille
);

void unique_gift_model_free(unique_gift_model_t *unique_gift_model);

unique_gift_model_t *unique_gift_model_parseFromJSON(cJSON *unique_gift_modelJSON);

cJSON *unique_gift_model_convertToJSON(unique_gift_model_t *unique_gift_model);

#endif /* _unique_gift_model_H_ */

