/*
 * transaction_partner_fragment.h
 *
 * Describes a withdrawal transaction with Fragment.
 */

#ifndef _transaction_partner_fragment_H_
#define _transaction_partner_fragment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_fragment_t transaction_partner_fragment_t;

#include "revenue_withdrawal_state.h"



typedef struct transaction_partner_fragment_t {
    char *type; // string
    struct revenue_withdrawal_state_t *withdrawal_state; //model

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_fragment_t;

__attribute__((deprecated)) transaction_partner_fragment_t *transaction_partner_fragment_create(
    char *type,
    revenue_withdrawal_state_t *withdrawal_state
);

void transaction_partner_fragment_free(transaction_partner_fragment_t *transaction_partner_fragment);

transaction_partner_fragment_t *transaction_partner_fragment_parseFromJSON(cJSON *transaction_partner_fragmentJSON);

cJSON *transaction_partner_fragment_convertToJSON(transaction_partner_fragment_t *transaction_partner_fragment);

#endif /* _transaction_partner_fragment_H_ */

