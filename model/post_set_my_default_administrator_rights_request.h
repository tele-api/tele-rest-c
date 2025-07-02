/*
 * post_set_my_default_administrator_rights_request.h
 *
 * 
 */

#ifndef _post_set_my_default_administrator_rights_request_H_
#define _post_set_my_default_administrator_rights_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_set_my_default_administrator_rights_request_t post_set_my_default_administrator_rights_request_t;

#include "chat_administrator_rights.h"



typedef struct post_set_my_default_administrator_rights_request_t {
    struct chat_administrator_rights_t *rights; //model
    int for_channels; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} post_set_my_default_administrator_rights_request_t;

__attribute__((deprecated)) post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_create(
    chat_administrator_rights_t *rights,
    int for_channels
);

void post_set_my_default_administrator_rights_request_free(post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request);

post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request_parseFromJSON(cJSON *post_set_my_default_administrator_rights_requestJSON);

cJSON *post_set_my_default_administrator_rights_request_convertToJSON(post_set_my_default_administrator_rights_request_t *post_set_my_default_administrator_rights_request);

#endif /* _post_set_my_default_administrator_rights_request_H_ */

