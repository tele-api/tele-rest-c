/*
 * _upgrade_gift_post_request.h
 *
 * 
 */

#ifndef __upgrade_gift_post_request_H_
#define __upgrade_gift_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _upgrade_gift_post_request_t _upgrade_gift_post_request_t;




typedef struct _upgrade_gift_post_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int keep_original_details; //boolean
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _upgrade_gift_post_request_t;

__attribute__((deprecated)) _upgrade_gift_post_request_t *_upgrade_gift_post_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int keep_original_details,
    int star_count
);

void _upgrade_gift_post_request_free(_upgrade_gift_post_request_t *_upgrade_gift_post_request);

_upgrade_gift_post_request_t *_upgrade_gift_post_request_parseFromJSON(cJSON *_upgrade_gift_post_requestJSON);

cJSON *_upgrade_gift_post_request_convertToJSON(_upgrade_gift_post_request_t *_upgrade_gift_post_request);

#endif /* __upgrade_gift_post_request_H_ */

