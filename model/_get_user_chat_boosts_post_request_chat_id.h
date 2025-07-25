/*
 * _get_user_chat_boosts_post_request_chat_id.h
 *
 * Unique identifier for the chat or username of the channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef __get_user_chat_boosts_post_request_chat_id_H_
#define __get_user_chat_boosts_post_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _get_user_chat_boosts_post_request_chat_id_t _get_user_chat_boosts_post_request_chat_id_t;




typedef struct _get_user_chat_boosts_post_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} _get_user_chat_boosts_post_request_chat_id_t;

__attribute__((deprecated)) _get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_create(
);

void _get_user_chat_boosts_post_request_chat_id_free(_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id);

_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id_parseFromJSON(cJSON *_get_user_chat_boosts_post_request_chat_idJSON);

cJSON *_get_user_chat_boosts_post_request_chat_id_convertToJSON(_get_user_chat_boosts_post_request_chat_id_t *_get_user_chat_boosts_post_request_chat_id);

#endif /* __get_user_chat_boosts_post_request_chat_id_H_ */

