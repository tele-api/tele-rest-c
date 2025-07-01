/*
 * star_transactions.h
 *
 * Contains a list of Telegram Star transactions.
 */

#ifndef _star_transactions_H_
#define _star_transactions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct star_transactions_t star_transactions_t;

#include "star_transaction.h"



typedef struct star_transactions_t {
    list_t *transactions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} star_transactions_t;

__attribute__((deprecated)) star_transactions_t *star_transactions_create(
    list_t *transactions
);

void star_transactions_free(star_transactions_t *star_transactions);

star_transactions_t *star_transactions_parseFromJSON(cJSON *star_transactionsJSON);

cJSON *star_transactions_convertToJSON(star_transactions_t *star_transactions);

#endif /* _star_transactions_H_ */

