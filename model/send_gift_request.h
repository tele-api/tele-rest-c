/*
 * send_gift_request.h
 *
 * Request parameters for sendGift
 */

#ifndef _send_gift_request_H_
#define _send_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_gift_request_t send_gift_request_t;

#include "message_entity.h"
#include "send_gift_request_chat_id.h"



typedef struct send_gift_request_t {
    char *gift_id; // string
    int user_id; //numeric
    struct send_gift_request_chat_id_t *chat_id; //model
    int pay_for_upgrade; //boolean
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} send_gift_request_t;

__attribute__((deprecated)) send_gift_request_t *send_gift_request_create(
    char *gift_id,
    int user_id,
    send_gift_request_chat_id_t *chat_id,
    int pay_for_upgrade,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void send_gift_request_free(send_gift_request_t *send_gift_request);

send_gift_request_t *send_gift_request_parseFromJSON(cJSON *send_gift_requestJSON);

cJSON *send_gift_request_convertToJSON(send_gift_request_t *send_gift_request);

#endif /* _send_gift_request_H_ */

