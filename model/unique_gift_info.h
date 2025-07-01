/*
 * unique_gift_info.h
 *
 * Describes a service message about a unique gift that was sent or received.
 */

#ifndef _unique_gift_info_H_
#define _unique_gift_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unique_gift_info_t unique_gift_info_t;

#include "unique_gift.h"

// Enum ORIGIN for unique_gift_info

typedef enum  { telegram_bot_api_unique_gift_info_ORIGIN_NULL = 0, telegram_bot_api_unique_gift_info_ORIGIN_upgrade, telegram_bot_api_unique_gift_info_ORIGIN_transfer } telegram_bot_api_unique_gift_info_ORIGIN_e;

char* unique_gift_info_origin_ToString(telegram_bot_api_unique_gift_info_ORIGIN_e origin);

telegram_bot_api_unique_gift_info_ORIGIN_e unique_gift_info_origin_FromString(char* origin);



typedef struct unique_gift_info_t {
    struct unique_gift_t *gift; //model
    telegram_bot_api_unique_gift_info_ORIGIN_e origin; //enum
    char *owned_gift_id; // string
    int transfer_star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unique_gift_info_t;

__attribute__((deprecated)) unique_gift_info_t *unique_gift_info_create(
    unique_gift_t *gift,
    telegram_bot_api_unique_gift_info_ORIGIN_e origin,
    char *owned_gift_id,
    int transfer_star_count
);

void unique_gift_info_free(unique_gift_info_t *unique_gift_info);

unique_gift_info_t *unique_gift_info_parseFromJSON(cJSON *unique_gift_infoJSON);

cJSON *unique_gift_info_convertToJSON(unique_gift_info_t *unique_gift_info);

#endif /* _unique_gift_info_H_ */

