/*
 * get_chat_request.h
 *
 * Request parameters for getChat
 */

#ifndef _get_chat_request_H_
#define _get_chat_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_chat_request_t get_chat_request_t;

#include "leave_chat_request_chat_id.h"



typedef struct get_chat_request_t {
    struct leave_chat_request_chat_id_t *chat_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_chat_request_t;

__attribute__((deprecated)) get_chat_request_t *get_chat_request_create(
    leave_chat_request_chat_id_t *chat_id
);

void get_chat_request_free(get_chat_request_t *get_chat_request);

get_chat_request_t *get_chat_request_parseFromJSON(cJSON *get_chat_requestJSON);

cJSON *get_chat_request_convertToJSON(get_chat_request_t *get_chat_request);

#endif /* _get_chat_request_H_ */

