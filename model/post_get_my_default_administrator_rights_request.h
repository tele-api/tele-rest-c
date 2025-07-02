/*
 * post_get_my_default_administrator_rights_request.h
 *
 * 
 */

#ifndef _post_get_my_default_administrator_rights_request_H_
#define _post_get_my_default_administrator_rights_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_get_my_default_administrator_rights_request_t post_get_my_default_administrator_rights_request_t;




typedef struct post_get_my_default_administrator_rights_request_t {
    int for_channels; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_get_my_default_administrator_rights_request_t;

__attribute__((deprecated)) post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_create(
    int for_channels
);

void post_get_my_default_administrator_rights_request_free(post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request);

post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request_parseFromJSON(cJSON *post_get_my_default_administrator_rights_requestJSON);

cJSON *post_get_my_default_administrator_rights_request_convertToJSON(post_get_my_default_administrator_rights_request_t *post_get_my_default_administrator_rights_request);

#endif /* _post_get_my_default_administrator_rights_request_H_ */

