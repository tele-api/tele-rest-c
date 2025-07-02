/*
 * set_my_default_administrator_rights_request.h
 *
 * Request parameters for setMyDefaultAdministratorRights
 */

#ifndef _set_my_default_administrator_rights_request_H_
#define _set_my_default_administrator_rights_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_my_default_administrator_rights_request_t set_my_default_administrator_rights_request_t;

#include "chat_administrator_rights.h"



typedef struct set_my_default_administrator_rights_request_t {
    struct chat_administrator_rights_t *rights; //model
    int for_channels; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_my_default_administrator_rights_request_t;

__attribute__((deprecated)) set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_create(
    chat_administrator_rights_t *rights,
    int for_channels
);

void set_my_default_administrator_rights_request_free(set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request);

set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request_parseFromJSON(cJSON *set_my_default_administrator_rights_requestJSON);

cJSON *set_my_default_administrator_rights_request_convertToJSON(set_my_default_administrator_rights_request_t *set_my_default_administrator_rights_request);

#endif /* _set_my_default_administrator_rights_request_H_ */

