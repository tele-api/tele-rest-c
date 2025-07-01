/*
 * revenue_withdrawal_state_succeeded.h
 *
 * The withdrawal succeeded.
 */

#ifndef _revenue_withdrawal_state_succeeded_H_
#define _revenue_withdrawal_state_succeeded_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revenue_withdrawal_state_succeeded_t revenue_withdrawal_state_succeeded_t;




typedef struct revenue_withdrawal_state_succeeded_t {
    char *type; // string
    int date; //numeric
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revenue_withdrawal_state_succeeded_t;

__attribute__((deprecated)) revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_create(
    char *type,
    int date,
    char *url
);

void revenue_withdrawal_state_succeeded_free(revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded);

revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded_parseFromJSON(cJSON *revenue_withdrawal_state_succeededJSON);

cJSON *revenue_withdrawal_state_succeeded_convertToJSON(revenue_withdrawal_state_succeeded_t *revenue_withdrawal_state_succeeded);

#endif /* _revenue_withdrawal_state_succeeded_H_ */

