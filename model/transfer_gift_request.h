/*
 * transfer_gift_request.h
 *
 * Request parameters for transferGift
 */

#ifndef _transfer_gift_request_H_
#define _transfer_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct transfer_gift_request_t transfer_gift_request_t;




typedef struct transfer_gift_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int new_owner_chat_id; //numeric
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} transfer_gift_request_t;

__attribute__((deprecated)) transfer_gift_request_t *transfer_gift_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int new_owner_chat_id,
    int star_count
);

void transfer_gift_request_free(transfer_gift_request_t *transfer_gift_request);

transfer_gift_request_t *transfer_gift_request_parseFromJSON(cJSON *transfer_gift_requestJSON);

cJSON *transfer_gift_request_convertToJSON(transfer_gift_request_t *transfer_gift_request);

#endif /* _transfer_gift_request_H_ */

