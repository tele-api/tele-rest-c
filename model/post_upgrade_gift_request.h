/*
 * post_upgrade_gift_request.h
 *
 * 
 */

#ifndef _post_upgrade_gift_request_H_
#define _post_upgrade_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_upgrade_gift_request_t post_upgrade_gift_request_t;




typedef struct post_upgrade_gift_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int keep_original_details; //boolean
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_upgrade_gift_request_t;

__attribute__((deprecated)) post_upgrade_gift_request_t *post_upgrade_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
);

void post_upgrade_gift_request_free(post_upgrade_gift_request_t *post_upgrade_gift_request);

post_upgrade_gift_request_t *post_upgrade_gift_request_parseFromJSON(cJSON *post_upgrade_gift_requestJSON);

cJSON *post_upgrade_gift_request_convertToJSON(post_upgrade_gift_request_t *post_upgrade_gift_request);

#endif /* _post_upgrade_gift_request_H_ */

