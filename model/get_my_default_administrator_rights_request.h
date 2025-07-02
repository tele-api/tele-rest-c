/*
 * get_my_default_administrator_rights_request.h
 *
 * Request parameters for getMyDefaultAdministratorRights
 */

#ifndef _get_my_default_administrator_rights_request_H_
#define _get_my_default_administrator_rights_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_my_default_administrator_rights_request_t get_my_default_administrator_rights_request_t;




typedef struct get_my_default_administrator_rights_request_t {
    int for_channels; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} get_my_default_administrator_rights_request_t;

__attribute__((deprecated)) get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_create(
    int for_channels
);

void get_my_default_administrator_rights_request_free(get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request);

get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request_parseFromJSON(cJSON *get_my_default_administrator_rights_requestJSON);

cJSON *get_my_default_administrator_rights_request_convertToJSON(get_my_default_administrator_rights_request_t *get_my_default_administrator_rights_request);

#endif /* _get_my_default_administrator_rights_request_H_ */

