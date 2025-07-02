/*
 * get_user_chat_boosts_request_chat_id.h
 *
 * Unique identifier for the chat or username of the channel (in the format &#x60;@channelusername&#x60;)
 */

#ifndef _get_user_chat_boosts_request_chat_id_H_
#define _get_user_chat_boosts_request_chat_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_user_chat_boosts_request_chat_id_t get_user_chat_boosts_request_chat_id_t;




typedef struct get_user_chat_boosts_request_chat_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} get_user_chat_boosts_request_chat_id_t;

__attribute__((deprecated)) get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_create(
);

void get_user_chat_boosts_request_chat_id_free(get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id);

get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id_parseFromJSON(cJSON *get_user_chat_boosts_request_chat_idJSON);

cJSON *get_user_chat_boosts_request_chat_id_convertToJSON(get_user_chat_boosts_request_chat_id_t *get_user_chat_boosts_request_chat_id);

#endif /* _get_user_chat_boosts_request_chat_id_H_ */

