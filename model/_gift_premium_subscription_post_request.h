/*
 * _gift_premium_subscription_post_request.h
 *
 * 
 */

#ifndef __gift_premium_subscription_post_request_H_
#define __gift_premium_subscription_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _gift_premium_subscription_post_request_t _gift_premium_subscription_post_request_t;

#include "message_entity.h"

// Enum MONTHCOUNT for _gift_premium_subscription_post_request

typedef enum  { telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_NULL = 0, telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT__3, telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT__6, telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT__12 } telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_e;

char* _gift_premium_subscription_post_request_month_count_ToString(telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_e month_count);

telegram_bot_api__gift_premium_subscription_post_request_MONTHCOUNT_e _gift_premium_subscription_post_request_month_count_FromString(char* month_count);



typedef struct _gift_premium_subscription_post_request_t {
    int user_id; //numeric
    int month_count; //numeric
    int star_count; //numeric
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} _gift_premium_subscription_post_request_t;

__attribute__((deprecated)) _gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_create(
    int user_id,
    int month_count,
    int star_count,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void _gift_premium_subscription_post_request_free(_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request);

_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request_parseFromJSON(cJSON *_gift_premium_subscription_post_requestJSON);

cJSON *_gift_premium_subscription_post_request_convertToJSON(_gift_premium_subscription_post_request_t *_gift_premium_subscription_post_request);

#endif /* __gift_premium_subscription_post_request_H_ */

