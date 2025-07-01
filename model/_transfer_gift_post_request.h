/*
 * _transfer_gift_post_request.h
 *
 * 
 */

#ifndef __transfer_gift_post_request_H_
#define __transfer_gift_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _transfer_gift_post_request_t _transfer_gift_post_request_t;




typedef struct _transfer_gift_post_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string
    int new_owner_chat_id; //numeric
    int star_count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _transfer_gift_post_request_t;

__attribute__((deprecated)) _transfer_gift_post_request_t *_transfer_gift_post_request_create(
    char *business_connection_id,
    char *owned_gift_id,
    int new_owner_chat_id,
    int star_count
);

void _transfer_gift_post_request_free(_transfer_gift_post_request_t *_transfer_gift_post_request);

_transfer_gift_post_request_t *_transfer_gift_post_request_parseFromJSON(cJSON *_transfer_gift_post_requestJSON);

cJSON *_transfer_gift_post_request_convertToJSON(_transfer_gift_post_request_t *_transfer_gift_post_request);

#endif /* __transfer_gift_post_request_H_ */

