/*
 * set_chat_description_request.h
 *
 * Request parameters for setChatDescription
 */

#ifndef _set_chat_description_request_H_
#define _set_chat_description_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_chat_description_request_t set_chat_description_request_t;

#include "send_message_request_chat_id.h"



typedef struct set_chat_description_request_t {
    struct send_message_request_chat_id_t *chat_id; //model
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_chat_description_request_t;

__attribute__((deprecated)) set_chat_description_request_t *set_chat_description_request_create(
    send_message_request_chat_id_t *chat_id,
    char *description
);

void set_chat_description_request_free(set_chat_description_request_t *set_chat_description_request);

set_chat_description_request_t *set_chat_description_request_parseFromJSON(cJSON *set_chat_description_requestJSON);

cJSON *set_chat_description_request_convertToJSON(set_chat_description_request_t *set_chat_description_request);

#endif /* _set_chat_description_request_H_ */

