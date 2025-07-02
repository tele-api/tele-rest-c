/*
 * gift_premium_subscription_request.h
 *
 * Request parameters for giftPremiumSubscription
 */

#ifndef _gift_premium_subscription_request_H_
#define _gift_premium_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gift_premium_subscription_request_t gift_premium_subscription_request_t;

#include "message_entity.h"

// Enum MONTHCOUNT for gift_premium_subscription_request

typedef enum  { telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_NULL = 0, telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT__3, telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT__6, telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT__12 } telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_e;

char* gift_premium_subscription_request_month_count_ToString(telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_e month_count);

telegram_bot_api_gift_premium_subscription_request_MONTHCOUNT_e gift_premium_subscription_request_month_count_FromString(char* month_count);



typedef struct gift_premium_subscription_request_t {
    int user_id; //numeric
    int month_count; //numeric
    int star_count; //numeric
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} gift_premium_subscription_request_t;

__attribute__((deprecated)) gift_premium_subscription_request_t *gift_premium_subscription_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void gift_premium_subscription_request_free(gift_premium_subscription_request_t *gift_premium_subscription_request);

gift_premium_subscription_request_t *gift_premium_subscription_request_parseFromJSON(cJSON *gift_premium_subscription_requestJSON);

cJSON *gift_premium_subscription_request_convertToJSON(gift_premium_subscription_request_t *gift_premium_subscription_request);

#endif /* _gift_premium_subscription_request_H_ */

