/*
 * send_gift_request_chat_id.h
 *
 * Required if *user\\_id* is not specified. Unique identifier for the chat or username of the channel (in the format &#x60;@channelusername&#x60;) that will receive the gift.
 */

#ifndef _send_gift_request_chat_id_H_
#define _send_gift_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_gift_request_chat_id_t send_gift_request_chat_id_t;




typedef struct send_gift_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} send_gift_request_chat_id_t;

__attribute__((deprecated)) send_gift_request_chat_id_t *send_gift_request_chat_id_create(
);

void send_gift_request_chat_id_free(send_gift_request_chat_id_t *send_gift_request_chat_id);

send_gift_request_chat_id_t *send_gift_request_chat_id_parseFromJSON(cJSON *send_gift_request_chat_idJSON);

cJSON *send_gift_request_chat_id_convertToJSON(send_gift_request_chat_id_t *send_gift_request_chat_id);

#endif /* _send_gift_request_chat_id_H_ */

