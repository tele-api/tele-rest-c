/*
 * transaction_partner_user.h
 *
 * Describes a transaction with a user.
 */

#ifndef _transaction_partner_user_H_
#define _transaction_partner_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_user_t transaction_partner_user_t;

#include "affiliate_info.h"
#include "gift.h"
#include "paid_media.h"
#include "user.h"

// Enum TRANSACTIONTYPE for transaction_partner_user

typedef enum  { telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_NULL = 0, telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_invoice_payment, telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_paid_media_payment, telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_gift_purchase, telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_premium_purchase, telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_business_account_transfer } telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e;

char* transaction_partner_user_transaction_type_ToString(telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type);

telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_partner_user_transaction_type_FromString(char* transaction_type);



typedef struct transaction_partner_user_t {
    char *type; // string
    telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type; //enum
    struct user_t *user; //model
    struct affiliate_info_t *affiliate; //model
    char *invoice_payload; // string
    int subscription_period; //numeric
    list_t *paid_media; //nonprimitive container
    char *paid_media_payload; // string
    struct gift_t *gift; //model
    int premium_subscription_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_user_t;

__attribute__((deprecated)) transaction_partner_user_t *transaction_partner_user_create(
    char *type,
    telegram_bot_api_transaction_partner_user_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration
);

void transaction_partner_user_free(transaction_partner_user_t *transaction_partner_user);

transaction_partner_user_t *transaction_partner_user_parseFromJSON(cJSON *transaction_partner_userJSON);

cJSON *transaction_partner_user_convertToJSON(transaction_partner_user_t *transaction_partner_user);

#endif /* _transaction_partner_user_H_ */

