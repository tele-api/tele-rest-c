/*
 * affiliate_info.h
 *
 * Contains information about the affiliate that received a commission via this transaction.
 */

#ifndef _affiliate_info_H_
#define _affiliate_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct affiliate_info_t affiliate_info_t;

#include "chat.h"
#include "user.h"



typedef struct affiliate_info_t {
    int commission_per_mille; //numeric
    int amount; //numeric
    struct user_t *affiliate_user; //model
    struct chat_t *affiliate_chat; //model
    int nanostar_amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} affiliate_info_t;

__attribute__((deprecated)) affiliate_info_t *affiliate_info_create(
    int commission_per_mille,
    int amount,
    user_t *affiliate_user,
    chat_t *affiliate_chat,
    int nanostar_amount
);

void affiliate_info_free(affiliate_info_t *affiliate_info);

affiliate_info_t *affiliate_info_parseFromJSON(cJSON *affiliate_infoJSON);

cJSON *affiliate_info_convertToJSON(affiliate_info_t *affiliate_info);

#endif /* _affiliate_info_H_ */

