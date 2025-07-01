/*
 * _send_gift_post_request.h
 *
 * 
 */

#ifndef __send_gift_post_request_H_
#define __send_gift_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _send_gift_post_request_t _send_gift_post_request_t;

#include "_send_gift_post_request_chat_id.h"
#include "message_entity.h"



typedef struct _send_gift_post_request_t {
    char *gift_id; // string
    int user_id; //numeric
    struct _send_gift_post_request_chat_id_t *chat_id; //model
    int pay_for_upgrade; //boolean
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} _send_gift_post_request_t;

__attribute__((deprecated)) _send_gift_post_request_t *_send_gift_post_request_create(
    char *gift_id,
    int user_id,
    _send_gift_post_request_chat_id_t *chat_id,
    int pay_for_upgrade,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void _send_gift_post_request_free(_send_gift_post_request_t *_send_gift_post_request);

_send_gift_post_request_t *_send_gift_post_request_parseFromJSON(cJSON *_send_gift_post_requestJSON);

cJSON *_send_gift_post_request_convertToJSON(_send_gift_post_request_t *_send_gift_post_request);

#endif /* __send_gift_post_request_H_ */

