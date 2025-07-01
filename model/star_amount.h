/*
 * star_amount.h
 *
 * Describes an amount of Telegram Stars.
 */

#ifndef _star_amount_H_
#define _star_amount_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct star_amount_t star_amount_t;




typedef struct star_amount_t {
    int amount; //numeric
    int nanostar_amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} star_amount_t;

__attribute__((deprecated)) star_amount_t *star_amount_create(
    int amount,
    int nanostar_amount
);

void star_amount_free(star_amount_t *star_amount);

star_amount_t *star_amount_parseFromJSON(cJSON *star_amountJSON);

cJSON *star_amount_convertToJSON(star_amount_t *star_amount);

#endif /* _star_amount_H_ */

