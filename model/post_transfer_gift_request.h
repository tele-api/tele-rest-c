/*
 * post_transfer_gift_request.h
 *
 * 
 */

#ifndef _post_transfer_gift_request_H_
#define _post_transfer_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_transfer_gift_request_t post_transfer_gift_request_t;




typedef struct post_transfer_gift_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int new_owner_chat_id; //numeric
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} post_transfer_gift_request_t;

__attribute__((deprecated)) post_transfer_gift_request_t *post_transfer_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int new_owner_chat_id,
    int star_count
);

void post_transfer_gift_request_free(post_transfer_gift_request_t *post_transfer_gift_request);

post_transfer_gift_request_t *post_transfer_gift_request_parseFromJSON(cJSON *post_transfer_gift_requestJSON);

cJSON *post_transfer_gift_request_convertToJSON(post_transfer_gift_request_t *post_transfer_gift_request);

#endif /* _post_transfer_gift_request_H_ */

