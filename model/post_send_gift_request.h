/*
 * post_send_gift_request.h
 *
 * 
 */

#ifndef _post_send_gift_request_H_
#define _post_send_gift_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_send_gift_request_t post_send_gift_request_t;

#include "message_entity.h"
#include "post_send_gift_request_chat_id.h"



typedef struct post_send_gift_request_t {
    char *gift_id; // string
    int user_id; //numeric
    struct post_send_gift_request_chat_id_t *chat_id; //model
    int pay_for_upgrade; //boolean
    char *text; // string
    char *text_parse_mode; // string
    list_t *text_entities; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} post_send_gift_request_t;

__attribute__((deprecated)) post_send_gift_request_t *post_send_gift_request_create(
    char *gift_id,
    int user_id,
    post_send_gift_request_chat_id_t *chat_id,
    int pay_for_upgrade,
    char *text,
    char *text_parse_mode,
    list_t *text_entities
);

void post_send_gift_request_free(post_send_gift_request_t *post_send_gift_request);

post_send_gift_request_t *post_send_gift_request_parseFromJSON(cJSON *post_send_gift_requestJSON);

cJSON *post_send_gift_request_convertToJSON(post_send_gift_request_t *post_send_gift_request);

#endif /* _post_send_gift_request_H_ */

