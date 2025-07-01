/*
 * business_intro.h
 *
 * Contains information about the start page settings of a Telegram Business account.
 */

#ifndef _business_intro_H_
#define _business_intro_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct business_intro_t business_intro_t;

#include "sticker.h"



typedef struct business_intro_t {
    char *title; // string
    char *message; // string
    struct sticker_t *sticker; //model

    int _library_owned; // Is the library responsible for freeing this object?
} business_intro_t;

__attribute__((deprecated)) business_intro_t *business_intro_create(
    char *title,
    char *message,
    sticker_t *sticker
);

void business_intro_free(business_intro_t *business_intro);

business_intro_t *business_intro_parseFromJSON(cJSON *business_introJSON);

cJSON *business_intro_convertToJSON(business_intro_t *business_intro);

#endif /* _business_intro_H_ */

