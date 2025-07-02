/*
 * get_user_chat_boosts_request.h
 *
 * Request parameters for getUserChatBoosts
 */

#ifndef _get_user_chat_boosts_request_H_
#define _get_user_chat_boosts_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_user_chat_boosts_request_t get_user_chat_boosts_request_t;

#include "get_user_chat_boosts_request_chat_id.h"



typedef struct get_user_chat_boosts_request_t {
    struct get_user_chat_boosts_request_chat_id_t *chat_id; //model
    int user_id; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} get_user_chat_boosts_request_t;

__attribute__((deprecated)) get_user_chat_boosts_request_t *get_user_chat_boosts_request_create(
    get_user_chat_boosts_request_chat_id_t *chat_id,
    int user_id
);

void get_user_chat_boosts_request_free(get_user_chat_boosts_request_t *get_user_chat_boosts_request);

get_user_chat_boosts_request_t *get_user_chat_boosts_request_parseFromJSON(cJSON *get_user_chat_boosts_requestJSON);

cJSON *get_user_chat_boosts_request_convertToJSON(get_user_chat_boosts_request_t *get_user_chat_boosts_request);

#endif /* _get_user_chat_boosts_request_H_ */

