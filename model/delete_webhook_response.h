/*
 * delete_webhook_response.h
 *
 * 
 */

#ifndef _delete_webhook_response_H_
#define _delete_webhook_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_webhook_response_t delete_webhook_response_t;




typedef struct delete_webhook_response_t {
    int ok; //boolean
    int result; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} delete_webhook_response_t;

__attribute__((deprecated)) delete_webhook_response_t *delete_webhook_response_create(
    int ok,
    int result
);

void delete_webhook_response_free(delete_webhook_response_t *delete_webhook_response);

delete_webhook_response_t *delete_webhook_response_parseFromJSON(cJSON *delete_webhook_responseJSON);

cJSON *delete_webhook_response_convertToJSON(delete_webhook_response_t *delete_webhook_response);

#endif /* _delete_webhook_response_H_ */

