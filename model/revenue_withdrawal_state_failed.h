/*
 * revenue_withdrawal_state_failed.h
 *
 * The withdrawal failed and the transaction was refunded.
 */

#ifndef _revenue_withdrawal_state_failed_H_
#define _revenue_withdrawal_state_failed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revenue_withdrawal_state_failed_t revenue_withdrawal_state_failed_t;




typedef struct revenue_withdrawal_state_failed_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revenue_withdrawal_state_failed_t;

__attribute__((deprecated)) revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_create(
    char *type
);

void revenue_withdrawal_state_failed_free(revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed);

revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed_parseFromJSON(cJSON *revenue_withdrawal_state_failedJSON);

cJSON *revenue_withdrawal_state_failed_convertToJSON(revenue_withdrawal_state_failed_t *revenue_withdrawal_state_failed);

#endif /* _revenue_withdrawal_state_failed_H_ */

