/*
 * webhook_info.h
 *
 * Describes the current status of a webhook.
 */

#ifndef _webhook_info_H_
#define _webhook_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct webhook_info_t webhook_info_t;




typedef struct webhook_info_t {
    char *url; // string
    int has_custom_certificate; //boolean
    int pending_update_count; //numeric
    char *ip_address; // string
    int last_error_date; //numeric
    char *last_error_message; // string
    int last_synchronization_error_date; //numeric
    int max_connections; //numeric
    list_t *allowed_updates; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} webhook_info_t;

__attribute__((deprecated)) webhook_info_t *webhook_info_create(
    char *url,
    int has_custom_certificate,
    int pending_update_count,
    char *ip_address,
    int last_error_date,
    char *last_error_message,
    int last_synchronization_error_date,
    int max_connections,
    list_t *allowed_updates
);

void webhook_info_free(webhook_info_t *webhook_info);

webhook_info_t *webhook_info_parseFromJSON(cJSON *webhook_infoJSON);

cJSON *webhook_info_convertToJSON(webhook_info_t *webhook_info);

#endif /* _webhook_info_H_ */

