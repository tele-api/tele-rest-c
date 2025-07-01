/*
 * revenue_withdrawal_state_pending.h
 *
 * The withdrawal is in progress.
 */

#ifndef _revenue_withdrawal_state_pending_H_
#define _revenue_withdrawal_state_pending_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revenue_withdrawal_state_pending_t revenue_withdrawal_state_pending_t;




typedef struct revenue_withdrawal_state_pending_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revenue_withdrawal_state_pending_t;

__attribute__((deprecated)) revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_create(
    char *type
);

void revenue_withdrawal_state_pending_free(revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending);

revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending_parseFromJSON(cJSON *revenue_withdrawal_state_pendingJSON);

cJSON *revenue_withdrawal_state_pending_convertToJSON(revenue_withdrawal_state_pending_t *revenue_withdrawal_state_pending);

#endif /* _revenue_withdrawal_state_pending_H_ */

