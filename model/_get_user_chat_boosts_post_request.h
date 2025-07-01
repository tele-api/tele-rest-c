/*
 * _get_user_chat_boosts_post_request.h
 *
 * 
 */

#ifndef __get_user_chat_boosts_post_request_H_
#define __get_user_chat_boosts_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_user_chat_boosts_post_request_t _get_user_chat_boosts_post_request_t;

#include "_get_user_chat_boosts_post_request_chat_id.h"



typedef struct _get_user_chat_boosts_post_request_t {
    struct _get_user_chat_boosts_post_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} _get_user_chat_boosts_post_request_t;

__attribute__((deprecated)) _get_user_chat_boosts_post_request_t *_get_user_chat_boosts_post_request_create(
    _get_user_chat_boosts_post_request_chat_id_t *chat_id,
    int user_id
);

void _get_user_chat_boosts_post_request_free(_get_user_chat_boosts_post_request_t *_get_user_chat_boosts_post_request);

_get_user_chat_boosts_post_request_t *_get_user_chat_boosts_post_request_parseFromJSON(cJSON *_get_user_chat_boosts_post_requestJSON);

cJSON *_get_user_chat_boosts_post_request_convertToJSON(_get_user_chat_boosts_post_request_t *_get_user_chat_boosts_post_request);

#endif /* __get_user_chat_boosts_post_request_H_ */

