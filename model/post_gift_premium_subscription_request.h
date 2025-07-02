/*
 * post_gift_premium_subscription_request.h
 *
 * 
 */

#ifndef _post_gift_premium_subscription_request_H_
#define _post_gift_premium_subscription_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_gift_premium_subscription_request_t post_gift_premium_subscription_request_t;

#include "message_entity.h"

// Enum MONTHCOUNT for post_gift_premium_subscription_request

typedef enum  { telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_NULL = 0, telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT__3, telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT__6, telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT__12 } telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_e;

char* post_gift_premium_subscription_request_month_count_ToString(telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_e month_count);

telegram_bot_api_post_gift_premium_subscription_request_MONTHCOUNT_e post_gift_premium_subscription_request_month_count_FromString(char* month_count);



typedef struct post_gift_premium_subscription_request_t {
    int user_id; //numeric
    int month_count; //numeric
    int star_count; //numeric
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_gift_premium_subscription_request_t;

__attribute__((deprecated)) post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void post_gift_premium_subscription_request_free(post_gift_premium_subscription_request_t *post_gift_premium_subscription_request);

post_gift_premium_subscription_request_t *post_gift_premium_subscription_request_parseFromJSON(cJSON *post_gift_premium_subscription_requestJSON);

cJSON *post_gift_premium_subscription_request_convertToJSON(post_gift_premium_subscription_request_t *post_gift_premium_subscription_request);

#endif /* _post_gift_premium_subscription_request_H_ */

