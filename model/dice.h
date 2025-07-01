/*
 * dice.h
 *
 * This object represents an animated emoji that displays a random value.
 */

#ifndef _dice_H_
#define _dice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dice_t dice_t;




typedef struct dice_t {
    char *emoji; // string
    int value; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} dice_t;

__attribute__((deprecated)) dice_t *dice_create(
    char *emoji,
    int value
);

void dice_free(dice_t *dice);

dice_t *dice_parseFromJSON(cJSON *diceJSON);

cJSON *dice_convertToJSON(dice_t *dice);

#endif /* _dice_H_ */

