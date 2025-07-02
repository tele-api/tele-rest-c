/*
 * set_business_account_gift_settings_request.h
 *
 * Request parameters for setBusinessAccountGiftSettings
 */

#ifndef _set_business_account_gift_settings_request_H_
#define _set_business_account_gift_settings_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_business_account_gift_settings_request_t set_business_account_gift_settings_request_t;

#include "accepted_gift_types.h"



typedef struct set_business_account_gift_settings_request_t {
    char *business_connection_id; // string
    int show_gift_button; //boolean
    struct accepted_gift_types_t *accepted_gift_types; //model

    int _library_owned; // Is the library responsible for freeing this object?
} set_business_account_gift_settings_request_t;

__attribute__((deprecated)) set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_create(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
);

void set_business_account_gift_settings_request_free(set_business_account_gift_settings_request_t *set_business_account_gift_settings_request);

set_business_account_gift_settings_request_t *set_business_account_gift_settings_request_parseFromJSON(cJSON *set_business_account_gift_settings_requestJSON);

cJSON *set_business_account_gift_settings_request_convertToJSON(set_business_account_gift_settings_request_t *set_business_account_gift_settings_request);

#endif /* _set_business_account_gift_settings_request_H_ */

