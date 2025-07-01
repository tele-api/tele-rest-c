/*
 * transaction_partner.h
 *
 * This object describes the source of a transaction, or its recipient for outgoing transactions. Currently, it can be one of  * [TransactionPartnerUser](https://core.telegram.org/bots/api/#transactionpartneruser) * [TransactionPartnerChat](https://core.telegram.org/bots/api/#transactionpartnerchat) * [TransactionPartnerAffiliateProgram](https://core.telegram.org/bots/api/#transactionpartneraffiliateprogram) * [TransactionPartnerFragment](https://core.telegram.org/bots/api/#transactionpartnerfragment) * [TransactionPartnerTelegramAds](https://core.telegram.org/bots/api/#transactionpartnertelegramads) * [TransactionPartnerTelegramApi](https://core.telegram.org/bots/api/#transactionpartnertelegramapi) * [TransactionPartnerOther](https://core.telegram.org/bots/api/#transactionpartnerother)
 */

#ifndef _transaction_partner_H_
#define _transaction_partner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transaction_partner_t transaction_partner_t;

#include "affiliate_info.h"
#include "chat.h"
#include "gift.h"
#include "paid_media.h"
#include "revenue_withdrawal_state.h"
#include "transaction_partner_affiliate_program.h"
#include "transaction_partner_chat.h"
#include "transaction_partner_fragment.h"
#include "transaction_partner_other.h"
#include "transaction_partner_telegram_ads.h"
#include "transaction_partner_telegram_api.h"
#include "transaction_partner_user.h"
#include "user.h"

// Enum TRANSACTIONTYPE for transaction_partner

typedef enum  { telegram_bot_api_transaction_partner_TRANSACTIONTYPE_NULL = 0, telegram_bot_api_transaction_partner_TRANSACTIONTYPE_invoice_payment, telegram_bot_api_transaction_partner_TRANSACTIONTYPE_paid_media_payment, telegram_bot_api_transaction_partner_TRANSACTIONTYPE_gift_purchase, telegram_bot_api_transaction_partner_TRANSACTIONTYPE_premium_purchase, telegram_bot_api_transaction_partner_TRANSACTIONTYPE_business_account_transfer } telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e;

char* transaction_partner_transaction_type_ToString(telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type);

telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_partner_transaction_type_FromString(char* transaction_type);



typedef struct transaction_partner_t {
    char *type; // string
    telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type; //enum
    struct user_t *user; //model
    struct chat_t *chat; //model
    int commission_per_mille; //numeric
    int request_count; //numeric
    struct affiliate_info_t *affiliate; //model
    char *invoice_payload; // string
    int subscription_period; //numeric
    list_t *paid_media; //nonprimitive container
    char *paid_media_payload; // string
    struct gift_t *gift; //model
    int premium_subscription_duration; //numeric
    struct user_t *sponsor_user; //model
    struct revenue_withdrawal_state_t *withdrawal_state; //model

    int _library_owned; // Is the library responsible for freeing this object?
} transaction_partner_t;

__attribute__((deprecated)) transaction_partner_t *transaction_partner_create(
    char *type,
    telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e transaction_type,
    user_t *user,
    chat_t *chat,
    int commission_per_mille,
    int request_count,
    affiliate_info_t *affiliate,
    char *invoice_payload,
    int subscription_period,
    list_t *paid_media,
    char *paid_media_payload,
    gift_t *gift,
    int premium_subscription_duration,
    user_t *sponsor_user,
    revenue_withdrawal_state_t *withdrawal_state
);

void transaction_partner_free(transaction_partner_t *transaction_partner);

transaction_partner_t *transaction_partner_parseFromJSON(cJSON *transaction_partnerJSON);

cJSON *transaction_partner_convertToJSON(transaction_partner_t *transaction_partner);

#endif /* _transaction_partner_H_ */

