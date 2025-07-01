/*
 * revenue_withdrawal_state.h
 *
 * This object describes the state of a revenue withdrawal operation. Currently, it can be one of  * [RevenueWithdrawalStatePending](https://core.telegram.org/bots/api/#revenuewithdrawalstatepending) * [RevenueWithdrawalStateSucceeded](https://core.telegram.org/bots/api/#revenuewithdrawalstatesucceeded) * [RevenueWithdrawalStateFailed](https://core.telegram.org/bots/api/#revenuewithdrawalstatefailed)
 */

#ifndef _revenue_withdrawal_state_H_
#define _revenue_withdrawal_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct revenue_withdrawal_state_t revenue_withdrawal_state_t;

#include "revenue_withdrawal_state_failed.h"
#include "revenue_withdrawal_state_pending.h"
#include "revenue_withdrawal_state_succeeded.h"



typedef struct revenue_withdrawal_state_t {
    char *type; // string
    int date; //numeric
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} revenue_withdrawal_state_t;

__attribute__((deprecated)) revenue_withdrawal_state_t *revenue_withdrawal_state_create(
    char *type,
    int date,
    char *url
);

void revenue_withdrawal_state_free(revenue_withdrawal_state_t *revenue_withdrawal_state);

revenue_withdrawal_state_t *revenue_withdrawal_state_parseFromJSON(cJSON *revenue_withdrawal_stateJSON);

cJSON *revenue_withdrawal_state_convertToJSON(revenue_withdrawal_state_t *revenue_withdrawal_state);

#endif /* _revenue_withdrawal_state_H_ */

