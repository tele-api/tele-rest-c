/*
 * upgrade_gift_request.h
 *
 * Request parameters for upgradeGift
 */

#ifndef _upgrade_gift_request_H_
#define _upgrade_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upgrade_gift_request_t upgrade_gift_request_t;




typedef struct upgrade_gift_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int keep_original_details; //boolean
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} upgrade_gift_request_t;

__attribute__((deprecated)) upgrade_gift_request_t *upgrade_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
);

void upgrade_gift_request_free(upgrade_gift_request_t *upgrade_gift_request);

upgrade_gift_request_t *upgrade_gift_request_parseFromJSON(cJSON *upgrade_gift_requestJSON);

cJSON *upgrade_gift_request_convertToJSON(upgrade_gift_request_t *upgrade_gift_request);

#endif /* _upgrade_gift_request_H_ */

