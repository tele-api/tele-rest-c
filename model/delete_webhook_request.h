/*
 * delete_webhook_request.h
 *
 * Request parameters for deleteWebhook
 */

#ifndef _delete_webhook_request_H_
#define _delete_webhook_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_webhook_request_t delete_webhook_request_t;




typedef struct delete_webhook_request_t {
    int drop_pending_updates; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_webhook_request_t;

__attribute__((deprecated)) delete_webhook_request_t *delete_webhook_request_create(
    int drop_pending_updates
);

void delete_webhook_request_free(delete_webhook_request_t *delete_webhook_request);

delete_webhook_request_t *delete_webhook_request_parseFromJSON(cJSON *delete_webhook_requestJSON);

cJSON *delete_webhook_request_convertToJSON(delete_webhook_request_t *delete_webhook_request);

#endif /* _delete_webhook_request_H_ */

