/*
 * _set_business_account_gift_settings_post_request.h
 *
 * 
 */

#ifndef __set_business_account_gift_settings_post_request_H_
#define __set_business_account_gift_settings_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _set_business_account_gift_settings_post_request_t _set_business_account_gift_settings_post_request_t;

#include "accepted_gift_types.h"



typedef struct _set_business_account_gift_settings_post_request_t {
    char *business_connection_id; // string
    int show_gift_button; //boolean
    struct accepted_gift_types_t *accepted_gift_types; //model

    int _library_owned; // Is the library responsible for freeing this object?
} _set_business_account_gift_settings_post_request_t;

__attribute__((deprecated)) _set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_create(
    char *business_connection_id,
    int show_gift_button,
    accepted_gift_types_t *accepted_gift_types
);

void _set_business_account_gift_settings_post_request_free(_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request);

_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request_parseFromJSON(cJSON *_set_business_account_gift_settings_post_requestJSON);

cJSON *_set_business_account_gift_settings_post_request_convertToJSON(_set_business_account_gift_settings_post_request_t *_set_business_account_gift_settings_post_request);

#endif /* __set_business_account_gift_settings_post_request_H_ */

