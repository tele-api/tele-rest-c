/*
 * transaction_partner_other.h
 *
 * Describes a transaction with an unknown source or recipient.
 */

#ifndef _transaction_partner_other_H_
#define _transaction_partner_other_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_other_t transaction_partner_other_t;




typedef struct transaction_partner_other_t {
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_other_t;

__attribute__((deprecated)) transaction_partner_other_t *transaction_partner_other_create(
    char *type
);

void transaction_partner_other_free(transaction_partner_other_t *transaction_partner_other);

transaction_partner_other_t *transaction_partner_other_parseFromJSON(cJSON *transaction_partner_otherJSON);

cJSON *transaction_partner_other_convertToJSON(transaction_partner_other_t *transaction_partner_other);

#endif /* _transaction_partner_other_H_ */

