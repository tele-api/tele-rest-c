/*
 * get_webhook_info_response.h
 *
 * 
 */

#ifndef _get_webhook_info_response_H_
#define _get_webhook_info_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_webhook_info_response_t get_webhook_info_response_t;

#include "webhook_info.h"



typedef struct get_webhook_info_response_t {
    int ok; //boolean
    struct webhook_info_t *result; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_webhook_info_response_t;

__attribute__((deprecated)) get_webhook_info_response_t *get_webhook_info_response_create(
    int ok,
    webhook_info_t *result
);

void get_webhook_info_response_free(get_webhook_info_response_t *get_webhook_info_response);

get_webhook_info_response_t *get_webhook_info_response_parseFromJSON(cJSON *get_webhook_info_responseJSON);

cJSON *get_webhook_info_response_convertToJSON(get_webhook_info_response_t *get_webhook_info_response);

#endif /* _get_webhook_info_response_H_ */

