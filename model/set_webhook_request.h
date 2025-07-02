/*
 * set_webhook_request.h
 *
 * Request parameters for setWebhook
 */

#ifndef _set_webhook_request_H_
#define _set_webhook_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_webhook_request_t set_webhook_request_t;

#include "any_type.h"



typedef struct set_webhook_request_t {
    char *url; // string
    any_type_t *certificate; // custom
    char *ip_address; // string
    int max_connections; //numeric
    list_t *allowed_updates; //primitive container
    int drop_pending_updates; //boolean
    char *secret_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} set_webhook_request_t;

__attribute__((deprecated)) set_webhook_request_t *set_webhook_request_create(
    char *url,
    any_type_t *certificate,
    char *ip_address,
    int max_connections,
    list_t *allowed_updates,
    int drop_pending_updates,
    char *secret_token
);

void set_webhook_request_free(set_webhook_request_t *set_webhook_request);

set_webhook_request_t *set_webhook_request_parseFromJSON(cJSON *set_webhook_requestJSON);

cJSON *set_webhook_request_convertToJSON(set_webhook_request_t *set_webhook_request);

#endif /* _set_webhook_request_H_ */

