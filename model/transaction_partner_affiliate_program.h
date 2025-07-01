/*
 * transaction_partner_affiliate_program.h
 *
 * Describes the affiliate program that issued the affiliate commission received via this transaction.
 */

#ifndef _transaction_partner_affiliate_program_H_
#define _transaction_partner_affiliate_program_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_affiliate_program_t transaction_partner_affiliate_program_t;

#include "user.h"



typedef struct transaction_partner_affiliate_program_t {
    char *type; // string
    int commission_per_mille; //numeric
    struct user_t *sponsor_user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_affiliate_program_t;

__attribute__((deprecated)) transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_create(
    char *type,
    int commission_per_mille,
    user_t *sponsor_user
);

void transaction_partner_affiliate_program_free(transaction_partner_affiliate_program_t *transaction_partner_affiliate_program);

transaction_partner_affiliate_program_t *transaction_partner_affiliate_program_parseFromJSON(cJSON *transaction_partner_affiliate_programJSON);

cJSON *transaction_partner_affiliate_program_convertToJSON(transaction_partner_affiliate_program_t *transaction_partner_affiliate_program);

#endif /* _transaction_partner_affiliate_program_H_ */

